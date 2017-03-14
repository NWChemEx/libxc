/*
 Copyright (C) 2006-2007 M.A.L. Marques

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

/************************************************************************
 Implements Perdew, Burke & Ernzerhof Generalized Gradient Approximation
 correlation functional.

 I based this implementation on a routine from L.C. Balbas and J.M. Soler
************************************************************************/

#define XC_GGA_C_PBE          130 /* Perdew, Burke & Ernzerhof correlation              */
#define XC_GGA_C_PBE_SOL      133 /* Perdew, Burke & Ernzerhof correlation SOL          */
#define XC_GGA_C_XPBE         136 /* xPBE reparametrization by Xu & Goddard             */
#define XC_GGA_C_PBE_JRGX     138 /* JRGX reparametrization by Pedroza, Silva & Capelle */
#define XC_GGA_C_RGE2         143 /* Regularized PBE                                    */
#define XC_GGA_C_APBE         186 /* mu fixed from the semiclassical neutral atom       */
#define XC_GGA_C_SPBE          89 /* PBE correlation to be used with the SSB exchange   */
#define XC_GGA_C_PBEINT        62 /* PBE for hybrid interfaces                          */
#define XC_GGA_C_PBEFE        258 /* PBE for formation energies                         */
#define XC_GGA_C_PBE_MOL      272 /* Del Campo, Gazquez, Trickey and Vela (PBE-like)    */

typedef struct{
  FLOAT beta, gamma, BB;
} gga_c_pbe_params;


static void gga_c_pbe_init(XC(func_type) *p)
{
  gga_c_pbe_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_c_pbe_params));
  params = (gga_c_pbe_params *) (p->params);

  /* most functionals have the same gamma and B */
  params->gamma = (1.0 - LOG(2.0))/(M_PI*M_PI);
  params->BB = 1.0; 

  switch(p->info->number){
  case XC_GGA_C_PBE:
    params->beta = 0.06672455060314922;
    break;
  case XC_GGA_C_PBE_SOL:
    params->beta = 0.046;
    break;
  case XC_GGA_C_XPBE:
    params->beta  = 0.089809;
    params->gamma = params->beta*params->beta/(2.0*0.197363);
    break;
  case XC_GGA_C_PBE_JRGX:
    params->beta = 3.0*10.0/(81.0*M_PI*M_PI);
    break;
  case XC_GGA_C_RGE2:
    params->beta = 0.053;
    break;
  case XC_GGA_C_APBE:
    params->beta = 3.0*0.260/(M_PI*M_PI);
    break;
  case XC_GGA_C_SPBE:
    params->beta = 0.06672455060314922;
    /* the sPBE functional contains one term less than the original PBE, so we set it to zero */
    params->BB = 0.0; 
    break;
  case XC_GGA_C_PBEINT:
    params->beta = 0.052;
    break;
  case XC_GGA_C_PBEFE:
    params->beta = 0.043;
    break;
  case XC_GGA_C_PBE_MOL:
    params->beta = 0.08384;
    break;
  default:
    fprintf(stderr, "Internal error in gga_c_pbe\n");
    exit(1);
  }
}


void 
XC(gga_c_pbe_set_params)(XC(func_type) *p, FLOAT beta)
{
  gga_c_pbe_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_c_pbe_params *) (p->params);

  params->beta = beta;
}


#include "maple2c/gga_c_pbe.c"

#define func maple2c_func
#include "work_gga_c.c"

const XC(func_info_type) XC(func_info_gga_c_pbe) = {
  XC_GGA_C_PBE,
  XC_CORRELATION,
  "Perdew, Burke & Ernzerhof",
  XC_FAMILY_GGA,
  {&xc_ref_Perdew1996_3865, &xc_ref_Perdew1996_3865_err, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-12, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};

const XC(func_info_type) XC(func_info_gga_c_pbe_sol) = {
  XC_GGA_C_PBE_SOL,
  XC_CORRELATION,
  "Perdew, Burke & Ernzerhof SOL",
  XC_FAMILY_GGA,
  {&xc_ref_Perdew2008_136406, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-12, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};

const XC(func_info_type) XC(func_info_gga_c_xpbe) = {
  XC_GGA_C_XPBE,
  XC_CORRELATION,
  "Extended PBE by Xu & Goddard III",
  XC_FAMILY_GGA,
  {&xc_ref_Xu2004_4068, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-12, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};

const XC(func_info_type) XC(func_info_gga_c_pbe_jrgx) = {
  XC_GGA_C_PBE_JRGX,
  XC_CORRELATION,
  "Reparametrized PBE by Pedroza, Silva & Capelle",
  XC_FAMILY_GGA,
  {&xc_ref_Pedroza2009_201106, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-12, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};

const XC(func_info_type) XC(func_info_gga_c_rge2) = {
  XC_GGA_C_RGE2,
  XC_CORRELATION,
  "Regularized PBE",
  XC_FAMILY_GGA,
  {&xc_ref_Ruzsinszky2009_763, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-12, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};

const XC(func_info_type) XC(func_info_gga_c_apbe) = {
  XC_GGA_C_APBE,
  XC_CORRELATION,
  "mu fixed from the semiclassical neutral atom",
  XC_FAMILY_GGA,
  {&xc_ref_Constantin2011_186406, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-12, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};

const XC(func_info_type) XC(func_info_gga_c_spbe) = {
  XC_GGA_C_SPBE,
  XC_CORRELATION,
  "PBE correlation to be used with the SSB exchange",
  XC_FAMILY_GGA,
  {&xc_ref_Swart2009_094103, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-12, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};

const XC(func_info_type) XC(func_info_gga_c_pbeint) = {
  XC_GGA_C_PBEINT,
  XC_CORRELATION,
  "PBE for hybrid interfaces",
  XC_FAMILY_GGA,
  {&xc_ref_Fabiano2010_113104, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC,
  1e-12, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};

const XC(func_info_type) XC(func_info_gga_c_pbefe) = {
  XC_GGA_C_PBEFE,
  XC_CORRELATION,
  "PBE for formation energies",
  XC_FAMILY_GGA,
  {&xc_ref_Perez2015_3844, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-32, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};

const XC(func_info_type) XC(func_info_gga_c_pbe_mol) = {
  XC_GGA_C_PBE_MOL,
  XC_EXCHANGE,
  "Reparametrized PBE by del Campo, Gazquez, Trickey & Vela",
  XC_FAMILY_GGA,
  {&xc_ref_delCampo2012_104108, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC,
  1e-32, 1e-32, 0.0, 1e-32,
  0, NULL, NULL,
  gga_c_pbe_init, NULL, 
  NULL, work_gga_c, NULL
};
