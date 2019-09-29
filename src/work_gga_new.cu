/*
 Copyright (C) 2006-2018 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/**
 * @file work_gga.cu
 * @brief This file is to be included in GGA functionals. As often these
 *        functionals are written as a function of rs and zeta, this
 *        routine performs the necessary conversions between this and a functional
 *        of rho.
 */
#ifdef __CUDACC__

#include <stdio.h>
extern xc_func_type *xc_func_data_device;

#define OUT_PARAMS_NO_EXC vrho, vsigma, v2rho2, v2rhosigma, v2sigma2, v3rho3, v3rho2sigma, v3rhosigma2, v3sigma3
#ifdef XC_NO_EXC
#define OUT_PARAMS OUT_PARAMS_NO_EXC
#else
#define OUT_PARAMS zk, OUT_PARAMS_NO_EXC
#endif

/**
 * @param[in,out] func_type: pointer to functional structure
 */
__global__ static void 
work_gga_device(const XC(func_type) *p,
                int dim_rho,    int dim_sigma,
                int dim_zk,     int dim_vrho,        int dim_vsigma,
                int dim_v2rho2, int dim_v2rhosigma,  int dim_v2sigma2,
                int dim_v3rho3, int dim_v3rho2sigma, int dim_v3rhosigma2, int dim_v3sigma3,
                int np,         const double *rho,   const double *sigma,
                double *zk,     double *vrho,        double *vsigma,
                double *v2rho2, double *v2rhosigma,  double *v2sigma2,
                double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if( tid < np ) {
        const double *rho_         = NULL;
        const double *sigma_       = NULL;
        double       *zk_          = NULL;
        double       *vrho_        = NULL;
        double       *vsigma_      = NULL;
        double       *v2rho2_      = NULL;
        double       *v2rhosigma_  = NULL;
        double       *v2sigma2_    = NULL;
        double       *v3rho3_      = NULL;
        double       *v3rho2sigma_ = NULL;
        double       *v3rhosigma2_ = NULL;
        double       *v3sigma3_    = NULL;
        rho_   = rho   + tid*dim_rho;
        sigma_ = sigma + tid*dim_sigma;
        if (zk          != NULL) zk_          = zk          + tid*dim_zk;
        if (vrho        != NULL) vrho_        = vrho        + tid*dim_vrho;
        if (vsigma      != NULL) vsigma_      = vsigma      + tid*dim_vsigma;
        if (v2rho2      != NULL) v2rho2_      = v2rho2      + tid*dim_v2rho2;
        if (v2rhosigma  != NULL) v2rhosigma_  = v2rhosigma  + tid*dim_v2rhosigma;
        if (v2sigma2    != NULL) v2sigma2_    = v2sigma2    + tid*dim_v2sigma2;
        if (v3rho3      != NULL) v3rho3_      = v3rho3      + tid*dim_v3rho3;
        if (v3rho2sigma != NULL) v3rho2sigma_ = v3rho2sigma + tid*dim_v3rho2sigma;
        if (v3rhosigma2 != NULL) v3rhosigma2_ = v3rhosigma2 + tid*dim_v3rhosigma2;
        if (v3sigma3    != NULL) v3sigma3_    = v3sigma3    + tid*dim_v3sigma3;
        work_gga(p,1,rho_,sigma_,zk_,vrho_,vsigma_,v2rho2_,v2rhosigma_,v2sigma2_,
                 v3rho3_,v3rho2sigma_,v3rhosigma2_,v3sigma3_);
    }
}

static void 
work_gga_offload(const XC(func_type) *p, int np, const double *rho, const double *sigma,
                 double *zk, double *vrho, double *vsigma,
                 double *v2rho2, double *v2rhosigma,  double *v2sigma2,
                 double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
    const xc_dimensions *dim = &(p->dim);
    work_gga_device<<<std::ceil(np/1024.),1024>>>
                   (xc_func_data_device+p->func_rank,dim->rho,dim->sigma,
                    dim->zk,dim->vrho,dim->vsigma,
                    dim->v2rho2,dim->v2rhosigma,dim->v2sigma2,
                    dim->v3rho3,dim->v3rho2sigma,dim->v3rhosigma2,dim->v3sigma3,
                    np,rho,sigma,zk,vrho,vsigma,
                    v2rho2,v2rhosigma,v2sigma2,
                    v3rho3,v3rho2sigma,v3rhosigma2,v3sigma3);
    //cudaError_t stat = cudaGetLastError();
    //cudaError_t stat = cudaDeviceSynchronize();
    //if (stat != cudaSuccess) {
    //    printf("Launch work_gga_device: %s\n",cudaGetErrorString( stat ));
    //}
}

#endif
