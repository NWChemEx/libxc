/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_GGA_C_WI0 153 /* Wilson & Ivanov initial version */
#define XC_GGA_C_WI  148 /* Wilson & Ivanov */

#pragma omp declare target

typedef struct {
  double a, b, c, d, k;
} gga_c_wi_params;

DEVICE
static const gga_c_wi_params dvc_wi0_params = {
  -0.44, 0.0032407, 7.8, 0.0073, 0.000311
};

DEVICE
static const gga_c_wi_params dvc_wi_params = {
  -0.00652, 0.0007, 0.21, 0.002, 0.001
};

DEVICE
static void 
dvc_gga_c_wi_init(xc_func_type *p)
{
  gga_c_wi_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_c_wi_params));
  params = (gga_c_wi_params *) (p->params);

  switch(p->info->number){
  case XC_GGA_C_WI0: 
    memcpy(params, &dvc_wi0_params, sizeof(gga_c_wi_params));
    break;
  case XC_GGA_C_WI:
    memcpy(params, &dvc_wi_params, sizeof(gga_c_wi_params));
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in gga_c_wi\n");
    exit(1);
    #endif
    break;
  }
}

#include "maple2c/gga_exc/gga_c_wi.c"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_c_wi0 = {
  XC_GGA_C_WI0,
  XC_CORRELATION,
  "Wilson & Ivanov initial version",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Wilson1998_523, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-14,
  0, NULL, NULL,
  dvc_gga_c_wi_init, NULL,
  NULL, dvc_work_gga, NULL
};

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_c_wi = {
  XC_GGA_C_WI,
  XC_CORRELATION,
  "Wilson & Ivanov",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Wilson1998_523, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-10,
  0, NULL, NULL,
  dvc_gga_c_wi_init, NULL,
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
