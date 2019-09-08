/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_C_HCTH_A        97 /* HCTH-A                                   */

#pragma omp declare target

#include "maple2c/gga_exc/gga_c_hcth_a.c"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_c_hcth_a = {
  XC_GGA_C_HCTH_A,
  XC_CORRELATION,
  "HCTH-A",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Hamprecht1998_6264, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-16,
  0, NULL, NULL,
  NULL, NULL,
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
