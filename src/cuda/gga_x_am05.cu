/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_AM05         120 /* Armiento & Mattsson 05 exchange                */

#pragma omp declare target

#include "maple2c/gga_exc/gga_x_am05.cu"
#include "work_gga_new.cu"

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_am05 = {
  XC_GGA_X_AM05,
  XC_EXCHANGE,
  "Armiento & Mattsson 05",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Armiento2005_085108, &dvc_xc_ref_Mattsson2008_084714, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  NULL, NULL,
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
