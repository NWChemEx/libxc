/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_DK87_R1      111 /* dePristo & Kress 87 (version R1)               */
#define XC_GGA_X_DK87_R2      112 /* dePristo & Kress 87 (version R2)               */

#pragma omp declare target

typedef struct {
  double a1, b1, alpha;
} gga_x_dk87_params;

DEVICE
static const gga_x_dk87_params dvc_par_dk87_r1 = {
  0.861504, 0.044286, 1.0
};

DEVICE
static const gga_x_dk87_params dvc_par_dk87_r2 = {
  0.861213, 0.042076, 0.98
};

DEVICE
static void 
dvc_gga_x_dk87_init(xc_func_type *p)
{
  gga_x_dk87_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_x_dk87_params));
  params = (gga_x_dk87_params *) (p->params);

  switch(p->info->number){
  case XC_GGA_X_DK87_R1: 
    memcpy(params, &dvc_par_dk87_r1, sizeof(gga_x_dk87_params));
    break;
  case XC_GGA_X_DK87_R2:
    memcpy(params, &dvc_par_dk87_r2, sizeof(gga_x_dk87_params));
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in gga_x_dk87\n");
    exit(1);
    #endif
    break;
  }
}

#include "maple2c/gga_exc/gga_x_dk87.c"
#include "work_gga_new.cu"

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_dk87_r1 = {
  XC_GGA_X_DK87_R1,
  XC_EXCHANGE,
  "dePristo & Kress 87 version R1",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_DePristo1987_1425, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  dvc_gga_x_dk87_init, NULL, 
  NULL, dvc_work_gga, NULL
};

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_dk87_r2 = {
  XC_GGA_X_DK87_R2,
  XC_EXCHANGE,
  "dePristo & Kress 87 version R2",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_DePristo1987_1425, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  dvc_gga_x_dk87_init, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
