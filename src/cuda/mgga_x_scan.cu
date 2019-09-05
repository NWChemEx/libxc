/*
 Copyright (C) 2016 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_X_SCAN          263 /* SCAN exchange of Sun, Ruzsinszky, and Perdew  */
#define XC_HYB_MGGA_X_SCAN0     264 /* SCAN hybrid exchange */
#define XC_MGGA_X_REVSCAN       581 /* revised SCAN */
#define XC_HYB_MGGA_X_REVSCAN0  583 /* revised SCAN hybrid exchange */

#pragma omp declare target

typedef struct{
  double c1, c2, d, k1;
} mgga_x_scan_params;

DEVICE static const mgga_x_scan_params dvc_par_scan = {0.667, 0.8, 1.24, 0.065};
DEVICE static const mgga_x_scan_params dvc_par_revscan = {0.607, 0.7, 1.37, 0.065};

DEVICE static void 
dvc_mgga_x_scan_init(xc_func_type *p)
{
  mgga_x_scan_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(mgga_x_scan_params));
  params = (mgga_x_scan_params *)p->params;

  switch(p->info->number){
  case XC_MGGA_X_SCAN:
    memcpy(params, &dvc_par_scan, sizeof(mgga_x_scan_params));
    break;
  case XC_MGGA_X_REVSCAN:
    memcpy(params, &dvc_par_revscan, sizeof(mgga_x_scan_params));
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in mgga_x_scan\n");
    exit(1);
    #endif
    break;
  }  
}

#include "maple2c/mgga_exc/mgga_x_scan.c"
#include "work_mgga_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_scan = {
  XC_MGGA_X_SCAN,
  XC_EXCHANGE,
  "SCAN exchange of Sun, Ruzsinszky, and Perdew",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Sun2015_036402, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-23,
  0, NULL, NULL,
  dvc_mgga_x_scan_init, NULL,
  NULL, NULL, dvc_work_mgga,
};

DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_revscan = {
  XC_MGGA_X_REVSCAN,
  XC_EXCHANGE,
  "revised SCAN",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Mezei2018_2469, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-23,
  0, NULL, NULL,
  dvc_mgga_x_scan_init, NULL,
  NULL, NULL, dvc_work_mgga,
};

DEVICE static void
dvc_hyb_mgga_x_scan0_init(xc_func_type *p)
{
  static int   funcs_id  [1] = {XC_MGGA_X_SCAN};
  static double funcs_coef[1] = {1.0 - 0.25};

  dvc_xc_mix_init(p, 1, funcs_id, funcs_coef);
  p->cam_alpha = 0.25;
}


DEVICE const xc_func_info_type dvc_xc_func_info_hyb_mgga_x_scan0 = {
  XC_HYB_MGGA_X_SCAN0,
  XC_EXCHANGE,
  "SCAN hybrid exchange (SCAN0)",
  XC_FAMILY_HYB_MGGA,
  {&dvc_xc_ref_Hui2016_044114, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  dvc_hyb_mgga_x_scan0_init, NULL,
  NULL, NULL, NULL /* this is taken care of by the generic routine */
};


DEVICE static void
dvc_hyb_mgga_x_revscan0_init(xc_func_type *p)
{
  static int   funcs_id  [1] = {XC_MGGA_X_REVSCAN};
  static double funcs_coef[1] = {1.0 - 0.25};

  dvc_xc_mix_init(p, 1, funcs_id, funcs_coef);
  p->cam_alpha = 0.25;
}


DEVICE const xc_func_info_type dvc_xc_func_info_hyb_mgga_x_revscan0 = {
  XC_HYB_MGGA_X_REVSCAN0,
  XC_EXCHANGE,
  "revised SCAN hybrid exchange (SCAN0)",
  XC_FAMILY_HYB_MGGA,
  {&dvc_xc_ref_Mezei2018_2469, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  dvc_hyb_mgga_x_revscan0_init, NULL,
  NULL, NULL, NULL /* this is taken care of by the generic routine */
};

#pragma omp end declare target
