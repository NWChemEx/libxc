/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_LDA_C_PK09   554   /* Proynov and Kong 2009 */

#pragma omp declare target

#include "maple2c/lda_exc/lda_c_pk09.c"
#include "work_lda_new.cu"

extern DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_pk09 = {
  XC_LDA_C_PK09,
  XC_CORRELATION,
  "Proynov and Kong 2009",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Proynov2009_014103, &dvc_xc_ref_Proynov2017_059904, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  5e-24,
  0, NULL, NULL,
  NULL, NULL,
  dvc_work_lda, NULL, NULL
};
#pragma omp end declare target
