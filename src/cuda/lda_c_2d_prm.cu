/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

/************************************************************************
Correlation functional by Pittalis, Rasanen & Marques for the 2D electron gas
************************************************************************/

/* TODO: convert this to an (rs, zeta) expression */

#define XC_LDA_C_2D_PRM  16   /* Pittalis, Rasanen & Marques correlation in 2D */

#pragma omp declare target

typedef struct{
  double N;
  double c;
} lda_c_2d_prm_params;

/* Initialization */
DEVICE static void
dvc_lda_c_2d_prm_init(xc_func_type *p)
{
  assert(p != NULL && p->params == NULL);

  p->params = malloc(sizeof(lda_c_2d_prm_params));
}

#include "maple2c/lda_exc/lda_c_2d_prm.c"
#include "work_lda_new.cu"

DEVICE static const func_params_type dvc_ext_params[] = {
  {"N", 2.0, "Number of electrons"},
};

DEVICE static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  static double prm_q = 3.9274; /* 2.258 */
  lda_c_2d_prm_params *params;
  double ff;

  assert(p != NULL && p->params != NULL);
  params = (lda_c_2d_prm_params *) (p->params);

  params->N = dvc_get_ext_param(p->info->ext_params, ext_params, 0);

  if(params->N <= 1.0){
    #ifndef __CUDACC__
    fprintf(stderr, "PRM functional cannot be used for N_electrons <= 1\n");
    exit(1);
    #endif
  }

  params->c = M_PI/(2.0*(params->N - 1.0)*prm_q*prm_q); /* Eq. (13) */
}

extern DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_2d_prm = {
  XC_LDA_C_2D_PRM,
  XC_CORRELATION,
  "PRM (for 2D systems)",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Pittalis2008_195322, NULL, NULL, NULL, NULL},
  XC_FLAGS_2D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_lda_c_2d_prm_init, NULL,
  dvc_work_lda, NULL, NULL
};
#pragma omp end declare target
