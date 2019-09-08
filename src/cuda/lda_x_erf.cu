/*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_LDA_X_ERF   546   /* Attenuated exchange LDA (erf) */

#pragma omp declare target

DEVICE static const func_params_type dvc_ext_params[] = {
  {"omega",  0.3, "screening parameter"},
};

DEVICE static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  assert(p != NULL);

  p->cam_omega = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
}


#include "maple2c/lda_exc/lda_x_erf.c"
#include "work_lda_new.cu"

extern DEVICE const xc_func_info_type dvc_xc_func_info_lda_x_erf = {
  XC_LDA_X_ERF,
  XC_EXCHANGE,
  "Attenuated exchange LDA (erf)",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Gill1996_1005, &dvc_xc_ref_Toulouse2004_1047, &dvc_xc_ref_Tawada2004_8425, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-13,
  1, dvc_ext_params, dvc_set_ext_params,
  NULL, NULL, 
  dvc_work_lda, NULL, NULL
};

#pragma omp end declare target
