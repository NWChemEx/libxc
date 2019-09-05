/*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_HJS_B88_V2   46 /* HJS screened exchange corrected B88 version */

#pragma omp declare target

typedef struct{
  double omega;
} gga_x_hjs_b88_v2_params;

DEVICE
static void
dvc_gga_x_hjs_init(xc_func_type *p)
{
  assert(p->params == NULL);
  p->params = malloc(sizeof(gga_x_hjs_b88_v2_params));
}

DEVICE
static func_params_type dvc_ext_params[] = {
  {"_omega", 0.11, "Screening parameter for HF"},
};

DEVICE
static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_x_hjs_b88_v2_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_x_hjs_b88_v2_params *) (p->params);

  params->omega = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
}

#include "maple2c/gga_exc/gga_x_hjs_b88_v2.c"
#include "work_gga_new.cu"

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_hjs_b88_v2 = {
  XC_GGA_X_HJS_B88_V2,
  XC_EXCHANGE,
  "HJS screened exchange B88 corrected version",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Weintraub2009_754, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-6, /* densities smaller than 1e-6 yield NaNs */
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_gga_x_hjs_init, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
