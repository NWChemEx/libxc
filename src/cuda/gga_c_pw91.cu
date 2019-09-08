/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_C_PW91 134 /* Perdew & Wang 91 */

#pragma omp declare target

#include "maple2c/gga_exc/gga_c_pw91.c"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_c_pw91 = {
  XC_GGA_C_PW91,
  XC_CORRELATION,
  "Perdew & Wang 91",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Perdew1991, &dvc_xc_ref_Perdew1992_6671, &dvc_xc_ref_Perdew1992_6671_err, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-12,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
