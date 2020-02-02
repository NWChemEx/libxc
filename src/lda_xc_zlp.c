/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "xc_device.h"
#include "xc_extern.h"

#define XC_LDA_XC_ZLP     43   /* Zhao, Levy & Parr, Eq. (20)  */

#include "maple2c/lda_exc/lda_xc_zlp.c"
#include "work_lda_new.c"
#include "work_lda_new.cpp"

EXTERN const xc_func_info_type xc_func_info_lda_xc_zlp = {
  XC_LDA_XC_ZLP,
  XC_EXCHANGE_CORRELATION,
  "Zhao, Levy & Parr, Eq. (20)",
  XC_FAMILY_LDA,
  {&xc_ref_Zhao1993_918, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  NULL, NULL,
  work_lda, NULL, NULL,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  work_lda_offload, NULL, NULL
#endif
};
