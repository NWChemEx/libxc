/*
 Copyright (C) 2015 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_XC_VV10         255 /* Vydrov and Van Voorhis */
#define XC_HYB_GGA_XC_LC_VV10  469 /* Vydrov and Van Voorhis */

#pragma omp declare target

DEVICE
static void
dvc_gga_xc_vv10_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_RPW86, XC_GGA_C_PBE};
  static double funcs_coef[2] = {1.0, 1.0};
  dvc_xc_mix_init(p, 2, funcs_id, funcs_coef);
  
  p->nlc_b = 5.9;
  p->nlc_C = 0.0093;
}

DEVICE
static void
dvc_hyb_gga_xc_lc_vv10_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_HJS_PBE, XC_GGA_C_PBE};
  static double funcs_coef[2] = {1.0, 1.0};
  
  dvc_xc_mix_init(p, 2, funcs_id, funcs_coef);
  
  p->cam_omega = 0.45;
  p->cam_alpha =  1.0;
  p->cam_beta  = -1.0;
  p->nlc_b = 6.3;
  p->nlc_C = 0.0089;
  dvc_xc_func_set_ext_params(p->func_aux[0], &p->cam_omega);  
}

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_xc_vv10 = {
  XC_GGA_XC_VV10,
  XC_EXCHANGE_CORRELATION,
  "Vydrov and Van Voorhis",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Vydrov2010_244103, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_VV10 | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  dvc_gga_xc_vv10_init,
  NULL, NULL, NULL, NULL
};

extern DEVICE
const xc_func_info_type dvc_xc_func_info_hyb_gga_xc_lc_vv10 = {
  XC_HYB_GGA_XC_LC_VV10,
  XC_EXCHANGE_CORRELATION,
  "Vydrov and Van Voorhis",
  XC_FAMILY_HYB_GGA,
  {&dvc_xc_ref_Vydrov2010_244103, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HYB_CAM | XC_FLAGS_VV10 | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  dvc_hyb_gga_xc_lc_vv10_init,
  NULL, NULL, NULL, NULL
};

#pragma omp end declare target
