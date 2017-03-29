/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_x_wc.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_wc_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t1, t2, t3, t4, t6, t7, t8, t11;
  double t12, t15, t18, t19, t22, t23, t24, t27;
  double t28, t31, t34, t38, t42, t45, t46, t50;
  double t54, t55, t64, t66, t67, t71, t74, t87;
  double t97;


  t1 = M_CBRT6;
  t2 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t3 = cbrt(t2);
  t4 = t3 * t3;
  t6 = t1 / t4;
  t7 = r->x * r->x;
  t8 = t6 * t7;
  t11 = exp(-t8 / 0.24e2);
  t12 = t7 * t11;
  t15 = t1 * t1;
  t18 = t15 / t3 / t2;
  t19 = t7 * t7;
  t22 = 0.1e1 + 0.13780328706878157621e-4 * t18 * t19;
  t23 = log(t22);
  t24 = 0.8040e0 + 0.5e1 / 0.972e3 * t8 + 0.40024242767108462450e-2 * t6 * t12 + t23;
  r->f = 0.18040e1 - 0.64641600e0 / t24;

  if(r->order < 1) return;

  t27 = t24 * t24;
  t28 = 0.1e1 / t27;
  t31 = r->x * t11;
  t34 = t7 * r->x;
  t38 = 0.1e1 / t22;
  t42 = 0.5e1 / 0.486e3 * t6 * r->x + 0.80048485534216924900e-2 * t6 * t31 - 0.33353535639257052042e-3 * t18 * t34 * t11 + 0.55121314827512630484e-4 * t18 * t34 * t38;
  r->dfdx = 0.64641600e0 * t28 * t42;

  if(r->order < 2) return;

  t45 = 0.1e1 / t27 / t24;
  t46 = t42 * t42;
  t50 = t6 * t11;
  t54 = t2 * t2;
  t55 = 0.1e1 / t54;
  t64 = t1 / t4 / t54;
  t66 = t22 * t22;
  t67 = 0.1e1 / t66;
  t71 = 0.5e1 / 0.486e3 * t6 + 0.80048485534216924900e-2 * t50 - 0.16676767819628526021e-2 * t18 * t12 + 0.16676767819628526021e-3 * t55 * t19 * t11 + 0.16536394448253789145e-3 * t18 * t7 * t38 - 0.18230156089882582635e-7 * t64 * t19 * t7 * t67;
  r->d2fdx2 = -0.129283200e1 * t45 * t46 + 0.64641600e0 * t28 * t71;

  if(r->order < 3) return;

  t74 = t27 * t27;
  t87 = t19 * r->x;
  t97 = t19 * t19;
  r->d3fdx3 = 0.387849600e1 / t74 * t46 * t42 - 0.387849600e1 * t45 * t42 * t71 + 0.64641600e0 * t28 * (-0.40024242767108462450e-2 * t18 * t31 + 0.15009091037665673419e-2 * t55 * t34 * t11 - 0.13897306516357105017e-4 * t55 * t87 * t50 + 0.33072788896507578290e-3 * t18 * r->x * t38 - 0.16407140480894324371e-6 * t64 * t87 * t67 + 0.12708439333547186897e-14 * t97 * r->x / t66 / t22);

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_wc_enhance)
