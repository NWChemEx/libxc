/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_WPBEH 524 /* short-range version of the PBE */

#pragma omp declare target

typedef struct{
  double omega;
} gga_x_wpbeh_params;

DEVICE
static void
dvc_gga_x_wpbeh_init(xc_func_type *p)
{
  assert(p->params == NULL);
  p->params = malloc(sizeof(gga_x_wpbeh_params));
}

/* The default value is actually PBEh */
DEVICE
static func_params_type dvc_ext_params[] = {
  {"_omega", 0.0, "Screening parameter for HF"},
};

DEVICE
static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_x_wpbeh_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_x_wpbeh_params *) (p->params);

  params->omega = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
}


/* This implementation follows the one from espresso, that, in turn,
   follows the one of the thesis of Jochen Heyd. Analytic derivatives
   are only implemented in espresso though. These implementations can
   be found in:

   vasp: xclib_grad.F, MODULE wpbe, and in particular SUBROUTINE EXCHWPBE_R
   espresso: flib/functionals.f90, SUBROUTINE wpbe_analy_erfc_approx_grad

   very important details can be found in references:

   *) J Heyd, GE Scuseria, and M Ernzerhof, J. Chem. Phys. 118, 8207 (2003)
      Erratum: J. Chem. Phys. 124, 219906 (2006).
   *) M Ernzerhof and JP Perdew, J. Chem. Phys. 109, 3313 (1998)
   *) J Heyd and GE Scuseria, J. Chem. Phys. 120, 7274 (2004)

   Also the whole mess with the rescaling of s is explained in

   *) TM Henderson, AF Izmaylov, G Scalmani, and GE Scuseria, J. Chem. Phys. 131, 044108 (2009)
*/

#include "maple2c/gga_exc/gga_x_wpbeh.cu"
#include "work_gga_new.cu"

extern DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_wpbeh = {
  XC_GGA_X_WPBEH,
  XC_EXCHANGE,
  "short-range part of the PBE (default w=0 gives PBEh)",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Heyd2003_8207, &dvc_xc_ref_Heyd2003_8207_err, &dvc_xc_ref_Ernzerhof1998_3313, &dvc_xc_ref_Heyd2004_7274, &dvc_xc_ref_Henderson2009_044108},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_gga_x_wpbeh_init, NULL, 
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
