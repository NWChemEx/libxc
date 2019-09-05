/*
 Copyright (C) 2008 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_C_M05           237 /* M05 correlation functional from Minnesota     */
#define XC_MGGA_C_M05_2X        238 /* M05-2X correlation functional from Minnesota  */
#define XC_MGGA_C_DLDF           37 /* Dispersionless Density Functional             */

#pragma omp declare target

typedef struct{
  double gamma_ss, gamma_ab;
  const double css[5], cab[5];
  double Fermi_D_cnst; /* correction term similar to 10.1063/1.2800011 */
} mgga_c_m05_params;

DEVICE static const mgga_c_m05_params dvc_par_m05 = {
  0.06, 0.0031,
  { 1.00000e0,  3.77344e0, -26.04463e0, 30.69913e0, -9.22695e0},
  { 1.00000e0,  3.78569e0, -14.15261e0, -7.46589e0, 17.94491e0},
  1e-10
};

DEVICE static const mgga_c_m05_params dvc_par_m05_2x = {
  0.06, 0.0031,
  { 1.00000e0, -3.05430e0,  7.61854e0,  1.47665e0, -11.92365e0},
  { 1.00000e0,  1.09297e0, -3.79171e0,  2.82810e0, -10.58909e0},
  1e-10
};

DEVICE static const mgga_c_m05_params dvc_par_dldf = {
  0.06, 0.0031,
  { 1.00000e0, -2.5960897,   2.2233793, 0.0, 0.0},
  { 1.00000e0,  5.9515308, -11.1602877, 0.0, 0.0},
  1e-10
};

DEVICE static void 
dvc_mgga_c_vsxc_init(xc_func_type *p)
{
  mgga_c_m05_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(mgga_c_m05_params));
  params = (mgga_c_m05_params *)p->params;

  switch(p->info->number){
  case XC_MGGA_C_M05:
    memcpy(params, &dvc_par_m05, sizeof(mgga_c_m05_params));
    break;
  case XC_MGGA_C_M05_2X:
    memcpy(params, &dvc_par_m05_2x, sizeof(mgga_c_m05_params));
    break;
  case XC_MGGA_C_DLDF:
    memcpy(params, &dvc_par_dldf, sizeof(mgga_c_m05_params));
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in mgga_c_m05\n");
    exit(1);
    #endif
    break;
  }  
}

DEVICE static const func_params_type dvc_ext_params[] = {
    {"Fermi_D_cnst", 1e-10, "Constant for the correction term similar to 10.1063/1.2800011"},
};

DEVICE static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  mgga_c_m05_params *params;

  assert(p != NULL && p->params != NULL);
  params = (mgga_c_m05_params *) (p->params);

  params->Fermi_D_cnst = max(dvc_get_ext_param(p->info->ext_params, ext_params, 0), 1e-10);
}

#include "maple2c/mgga_exc/mgga_c_m05.c"
#include "work_mgga_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_mgga_c_m05 = {
  XC_MGGA_C_M05,
  XC_CORRELATION,
  "Minnesota M05 correlation functional",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Zhao2005_161103, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1.0e-23,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_mgga_c_vsxc_init, NULL, 
  NULL, NULL, dvc_work_mgga
};


DEVICE const xc_func_info_type dvc_xc_func_info_mgga_c_m05_2x = {
  XC_MGGA_C_M05_2X,
  XC_CORRELATION,
  "Minnesota M05-2X correlation functional",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Zhao2006_364, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1.0e-23,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_mgga_c_vsxc_init, NULL, 
  NULL, NULL, dvc_work_mgga
};

DEVICE const xc_func_info_type dvc_xc_func_info_mgga_c_dldf = {
  XC_MGGA_C_DLDF,
  XC_CORRELATION,
  "Dispersionless Density Functional",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Pernal2009_263201, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  5.0e-23,
  1, dvc_ext_params, dvc_set_ext_params,
  dvc_mgga_c_vsxc_init, NULL,
  NULL, NULL, dvc_work_mgga
};

#pragma omp end declare target
