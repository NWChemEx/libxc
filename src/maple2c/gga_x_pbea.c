/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_x_pbea.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_pbea_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t1, t3, t4, t6, t8, t12;


  t1 = r->x * r->x;
  t3 = 0.1e1 + 0.86399408095363255118e-2 * t1;
  t4 = pow(t3, -0.52e0);
  r->f = 0.18040e1 - 0.8040e0 * t4;

  if(r->order < 1) return;

  t6 = pow(t3, -0.152e1);
  r->dfdx = 0.72243729073018939401e-2 * t6 * r->x;

  if(r->order < 2) return;

  t8 = pow(t3, -0.252e1);
  r->d2fdx2 = -0.18975118908752291802e-3 * t8 * t1 + 0.72243729073018939401e-2 * t6;

  if(r->order < 3) return;

  t12 = pow(t3, -0.352e1);
  r->d3fdx3 = 0.82627727729668790042e-5 * t12 * t1 * r->x - 0.56925356726256875406e-3 * t8 * r->x;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_pbea_enhance)
