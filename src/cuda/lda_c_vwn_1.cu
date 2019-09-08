/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_LDA_C_VWN_1   28   /* Vosko, Wilk, & Nusair (1)   */

#pragma omp declare target

#include "maple2c/lda_exc/lda_c_vwn_1.c"
#include "work_lda_new.cu"

extern DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_vwn_1 = {
  XC_LDA_C_VWN_1,
  XC_CORRELATION,
  "Vosko, Wilk & Nusair (VWN1)",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Vosko1980_1200, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  NULL, NULL,
  dvc_work_lda, NULL, NULL
};
#pragma omp end declare target
