/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_HJS_PBE     525 /* HJS screened exchange PBE version */
#define XC_GGA_X_HJS_PBE_SOL 526 /* HJS screened exchange PBE_SOL version */
#define XC_GGA_X_HJS_B88     527 /* HJS screened exchange B88 version */
#define XC_GGA_X_HJS_B97X    528 /* HJS screened exchange B97x version */

#pragma omp declare target

typedef struct{
  double omega;

  const double *a, *b; /* pointers to the a and b parameters */
} gga_x_hjs_params;

DEVICE
static const double dvc_a_PBE[] = 
  {0.0159941, 0.0852995, -0.160368, 0.152645, -0.0971263, 0.0422061};
DEVICE
static const double dvc_b_PBE[] = 
  {5.33319, -12.4780, 11.0988, -5.11013, 1.71468, -0.610380, 0.307555, -0.0770547, 0.0334840};

DEVICE
static const double dvc_a_PBE_sol[] = 
  {0.0047333, 0.0403304, -0.0574615, 0.0435395, -0.0216251, 0.0063721};
DEVICE
static const double dvc_b_PBE_sol[] = 
  {8.52056, -13.9885, 9.28583, -3.27287, 0.843499, -0.235543, 0.0847074, -0.0171561, 0.0050552};

DEVICE
static const double dvc_a_B88[] =
  {0.00968615, -0.0242498, 0.0259009, -0.0136606, 0.00309606, -7.32583e-5};
DEVICE
static const double dvc_b_B88[] =
  {-2.50356, 2.79656, -1.79401, 0.714888, -0.165924, 0.0118379, 0.0037806, -1.57905e-4, 1.45323e-6};

DEVICE
static const double dvc_a_B97x[] =
  {0.0027355, 0.0432970, -0.0669379, 0.0699060, -0.0474635, 0.0153092};
DEVICE
static const double dvc_b_B97x[] =
  {15.8279, -26.8145, 17.8127, -5.98246, 1.25408, -0.270783, 0.0919536, -0.0140960, 0.0045466};

DEVICE
static const double dvc_a_B88_V2[] =
  {0.0253933, -0.0673075, 0.0891476, -0.0454168, -0.00765813, 0.0142506};
DEVICE
static const double dvc_b_B88_V2[] =
  {-2.6506, 3.91108, -3.31509, 1.54485, -0.198386, -0.136112, 0.0647862, 0.0159586, -0.000245066};

DEVICE
static void
dvc_gga_x_hjs_init(xc_func_type *p)
{
  gga_x_hjs_params *params;
  
  assert(p->params == NULL);
  p->params = malloc(sizeof(gga_x_hjs_params));
  params = (gga_x_hjs_params *) (p->params);
  
  /* omega = 0.11 is set by ext_params */
  switch(p->info->number){
  case XC_GGA_X_HJS_PBE:
    params->a = dvc_a_PBE;
    params->b = dvc_b_PBE;
    break;
  case XC_GGA_X_HJS_PBE_SOL:
    params->a = dvc_a_PBE_sol;
    params->b = dvc_b_PBE_sol;
    break;
  case XC_GGA_X_HJS_B88:
    params->a = dvc_a_B88;
    params->b = dvc_b_B88;
    break;
  case XC_GGA_X_HJS_B97X:
    params->a = dvc_a_B97x;
    params->b = dvc_b_B97x;
    break;
  case XC_GGA_X_HJS_B88_V2:
    params->a = dvc_a_B88_V2;
    params->b = dvc_b_B88_V2;
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in gga_x_hjs_init\n");
    exit(1);
    #endif
    break;
  }
}

DEVICE
static func_params_type dvc_ext_params[] = {
  {"_omega", 0.11, "Screening parameter for HF"},
};

DEVICE
static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_x_hjs_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_x_hjs_params *) (p->params);

  params->omega = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
}


#include "maple2c/gga_exc/gga_x_hjs.c"
#include "work_gga_new.cu"

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_hjs_pbe = {
  XC_GGA_X_HJS_PBE,
  XC_EXCHANGE,
  "HJS screened exchange PBE version",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Henderson2008_194105, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  5e-12,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_gga_x_hjs_init, NULL, 
  NULL, dvc_work_gga, NULL
};

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_hjs_pbe_sol = {
  XC_GGA_X_HJS_PBE_SOL,
  XC_EXCHANGE,
  "HJS screened exchange PBE_SOL version",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Henderson2008_194105, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  5e-12,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_gga_x_hjs_init, NULL, 
  NULL, dvc_work_gga, NULL
};

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_hjs_b88 = {
  XC_GGA_X_HJS_B88,
  XC_EXCHANGE,
  "HJS screened exchange B88 version",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Henderson2008_194105, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-7, /* densities smaller than 1e-7 yield NaNs */
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_gga_x_hjs_init, NULL, 
  NULL,  dvc_work_gga, NULL
};

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_hjs_b97x = {
  XC_GGA_X_HJS_B97X,
  XC_EXCHANGE,
  "HJS screened exchange B97x version",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Henderson2008_194105, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-10,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_gga_x_hjs_init, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
