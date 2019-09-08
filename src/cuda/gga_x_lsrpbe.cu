/*
 Copyright (C) 2006-2007 M.A.L. Marques
 Copyright (C) 2018      Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_LSRPBE  169 /* PW91-like modification of RPBE */

#pragma omp declare target

typedef struct{
  double kappa;
  double mu;
  double alpha;
} gga_x_lsrpbe_params;

DEVICE
static void 
dvc_gga_x_lsrpbe_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_x_lsrpbe_params));
}

DEVICE
static const func_params_type dvc_ext_params[] = {
  {"_kappa", 0.8040, "Asymptotic value of the enhancement function"},
  {"_mu",    MU_PBE, "Coefficient of the 2nd order expansion of the full Lsrpbe functional"},
  {"_alpha", 0.00680892, "Exponent that should satisfy the PW91 criterion"}
};

DEVICE
static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_x_lsrpbe_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_x_lsrpbe_params *) (p->params);

  params->kappa = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
  params->mu    = dvc_get_ext_param(p->info->ext_params, ext_params, 1);
  params->alpha = dvc_get_ext_param(p->info->ext_params, ext_params, 2);

  /* adapt used mu value to yield wanted mu near origin (eq 9) */
  params-> mu += params->alpha*(1.0 + params->kappa);

  printf("mu = %.10f\n",params->mu);
}

#include "maple2c/gga_exc/gga_x_lsrpbe.c"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_lsrpbe = {
  XC_GGA_X_LSRPBE,
  XC_EXCHANGE,
  "lsRPBE, a PW91-like modification of RPBE",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_PachecoKato2016_268, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  3, dvc_ext_params, dvc_set_ext_params,
  dvc_gga_x_lsrpbe_init, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
