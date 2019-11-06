/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Some useful formulas:

   sigma_st          = grad rho_s . grad rho_t
   zk                = energy density per unit particle

   vrho_s            = d zk / d rho_s
   vsigma_st         = d n*zk / d sigma_st
   
   v2rho2_st         = d^2 n*zk / d rho_s d rho_t
   v2rhosigma_svx    = d^2 n*zk / d rho_s d sigma_tv
   v2sigma2_stvx     = d^2 n*zk / d sigma_st d sigma_vx

   v3rho3_stv        = d^3 n*zk / d rho_s d rho_t d rho_v
   v3rho2sigma_stvx  = d^3 n*zk / d rho_s d rho_t d sigma_vx
   v3rhosigma2_svxyz = d^3 n*zk / d rho_s d sigma_vx d sigma_yz
   v3sigma3_stvxyz   = d^3 n*zk / d sigma_st d sigma_vx d sigma_yz

if nspin == 2
   rho(2)          = (u, d)
   sigma(3)        = (uu, ud, dd)

   vrho(2)         = (u, d)
   vsigma(3)       = (uu, ud, dd)

   v2rho2(3)       = (u_u, u_d, d_d)
   v2rhosigma(6)   = (u_uu, u_ud, u_dd, d_uu, d_ud, d_dd)
   v2sigma2(6)     = (uu_uu, uu_ud, uu_dd, ud_ud, ud_dd, dd_dd)

   v3rho3(4)       = (u_u_u, u_u_d, u_d_d, d_d_d)
   v3rho2sigma(9)  = (u_u_uu, u_u_ud, u_u_dd, u_d_uu, u_d_ud, u_d_dd, d_d_uu, d_d_ud, d_d_dd)
   v3rhosigma2(12) = (u_uu_uu, u_uu_ud, u_uu_dd, u_ud_ud, u_ud_dd, u_dd_dd, d_uu_uu, d_uu_ud, d_uu_dd, d_ud_ud, d_ud_dd, d_dd_dd)
   v3sigma(10)     = (uu_uu_uu, uu_uu_ud, uu_uu_dd, uu_ud_ud, uu_ud_dd, uu_dd_dd, ud_ud_ud, ud_ud_dd, ud_dd_dd, dd_dd_dd)
   
*/
void xc_gga_offload(const xc_func_type *func, int np, const double *rho, const double *sigma,
	     double *zk, double *vrho, double *vsigma,
	     double *v2rho2, double *v2rhosigma, double *v2sigma2,
	     double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3,
             cudaStream_t stream)
{
  const xc_dimensions *dim = &(func->dim);
  /* CUDA status */
  cudaError_t stat;

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
    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(zk, 0, dim->zk*np*nd*sizeof(double), stream));

  if(vrho != NULL){
    assert(vsigma != NULL);
    
    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(vrho,   0, dim->vrho  *np*nd*sizeof(double), stream));
    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(vsigma, 0, dim->vsigma*np*nd*sizeof(double), stream));
  }

  if(v2rho2 != NULL){
    assert(v2rhosigma!=NULL && v2sigma2!=NULL);

    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2rho2,     0, dim->v2rho2    *np*nd*sizeof(double), stream));
    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2rhosigma, 0, dim->v2rhosigma*np*nd*sizeof(double), stream));
    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v2sigma2,   0, dim->v2sigma2  *np*nd*sizeof(double), stream));
  }

  if(v3rho3 != NULL){
    assert(v3rho2sigma!=NULL && v3rhosigma2!=NULL && v3sigma3!=NULL);

    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v3rho3,      0, dim->v3rho3     *np*nd*sizeof(double), stream));
    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v3rho2sigma, 0, dim->v3rho2sigma*np*nd*sizeof(double), stream));
    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v3rhosigma2, 0, dim->v3rhosigma2*np*nd*sizeof(double), stream));
    checkCuda(__FILE__,__LINE__,cudaMemsetAsync(v3sigma3,    0, dim->v3sigma3   *np*nd*sizeof(double), stream));
  }
  //stat = cudaDeviceSynchronize();

  /* call functional */
  if(func->info->gga != NULL) {
    if(func->info->gga_offload == NULL) {
      fprintf(stderr,"GPU port of %s not supported\n",func->info->name);
    }
    assert(func->info->gga_offload != NULL);
    func->info->gga_offload(func, np, rho, sigma, zk, vrho, vsigma, 
		    v2rho2, v2rhosigma, v2sigma2,
		    v3rho3, v3rho2sigma, v3rhosigma2, v3sigma3,
                    stream);
  }

  if(func->n_func_aux > 0) {
    //fprintf(stderr,"Multi-term functional: %s\n",func->info->name);
    xc_mix_func_offload(func, np, rho, sigma, NULL, NULL, zk, vrho, vsigma, NULL, NULL,
                v2rho2, v2rhosigma, NULL, NULL, v2sigma2, NULL, NULL, NULL, NULL, NULL,
                v3rho3, v3rho2sigma, NULL, NULL,
                v3rhosigma2, NULL, NULL,
                NULL, NULL,
                NULL,
                v3sigma3, NULL, NULL,
                NULL, NULL,
                NULL,
                NULL, NULL,
                NULL,
                NULL,
                stream);
  }
}

/* specializations */
/* returns only energy */
void
xc_gga_exc_offload(const xc_func_type *p, int np, const double *rho, const double *sigma, 
	    double *zk, cudaStream_t stream)
{
  xc_gga_offload(p, np, rho, sigma, zk, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, stream);
}

/* returns only potential */
void
xc_gga_vxc_offload(const xc_func_type *p, int np, const double *rho, const double *sigma,
	    double *vrho, double *vsigma, cudaStream_t stream)
{
  xc_gga_offload(p, np, rho, sigma, NULL, vrho, vsigma, NULL, NULL, NULL, NULL, NULL, NULL, NULL, stream);
}

/* returns both energy and potential (the most common call usually) */
void
xc_gga_exc_vxc_offload(const xc_func_type *p, int np, const double *rho, const double *sigma,
		double *zk, double *vrho, double *vsigma, cudaStream_t stream)
{
  xc_gga_offload(p, np, rho, sigma, zk, vrho, vsigma, NULL, NULL, NULL, NULL, NULL, NULL, NULL, stream);
}

/* returns second derivatives */
void
xc_gga_fxc_offload(const xc_func_type *p, int np, const double *rho, const double *sigma,
	    double *v2rho2, double *v2rhosigma, double *v2sigma2, cudaStream_t stream)
{
  xc_gga_offload(p, np, rho, sigma, NULL, NULL, NULL, v2rho2, v2rhosigma, v2sigma2, NULL, NULL, NULL, NULL, stream);
}

/* returns third derivatives */
void
xc_gga_kxc_offload(const xc_func_type *p, int np, const double *rho, const double *sigma,
	    double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3, cudaStream_t stream)
{
  xc_gga_offload(p, np, rho, sigma, NULL, NULL, NULL, NULL, NULL, NULL, v3rho3, v3rho2sigma, v3rhosigma2, v3sigma3, stream);
}

#ifdef __cplusplus
}
#endif
