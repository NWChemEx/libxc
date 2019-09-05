/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_LDA_C_ML1    22   /* Modified LSD (version 1) of Proynov and Salahub */
#define XC_LDA_C_ML2    23   /* Modified LSD (version 2) of Proynov and Salahub */

#pragma omp declare target

typedef struct {
  double fc, q;
} lda_c_ml1_params;

DEVICE static void 
dvc_lda_c_ml1_init(xc_func_type *p)
{
  lda_c_ml1_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(lda_c_ml1_params));
  params = (lda_c_ml1_params *) (p->params);

  switch(p->info->number){
  case XC_LDA_C_ML1:
    params->fc = 0.2026;
    params->q  = 0.084;
    break;
  case XC_LDA_C_ML2:
    params->fc = 0.266;
    params->q  = 0.5;
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in lda_c_ml1\n");
    exit(1);
    #endif
    break;
  }
}

#include "maple2c/lda_exc/lda_c_ml1.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_ml1 = {
  XC_LDA_C_ML1,
  XC_CORRELATION,
  "Modified LSD (version 1) of Proynov and Salahub",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Proynov1994_7874, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  dvc_lda_c_ml1_init, NULL,
  dvc_work_lda, NULL, NULL
};

DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_ml2 = {
  XC_LDA_C_ML2,
  XC_CORRELATION,
  "Modified LSD (version 2) of Proynov and Salahub",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Proynov1994_7874, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  dvc_lda_c_ml1_init, NULL,
  dvc_work_lda, NULL, NULL
};
#pragma omp end declare target
