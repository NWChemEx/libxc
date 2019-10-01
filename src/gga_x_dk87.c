/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "xc_device.h"
#include "xc_extern.h"

#define XC_GGA_X_DK87_R1      111 /* dePristo & Kress 87 (version R1)               */
#define XC_GGA_X_DK87_R2      112 /* dePristo & Kress 87 (version R2)               */

typedef struct {
  double a1, b1, alpha;
} gga_x_dk87_params;

static const gga_x_dk87_params par_dk87_r1 = {
  0.861504, 0.044286, 1.0
};

static const gga_x_dk87_params par_dk87_r2 = {
  0.861213, 0.042076, 0.98
};

static void 
gga_x_dk87_init(xc_func_type *p)
{
  gga_x_dk87_params *params;

  assert(sizeof(gga_x_dk87_params) <= XC_MAX_FUNC_PARAMS*sizeof(double));
  assert(p!=NULL);
  //p->params = malloc(sizeof(gga_x_dk87_params));
  params = (gga_x_dk87_params *) (p->params);

  switch(p->info->number){
  case XC_GGA_X_DK87_R1: 
    memcpy(params, &par_dk87_r1, sizeof(gga_x_dk87_params));
    break;
  case XC_GGA_X_DK87_R2:
    memcpy(params, &par_dk87_r2, sizeof(gga_x_dk87_params));
    break;
  default:
    fprintf(stderr, "Internal error in gga_x_dk87\n");
    exit(1);
  }
}

#include "maple2c/gga_exc/gga_x_dk87.c"
#include "work_gga_new.c"
#include "work_gga_new.cu"

EXTERN const xc_func_info_type xc_func_info_gga_x_dk87_r1 = {
  XC_GGA_X_DK87_R1,
  XC_EXCHANGE,
  "dePristo & Kress 87 version R1",
  XC_FAMILY_GGA,
  {&xc_ref_DePristo1987_1425, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  gga_x_dk87_init, NULL, 
  NULL, work_gga, NULL,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  NULL, work_gga_offload, NULL
#endif
};

EXTERN const xc_func_info_type xc_func_info_gga_x_dk87_r2 = {
  XC_GGA_X_DK87_R2,
  XC_EXCHANGE,
  "dePristo & Kress 87 version R2",
  XC_FAMILY_GGA,
  {&xc_ref_DePristo1987_1425, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  gga_x_dk87_init, NULL, 
  NULL, work_gga, NULL,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  NULL, work_gga_offload, NULL
#endif
};
