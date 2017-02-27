/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/gga_x_g96.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_g96_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t1, t3, t4, t5;


  t1 = pow(r->x, 0.15000000000000000000e1);
  r->f = 0.10e1 + 0.78442430852382950888e-2 * t1;

  if(r->order < 1) return;

  t3 = pow(r->x, 0.5000000000000000000e0);
  r->dfdx = 0.11766364627857442633e-1 * t3;

  if(r->order < 2) return;

  t4 = pow(r->x, -0.5000000000000000000e0);
  r->d2fdx2 = 0.58831823139287213165e-2 * t4;

  if(r->order < 3) return;

  t5 = pow(r->x, -0.15000000000000000000e1);
  r->d3fdx3 = -0.29415911569643606582e-2 * t5;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_g96_enhance)
