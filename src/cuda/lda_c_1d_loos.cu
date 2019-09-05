/*
 Copyright (C) 2006-2009 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_LDA_C_1D_LOOS          26 /* P-F Loos correlation LDA     */

#pragma omp declare target

#include "maple2c/lda_exc/lda_c_1d_loos.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_1d_loos = {
  XC_LDA_C_1D_LOOS,
  XC_CORRELATION,
  "P-F Loos correlation LDA",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Loos2013_064108, NULL, NULL, NULL, NULL},
  XC_FLAGS_1D |  XC_FLAGS_I_HAVE_ALL,
  5e-28,
  0, NULL, NULL,
  NULL, NULL,
  dvc_work_lda, NULL, NULL
};
#pragma omp end declare target
