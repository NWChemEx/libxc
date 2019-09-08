/*
 Copyright (C) 2015 Narbe Mardirossian and Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_XC_B97M_V        254 /* Mardirossian and Head-Gordon */

#pragma omp declare target

DEVICE static void
dvc_mgga_xc_b97mv_init(xc_func_type *p)
{
  /* Non-local correlation parameters */
  p->nlc_b = 6.0;
  p->nlc_C = 0.01;
}

#include "maple2c/mgga_exc/mgga_xc_b97mv.c"
#include "work_mgga_new.cu"

extern DEVICE const xc_func_info_type dvc_xc_func_info_mgga_xc_b97m_v = {
  XC_MGGA_XC_B97M_V,
  XC_EXCHANGE_CORRELATION,
  "B97M-V exchange-correlation functional",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Mardirossian2015_074111, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_VV10 | XC_FLAGS_I_HAVE_ALL,
  1e-23,
  0, NULL, NULL,
  dvc_mgga_xc_b97mv_init, NULL, 
  NULL, NULL, dvc_work_mgga,
};

#pragma omp end declare target
