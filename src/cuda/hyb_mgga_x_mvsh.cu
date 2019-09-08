/*
 Copyright (C) 2015 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_HYB_MGGA_X_MVSH     474 /* MVSh hybrid */

DEVICE static void
dvc_hyb_mgga_x_mvsh_init(xc_func_type *p)
{
  static int   funcs_id  [1] = {XC_MGGA_X_MVS};
  static double funcs_coef[1] = {0.75};

  dvc_xc_mix_init(p, 1, funcs_id, funcs_coef);
  p->cam_alpha = 0.25;
}

extern DEVICE
const xc_func_info_type dvc_xc_func_info_hyb_mgga_x_mvsh = {
  XC_HYB_MGGA_X_MVSH,
  XC_EXCHANGE,
  "MVSh hybrid exchange functional",
  XC_FAMILY_HYB_MGGA,
  {&dvc_xc_ref_Sun2015_685, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC,
  1e-32,
  0, NULL, NULL,
  dvc_hyb_mgga_x_mvsh_init,
  NULL, NULL, NULL, NULL /* this is taken care of by the generic routine */
};
