/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_x_pbe.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_pbe_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t1, t2, t3, t4, t5, t6, t7, t11;
  double t16, t17, t19, t27, t28, t29, t32, t39;
  double t43;

  gga_x_pbe_params *params;
 
  assert(p->params != NULL);
  params = (gga_x_pbe_params * )(p->params);

  t1 = M_CBRT6;
  t2 = params->mu * t1;
  t3 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t4 = cbrt(t3);
  t5 = t4 * t4;
  t6 = 0.1e1 / t5;
  t7 = r->x * r->x;
  t11 = params->kappa + t2 * t6 * t7 / 0.24e2;
  r->f = 0.1e1 + params->kappa * (0.1e1 - params->kappa / t11);

  if(r->order < 1) return;

  t16 = params->kappa * params->kappa;
  t17 = t11 * t11;
  t19 = t16 / t17;
  r->dfdx = t19 * params->mu * t1 * t6 * r->x / 0.12e2;

  if(r->order < 2) return;

  t27 = params->mu * params->mu;
  t28 = t16 / t17 / t11 * t27;
  t29 = t1 * t1;
  t32 = t29 / t4 / t3;
  r->d2fdx2 = -t28 * t32 * t7 / 0.72e2 + t19 * t2 * t6 / 0.12e2;

  if(r->order < 3) return;

  t39 = t17 * t17;
  t43 = t3 * t3;
  r->d3fdx3 = t16 / t39 * t27 * params->mu / t43 * t7 * r->x / 0.48e2 - t28 * t32 * r->x / 0.24e2;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_pbe_enhance)
