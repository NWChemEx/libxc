/*
 Copyright (C) 2015 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_X_SA_TPSS          542 /* TPSS with correct surface asymptotics */

#pragma omp declare target

#include "maple2c/mgga_exc/mgga_x_sa_tpss.c"
#include "work_mgga_new.cu"

extern DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_sa_tpss = {
  XC_MGGA_X_SA_TPSS,
  XC_EXCHANGE,
  "TPSS with correct surface asymptotics",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Constantin2016_115127, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-23,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, NULL, dvc_work_mgga,
};

#pragma omp end declare target
