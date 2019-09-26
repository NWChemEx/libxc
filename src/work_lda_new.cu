/*
 Copyright (C) 2006-2018 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/**
 * @file work_lda.cu
 * @brief This file is to be included in LDA functionals. As often these
 *        functionals are written as a function of rs and zeta, this
 *        routine performs the necessary conversions between this and a functional
 *        of rho.
 */
#ifdef __CUDACC__

#include "xc_func_data.cuh"

#ifdef XC_NO_EXC
#define OUT_PARAMS vrho, v2rho2, v3rho3
#else
#define OUT_PARAMS zk, vrho, v2rho2, v3rho3
#endif

/**
 * @param[in,out] func_type: pointer to functional structure
 */
__global__ static void 
work_lda_offload(const XC(func_type) *p, int np, const double *rho, 
                 double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
    const xc_dimensions *dim = &(func->dim);
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    double *rho_    = NULL;
    double *zk_     = NULL;
    double *vrho_   = NULL;
    double *v2rho2_ = NULL;
    double *v3rho3_ = NULL;
    rho_ = rho+tid*dim->rho;
    if (zk     != NULL) zk_     = zk+tid*dim->zk;
    if (vrho   != NULL) vrho_   = vrho+tid*dim->vrho;
    if (v2rho2 != NULL) v2rho2_ = v2rho2+tid*dim->v2rho2;
    if (v3rho3 != NULL) v3rho3_ = v3rho3+tid*dim->v3rho3;
    work_lda(xc_func_data[p->func_rank],1,rho_,zk_,vrho_,v2rho2_,v3rho3_);
}

#endif
