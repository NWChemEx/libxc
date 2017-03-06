/*
 Copyright (C) 2008 Lara Ferrigni, Georg Madsen, M.A.L. Marques

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.
  
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
  
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include "util.h"

#define XC_MGGA_X_M06_L         203 /* M06-Local functional of Minnesota      */
#define XC_HYB_MGGA_X_M06_HF    444 /* Minnesota M06-HF functional (exchange) */
#define XC_HYB_MGGA_X_M06       449 /* M06 exchange functional                */

static const FLOAT a_m06l[12] = {
  0.3987756, 0.2548219, 0.3923994, -2.103655, -6.302147, 10.97615,
  30.97273,  -23.18489, -56.73480, 21.60364, 34.21814, -9.049762
};
static const FLOAT d_m06l[6] = {0.6012244, 0.004748822, -0.008635108, -0.000009308062, 0.00004482811, 0.0};

static const FLOAT a_m06hf[12] = {
   1.179732e-01, -1.066708e+00, -1.462405e-01,  7.481848e+00,  3.776679e+00, -4.436118e+01, 
  -1.830962e+01,  1.003903e+02,  3.864360e+01, -9.806018e+01, -2.557716e+01,  3.590404e+01
};
static const FLOAT d_m06hf[6] = {-1.179732e-01, -2.500000e-03, -1.180065e-02, 0.0, 0.0, 0.0};

static const FLOAT a_m06[12] = {
   5.877943e-01, -1.371776e-01,  2.682367e-01, -2.515898e+00, -2.978892e+00,  8.710679e+00,
   1.688195e+01, -4.489724e+00, -3.299983e+01, -1.449050e+01,  2.043747e+01,  1.256504e+01
};
static const FLOAT d_m06[6] = {1.422057e-01, 7.370319e-04, -1.601373e-02, 0.0, 0.0, 0.0};

typedef struct{
  const FLOAT *a, *d;
} mgga_x_m06l_params;


static void
mgga_x_m06l_init(XC(func_type) *p)
{
  mgga_x_m06l_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(mgga_x_m06l_params));
  params = (mgga_x_m06l_params *)p->params;

  switch(p->info->number){
  case XC_MGGA_X_M06_L:
    params->a = a_m06l;
    params->d = d_m06l;
    break;
  case XC_HYB_MGGA_X_M06_HF:
    params->a = a_m06hf;
    params->d = d_m06hf;
    p->cam_alpha = 1.0;
    break;
  case XC_HYB_MGGA_X_M06:
    params->a = a_m06;
    params->d = d_m06;
    p->cam_alpha = 0.27;
    break;
  default:
    fprintf(stderr, "Internal error in mgga_x_m06l\n");
    exit(1);
  }
}

#include "maple2c/mgga_x_m06l.c"

#define func XC(mgga_x_m06l_enhance)
#include "work_mgga_x.c"

const XC(func_info_type) XC(func_info_mgga_x_m06_l) = {
  XC_MGGA_X_M06_L,
  XC_EXCHANGE,
  "Minnesota M06-L functional",
  XC_FAMILY_MGGA,
  {&xc_ref_Zhao2006_194101, &xc_ref_Zhao2008_215, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  MIN_DENS, MIN_GRAD, MIN_TAU, MIN_ZETA,
  0, NULL, NULL,
  mgga_x_m06l_init, NULL,
  NULL, NULL, work_mgga_x,
};

const XC(func_info_type) XC(func_info_hyb_mgga_x_m06_hf) = {
  XC_HYB_MGGA_X_M06_HF,
  XC_EXCHANGE,
  "Minnesota M06-HF functional (exchange)",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2006_13126, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  MIN_DENS, MIN_GRAD, MIN_TAU, MIN_ZETA,
  0, NULL, NULL,
  mgga_x_m06l_init, NULL,
  NULL, NULL, work_mgga_x,
};

const XC(func_info_type) XC(func_info_hyb_mgga_x_m06) = {
  XC_HYB_MGGA_X_M06,
  XC_EXCHANGE,
  "Minnesota M06 functional exchange",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Zhao2008_215, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  MIN_DENS, MIN_GRAD, MIN_TAU, MIN_ZETA,
  0, NULL, NULL,
  mgga_x_m06l_init, NULL, 
  NULL, NULL, work_mgga_x,
};
