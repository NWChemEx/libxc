/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_x_lg93.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_lg93_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t1, t2, t3, t4, t5, t6, t7, t8;
  double t10, t13, t14, t17, t19, t22, t23, t29;
  double t30, t35, t36, t38, t39, t40, t41, t42;
  double t44, t47, t49, t52, t57, t60, t61, t62;
  double t65, t66, t67, t70, t75, t83, t87, t88;
  double t93, t116, t127;


  t1 = M_CBRT6;
  t2 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t3 = cbrt(t2);
  t4 = t3 * t3;
  t5 = 0.1e1 / t4;
  t6 = t1 * t5;
  t7 = r->x * r->x;
  t8 = t6 * t7;
  t10 = t1 * t1;
  t13 = t10 / t3 / t2;
  t14 = t7 * t7;
  t17 = t14 * t7;
  t19 = t2 * t2;
  t22 = t1 / t4 / t19;
  t23 = t14 * t14;
  t29 = t10 / t3 / t19 / t2;
  t30 = t23 * t7;
  t35 = 0.1e1 + 0.20588079936467259283e0 * t8 + 0.51718749999999999998e-1 * t13 * t14 + 0.99883908074331051182e-4 * t17 + 0.21916594328703703703e-3 * t22 * t23 + 0.11831024546682098765e-2 * t29 * t30 + 0.11106816177675317211e-8 * t23 * t14;
  t36 = pow(t35, 0.24974e-1);
  t38 = 0.1e1 + 0.41666666666666666666e-9 * t8;
  t39 = 0.1e1 / t38;
  r->f = t36 * t39;

  if(r->order < 1) return;

  t40 = pow(t35, -0.975026e0);
  t41 = t40 * t39;
  t42 = t6 * r->x;
  t44 = t7 * r->x;
  t47 = t14 * r->x;
  t49 = t14 * t44;
  t52 = t23 * r->x;
  t57 = 0.41176159872934518566e0 * t42 + 0.20687499999999999999e0 * t13 * t44 + 0.59930344844598630709e-3 * t47 + 0.17533275462962962962e-2 * t22 * t49 + 0.11831024546682098765e-1 * t29 * t52 + 0.13328179413210380653e-7 * t23 * t44;
  t60 = t38 * t38;
  t61 = 0.1e1 / t60;
  t62 = t36 * t61;
  r->dfdx = 0.24974e-1 * t41 * t57 - 0.83333333333333333332e-9 * t62 * t42;

  if(r->order < 2) return;

  t65 = pow(t35, -0.1975026e1);
  t66 = t65 * t39;
  t67 = t57 * t57;
  t70 = t40 * t61;
  t75 = t13 * t7;
  t83 = 0.41176159872934518566e0 * t6 + 0.62062499999999999997e0 * t75 + 0.29965172422299315354e-2 * t14 + 0.12273292824074074073e-1 * t22 * t17 + 0.10647922092013888888e0 * t29 * t23 + 0.14660997354531418718e-6 * t30;
  t87 = 0.1e1 / t60 / t38;
  t88 = t36 * t87;
  r->d2fdx2 = -0.24350299324e-1 * t66 * t67 - 0.41623333333333333332e-10 * t70 * t57 * t42 + 0.24974e-1 * t41 * t83 + 0.13888888888888888888e-17 * t88 * t75 - 0.83333333333333333332e-9 * t62 * t6;

  if(r->order < 3) return;

  t93 = pow(t35, -0.2975026e1);
  t116 = t13 * r->x;
  t127 = t60 * t60;
  r->d3fdx3 = 0.48092474272682424e-1 * t93 * t39 * t67 * t57 + 0.60875748309999999998e-10 * t65 * t61 * t67 * t42 - 0.73050897972e-1 * t66 * t57 * t83 + 0.10405833333333333333e-18 * t40 * t87 * t57 * t75 - 0.62434999999999999998e-10 * t70 * t83 * t42 - 0.62434999999999999998e-10 * t70 * t57 * t1 * t5 + 0.24974e-1 * t41 * (0.12412499999999999999e1 * t116 + 0.11986068968919726142e-1 * t44 + 0.73639756944444444438e-1 * t22 * t47 + 0.85183376736111111104e0 * t29 * t49 + 0.14660997354531418718e-5 * t52) - 0.21387463030592364975e-27 * t36 / t127 * t44 + 0.41666666666666666664e-17 * t88 * t116;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_lg93_enhance)
