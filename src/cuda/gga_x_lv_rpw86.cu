/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_LV_RPW86 58 /* Berland and Hyldgaard */

#pragma omp declare target

#include "maple2c/gga_exc/gga_x_lv_rpw86.c"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_lv_rpw86 = {
  XC_GGA_X_LV_RPW86,
  XC_EXCHANGE,
  "Berland and Hyldgaard",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Berland2014_035412, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
