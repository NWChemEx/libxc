/*
 Copyright (C) 2015 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "xc_device.h"
#include "xc_extern.h"

#define XC_MGGA_X_VT84          541 /* meta-GGA version of VT{8,4} GGA */

#include "maple2c/mgga_exc/mgga_x_vt84.c"
#include "work_mgga_new.c"
#include "work_mgga_new.cpp"

EXTERN const xc_func_info_type xc_func_info_mgga_x_vt84 = {
  XC_MGGA_X_VT84,
  XC_EXCHANGE,
  "meta-GGA version of VT{8,4} GGA",
  XC_FAMILY_MGGA,
  {&xc_ref_Campo2012_179, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-23,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, NULL, work_mgga,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  NULL, NULL, work_mgga_offload
#endif
};
