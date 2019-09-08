/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_MPBE         122 /* Adamo & Barone modification to PBE             */

#pragma omp declare target

typedef struct{
  double a;
  double c1, c2, c3;
} gga_x_mpbe_params;


DEVICE
static void 
dvc_gga_x_mpbe_init(xc_func_type *p)
{
  gga_x_mpbe_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_x_mpbe_params));
  params = (gga_x_mpbe_params *) (p->params);
 
  switch(p->info->number){
  case XC_GGA_X_MPBE:
    params->a  =  0.157;
    params->c1 =  0.21951;
    params->c2 = -0.015;
    params->c3 =  0.0;
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in gga_x_mpbe\n");
    exit(1);
    #endif
    break;
  }
}


#include "maple2c/gga_exc/gga_x_mpbe.c"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_mpbe = {
  XC_GGA_X_MPBE,
  XC_EXCHANGE,
  "Adamo & Barone modification to PBE",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Adamo2002_5933, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-21,
  0, NULL, NULL,
  dvc_gga_x_mpbe_init, NULL,
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
