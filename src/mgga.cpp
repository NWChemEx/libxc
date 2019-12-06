/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <hip/hip_runtime.h>
#include "xc_device.h"
#include "util.h"

#ifdef __cplusplus
extern "C" {
#endif

void 
xc_mgga_offload(const xc_func_type *func, int np,
        const double *rho, const double *sigma, const double *lapl, const double *tau,
        double *zk, MGGA_OUT_PARAMS_NO_EXC(double *),
        hipStream_t stream)
{
  assert(func != NULL);
  const xc_dimensions *dim = &(func->dim);
  
  /* sanity check */
  if(zk != NULL && !(func->info->flags & XC_FLAGS_HAVE_EXC)){
    fprintf(stderr, "Functional '%s' does not provide an implementation of Exc\n",
            func->info->name);
    exit(1);
  }

  if(vrho != NULL && !(func->info->flags & XC_FLAGS_HAVE_VXC)){
    fprintf(stderr, "Functional '%s' does not provide an implementation of vxc\n",
            func->info->name);
    exit(1);
  }

  if(v2rho2 != NULL && !(func->info->flags & XC_FLAGS_HAVE_FXC)){
    fprintf(stderr, "Functional '%s' does not provide an implementation of fxc\n",
            func->info->name);
    exit(1);
  }

  if(v3rho3 != NULL && !(func->info->flags & XC_FLAGS_HAVE_KXC)){
    fprintf(stderr, "Functional '%s' does not provide an implementation of kxc\n",
            func->info->name);
    exit(1);
  }


  /* initialize output to zero */
  int nd = 1;
  if(func->n_func_aux > 0) nd = 2;
  if(zk != NULL)
    checkHip(__FILE__,__LINE__,hipMemsetAsync(zk, 0, dim->zk*np*nd*sizeof(double), stream));

  if(vrho != NULL){
    assert(vsigma != NULL);
    if(func->info->flags & XC_FLAGS_NEEDS_LAPLACIAN)
      assert(vlapl != NULL);
    assert(vtau   != NULL);

    checkHip(__FILE__,__LINE__,hipMemsetAsync(vrho,   0, dim->vrho  *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(vsigma, 0, dim->vsigma*np*nd*sizeof(double), stream));
    if(func->info->flags & XC_FLAGS_NEEDS_LAPLACIAN)
       checkHip(__FILE__,__LINE__,hipMemsetAsync(vlapl,  0, dim->vlapl *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(vtau,   0, dim->vtau  *np*nd*sizeof(double), stream));
  }

  if(v2rho2 != NULL){
    assert(v2rhosigma != NULL);
    assert(v2rhotau   != NULL);
    assert(v2sigma2   != NULL);
    assert(v2sigmatau != NULL);
    assert(v2tau2     != NULL);

    if(func->info->flags & XC_FLAGS_NEEDS_LAPLACIAN){
      assert(v2rholapl   != NULL);
      assert(v2sigmalapl != NULL);
      assert(v2lapl2     != NULL);
      assert(v2lapltau   != NULL);
    }
      
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v2rho2,     0, dim->v2rho2     *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v2rhosigma, 0, dim->v2rhosigma *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v2rhotau,   0, dim->v2rhotau   *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v2sigma2,   0, dim->v2sigma2   *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v2sigmatau, 0, dim->v2sigmatau *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v2tau2,     0, dim->v2tau2     *np*nd*sizeof(double), stream));

    if(func->info->flags & XC_FLAGS_NEEDS_LAPLACIAN){
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v2rholapl,   0, dim->v2rholapl  *np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v2sigmalapl, 0, dim->v2sigmalapl*np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v2lapl2,     0, dim->v2lapl2    *np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v2lapltau,   0, dim->v2lapltau  *np*nd*sizeof(double), stream));
    }
  }

  if(v3rho3 != NULL){
    assert(v3rho2sigma   != NULL);
    assert(v3rho2tau     != NULL);
    assert(v3rhosigma2   != NULL);
    assert(v3rhosigmatau != NULL);
    assert(v3rhotau2     != NULL);
    assert(v3sigma3      != NULL);
    assert(v3sigma2tau   != NULL);
    assert(v3sigmatau2   != NULL);
    assert(v3tau3        != NULL);

    if(func->info->flags & XC_FLAGS_NEEDS_LAPLACIAN){    
      assert(v3rho2lapl     != NULL);
      assert(v3rhosigmalapl != NULL);
      assert(v3rholapl2     != NULL);
      assert(v3rholapltau   != NULL);
      assert(v3sigma2lapl   != NULL);
      assert(v3sigmalapl2   != NULL);
      assert(v3sigmalapltau != NULL);
      assert(v3lapl3        != NULL);
      assert(v3lapl2tau     != NULL);
    }
	
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rho3,        0, dim->v3rho3       *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rho2sigma,   0, dim->v3rho2sigma  *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rho2tau,     0, dim->v3rho2tau    *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rhosigma2,   0, dim->v3rhosigma2  *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rhosigmatau, 0, dim->v3rhosigmatau*np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rhotau2,     0, dim->v3rhotau2    *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3sigma3,      0, dim->v3sigma3     *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3sigma2tau,   0, dim->v3sigma2tau  *np*nd*sizeof(double), stream));
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3sigmatau2,   0, dim->v3sigmatau2  *np*nd*sizeof(double), stream));  
    checkHip(__FILE__,__LINE__,hipMemsetAsync(v3tau3,        0, dim->v3tau3       *np*nd*sizeof(double), stream));

    if(func->info->flags & XC_FLAGS_NEEDS_LAPLACIAN){
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rho2lapl,     0, dim->v3rho2lapl    *np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rhosigmalapl, 0, dim->v3rhosigmalapl*np*nd*sizeof(double), stream));      
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rholapl2,     0, dim->v3rholapl2    *np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v3rholapltau,   0, dim->v3rholapltau  *np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v3sigma2lapl,   0, dim->v3sigma2lapl  *np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v3sigmalapl2,   0, dim->v3sigmalapl2  *np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v3sigmalapltau, 0, dim->v3sigmalapltau*np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v3lapl3,        0, dim->v3lapl3       *np*nd*sizeof(double), stream));
      checkHip(__FILE__,__LINE__,hipMemsetAsync(v3lapl2tau,     0, dim->v3lapl2tau    *np*nd*sizeof(double), stream));
    }
  }

  /* call functional */
  if(func->info->mgga != NULL) {
    if(func->info->mgga_offload == NULL) {
      fprintf(stderr,"GPU port of %s not supported\n",func->info->name);
    }
    assert(func->info->mgga_offload != NULL);
    func->info->mgga_offload(func, np, rho, sigma, lapl, tau, zk, MGGA_OUT_PARAMS_NO_EXC(), stream);
  }

  /* WARNING: Kxc is not properly mixed */
  if(func->n_func_aux > 0) {
    //fprintf(stderr,"Multi-term functional: %s\n",func->info->name);
    xc_mix_func_offload(func, np, rho, sigma, lapl, tau,
                zk, vrho, vsigma, vlapl, vtau,
                v2rho2, v2rhosigma, v2rholapl, v2rhotau, 
                v2sigma2, v2sigmalapl, v2sigmatau,
                v2lapl2, v2lapltau,
                v2tau2,
                v3rho3, v3rho2sigma, v3rho2lapl, v3rho2tau,
                v3rhosigma2, v3rhosigmalapl, v3rhosigmatau,
                v3rholapl2, v3rholapltau,
                v3rhotau2,
                v3sigma3, v3sigma2lapl, v3sigma2tau,
                v3sigmalapl2, v3sigmalapltau,
                v3sigmatau2,
                v3lapl3, v3lapl2tau,
                v3lapltau2,
                v3tau3,
                stream
                );
  }

}

