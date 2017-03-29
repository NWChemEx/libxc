/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_x_2d_b86.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_2d_b86_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t1, t3, t5, t6, t9, t10, t11, t18;
  double t19, t25, t28;


  t1 = r->x * r->x;
  t3 = 0.1e1 + 0.2105e-2 * t1;
  t5 = 0.1e1 + 0.119e-3 * t1;
  t6 = 0.1e1 / t5;
  r->f = t3 * t6;

  if(r->order < 1) return;

  t9 = t5 * t5;
  t10 = 0.1e1 / t9;
  t11 = t3 * t10;
  r->dfdx = 0.4210e-2 * r->x * t6 - 0.238e-3 * t11 * r->x;

  if(r->order < 2) return;

  t18 = 0.1e1 / t9 / t5;
  t19 = t3 * t18;
  r->d2fdx2 = 0.4210e-2 * t6 - 0.2003960e-5 * t1 * t10 + 0.113288e-6 * t19 * t1 - 0.238e-3 * t11;

  if(r->order < 3) return;

  t25 = t1 * r->x;
  t28 = t9 * t9;
  r->d3fdx3 = -0.6011880e-5 * t10 * r->x + 0.1430827440e-8 * t25 * t18 - 0.80887632e-10 * t3 / t28 * t25 + 0.339864e-6 * t19 * r->x;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_2d_b86_enhance)
