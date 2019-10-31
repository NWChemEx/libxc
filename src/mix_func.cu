/*
 Copyright (C) 2006-2007 M.A.L. Marques
               2018 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "xc_device.h"
#include "cublas_v2.h"


#define is_mgga(id)   ((id) == XC_FAMILY_MGGA || (id) == XC_FAMILY_HYB_MGGA)
#define is_gga(id)    ((id) == XC_FAMILY_GGA  || (id) == XC_FAMILY_HYB_GGA || is_mgga(id))
#define is_lda(id)    ((id) == XC_FAMILY_LDA  || is_gga(is))
#define safe_free(pt) if(pt != NULL) free(pt)

cublasHandle_t cublas_handle;
double *device_funcs_coef;

void
xc_mix_func_init_cublas()
{
    checkCublas(__FILE__,__LINE__,cublasCreate(&cublas_handle));
    checkCublas(__FILE__,__LINE__,cublasSetPointerMode(cublas_handle,CUBLAS_POINTER_MODE_DEVICE));
    checkCuda(__FILE__,__LINE__,cudaMalloc(&device_funcs_coef,XC_MAX_FUNC_TERMS*sizeof(double)));
}

void
xc_mix_func_end_cublas()
{
    checkCublas(__FILE__,__LINE__,cublasDestroy(cublas_handle));
    checkCuda(__FILE__,__LINE__,cudaFree(device_funcs_coef));
}

void
xc_mix_func_offload(const xc_func_type *func, int np,
            const double *rho, const double *sigma, const double *lapl, const double *tau,
            double *zk, MGGA_OUT_PARAMS_NO_EXC(double *),
            cudaStream_t stream)
{
  const xc_func_type *aux;
  double *zk_;
  double *vrho_, *vsigma_, *vlapl_, *vtau_;
  double *v2rho2_, *v2rhosigma_, *v2rholapl_, *v2rhotau_;
  double *v2sigma2_, *v2sigmalapl_, *v2sigmatau_;
  double *v2lapl2_, *v2lapltau_;
  double *v2tau2_;
  double *v3rho3_, *v3rho2sigma_, *v3rho2lapl_, *v3rho2tau_;
  double *v3rhosigma2_, *v3rhosigmalapl_, *v3rhosigmatau_;
  double *v3rholapl2_, *v3rholapltau_;
  double *v3rhotau2_;
  double *v3sigma3_, *v3sigma2lapl_, *v3sigma2tau_;
  double *v3sigmalapl2_, *v3sigmalapltau_;
  double *v3sigmatau2_;
  double *v3lapl3_, *v3lapl2tau_;
  double *v3lapltau2_;
  double *v3tau3_;

  int ii;
  /* CUDA status */
  cudaError_t stat;

  const xc_dimensions *dim = &(func->dim);

  /* prepare buffers that will hold the results from the individual functionals */
  /* The model is:
   * - we allocate the output buffers to be twice the regular size:
   *   - the first np entries will be set to the results of the total functional
   *   - the second np entries will be used as buffers for the functional terms.
   * - hence the second np entries are the ones passed into the functional as 
   *   output buffer.
   * - we need to use some cuBlas operation to add the terms as all the (double*)
   *   arguments are device pointers that cannot be accessed directly in this 
   *   function.
   * Doing things this way we can use linear combinations of functionals without
   * having to do strange things to the API.
   */
  zk_ = NULL;  
  vrho_ = vsigma_ = vlapl_ = vtau_ = NULL;
  v2rho2_ = v2rhosigma_ = v2rholapl_ = v2rhotau_ = NULL;
  v2sigma2_ =  v2sigmalapl_ = v2sigmatau_ = NULL;
  v2lapl2_ = v2lapltau_ = NULL;
  v2tau2_ = NULL;
  v3rho3_ = v3rho2sigma_ = v3rho2lapl_ = v3rho2tau_ = NULL;
  v3rhosigma2_ = v3rhosigmalapl_ = v3rhosigmatau_ = NULL;
  v3rholapl2_ = v3rholapltau_ = NULL;
  v3rhotau2_ = NULL;
  v3sigma3_ = v3sigma2lapl_ = v3sigma2tau_ = NULL;
  v3sigmalapl2_ = v3sigmalapltau_ = NULL;
  v3sigmatau2_ = NULL;
  v3lapl3_ = v3lapl2tau_ = NULL;
  v3lapltau2_ = NULL;
  v3tau3_ = NULL;

  if(zk != NULL)
    zk_ = zk + np*dim->zk;

  if(vrho != NULL){
    vrho_ = vrho + np*dim->vrho;
    if(is_gga(func->info->family)){
      vsigma_ = vsigma + np*dim->vsigma;
    }
    if(is_mgga(func->info->family)){
      /* At the moment we always allocate the derivatives involving
         the laplacian, as some parts of Libxc do not take into
         account the XC_FLAGS_NEEDS_LAPLACIAN flag.
         if(func->info->flags & XC_FLAGS_NEEDS_LAPLACIAN){ */
      vlapl_ = vlapl + np*dim->vlapl;
      /* } */
      vtau_  = vtau  + np*dim->vtau;
    }
  }

  if(v2rho2 != NULL){
    v2rho2_ = v2rho2 + np*dim->v2rho2;
    if(is_gga(func->info->family)){
      v2rhosigma_  = v2rhosigma + np*dim->v2rhosigma;
      v2sigma2_    = v2sigma2   + np*dim->v2sigma2;
    }
    if(is_mgga(func->info->family)){
      v2rholapl_   = v2rholapl   + np*dim->v2rholapl;
      v2rhotau_    = v2rhotau    + np*dim->v2rhotau;
      v2sigmalapl_ = v2sigmalapl + np*dim->v2sigmalapl;
      v2sigmatau_  = v2sigmatau  + np*dim->v2sigmatau;
      v2lapl2_     = v2lapl2     + np*dim->v2lapl2;
      v2lapltau_   = v2lapltau   + np*dim->v2lapltau;
      v2tau2_      = v2tau2      + np*dim->v2tau2;
    }
  }

  if(v3rho3 != NULL){
    v3rho3_      = v3rho3 + np*dim->v3rho3;
    if(is_gga(func->info->family)){
      v3rho2sigma_ = v3rho2sigma + np*dim->v3rho2sigma;
      v3rhosigma2_ = v3rhosigma2 + np*dim->v3rhosigma2;
      v3sigma3_    = v3sigma3    + np*dim->v3sigma3;
    }
    if(is_mgga(func->info->family)){
      v3rho2lapl_     = v3rho2lapl     + np*dim->v3rho2lapl;
      v3rho2tau_      = v3rho2tau      + np*dim->v3rho2tau;
      v3rhosigmalapl_ = v3rhosigmalapl + np*dim->v3rhosigmalapl;
      v3rhosigmatau_  = v3rhosigmatau  + np*dim->v3rhosigmatau;
      v3rholapl2_     = v3rholapl2     + np*dim->v3rholapl2;
      v3rholapltau_   = v3rholapltau   + np*dim->v3rholapltau;
      v3rhotau2_      = v3rhotau2      + np*dim->v3rhotau2;
      v3sigma2lapl_   = v3sigma2lapl   + np*dim->v3sigma2lapl;
      v3sigma2tau_    = v3sigma2tau    + np*dim->v3sigma2tau;
      v3sigmalapl2_   = v3sigmalapl2   + np*dim->v3sigmalapl2;
      v3sigmalapltau_ = v3sigmalapltau + np*dim->v3sigmalapltau;
      v3sigmatau2_    = v3sigmatau2    + np*dim->v3sigmatau2;
      v3lapl3_        = v3lapl3        + np*dim->v3lapl3;
      v3lapl2tau_     = v3lapl2tau     + np*dim->v3lapl2tau;
      v3lapltau2_     = v3lapltau2     + np*dim->v3lapltau2;
      v3tau3_         = v3tau3         + np*dim->v3tau3;
    }
  }
  
  /* we now add the different components */
  checkCuda(__FILE__,__LINE__,cudaMemcpyAsync(device_funcs_coef,func->mix_coef,
                              func->n_func_aux*sizeof(double),cudaMemcpyHostToDevice,stream));
  checkCublas(__FILE__,__LINE__,cublasSetStream(cublas_handle, stream));
  for(ii=0; ii<func->n_func_aux; ii++){
    if(zk != NULL)
      checkCuda(__FILE__,__LINE__,cudaMemsetAsync(zk_, 0, dim->zk*np*sizeof(double), stream));
  
    if(vrho != NULL){
      assert(vsigma != NULL);
  
      checkCuda(__FILE__,__LINE__,cudaMemsetAsync(vrho_,   0, dim->vrho  *np*sizeof(double), stream));
      if(is_gga(func->info->family)){
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(vsigma_, 0, dim->vsigma*np*sizeof(double), stream));
      }
      if(is_mgga(func->info->family)){
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(vlapl_,  0, dim->vlapl*np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(vtau_,   0, dim->vtau*np*sizeof(double), stream));
      }
    }
  
    if(v2rho2 != NULL){
      assert(v2rhosigma!=NULL && v2sigma2!=NULL);
  
      checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2rho2_,        0, dim->v2rho2     *np*sizeof(double), stream));
      if(is_gga(func->info->family)){
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2rhosigma_,  0, dim->v2rhosigma *np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2sigma2_,    0, dim->v2sigma2   *np*sizeof(double), stream));
      }
      if(is_mgga(func->info->family)){
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2rholapl_,   0, dim->v2rholapl  *np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2rhotau_,    0, dim->v2rhotau   *np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2sigmalapl_, 0, dim->v2sigmalapl*np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2sigmatau_,  0, dim->v2sigmatau *np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2lapl2_,     0, dim->v2lapl2    *np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2lapltau_,   0, dim->v2lapltau  *np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2tau2_,      0, dim->v2tau2     *np*sizeof(double), stream));
      }
    }
  
    if(v3rho3 != NULL){
      assert(v3rho2sigma!=NULL && v3rhosigma2!=NULL && v3sigma3!=NULL);
  
      checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v3rho3_,      0, dim->v3rho3     *np*sizeof(double), stream));
      if(is_gga(func->info->family)){
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v3rho2sigma_, 0, dim->v3rho2sigma*np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v3rhosigma2_, 0, dim->v3rhosigma2*np*sizeof(double), stream));
        checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v3sigma3_,    0, dim->v3sigma3   *np*sizeof(double), stream));
      }
    }
    /* cudaMemset is supposed to be blocking
    stat = cudaDeviceSynchronize();
    if (stat != cudaSuccess) {
        fprintf(stderr,"Error: mix_init_offload pre-launch: %s\n",cudaGetErrorString( stat ));
    }
    else {
        fprintf(stderr,"Success: pre-launch sync\n");
    }
    */
    aux = func->func_aux[ii];
    if (aux->n_func_aux > 0) {
      fprintf(stderr,"Nested multi-term functionals in: %s\n",
              xc_functional_get_name(func->info->number));
      exit(1);
    }
    switch(aux->info->family){
    case XC_FAMILY_LDA:
      xc_lda_offload(aux, np, rho, zk_, vrho_, v2rho2_, NULL, stream);
      break;
    case XC_FAMILY_GGA:
      xc_gga_offload(aux, np, rho, sigma, zk_, vrho_, vsigma_,
             v2rho2_, v2rhosigma_, v2sigma2_,
             v3rho3_, v3rho2sigma_, v3rhosigma2_, v3sigma3_, stream);
      break;
    case XC_FAMILY_MGGA:
      xc_mgga_offload(aux, np, rho, sigma, lapl, tau,
              zk_,
              vrho_, vsigma_, vlapl_, vtau_,
              v2rho2_, v2rhosigma_, v2rholapl_, v2rhotau_,
              v2sigma2_, v2sigmalapl_, v2sigmatau_,
              v2lapl2_, v2lapltau_,
              v2tau2_,
              v3rho3_, v3rho2sigma_, v3rho2lapl_, v3rho2tau_,
              v3rhosigma2_, v3rhosigmalapl_, v3rhosigmatau_,
              v3rholapl2_, v3rholapltau_,
              v3rhotau2_,
              v3sigma3_, v3sigma2lapl_, v3sigma2tau_,
              v3sigmalapl2_, v3sigmalapltau_,
              v3sigmatau2_,
              v3lapl3_, v3lapl2tau_,
              v3lapltau2_,
              v3tau3_,
              stream);
      break;
    }
    //stat = cudaDeviceSynchronize();
    //if (stat != cudaSuccess) {
    //    fprintf(stderr,"Error: mix_init_offload post-launch: %s\n",cudaGetErrorString( stat ));
    //}
    //else {
    //    fprintf(stderr,"Success: post-launch sync\n");
    //}

    /* Sanity checks */
    if(is_gga(aux->info->family))
      assert(is_gga(func->info->family));
    if(is_mgga(aux->info->family) && !is_mgga(func->info->family))
      assert(is_mgga(func->info->family));
    if(aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN)
      assert(func->info->flags & XC_FLAGS_NEEDS_LAPLACIAN);

    if(zk != NULL) {
      checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->zk,device_funcs_coef+ii,
                                                zk_,1,zk,1));
    }

    if(vrho != NULL) {
      checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->vrho,device_funcs_coef+ii,vrho_,1,vrho,1));

      if(is_gga(aux->info->family)) {
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->vsigma,device_funcs_coef+ii,vsigma_,1,vsigma,1));
      }

      if(is_mgga(aux->info->family)) {
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->vtau,device_funcs_coef+ii,vtau_,1,vtau,1));
        if(aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) {
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->lapl,device_funcs_coef+ii,vlapl_,1,vlapl,1));
        }
      }
    }

    if(v2rho2 != NULL){
      checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2rho2,device_funcs_coef+ii,v2rho2_,1,v2rho2,1));

      if(is_gga(aux->info->family)) {
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2rhosigma,device_funcs_coef+ii,v2rhosigma_,1,v2rhosigma,1));
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2sigma2,device_funcs_coef+ii,v2sigma2_,1,v2sigma2,1));
      }

      if(is_mgga(aux->info->family)) {
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2rhotau,device_funcs_coef+ii,v2rhotau_,1,v2rhotau,1));
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2sigmatau,device_funcs_coef+ii,v2sigmatau_,1,v2sigmatau,1));
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2tau2,device_funcs_coef+ii,v2tau2_,1,v2tau2,1));
        if(aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) {
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2rholapl,device_funcs_coef+ii,v2rholapl_,1,v2rholapl,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2lapl2,device_funcs_coef+ii,v2lapl2_,1,v2lapl2,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2sigmalapl,device_funcs_coef+ii,v2sigmalapl_,1,v2sigmalapl,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v2lapltau,device_funcs_coef+ii,v2lapltau_,1,v2lapltau,1));
        }
      }
    }

    if(v3rho3 != NULL){
      checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3rho3,device_funcs_coef+ii,v3rho3_,1,v3rho3,1));
      
      if(is_gga(aux->info->family)) {
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3rho2sigma,device_funcs_coef+ii,v3rho2sigma_,1,v3rho2sigma,1));
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3rhosigma2,device_funcs_coef+ii,v3rhosigma2_,1,v3rhosigma2,1));
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3sigma3,device_funcs_coef+ii,v3sigma3_,1,v3sigma3,1));
      }
      if(is_mgga(aux->info->family)) {
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3rho2tau,device_funcs_coef+ii,v3rho2tau_,1,v3rho2tau,1));
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3rhotau2,device_funcs_coef+ii,v3rhotau2_,1,v3rhotau2,1));
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3sigma2tau,device_funcs_coef+ii,v3sigma2tau_,1,v3sigma2tau,1));
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3sigmatau2,device_funcs_coef+ii,v3sigmatau2_,1,v3sigmatau2,1));
        checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3tau3,device_funcs_coef+ii,v3tau3_,1,v3tau3,1));

        if(aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) {
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3rho2lapl,device_funcs_coef+ii,v3rho2lapl_,1,v3rho2lapl,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3rholapl2,device_funcs_coef+ii,v3rholapl2_,1,v3rholapl2,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3rholapltau,device_funcs_coef+ii,v3rholapltau_,1,v3rholapltau,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3sigma2lapl,device_funcs_coef+ii,v3sigma2lapl_,1,v3sigma2lapl,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3sigmalapl2,device_funcs_coef+ii,v3sigmalapl2_,1,v3sigmalapl2,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3sigmalapltau,device_funcs_coef+ii,v3sigmalapltau_,1,v3sigmalapltau,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3lapl3,device_funcs_coef+ii,v3lapl3_,1,v3lapl3,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3lapl2tau,device_funcs_coef+ii,v3lapl2tau_,1,v3lapl2tau,1));
          checkCublas(__FILE__,__LINE__,cublasDaxpy(cublas_handle,np*dim->v3lapltau2,device_funcs_coef+ii,v3lapltau2_,1,v3lapltau2,1));
        }
      }  
    }
    //stat = cudaDeviceSynchronize();
    //if (stat != cudaSuccess) {
    //    fprintf(stderr,"Error: mix_init_offload post-daxpy: %s\n",cudaGetErrorString( stat ));
    //}
    //else {
    //    fprintf(stderr,"Success: post-daxpy sync\n");
    //}
  }
  checkCublas(__FILE__,__LINE__,cublasSetStream(cublas_handle,NULL));

}
