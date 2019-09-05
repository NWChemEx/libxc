/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

/************************************************************************
 Random Phase Approximation (RPA)
************************************************************************/

#define XC_LDA_C_GK72  578   /* Gordon and Kim 1972 */

#pragma omp declare target

#include "maple2c/lda_exc/lda_c_gk72.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_gk72 = {
  XC_LDA_C_GK72,
  XC_CORRELATION,
  "Gordon and Kim 1972",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Gordon1972_3122, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  NULL, NULL,
  dvc_work_lda, NULL, NULL
};
#pragma omp end declare target
