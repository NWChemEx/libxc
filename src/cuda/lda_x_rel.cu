/*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_LDA_X_REL   532   /* Relativistic exchange        */

#pragma omp declare target

#include "maple2c/lda_exc/lda_x_rel.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_x_rel = {
  XC_LDA_X_REL,
  XC_EXCHANGE,
  "Slater exchange with relativistic corrections",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Rajagopal1978_L943, &dvc_xc_ref_MacDonald1979_2977, &dvc_xc_ref_Engel1995_2750, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  NULL, NULL, 
  dvc_work_lda, NULL, NULL
};

#pragma omp end declare target
