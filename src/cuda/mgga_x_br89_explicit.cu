/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_X_BR89_EXPLICIT    586 /* Becke-Roussel 89 with an explicit inversion of x(y), gamma = 0.8 */
#define XC_MGGA_X_BR89_EXPLICIT_1  602 /* Becke-Roussel 89 with an explicit inversion of x(y), gamma = 1.0 */

#pragma omp declare target

typedef struct{
  double gamma;
} mgga_x_br89_params;

DEVICE static const mgga_x_br89_params dvc_par_one = {1.0};

DEVICE static void
dvc_mgga_x_br89_init(xc_func_type *p)
{
  mgga_x_br89_params *params;

  assert(p != NULL && p->params == NULL);
  p->params = malloc(sizeof(mgga_x_br89_params));
  params = (mgga_x_br89_params *)p->params;

  switch(p->info->number){
  case XC_MGGA_X_BR89_EXPLICIT:
    /* default set by set_ext_params */
    break;
  case XC_MGGA_X_BR89_EXPLICIT_1:
    memcpy(params, &dvc_par_one, sizeof(mgga_x_br89_params));
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in mgga_x_br89_explicit\n");
    exit(1);
    #endif
    break;
  }
}

DEVICE static const func_params_type dvc_ext_params[] = {
  {"_gamma", 0.8, "gamma"},
};

DEVICE static void
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  mgga_x_br89_params *params;

  assert(p != NULL && p->params != NULL);
  params = (mgga_x_br89_params *) (p->params);

  params->gamma = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
}

#include "maple2c/mgga_exc/mgga_x_br89_explicit.c"
#include "work_mgga_new.cu"

extern DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_br89_explicit = {
  XC_MGGA_X_BR89_EXPLICIT,
  XC_EXCHANGE,
  "Becke-Roussel 89 with an explicit inversion of x(y), gamma = 0.8",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Becke1989_3761, &dvc_xc_ref_Proynov2008_103, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_I_HAVE_ALL,
  1.0e-12,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_mgga_x_br89_init, NULL,
  NULL, NULL, dvc_work_mgga
};

extern DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_br89_explicit_1 = {
  XC_MGGA_X_BR89_EXPLICIT_1,
  XC_EXCHANGE,
  "Becke-Roussel 89 with an explicit inversion of x(y), gamma = 1.0",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Becke1989_3761, &dvc_xc_ref_Proynov2008_103, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_I_HAVE_ALL,
  1.0e-12,
  0, NULL, NULL,
  dvc_mgga_x_br89_init, NULL,
  NULL, NULL, dvc_work_mgga
};

#pragma omp end declare target