/* specializations */
void
xc_mgga_exc_offload(const xc_func_type *p, int np, 
            const double *rho, const double *sigma, const double *lapl, const double *tau,
            double *zk, hipStream_t stream)
{
  xc_mgga_offload(p, np, rho, sigma, lapl, tau, zk, NULL, NULL, NULL, NULL, 
          NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
          NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
          NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
          stream);
}

void
xc_mgga_exc_vxc_offload(const xc_func_type *p, int np,
                const double *rho, const double *sigma, const double *lapl, const double *tau,
                double *zk, double *vrho, double *vsigma, double *vlapl, double *vtau, hipStream_t stream)
{
  xc_mgga_offload(p, np, rho, sigma, lapl, tau, zk, vrho, vsigma, vlapl, vtau, 
          NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
          NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
          NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
          stream);
}

void
xc_mgga_vxc_offload(const xc_func_type *p, int np,
            const double *rho, const double *sigma, const double *lapl, const double *tau,
            double *vrho, double *vsigma, double *vlapl, double *vtau, hipStream_t stream)
{
  xc_mgga_offload(p, np, rho, sigma, lapl, tau, NULL, vrho, vsigma, vlapl, vtau, 
          NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
          NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
          NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
          stream);
}

void
xc_mgga_fxc_offload(const xc_func_type *p, int np,
            const double *rho, const double *sigma, const double *lapl, const double *tau,
            double *v2rho2, double *v2rhosigma, double *v2rholapl, double *v2rhotau,
            double *v2sigma2, double *v2sigmalapl, double *v2sigmatau,
            double *v2lapl2, double *v2lapltau,
            double *v2tau2, hipStream_t stream)
{
  xc_mgga_offload(p, np, rho, sigma, lapl, tau,
          NULL, NULL, NULL, NULL, NULL,
          v2rho2, v2rhosigma, v2rholapl, v2rhotau,
          v2sigma2, v2sigmalapl, v2sigmatau,
          v2lapl2, v2lapltau,
          v2tau2,
          NULL, NULL, NULL, NULL,
          NULL, NULL, NULL,
          NULL, NULL,
          NULL,
          NULL, NULL, NULL,
          NULL, NULL,
          NULL,
          NULL, NULL,
          NULL,
          NULL,
          stream);
}

