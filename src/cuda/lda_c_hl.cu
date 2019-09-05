/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_LDA_C_HL   4   /* Hedin & Lundqvist            */
#define XC_LDA_C_GL   5   /* Gunnarson & Lundqvist        */
#define XC_LDA_C_vBH 17   /* von Barth & Hedin            */

#pragma omp declare target

typedef struct {
  double r[2], c[2];
} lda_c_hl_params;

DEVICE static const lda_c_hl_params dvc_par_hl = { /* HL unpolarized only*/
  {21.0, 21.0}, {0.0225, 0.0225}
};

DEVICE static const lda_c_hl_params dvc_par_gl = {
  {11.4, 15.9}, {0.0333, 0.0203}
};

DEVICE static const lda_c_hl_params dvc_par_vbh = {
  {30.0, 75.0}, {0.0252, 0.0127}
};

DEVICE static void 
dvc_lda_c_hl_init(xc_func_type *p)
{
  lda_c_hl_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(lda_c_hl_params));
  params = (lda_c_hl_params *) (p->params);

  switch(p->info->number){
  case XC_LDA_C_HL:
    memcpy(params, &dvc_par_hl, sizeof(lda_c_hl_params));
    break;
  case XC_LDA_C_GL:
    memcpy(params, &dvc_par_gl, sizeof(lda_c_hl_params));
    break;
  case XC_LDA_C_vBH:
    memcpy(params, &dvc_par_vbh, sizeof(lda_c_hl_params));
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in lda_c_hl\n");
    exit(1);
    #endif
    break;
  }
}

#include "maple2c/lda_exc/lda_c_hl.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_hl = {
  XC_LDA_C_HL,
  XC_CORRELATION,
  "Hedin & Lundqvist",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Hedin1971_2064, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-16,
  0, NULL, NULL,
  dvc_lda_c_hl_init, NULL,
  dvc_work_lda, NULL, NULL
};

DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_gl = {
  XC_LDA_C_GL,
  XC_CORRELATION,
  "Gunnarson & Lundqvist",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Gunnarsson1976_4274, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-17,
  0, NULL, NULL,
  dvc_lda_c_hl_init, NULL,
  dvc_work_lda, NULL, NULL
};

DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_vbh = {
  XC_LDA_C_vBH,
  XC_CORRELATION,
  "von Barth & Hedin",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_vonBarth1972_1629, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-17,
  0, NULL, NULL,
  dvc_lda_c_hl_init, NULL,
  dvc_work_lda, NULL, NULL
};
#pragma omp end declare target
