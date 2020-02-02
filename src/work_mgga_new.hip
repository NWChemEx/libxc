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
#ifdef __HIPCC__

#include "hip/hip_runtime.h"
#include <stdio.h>
extern xc_func_type *xc_func_data_device;

#ifdef XC_NO_EXC
#define OUT_PARAMS(P_) MGGA_OUT_PARAMS_NO_EXC(P_)
#else
#define OUT_PARAMS(P_) P_ zk, MGGA_OUT_PARAMS_NO_EXC(P_)
#endif

/**
 * @param[in,out] func_type: pointer to functional structure
 */
__global__ static void 
work_gga_device(const XC(func_type) *p,
                int dim_rho,          int dim_sigma,          int dim_lapl,        int dim_tau,
                int dim_zk,           int dim_vrho,           int dim_vsigma,      int dim_vlapl,   int dim_vtau,
                int dim_v2rho2,       int dim_v2rhosigma,     int dim_v2rholapl,   int dim_v2rhotau,
                int dim_v2sigma2,     int dim_v2sigmalapl,    int dim_v2sigmatau,
                int dim_v2lapl2,      int dim_v2lapltau,
                int dim_v2tau2,
                int dim_v3rho3,       int dim_v3rho2sigma,    int dim_v3rho2lapl,  int dim_v3rho2tau,
                int dim_v3rhosigma2,  int dim_v3rhosigmalapl, int dim_v3rhosigmatau, 
                int dim_v3rholapl2,   int dim_v3rholapltau,   int dim_v3rhotau2,
                int dim_v3sigma3,     int dim_v3sigma2lapl,   int dim_v3sigma2tau, 
                int dim_v3sigmalapl2, int dim_v3sigmalapltau, int dim_v3sigmatau2,
                int dim_v3lapl3,      int dim_v3lapl2tau,     int dim_v3lapltau2, int dim_v3tau3,
                int np,
                const double *rho,    const double *sigma,    const double *lapl,   const double *tau,
                double *zk,
                double *vrho,         double *vsigma,         double *vlapl,        double *vtau,
                double *v2rho2,       double *v2rhosigma,     double *v2rholapl,    double *v2rhotau,
                double *v2sigma2,     double *v2sigmalapl,    double *v2sigmatau,
                double *v2lapl2,      double *v2lapltau,      double *v2tau2,
                double *v3rho3,       double *v3rho2sigma,    double *v3rho2lapl,   double *v3rho2tau,
                double *v3rhosigma2,  double *v3rhosigmalapl, double *v3rhosigmatau,
                double *v3rholapl2,   double *v3rholapltau,   double *v3rhotau2,
                double *v3sigma3,     double *v3sigma2lapl,   double *v3sigma2tau,
                double *v3sigmalapl2, double *v3sigmalapltau, double *v3sigmatau2,
                double *v3lapl3,      double *v3lapl2tau,     double *v3lapltau2,   double *v3tau3)
{
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if( tid < np ) {
        const double *rho_            = NULL;
        const double *sigma_          = NULL;
        const double *lapl_           = NULL;
        const double *tau_            = NULL;
        double       *zk_             = NULL;
        double       *vrho_           = NULL;
        double       *vsigma_         = NULL;
        double       *vlapl_          = NULL;
        double       *vtau_           = NULL;
        double       *v2rho2_         = NULL;
        double       *v2rhosigma_     = NULL;
        double       *v2rholapl_      = NULL;
        double       *v2rhotau_       = NULL;
        double       *v2sigma2_       = NULL;
        double       *v2sigmalapl_    = NULL;
        double       *v2sigmatau_     = NULL;
        double       *v2lapl2_        = NULL;
        double       *v2lapltau_      = NULL;
        double       *v2tau2_         = NULL;
        double       *v3rho3_         = NULL;
        double       *v3rho2sigma_    = NULL;
        double       *v3rho2lapl_     = NULL;
        double       *v3rho2tau_      = NULL;
        double       *v3rhosigma2_    = NULL;
        double       *v3rhosigmalapl_ = NULL;
        double       *v3rhosigmatau_  = NULL;
        double       *v3rholapl2_     = NULL;
        double       *v3rholapltau_   = NULL;
        double       *v3rhotau2_      = NULL;
        double       *v3sigma3_       = NULL;
        double       *v3sigma2lapl_   = NULL;
        double       *v3sigma2tau_    = NULL;
        double       *v3sigmalapl2_   = NULL;
        double       *v3sigmalapltau_ = NULL;
        double       *v3sigmatau2_    = NULL;
        double       *v3lapl3_        = NULL;
        double       *v3lapl2tau_     = NULL;
        double       *v3lapltau2_     = NULL;
        double       *v3tau3_         = NULL;
        rho_   = rho   + tid*dim_rho;
        sigma_ = sigma + tid*dim_sigma;
        lapl_  = lapl  + tid*dim_lapl;
        tau_   = tau   + tid*dim_tau;
        if (zk             != NULL) zk_             = zk             + tid*dim_zk;
        if (vrho           != NULL) vrho_           = vrho           + tid*dim_vrho;
        if (vsigma         != NULL) vsigma_         = vsigma         + tid*dim_vsigma;
        if (vlapl          != NULL) vlapl_          = vlapl          + tid*dim_vlapl;
        if (vtau           != NULL) vtau_           = vtau           + tid*dim_vtau;
        if (v2rho2         != NULL) v2rho2_         = v2rho2         + tid*dim_v2rho2;
        if (v2rhosigma     != NULL) v2rhosigma_     = v2rhosigma     + tid*dim_v2rhosigma;
        if (v2rholapl      != NULL) v2rholapl_      = v2rholapl      + tid*dim_v2rholapl;
        if (v2rhotau       != NULL) v2rhotau_       = v2rhotau       + tid*dim_v2rhotau;
        if (v2sigma2       != NULL) v2sigma2_       = v2sigma2       + tid*dim_v2sigma2;
        if (v2sigmalapl    != NULL) v2sigmalapl_    = v2sigmalapl    + tid*dim_v2sigmalapl;
        if (v2sigmatau     != NULL) v2sigmatau_     = v2sigmatau     + tid*dim_v2sigmatau;
        if (v2lapl2        != NULL) v2lapl2_        = v2lapl2        + tid*dim_v2lapl2;
        if (v2lapltau      != NULL) v2lapltau_      = v2lapltau      + tid*dim_v2lapltau;
        if (v2tau2         != NULL) v2tau2_         = v2tau2         + tid*dim_v2tau2;
        if (v3rho3         != NULL) v3rho3_         = v3rho3         + tid*dim_v3rho3;
        if (v3rho2sigma    != NULL) v3rho2sigma_    = v3rho2sigma    + tid*dim_v3rho2sigma;
        if (v3rho2lapl     != NULL) v3rho2lapl_     = v3rho2lapl     + tid*dim_v3rho2lapl;
        if (v3rho2tau      != NULL) v3rho2tau_      = v3rho2tau      + tid*dim_v3rho2tau;
        if (v3rhosigma2    != NULL) v3rhosigma2_    = v3rhosigma2    + tid*dim_v3rhosigma2;
        if (v3rhosigmalapl != NULL) v3rhosigmalapl_ = v3rhosigmalapl + tid*dim_v3rhosigmalapl;
        if (v3rhosigmatau  != NULL) v3rhosigmatau_  = v3rhosigmatau  + tid*dim_v3rhosigmatau;
        if (v3rholapl2     != NULL) v3rholapl2_     = v3rholapl2     + tid*dim_v3rholapl2;
        if (v3rholapltau   != NULL) v3rholapltau_   = v3rholapltau   + tid*dim_v3rholapltau;
        if (v3rhotau2      != NULL) v3rhotau2_      = v3rhotau2      + tid*dim_v3rhotau2;
        if (v3sigma3       != NULL) v3sigma3_       = v3sigma3       + tid*dim_v3sigma3;
        if (v3sigma2lapl   != NULL) v3sigma2lapl_   = v3sigma2lapl   + tid*dim_v3sigma2lapl;
        if (v3sigma2tau    != NULL) v3sigma2tau_    = v3sigma2tau    + tid*dim_v3sigma2tau;
        if (v3sigmalapl2   != NULL) v3sigmalapl2_   = v3sigmalapl2   + tid*dim_v3sigmalapl2;
        if (v3sigmalapltau != NULL) v3sigmalapltau_ = v3sigmalapltau + tid*dim_v3sigmalapltau;
        if (v3sigmatau2    != NULL) v3sigmatau2_    = v3sigmatau2    + tid*dim_v3sigmatau2;
        if (v3lapl3        != NULL) v3lapl3_        = v3lapl3        + tid*dim_v3lapl3;
        if (v3lapl2tau     != NULL) v3lapl2tau_     = v3lapl2tau     + tid*dim_v3lapl2tau;
        if (v3lapltau2     != NULL) v3lapltau2_     = v3lapltau2     + tid*dim_v3lapltau2;
        if (v3tau3         != NULL) v3tau3_         = v3tau3         + tid*dim_v3tau3;
        work_mgga(p,1,rho_,sigma_,lapl_,tau_,zk_,vrho_,vsigma_,vlapl_,vtau_,
                  v2rho2_,v2rhosigma_,v2rholapl_,v2rhotau_,
                  v2sigma2_,v2sigmalapl_,v2sigmatau_,
                  v2lapl2_,v2lapltau_,
                  v2tau2_,
                  v3rho3_,v3rho2sigma_,v3rho2lapl_,v3rho2tau_,
                  v3rhosigma2_,v3rhosigmalapl_,v3rhosigmatau_,
                  v3rholapl2_,v3rholapltau_,v3rhotau2_,
                  v3sigma3_,v3sigma2lapl_,v3sigma2tau_,
                  v3sigmalapl2_,v3sigmalapltau_,v3sigmatau2_,
                  v3lapl3_,v3lapl2tau_,v3lapltau2_,v3tau3_);
    }
}

