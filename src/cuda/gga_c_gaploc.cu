/*
 Copyright (C) 2008 Georg Madsen

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_C_GAPLOC  556 /* Gaploc */

#pragma omp declare target

#include "maple2c/gga_exc/gga_c_gaploc.c"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_c_gaploc = {
  XC_GGA_C_GAPLOC,
  XC_CORRELATION,
  "Gaploc",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Fabiano2014_2016, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-18,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
