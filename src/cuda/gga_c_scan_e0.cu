/*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_C_SCAN_E0        553 /* GGA component of SCAN */

#pragma omp declare target

#include "maple2c/gga_exc/gga_c_scan_e0.c"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_c_scan_e0 = {
  XC_GGA_C_SCAN_E0,
  XC_CORRELATION,
  "GGA component of SCAN",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Sun2015_036402, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-26,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
