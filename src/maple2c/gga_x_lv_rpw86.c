/* 
  This file was generated automatically with /nfs/data-012/marques/software/source/libxc/svn/scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ../maple/gga_x_lv_rpw86.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_lv_rpw86_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t1, t2, t3, t4, t6, t7, t8, t10;
  double t11, t12, t13, t14, t15, t18, t21, t25;
  double t26, t28, t29, t35, t36, t37, t38, t44;
  double t45, t47, t48, t49, t50, t53, t57, t58;
  double t61, t62, t64, t65, t74, t75, t76, t84;
  double t91, t92, t93, t94, t97, t98, t105, t106;
  double t109, t112, t118, t135, t169, t173, t184;


  t1 = M_CBRT6;
  t2 = 0.31415926535897932385e1 * 0.31415926535897932385e1;
  t3 = cbrt(t2);
  t4 = t3 * t3;
  t6 = t1 / t4;
  t7 = r->x * r->x;
  t8 = t6 * t7;
  t10 = 0.1e1 + 0.39310185185185185185e-2 * t8;
  t11 = t7 * t7;
  t12 = t11 * t7;
  t13 = 0.97045613501312856080e-7 * t12;
  t14 = 0.1e1 + t13;
  t15 = 0.1e1 / t14;
  t18 = t1 * t1;
  t21 = t18 / t3 / t2;
  t25 = 0.1e1 + 0.77125000000000000002e-1 * t8 + 0.30086805555555555556e-1 * t21 * t11 + 0.72628259874719906066e-6 * t12;
  t26 = pow(t25, 0.1e1 / 0.15e2);
  t28 = 0.115e1 + t13;
  t29 = 0.1e1 / t28;
  r->f = t10 * t15 + 0.97045613501312856080e-7 * t12 * t26 * t29;

  if(r->order < 1) return;

  t35 = t14 * t14;
  t36 = 0.1e1 / t35;
  t37 = t10 * t36;
  t38 = t11 * r->x;
  t44 = t26 * t26;
  t45 = t44 * t44;
  t47 = t45 * t45;
  t48 = t47 * t45 * t44;
  t49 = 0.1e1 / t48;
  t50 = t12 * t49;
  t53 = t7 * r->x;
  t57 = 0.15425000000000000000e0 * t6 * r->x + 0.12034722222222222222e0 * t21 * t53 + 0.43576955924831943640e-5 * t38;
  t58 = t29 * t57;
  t61 = t11 * t11;
  t62 = t61 * t53;
  t64 = t28 * t28;
  t65 = 0.1e1 / t64;
  r->dfdx = 0.78620370370370370370e-2 * t6 * r->x * t15 - 0.58227368100787713648e-6 * t37 * t38 + 0.58227368100787713648e-6 * t38 * t26 * t29 + 0.64697075667541904053e-8 * t50 * t58 - 0.56507106599077176585e-13 * t62 * t26 * t65;

  if(r->order < 2) return;

  t74 = 0.1e1 / t35 / t14;
  t75 = t10 * t74;
  t76 = t61 * t7;
  t84 = t38 * t49;
  t91 = 0.1e1 / t48 / t25;
  t92 = t12 * t91;
  t93 = t57 * t57;
  t94 = t29 * t93;
  t97 = t62 * t49;
  t98 = t65 * t57;
  t105 = 0.15425000000000000000e0 * t6 + 0.36104166666666666666e0 * t21 * t7 + 0.21788477962415971820e-4 * t11;
  t106 = t29 * t105;
  t109 = t61 * t61;
  t112 = 0.1e1 / t64 / t28;
  r->d2fdx2 = 0.78620370370370370370e-2 * t6 * t15 - 0.91557144915516384552e-8 * t6 * t12 * t36 + 0.67808527918892611904e-12 * t75 * t76 - 0.29113684050393856824e-5 * t37 * t11 + 0.29113684050393856824e-5 * t11 * t26 * t29 + 0.77636490801050284864e-7 * t84 * t58 - 0.96062081218431200195e-12 * t76 * t26 * t65 - 0.60383937289705777116e-8 * t92 * t94 - 0.75342808798769568780e-14 * t97 * t98 + 0.64697075667541904053e-8 * t50 * t106 + 0.65805201925098346010e-19 * t109 * t26 * t112;

  if(r->order < 3) return;

  t118 = t25 * t25;
  t135 = t61 * r->x;
  t169 = t35 * t35;
  t173 = t61 * t11 * t53;
  t184 = t64 * t64;
  r->d3fdx3 = -0.10869108712147039881e-6 * t38 * t91 * t94 + 0.11674227876009783576e-7 * t12 / t48 / t118 * t29 * t93 * t57 - 0.18115181186911733135e-7 * t92 * t58 * t105 - 0.82401430423964746097e-7 * t6 * t36 * t38 + 0.15993394737758810213e-13 * t6 * t62 * t74 + 0.10171279187833891786e-10 * t75 * t135 - 0.11645473620157542730e-4 * t37 * t53 + 0.11645473620157542730e-4 * t53 * t26 * t29 + 0.58227368100787713648e-6 * t11 * t49 * t58 + 0.11645473620157542730e-6 * t84 * t106 - 0.19212416243686240039e-12 * t76 * t49 * t98 + 0.10547993231827739629e-13 * t62 * t91 * t65 * t93 - 0.11301421319815435317e-13 * t97 * t65 * t105 + 0.13161040385019669202e-19 * t109 * t49 * t112 * t57 + 0.64697075667541904053e-8 * t50 * t29 * (0.72208333333333333332e0 * t21 * r->x + 0.87153911849663887280e-4 * t53) - 0.11844936346517702282e-17 * t10 / t169 * t173 - 0.11301421319815435317e-10 * t135 * t26 * t65 + 0.21715716635282454184e-17 * t173 * t26 * t112 - 0.11494991146318097032e-24 * t109 * t38 * t26 / t184;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_lv_rpw86_enhance)