static void 
work_mgga_offload(const XC(func_type) *p, int np, 
                  const double *rho,    const double *sigma,    const double *lapl,   const double *tau,
                  double *zk,
                  double *vrho,         double *vsigma,         double *vlapl,        double *vtau,
                  double *v2rho2,       double *v2rhosigma,     double *v2rholapl,    double *v2rhotau,
                  double *v2sigma2,     double *v2sigmalapl,    double *v2sigmatau,
                  double *v2lapl2,      double *v2lapltau,      double *v2tau2,
                  double *v3rho3,       double *v3rho2sigma,    double *v3rho2lapl,   double *v3rho2tau,
                  double *v3rhosigma2,  double *v3rhosigmalapl, double *v3rhosigmatau,
                  double *v3rholapl2,   double *v3rholapltau,   double *v3rhotau2,
                  double *v3sigma3,     double *v3sigma2lapl,   double *v3sigma2tau,
                  double *v3sigmalapl2, double *v3sigmalapltau, double *v3sigmatau2,
                  double *v3lapl3,      double *v3lapl2tau,     double *v3lapltau2,   double *v3tau3,
                  hipStream_t stream)
{
    const xc_dimensions *dim = &(p->dim);
    hipLaunchKernelGGL((work_gga_device), dim3(std::ceil(np/1024.)), dim3(1024), 0, stream, xc_func_data_device+p->func_rank,
                    dim->rho,dim->sigma,dim->lapl,dim->tau,
                    dim->zk,dim->vrho,dim->vsigma,dim->vlapl,dim->vtau,
                    dim->v2rho2,dim->v2rhosigma,dim->v2rholapl,dim->v2rhotau,
                    dim->v2sigma2,dim->v2sigmalapl,dim->v2sigmatau,
                    dim->v2lapl2,dim->v2lapltau,dim->v2tau2,
                    dim->v3rho3,dim->v3rho2sigma,dim->v3rho2lapl,dim->v3rho2tau,
                    dim->v3rhosigma2,dim->v3rhosigmalapl,dim->v3rhosigmatau,
                    dim->v3rholapl2,dim->v3rholapltau,dim->v3rhotau2,
                    dim->v3sigma3,dim->v3sigma2lapl,dim->v3sigma2tau,
                    dim->v3sigmalapl2,dim->v3sigmalapltau,dim->v3sigmatau2,
                    dim->v3lapl3,dim->v3lapl2tau,dim->v3lapltau2,dim->v3tau3,
                    np,rho,sigma,lapl,tau,zk,vrho,vsigma,vlapl,vtau,
                    v2rho2,v2rhosigma,v2rholapl,v2rhotau,
                    v2sigma2,v2sigmalapl,v2sigmatau,
                    v2lapl2,v2lapltau,
                    v2tau2,
                    v3rho3,v3rho2sigma,v3rho2lapl,v3rho2tau,
                    v3rhosigma2,v3rhosigmalapl,v3rhosigmatau,
                    v3rholapl2,v3rholapltau,v3rhotau2,
                    v3sigma3,v3sigma2lapl,v3sigma2tau,
                    v3sigmalapl2,v3sigmalapltau,v3sigmatau2,
                    v3lapl3,v3lapl2tau,v3lapltau2,v3tau3);
}

#endif
