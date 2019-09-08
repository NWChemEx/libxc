/*
 Copyright (C) 2008 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_C_BC95          240 /* Becke correlation 95 */

#pragma omp declare target

typedef struct{
  double css, copp;
} mgga_c_bc95_params;


DEVICE static void 
dvc_mgga_c_bc95_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(mgga_c_bc95_params));
}

DEVICE static const func_params_type dvc_ext_params[] = {
  {"_css",  0.038,  "Parallel spin"},
  {"_copp", 0.0031, "Opposite spin"},
};

DEVICE static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  mgga_c_bc95_params *params;

  assert(p != NULL && p->params != NULL);
  params = (mgga_c_bc95_params *) (p->params);

  params->css  = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
  params->copp = dvc_get_ext_param(p->info->ext_params, ext_params, 1);
}

#include "maple2c/mgga_exc/mgga_c_bc95.c"
#include "work_mgga_new.cu"

extern DEVICE const xc_func_info_type dvc_xc_func_info_mgga_c_bc95 = {
  XC_MGGA_C_BC95,
  XC_CORRELATION,
  "Becke correlation 95",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Becke1996_1040, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-23,
  2, dvc_ext_params, dvc_set_ext_params,
  dvc_mgga_c_bc95_init, NULL,
  NULL, NULL, dvc_work_mgga,
};

#pragma omp end declare target