void xc_mgga_kxc_offload(const xc_func_type *p, int np,
                 const double *rho, const double *sigma, const double *lapl, const double *tau,
                 double *v3rho3, double *v3rho2sigma, double *v3rho2lapl, double *v3rho2tau,
                 double *v3rhosigma2, double *v3rhosigmalapl, double *v3rhosigmatau,
                 double *v3rholapl2, double *v3rholapltau,
                 double *v3rhotau2,
                 double *v3sigma3, double *v3sigma2lapl, double *v3sigma2tau,
                 double *v3sigmalapl2, double *v3sigmalapltau,
                 double *v3sigmatau2,
                 double *v3lapl3, double *v3lapl2tau,
                 double *v3lapltau2,
                 double *v3tau3, hipStream_t stream)
{
  xc_mgga_offload(p, np, rho, sigma, lapl, tau,
          NULL, NULL, NULL, NULL, NULL,
          NULL, NULL, NULL, NULL,
          NULL, NULL, NULL,
          NULL, NULL,
          NULL,
          v3rho3, v3rho2sigma, v3rho2lapl, v3rho2tau,
          v3rhosigma2, v3rhosigmalapl, v3rhosigmatau,
          v3rholapl2, v3rholapltau,
          v3rhotau2,
          v3sigma3, v3sigma2lapl, v3sigma2tau,
          v3sigmalapl2, v3sigmalapltau,
          v3sigmatau2,
          v3lapl3, v3lapl2tau,
          v3lapltau2,
          v3tau3,
          stream);
}

#ifdef __cplusplus
}
#endif
