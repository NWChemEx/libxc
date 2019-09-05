/*
 Copyright (C) 2017 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_LDA_C_LP96      289   /* Liu-Parr correlation */
#define XC_LDA_K_LP96      580   /* Liu-Parr kinetic */

#pragma omp declare target

typedef struct {
  double C1, C2, C3;
} lda_c_lp96_params;

DEVICE static lda_c_lp96_params dvc_c_lp96 = {-0.0603,   0.0175, -0.00053};
DEVICE static lda_c_lp96_params dvc_k_lp96 = { 0.03777, -0.01002, 0.00039};

DEVICE static void 
dvc_lda_c_lp96_init(xc_func_type *p)
{
  lda_c_lp96_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(lda_c_lp96_params));
  params = (lda_c_lp96_params *) (p->params);

  switch(p->info->number){
  case XC_LDA_C_LP96:
    memcpy(params, &dvc_c_lp96, sizeof(lda_c_lp96_params));
    break;
  case XC_LDA_K_LP96:
    memcpy(params, &dvc_k_lp96, sizeof(lda_c_lp96_params));
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in lda_c_lp96\n");
    exit(1);
    #endif
    break;
  }
}

#include "maple2c/lda_exc/lda_c_lp96.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_lp96 = {
  XC_LDA_C_LP96,
  XC_CORRELATION,
  "Liu-Parr correlation",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Liu1996_2211, &dvc_xc_ref_Liu2000_29, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-16,
  0, NULL, NULL,
  dvc_lda_c_lp96_init, NULL,
  dvc_work_lda, NULL, NULL
};

DEVICE const xc_func_info_type dvc_xc_func_info_lda_k_lp96 = {
  XC_LDA_K_LP96,
  XC_KINETIC,
  "Liu-Parr kinetic",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Liu1996_2211, &dvc_xc_ref_Liu2000_29, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-16,
  0, NULL, NULL,
  dvc_lda_c_lp96_init, NULL,
  dvc_work_lda, NULL, NULL
};
#pragma omp end declare target
