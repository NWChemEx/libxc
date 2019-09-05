/*
 Copyright (C) 2006-2009 J.I.J. Ojajarvi

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_X_2D_PRHG07         210   /* Pittalis, Rasanen, Helbig, Gross Exchange Functional */
#define XC_MGGA_X_2D_PRHG07_PRP10   211   /* PRGH07 with PRP10 correction */

#pragma omp declare target

typedef struct xc_mgga_work_x_t {
  int   order; /* to which order should I return the derivatives */
  double rs, zeta, x, t, u;

  double f;                                   /* enhancement factor       */
  double dfdrs, dfdx, dfdt, dfdu;             /* first derivatives of f  */
  double d2fdrs2, d2fdx2, d2fdt2, d2fdu2;     /* second derivatives of zk */
  double d2fdrsx, d2fdrst, d2fdrsu, d2fdxt, d2fdxu, d2fdtu;
} xc_mgga_work_x_t;

#ifdef __CUDACC__
// In CUDA 'long double' is treated as 'double'.
// However functions on 'long double' are not permitted,
// so we define those functions here to get around that limitation.
// Because of the limitations of the CUDA language we implement
// the relevant functions using 'double' (IF CUDA ever were to
// support 'long double' this code would need to be removed to
// take advantage of such capability).
//
DEVICE inline long double expl(long double x) noexcept
{
  long double result;
  double input = x;
  result = exp(input);
  return result;
}
DEVICE inline long double logl(long double x) noexcept
{
  long double result;
  double input = x;
  result = log(input);
  return result;
}
DEVICE inline long double fabsl(long double x) noexcept
{
  if (x < 0.0) {
    return -x;
  }
  else {
    return x;
  }
}
#endif

/* Standard Newton's method */
DEVICE static double
dvc_prhg_newt(double c, double tol, double * res, int *ierr)
{
  int count;
  long double y, f, yf;
  long double ey, fp, step;
  static int max_iter = 50;

   *ierr = 1;
   if(c < -1.0)
     return 0.0;
     
   count = 0;
   
   /** We need to calculate y in different ways in different regions
   because of numerical problems. (y-1)*exp(y) is very nasty at high y
   and log(y-1)+y is very nasty at low y. **/
   if (c < 4.0) {
     y = 2.0;
     do {
       ey = expl(y);
       yf = (y-1.0)*ey;
       f = yf - c;
       fp = ey*y;
       
       step = f/fp;
       
       y -= fabsl(step) < 1.0 ? step : (step)/fabsl(step);
       y  = fabsl(y);
       
       count ++;
       *res = fabsl(f);
     } while((*res > tol) && (count < max_iter));
   }
   else {
     y = 6.0;
     c = logl(c);
     do {
       yf = logl(y-1.0)+y;
       f = yf - c;
       fp = 1.0 + 1.0/(-1.0 + y);
       
       step = f/fp;
       
       y -= fabsl(step) < 1.0 ? step : (step)/fabsl(step);
       y  = fabsl(y);
       
       count ++;
       *res = fabsl(f);
     } while((*res > tol) && (count < max_iter));
   }
   
   if(count == max_iter) *ierr=0;
   
   return y;
}

DEVICE double dvc_xc_mgga_x_2d_prhg_get_y(double C)
{
  double rhs, res, y, tol;
  int ierr;

  tol = 5e-12;

  rhs = C/M_PI;

  y = dvc_prhg_newt(rhs, tol, &res, &ierr);
  #ifndef __CUDACC__
  if(ierr == 0){
    fprintf(stderr, 
	    "Warning: Convergence not reached in PRHG functional\n"
	    "For c = %e (residual = %e)\n", C, res);
  }
  #endif

  return y;
}

DEVICE static void 
func(const xc_func_type *p, xc_mgga_work_x_t *r)
{
  double y;
  double v_PRHG, C;

  assert(p != NULL);
  
  C = 0.25*(r->u - 4.0*r->t + 0.5*r->x*r->x);
  
  y = dvc_xc_mgga_x_2d_prhg_get_y(C);
  
  v_PRHG = M_PI*dvc_xc_bessel_I0(y/2.0);
  v_PRHG /= X_FACTOR_2D_C;

  if (p->info->number == XC_MGGA_X_2D_PRHG07) {
    r->dfdrs = v_PRHG*(1.0 / 3.0); // This factor is here in order to get the correct potential through work_mgga_x.c
    r->f = v_PRHG / 2.0;
  }else if (p->info->number == XC_MGGA_X_2D_PRHG07_PRP10) {
    r->dfdrs = (v_PRHG - ((2.0*M_SQRT2)/(3.0*M_PI))*sqrt(max(2.0*r->t - 0.25*r->x*r->x, 0.0))/X_FACTOR_2D_C)*(1.0 / 3.0);
    r->f = r->dfdrs * (3.0 / 2.0);
  }

  r->dfdrs /= -r->rs; /* due to the definition of dfdrs */
  
  return;
}
#define XC_DIMENSIONS 2
#include "work_mgga_x.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_2d_prhg07 = {
  XC_MGGA_X_2D_PRHG07,
  XC_EXCHANGE,
  "Pittalis-Rasanen-Helbig-Gross 2007",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Pittalis2007_235314, NULL, NULL, NULL, NULL},
  XC_FLAGS_2D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_HAVE_EXC | XC_FLAGS_I_HAVE_VXC,
  1.0e-23,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, NULL,
  dvc_work_mgga_x,
};

DEVICE const xc_func_info_type dvc_xc_func_info_mgga_x_2d_prhg07_prp10 = {
  XC_MGGA_X_2D_PRHG07_PRP10,
  XC_EXCHANGE,
  "PRHG07 with Pittalis-Rasanen-Proetto 2010 correction",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Pittalis2007_235314, &dvc_xc_ref_Pittalis2010_115108, NULL, NULL, NULL},
  XC_FLAGS_2D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_HAVE_EXC | XC_FLAGS_I_HAVE_VXC,
  1.0e-23,
  0, NULL, NULL,
  NULL,
  NULL,
  NULL, NULL,
  dvc_work_mgga_x,
};

#pragma omp end declare target
