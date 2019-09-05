/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_LDA_X_2D  19 /* Exchange in 2D */

#pragma omp declare target

#include "maple2c/lda_exc/lda_x_2d.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_x_2d = {
  XC_LDA_X_2D,
  XC_EXCHANGE,
  "Slater exchange",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Dirac1930_376, &dvc_xc_ref_Bloch1929_545, NULL, NULL, NULL},
  XC_FLAGS_2D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  NULL, NULL,
  dvc_work_lda, NULL,  NULL
};

#pragma omp end declare target
