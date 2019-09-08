/*
 Copyright (C) 2006-2008 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

/* Local tau approximation */

#define XC_MGGA_X_MK00          230 /* Exchange for accurate virtual orbital energies */
#define XC_MGGA_X_MK00B         243 /* Exchange for accurate virtual orbital energies (v. B) */

#pragma omp declare target

#include "maple2c/mgga_exc/mgga_x_mk00.c"
#include "work_mgga_new.cu"

extern DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_mk00 = {
  XC_MGGA_X_MK00,
  XC_EXCHANGE,
  "Exchange for accurate virtual orbital energies",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Manby2000_7002, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_I_HAVE_ALL,
  1.0e-23,
  0, NULL, NULL,
  NULL, NULL,
  NULL, NULL, dvc_work_mgga,
};


DEVICE static void
dvc_mgga_x_mk00b_init(xc_func_type *p)
{
  static int    funcs_id  [3] = {XC_LDA_X, XC_GGA_X_B88, XC_MGGA_X_MK00};
  static double funcs_coef[3] = {-1.0, 1.0, 1.0};

  static double par_x_b88[] = {0.0016, 6.0};
  
  dvc_xc_mix_init(p, 3, funcs_id, funcs_coef);  

  dvc_xc_func_set_ext_params(p->func_aux[1], par_x_b88);
}

extern DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_mk00b = {
  XC_MGGA_X_MK00B,
  XC_EXCHANGE,
  "Exchange for accurate virtual orbital energies (v. B)",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Manby2000_7002, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_I_HAVE_ALL,
  1.0e-23,
  0, NULL, NULL,
  dvc_mgga_x_mk00b_init, NULL,
  NULL, NULL, NULL,
};

#pragma omp end declare target
