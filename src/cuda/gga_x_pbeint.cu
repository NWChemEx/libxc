/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_PBEINT        60 /* PBE for hybrid interfaces                      */

#pragma omp declare target

typedef struct{
  double kappa, alpha, muPBE, muGE;
} gga_x_pbeint_params;


DEVICE
static void 
dvc_gga_x_pbe_init(xc_func_type *p)
{
  gga_x_pbeint_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_x_pbeint_params));
  params = (gga_x_pbeint_params *) (p->params);
 
  switch(p->info->number){
  case XC_GGA_X_PBEINT:
    /* default set by set_ext_params */
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in gga_x_pbeint\n");
    exit(1);
    #endif
    break;
  }
}

DEVICE
static const func_params_type dvc_ext_params[] = {
  {"_kappa", 0.8040, "Asymptotic value of the enhancement function"},
  {"_alpha", 0.197, "defines the width of the interpolation"},
  {"_muPBE", MU_PBE, "Limiting value for large s"},
  {"_muGE",  MU_GE, "Limiting value for small s"},
};

DEVICE
static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_x_pbeint_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_x_pbeint_params *) (p->params);

  params->kappa = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
  params->alpha = dvc_get_ext_param(p->info->ext_params, ext_params, 1);
  params->muPBE = dvc_get_ext_param(p->info->ext_params, ext_params, 2);
  params->muGE  = dvc_get_ext_param(p->info->ext_params, ext_params, 3);
}

#include "maple2c/gga_exc/gga_x_pbeint.c"
#include "work_gga_new.cu"

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_pbeint = {
  XC_GGA_X_PBEINT,
  XC_EXCHANGE,
  "PBE for hybrid interfaces",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Fabiano2010_113104, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-12,
  4, dvc_ext_params, dvc_set_ext_params,
  dvc_gga_x_pbe_init, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
