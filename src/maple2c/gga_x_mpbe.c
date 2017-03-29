/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_x_mpbe.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_mpbe_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t1, t2, t3, t4, t6, t7, t10, t11;
  double t15, t18, t19, t20, t21, t28, t32, t34;
  double t45, t46;


  t1 = M_CBRT6;
  t2 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t3 = cbrt(t2);
  t4 = t3 * t3;
  t6 = t1 / t4;
  t7 = r->x * r->x;
  t10 = 0.1e1 + 0.65416666666666666668e-2 * t6 * t7;
  t11 = 0.1e1 / t10;
  t15 = t1 * t1;
  t18 = t15 / t3 / t2;
  t19 = t7 * t7;
  t20 = t10 * t10;
  t21 = 0.1e1 / t20;
  r->f = 0.1e1 + 0.91462500000000000000e-2 * t6 * t7 * t11 - 0.26041666666666666667e-4 * t18 * t19 * t21;

  if(r->order < 1) return;

  t28 = t7 * r->x;
  t32 = t19 * r->x;
  t34 = 0.1e1 / t20 / t10;
  r->dfdx = 0.18292500000000000000e-1 * t6 * r->x * t11 - 0.22383010416666666668e-3 * t18 * t28 * t21 + 0.41972896197537516269e-7 * t32 * t34;

  if(r->order < 2) return;

  t45 = t20 * t20;
  t46 = 0.1e1 / t45;
  r->d2fdx2 = 0.18292500000000000000e-1 * t6 * t11 - 0.91081718750000000005e-3 * t18 * t7 * t21 + 0.57062471374563354654e-6 * t19 * t34 - 0.16474361757533475136e-8 * t19 * t7 * t46 * t6;

  if(r->order < 3) return;

  r->d3fdx3 = -0.20609612500000000001e-2 * t18 * t21 * r->x + 0.37505168491919638820e-5 * t28 * t34 - 0.32281637069036201785e-7 * t32 * t46 * t6 + 0.86215826531091853216e-10 * t19 * t28 / t45 / t10 * t18;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_mpbe_enhance)
