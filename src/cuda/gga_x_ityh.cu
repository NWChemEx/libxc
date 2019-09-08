/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_ITYH 529 /* short-range recipe B88 functionals - erf */

#pragma omp declare target

DEVICE
static const func_params_type dvc_ext_params[] = {
  {"_omega", 0.2, "Screening parameter"},
};

DEVICE
static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  p->cam_omega = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
}

#include "maple2c/gga_exc/gga_x_ityh.c"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_ityh = {
  XC_GGA_X_ITYH,
  XC_EXCHANGE,
  "Short-range recipe for B88 functional - erf",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Iikura2001_3540, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-8,
  1, dvc_ext_params, dvc_set_ext_params,
  NULL, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
