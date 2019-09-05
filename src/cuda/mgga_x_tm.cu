/*
 Copyright (C) 2008 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_X_TM          540 /* Tao and Mo 2016 exchange */

#pragma omp declare target

#include "maple2c/mgga_exc/mgga_x_tm.c"
#include "work_mgga_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_tm = {
  XC_MGGA_X_TM,
  XC_EXCHANGE,
  "Tao and Mo 2016 exchange",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Tao2016_073001, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1.0e-23,
  0, NULL, NULL,
  NULL, NULL,
  NULL, NULL, dvc_work_mgga,
};

#pragma omp end declare target
