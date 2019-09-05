/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_LDA_K_GDS08_WORKER 100001   /* Combined analytical theory with Monte Carlo sampling */

#pragma omp declare target

typedef struct {
  double A, B, C;
} lda_k_gds08_params;

DEVICE static void 
dvc_lda_k_gds08_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(lda_k_gds08_params));
}

DEVICE static func_params_type dvc_ext_params[] = {
  {"_A", 0.860, "linear term"},
  {"_B", 0.224, "term proportional to the logarithm of the density"},
  {"_C", 0.0,   "term proportional to the square of the logarithm"},
};

DEVICE static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  lda_k_gds08_params *params;

  assert(p != NULL && p->params != NULL);
  params = (lda_k_gds08_params *) (p->params);

  params->A = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
  params->B = dvc_get_ext_param(p->info->ext_params, ext_params, 1);
  params->C = dvc_get_ext_param(p->info->ext_params, ext_params, 2);
}

#include "maple2c/lda_exc/lda_k_gds08_worker.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_k_gds08_worker = {
  XC_LDA_K_GDS08_WORKER,
  XC_KINETIC,
  "Combined analytical theory with Monte Carlo sampling",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Ghiringhelli2008_073104, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  3, dvc_ext_params, dvc_set_ext_params,
  dvc_lda_k_gds08_init, NULL,
  dvc_work_lda, NULL, NULL
};

#pragma omp end declare target
