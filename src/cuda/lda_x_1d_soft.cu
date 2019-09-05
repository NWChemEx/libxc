/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_LDA_X_1D_SOFT  21 /* Exchange in 1D for a soft-Coulomb interaction */

#pragma omp declare target

typedef struct{
  double beta;         /* screening parameter beta */
} lda_x_1d_exponential_params;

DEVICE static void 
dvc_lda_x_1d_exponential_init(xc_func_type *p)
{
  assert(p->params == NULL);
  p->params = malloc(sizeof(lda_x_1d_exponential_params));
}

DEVICE static inline double dvc_FT_inter(double x)
{
  return 2.0*dvc_xc_bessel_K0(x);
}

DEVICE static void func1(double *x, int n, void *dummy)
{
  int ii;
  
  for(ii=0; ii<n; ii++)
    x[ii] = dvc_FT_inter(x[ii]);
}

DEVICE static void func2(double *x, int n, void *dummy)
{
  int ii;
  
  for(ii=0; ii<n; ii++)
    x[ii] = x[ii]*dvc_FT_inter(x[ii]);
}

#include "maple2c/lda_exc/lda_x_1d_soft.cu"
#include "work_lda_new.cu"

DEVICE static const func_params_type dvc_ext_params[] = {
  {"beta", 1.0, "Screening parameter"}
};

DEVICE static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  lda_x_1d_exponential_params *params;

  assert(p != NULL && p->params != NULL);
  params = (lda_x_1d_exponential_params *)(p->params);

  params->beta = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
}

DEVICE const xc_func_info_type dvc_xc_func_info_lda_x_1d_soft = {
  XC_LDA_X_1D_SOFT,
  XC_EXCHANGE,
  "Exchange in 1D for an soft-Coulomb interaction",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Helbig2011_032503, NULL, NULL, NULL, NULL},
  XC_FLAGS_1D | XC_FLAGS_I_HAVE_ALL,
  1e-26,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_lda_x_1d_exponential_init, NULL,
  dvc_work_lda, NULL, NULL
};

#pragma omp end declare target
