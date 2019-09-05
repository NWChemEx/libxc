/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_K_PBE3         595 /* Three parameter PBE-like expansion             */
#define XC_GGA_K_PBE4         596 /* Four  parameter PBE-like expansion             */

#pragma omp declare target

typedef struct{
  double a;
  double c1, c2, c3;
} gga_k_mpbe_params;


DEVICE
static void 
dvc_gga_k_mpbe_init(xc_func_type *p)
{
  gga_k_mpbe_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_k_mpbe_params));
  params = (gga_k_mpbe_params *) (p->params);
 
  switch(p->info->number){
  case XC_GGA_K_PBE3:
    params->a  =  4.1355;
    params->c1 = -3.7425;
    params->c2 = 50.258;
    params->c3 =  0.0;
    break;
  case XC_GGA_K_PBE4:
    params->a  =   1.7107;
    params->c1 =  -7.2333;
    params->c2 =  61.645;
    params->c3 = -93.683;
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in gga_k_mpbe\n");
    exit(1);
    #endif
    break;
  }
}


#include "maple2c/gga_exc/gga_k_mpbe.c"
#include "work_gga_new.cu"

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_k_pbe3 = {
  XC_GGA_K_PBE3,
  XC_KINETIC,
  "Three parameter PBE-like expansion",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Karasiev2006_111, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-21,
  0, NULL, NULL,
  dvc_gga_k_mpbe_init, NULL,
  NULL, dvc_work_gga, NULL
};

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_k_pbe4 = {
  XC_GGA_K_PBE4,
  XC_KINETIC,
  "Four parameter PBE-like expansion",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Karasiev2006_111, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-21,
  0, NULL, NULL,
  dvc_gga_k_mpbe_init, NULL,
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
