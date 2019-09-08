/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_XC_CC06          229 /* Cancio and Chou 2006 */

#pragma omp declare target

#include "maple2c/mgga_exc/mgga_xc_cc06.c"
#include "work_mgga_new.cu"


extern DEVICE const xc_func_info_type dvc_xc_func_info_mgga_xc_cc06 = {
  XC_MGGA_XC_CC06,
  XC_EXCHANGE_CORRELATION,
  "Cancio and Chou 2006",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Cancio2006_081202, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_I_HAVE_ALL,
  1e-23,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, NULL, dvc_work_mgga,
};

#pragma omp end declare target
