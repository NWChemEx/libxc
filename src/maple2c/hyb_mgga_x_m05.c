/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/hyb_mgga_x_m05.mpl
  Type of functional: work_mgga_x
*/

static void 
XC(hyb_mgga_x_m05_enhance)(const XC(func_type) *pt, XC(mgga_work_x_t) *r)
{
  double t1, t3, t7, t9, t10, t11, t12, t13;
  double t16, t17, t18, t19, t20, t23, t24, t25;
  double t26, t27, t30, t31, t32, t33, t34, t37;
  double t38, t39, t40, t41, t44, t45, t46, t48;
  double t51, t52, t53, t55, t58, t59, t60, t61;
  double t62, t65, t66, t67, t69, t72, t73, t74;
  double t76, t79, t81, t83, t86, t87, t89, t96;
  double t101, t106, t111, t116, t119, t122, t127, t132;
  double t137, t142, t146, t149, t150, t191, t235;

  mgga_x_m05_params *params;

  assert(pt->params != NULL);
  params = (mgga_x_m05_params * )(pt->params);

  t1 = r->x * r->x;
  t3 = 0.8040e0 + 0.36121864536509472266e-2 * t1;
  t7 = params->csi_HF * (0.180400e1 - 0.64641600e0 / t3);
  t9 = params->a[1];
  t10 = 0.45577998723455971374e1 - r->t;
  t11 = t9 * t10;
  t12 = 0.45577998723455971374e1 + r->t;
  t13 = 0.1e1 / t12;
  t16 = params->a[2];
  t17 = t10 * t10;
  t18 = t16 * t17;
  t19 = t12 * t12;
  t20 = 0.1e1 / t19;
  t23 = params->a[3];
  t24 = t17 * t10;
  t25 = t23 * t24;
  t26 = t19 * t12;
  t27 = 0.1e1 / t26;
  t30 = params->a[4];
  t31 = t17 * t17;
  t32 = t30 * t31;
  t33 = t19 * t19;
  t34 = 0.1e1 / t33;
  t37 = params->a[5];
  t38 = t31 * t10;
  t39 = t37 * t38;
  t40 = t33 * t12;
  t41 = 0.1e1 / t40;
  t44 = params->a[6];
  t45 = t31 * t17;
  t46 = t44 * t45;
  t48 = 0.1e1 / t33 / t19;
  t51 = params->a[7];
  t52 = t31 * t24;
  t53 = t51 * t52;
  t55 = 0.1e1 / t33 / t26;
  t58 = params->a[8];
  t59 = t31 * t31;
  t60 = t58 * t59;
  t61 = t33 * t33;
  t62 = 0.1e1 / t61;
  t65 = params->a[9];
  t66 = t59 * t10;
  t67 = t65 * t66;
  t69 = 0.1e1 / t61 / t12;
  t72 = params->a[10];
  t73 = t59 * t17;
  t74 = t72 * t73;
  t76 = 0.1e1 / t61 / t19;
  t79 = params->a[11];
  t81 = t79 * t59 * t24;
  t83 = 0.1e1 / t61 / t26;
  t86 = params->a[0] + 0.10e1 * t11 * t13 + 0.100e1 * t18 * t20 + 0.1000e1 * t25 * t27 + 0.10000e1 * t32 * t34 + 0.100000e1 * t39 * t41 + 0.1000000e1 * t46 * t48 + 0.10000000e1 * t53 * t55 + 0.100000000e1 * t60 * t62 + 0.1000000000e1 * t67 * t69 + 0.10000000000e1 * t74 * t76 + 0.100000000000e1 * t81 * t83;
  r->f = t7 * t86;

  if(r->order < 1) return;

  r->dfdrs = 0;
  t87 = t3 * t3;
  t89 = params->csi_HF / t87;
  r->dfdx = 0.46699502372464614049e-2 * t89 * r->x * t86;
  t96 = t16 * t10;
  t101 = t23 * t17;
  t106 = t30 * t24;
  t111 = t37 * t31;
  t116 = t44 * t38;
  t119 = -0.10e1 * t9 * t13 - 0.10e1 * t11 * t20 - 0.200e1 * t96 * t20 - 0.200e1 * t18 * t27 - 0.3000e1 * t101 * t27 - 0.3000e1 * t25 * t34 - 0.40000e1 * t106 * t34 - 0.40000e1 * t32 * t41 - 0.500000e1 * t111 * t41 - 0.500000e1 * t39 * t48 - 0.6000000e1 * t116 * t48;
  t122 = t51 * t45;
  t127 = t58 * t52;
  t132 = t65 * t59;
  t137 = t72 * t66;
  t142 = t79 * t73;
  t146 = 0.1e1 / t61 / t33;
  t149 = -0.6000000e1 * t46 * t55 - 0.70000000e1 * t122 * t55 - 0.70000000e1 * t53 * t62 - 0.800000000e1 * t127 * t62 - 0.800000000e1 * t60 * t69 - 0.9000000000e1 * t132 * t69 - 0.9000000000e1 * t67 * t76 - 0.100000000000e2 * t137 * t76 - 0.100000000000e2 * t74 * t83 - 0.1100000000000e2 * t142 * t83 - 0.1100000000000e2 * t81 * t146;
  t150 = t119 + t149;
  r->dfdt = t7 * t150;
  r->dfdu = 0;

  if(r->order < 2) return;

  r->d2fdrs2 = 0;
  r->d2fdx2 = -0.67474923944822780255e-4 * params->csi_HF / t87 / t3 * t1 * t86 + 0.46699502372464614049e-2 * t89 * t86;
  t191 = 0.20e1 * t11 * t27 + 0.800e1 * t96 * t27 + 0.600e1 * t18 * t34 + 0.18000e2 * t101 * t34 + 0.12000e2 * t25 * t41 + 0.320000e2 * t106 * t41 + 0.200000e2 * t32 * t48 + 0.5000000e2 * t111 * t48 + 0.3000000e2 * t39 * t55 + 0.72000000e2 * t116 * t55 + 0.42000000e2 * t46 * t62 + 0.980000000e2 * t122 * t62 + 0.560000000e2 * t53 * t69 + 0.12800000000e3 * t127 * t69 + 0.7200000000e2 * t60 * t76 + 0.162000000000e3 * t132 * t76;
  t235 = 0.90000000000e2 * t67 * t83 + 0.2000000000000e3 * t137 * t83 + 0.1100000000000e3 * t74 * t146 + 0.24200000000000e3 * t142 * t146 + 0.13200000000000e3 * t81 / t61 / t40 + 0.6000e1 * t23 * t10 * t27 + 0.120000e2 * t30 * t17 * t34 + 0.2000000e2 * t37 * t24 * t41 + 0.30000000e2 * t44 * t31 * t48 + 0.420000000e2 * t51 * t38 * t55 + 0.5600000000e2 * t58 * t45 * t62 + 0.72000000000e2 * t65 * t52 * t69 + 0.900000000000e2 * t72 * t59 * t76 + 0.11000000000000e3 * t79 * t66 * t83 + 0.20e1 * t9 * t20 + 0.200e1 * t16 * t20;
  r->d2fdt2 = t7 * (t191 + t235);
  r->d2fdu2 = 0;
  r->d2fdrsx = 0;
  r->d2fdrst = 0;
  r->d2fdrsu = 0;
  r->d2fdxt = 0.46699502372464614049e-2 * t89 * r->x * t150;
  r->d2fdxu = 0;
  r->d2fdtu = 0;

  if(r->order < 3) return;


}

#define maple2c_order 3
#define maple2c_func  XC(hyb_mgga_x_m05_enhance)
