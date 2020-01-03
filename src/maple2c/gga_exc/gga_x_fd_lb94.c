/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/gga_exc/gga_x_fd_lb94.mpl
  Type of functional: gga_exc
*/

#define maple2c_order 3

DEVICE static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t5, t6, t7, t8, t9, t10;
  double t11, t12, t13, t14, t15, t16, t17, t18;
  double t19, t20, t21, t22, t26, t27, t28, t30;
  double t31, t32, t35, t37, t41, t42, t43, t45;
  double t46, t47, t49, t52, t56, t57, t59, t63;
  double t66, t67, t68, t75, t78, t79, t82, t85;
  double t86, t87, t88, t89, t92, t93, t94, t95;
  double t96, t101, t103, t108, t110, t111, t112, t116;
  double t117, t118, t121, t126, t134, t136, t140, t145;
  double t149, t150, t151, t155, t172, t186, t187, t192;
  double t193, t198, t204, t209, t210, t254, t257, t266;

  gga_x_fd_lb94_params *params;

  assert(p->params != NULL);
  params = (gga_x_fd_lb94_params * )(p->params);

  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = t1 * t3 * t6;
  t8 = M_CBRT2;
  t9 = t8 * t8;
  t10 = POW_1_3(rho[0]);
  t11 = t9 * t10;
  t12 = M_CBRT6;
  t13 = t12 * t12;
  t14 = M_PI * M_PI;
  t15 = POW_1_3(t14);
  t16 = 0.1e1 / t15;
  t17 = t13 * t16;
  t18 = sqrt(sigma[0]);
  t19 = t17 * t18;
  t20 = t10 * rho[0];
  t21 = 0.1e1 / t20;
  t22 = t8 * t21;
  t26 = t17 * t18 * t8 * t21 / 0.12e2;
  t27 = xc_integrate(func0, NULL, 0.0, t26);
  t28 = log(t26);
  t30 = xc_integrate(func1, NULL, 0.0, t26);
  t31 = t27 * t28 - t30;
  t32 = t22 * t31;
  t35 = 0.1e1 - t19 * t32 / 0.12e2;
  t37 = t7 * t11 * t35;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.16e2 * t37;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t41 = t20 * t1 * t3;
  t42 = t6 * t9;
  t43 = rho[0] * rho[0];
  t45 = 0.1e1 / t10 / t43;
  t46 = t8 * t45;
  t47 = t46 * t31;
  t49 = t46 * t27;
  t52 = t19 * t47 / 0.9e1 + t19 * t49 / 0.9e1;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t37 / 0.4e1 - 0.3e1 / 0.16e2 * t41 * t42 * t52;

  t56 = 0.1e1 / t18;
  t57 = t17 * t56;
  t59 = t22 * t27;
  t63 = t42 * (-t57 * t32 / 0.24e2 - t57 * t59 / 0.24e2);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.3e1 / 0.16e2 * t41 * t63;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t66 = t10 * t10;
  t67 = 0.1e1 / t66;
  t68 = t9 * t67;
  t75 = t43 * rho[0];
  t78 = t8 / t10 / t75;
  t79 = t78 * t31;
  t82 = t78 * t27;
  t85 = t15 * t15;
  t86 = 0.1e1 / t85;
  t87 = t12 * t86;
  t88 = t87 * sigma[0];
  t89 = t43 * t43;
  t92 = 0.1e1 / t66 / t89 * params->beta;
  t93 = params->beta * t9;
  t94 = t93 * t13;
  t95 = t16 * t18;
  t96 = t9 * t13;
  t101 = t86 * sigma[0];
  t103 = 0.1e1 / t66 / t43;
  t108 = sqrt(0.3e1 * t8 * t12 * t101 * t103 + 0.36e2);
  t110 = t96 * t95 * t21 / 0.12e2 + t108 / 0.6e1;
  t111 = log(t110);
  t112 = t21 * t111;
  t116 = 0.1e1 + t94 * t95 * t112 / 0.4e1;
  t117 = 0.1e1 / t116;
  t118 = t92 * t117;
  t121 = -0.7e1 / 0.27e2 * t19 * t79 - 0.11e2 / 0.27e2 * t19 * t82 + t88 * t118 / 0.9e1;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t7 * t68 * t35 / 0.12e2 - t7 * t11 * t52 / 0.2e1 - 0.3e1 / 0.16e2 * t41 * t42 * t121;

  t126 = t10 * t1 * t3;
  t134 = 0.1e1 / t66 / t75;
  t136 = t134 * params->beta * t117;
  t140 = t42 * (t57 * t47 / 0.18e2 + t57 * t49 / 0.9e1 - t87 * t136 / 0.24e2);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t126 * t63 / 0.4e1 - 0.3e1 / 0.16e2 * t41 * t140;

  t145 = t17 / t18 / sigma[0];
  t149 = t87 / sigma[0];
  t150 = t103 * params->beta;
  t151 = t150 * t117;
  t155 = t42 * (t145 * t32 / 0.48e2 + t149 * t151 / 0.64e2);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.3e1 / 0.16e2 * t41 * t155;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t172 = t8 / t10 / t89;
  t186 = t116 * t116;
  t187 = 0.1e1 / t186;
  t192 = t93 * t17;
  t193 = t18 * t21;
  t198 = 0.1e1 / t108 * t8;
  t204 = 0.1e1 / t110;
  t209 = -t94 * t95 * t45 * t111 / 0.3e1 + t192 * t193 * (-t96 * t95 * t45 / 0.9e1 - 0.2e1 / 0.3e1 * t198 * t12 * t101 * t134) * t204 / 0.4e1;
  t210 = t187 * t209;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t7 * t9 / t66 / rho[0] * t35 / 0.18e2 - t7 * t68 * t52 / 0.4e1 - 0.3e1 / 0.4e1 * t7 * t11 * t121 - 0.3e1 / 0.16e2 * t41 * t42 * (0.70e2 / 0.81e2 * t19 * t172 * t31 + 0.46e2 / 0.27e2 * t19 * t172 * t27 - 0.25e2 / 0.27e2 * t88 / t66 / t89 / rho[0] * params->beta * t117 - t88 * t92 * t210 / 0.9e1);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -t67 * t1 * t3 * t63 / 0.12e2 - t126 * t140 / 0.2e1 - 0.3e1 / 0.16e2 * t41 * t42 * (-0.7e1 / 0.54e2 * t57 * t79 - t57 * t82 / 0.3e1 + 0.19e2 / 0.72e2 * t87 * t118 + t87 * t134 * params->beta * t187 * t209 / 0.24e2);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t126 * t155 / 0.4e1 - 0.3e1 / 0.16e2 * t41 * t42 * (-t145 * t47 / 0.36e2 - t145 * t49 / 0.36e2 - t149 * t136 / 0.24e2 - t149 * t150 * t210 / 0.64e2);

  t254 = sigma[0] * sigma[0];
  t257 = t17 / t18 / t254;
  t266 = t16 * t56;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.3e1 / 0.16e2 * t41 * t42 * (-t257 * t32 / 0.32e2 + t257 * t59 / 0.96e2 - t87 / t254 * t151 / 0.64e2 - t149 * t150 * t187 * (t94 * t266 * t112 / 0.8e1 + t192 * t193 * (t96 * t266 * t21 / 0.24e2 + t198 * t87 * t103 / 0.4e1) * t204 / 0.4e1) / 0.64e2);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


DEVICE static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t4, t5, t6, t7, t8, t9;
  double t10, t11, t12, t13, t14, t15, t16, t17;
  double t18, t20, t21, t22, t24, t25, t29, t31;
  double t34, t35, t36, t38, t39, t45, t49, t50;
  double t57, t60, t61, t62, t68, t70, t71, t78;
  double t79, t80, t81, t82, t84, t86, t87, t88;
  double t89, t90, t93, t95, t97, t102, t104, t105;
  double t106, t110, t111, t112, t116, t120, t123, t131;
  double t132, t133, t137, t141, t146, t147, t149, t153;
  double t170, t186, t187, t192, t197, t203, t210, t221;
  double t239, t251, t258, t261, t272;

  gga_x_fd_lb94_params *params;

  assert(p->params != NULL);
  params = (gga_x_fd_lb94_params * )(p->params);

  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = POW_1_3(rho[0]);
  t8 = t6 * t7;
  t9 = M_CBRT6;
  t10 = t9 * t9;
  t11 = M_PI * M_PI;
  t12 = POW_1_3(t11);
  t13 = 0.1e1 / t12;
  t14 = t10 * t13;
  t15 = sqrt(sigma[0]);
  t16 = t7 * rho[0];
  t17 = 0.1e1 / t16;
  t18 = t15 * t17;
  t20 = t14 * t18 / 0.12e2;
  t21 = xc_integrate(func0, NULL, 0.0, t20);
  t22 = log(t20);
  t24 = xc_integrate(func1, NULL, 0.0, t20);
  t25 = t21 * t22 - t24;
  t29 = 0.1e1 - t14 * t18 * t25 / 0.12e2;
  t31 = t4 * t8 * t29;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.8e1 * t31;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t34 = t16 * t1;
  t35 = t3 * t6;
  t36 = rho[0] * rho[0];
  t38 = 0.1e1 / t7 / t36;
  t39 = t15 * t38;
  t45 = t14 * t39 * t21 / 0.9e1 + t14 * t39 * t25 / 0.9e1;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t31 / 0.2e1 - 0.3e1 / 0.8e1 * t34 * t35 * t45;

  t49 = 0.1e1 / t15;
  t50 = t49 * t17;
  t57 = t35 * (-t14 * t50 * t21 / 0.24e2 - t14 * t50 * t25 / 0.24e2);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.3e1 / 0.8e1 * t34 * t57;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t60 = t7 * t7;
  t61 = 0.1e1 / t60;
  t62 = t6 * t61;
  t68 = t36 * rho[0];
  t70 = 0.1e1 / t7 / t68;
  t71 = t15 * t70;
  t78 = t12 * t12;
  t79 = 0.1e1 / t78;
  t80 = t9 * t79;
  t81 = t80 * sigma[0];
  t82 = t36 * t36;
  t84 = 0.1e1 / t60 / t82;
  t86 = M_CBRT2;
  t87 = params->beta * t86;
  t88 = t87 * t10;
  t89 = t13 * t15;
  t90 = t86 * t10;
  t93 = t86 * t86;
  t95 = t79 * sigma[0];
  t97 = 0.1e1 / t60 / t36;
  t102 = sqrt(0.6e1 * t93 * t9 * t95 * t97 + 0.144e3);
  t104 = t90 * t89 * t17 / 0.12e2 + t102 / 0.12e2;
  t105 = log(t104);
  t106 = t17 * t105;
  t110 = 0.1e1 + t88 * t89 * t106 / 0.4e1;
  t111 = 0.1e1 / t110;
  t112 = t86 * t111;
  t116 = -0.7e1 / 0.27e2 * t14 * t71 * t25 - 0.11e2 / 0.27e2 * t14 * t71 * t21 + t81 * t84 * params->beta * t112 / 0.18e2;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t4 * t62 * t29 / 0.6e1 - t4 * t8 * t45 - 0.3e1 / 0.8e1 * t34 * t35 * t116;

  t120 = t7 * t1;
  t123 = t49 * t38;
  t131 = 0.1e1 / t60 / t68;
  t132 = t80 * t131;
  t133 = t87 * t111;
  t137 = t35 * (t14 * t123 * t25 / 0.18e2 + t14 * t123 * t21 / 0.9e1 - t132 * t133 / 0.48e2);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t120 * t57 / 0.2e1 - 0.3e1 / 0.8e1 * t34 * t137;

  t141 = 0.1e1 / t15 / sigma[0];
  t146 = 0.1e1 / sigma[0];
  t147 = t80 * t146;
  t149 = t97 * params->beta * t112;
  t153 = t35 * (t14 * t141 * t17 * t25 / 0.48e2 + t147 * t149 / 0.128e3);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.3e1 / 0.8e1 * t34 * t153;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t170 = t15 / t7 / t82;
  t186 = t110 * t110;
  t187 = 0.1e1 / t186;
  t192 = t87 * t14;
  t197 = 0.1e1 / t102 * t93;
  t203 = 0.1e1 / t104;
  t210 = t87 * t187 * (-t88 * t89 * t38 * t105 / 0.3e1 + t192 * t18 * (-t90 * t89 * t38 / 0.9e1 - 0.2e1 / 0.3e1 * t197 * t9 * t95 * t131) * t203 / 0.4e1);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t4 * t6 / t60 / rho[0] * t29 / 0.9e1 - t4 * t62 * t45 / 0.2e1 - 0.3e1 / 0.2e1 * t4 * t8 * t116 - 0.3e1 / 0.8e1 * t34 * t35 * (0.70e2 / 0.81e2 * t14 * t170 * t25 + 0.46e2 / 0.27e2 * t14 * t170 * t21 - 0.25e2 / 0.54e2 * t81 / t60 / t82 / rho[0] * params->beta * t112 - t80 * sigma[0] * t84 * t210 / 0.18e2);

  t221 = t49 * t70;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -t61 * t1 * t57 / 0.6e1 - t120 * t137 - 0.3e1 / 0.8e1 * t34 * t35 * (-0.7e1 / 0.54e2 * t14 * t221 * t25 - t14 * t221 * t21 / 0.3e1 + 0.19e2 / 0.144e3 * t80 * t84 * t133 + t132 * t210 / 0.48e2);

  t239 = t141 * t38;
  t251 = t80 * t146 * t97;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t120 * t153 / 0.2e1 - 0.3e1 / 0.8e1 * t34 * t35 * (-t14 * t239 * t25 / 0.36e2 - t14 * t239 * t21 / 0.36e2 - t147 * t131 * params->beta * t112 / 0.48e2 - t251 * t210 / 0.128e3);

  t258 = sigma[0] * sigma[0];
  t261 = 0.1e1 / t15 / t258 * t17;
  t272 = t13 * t49;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.3e1 / 0.8e1 * t34 * t35 * (-t14 * t261 * t25 / 0.32e2 + t14 * t261 * t21 / 0.96e2 - t80 / t258 * t149 / 0.128e3 - t251 * t87 * t187 * (t88 * t272 * t106 / 0.8e1 + t192 * t18 * (t90 * t272 * t17 / 0.24e2 + t197 * t80 * t97 / 0.4e1) * t203 / 0.4e1) / 0.128e3);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


DEVICE static inline void
func_pol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t4, t5, t6, t7, t8, t9;
  double t10, t11, t13, t14, t15, t16, t17, t18;
  double t19, t20, t21, t22, t23, t24, t25, t27;
  double t28, t30, t31, t32, t34, t35, t39, t41;
  double t43, t44, t45, t46, t47, t48, t50, t51;
  double t53, t54, t55, t57, t58, t62, t64, t66;
  double t67, t68, t69, t70, t71, t73, t74, t76;
  double t77, t78, t79, t80, t82, t83, t84, t86;
  double t87, t93, t95, t96, t97, t98, t99, t101;
  double t102, t103, t105, t106, t110, t111, t113, t114;
  double t115, t116, t118, t119, t120, t122, t123, t129;
  double t131, t132, t136, t137, t138, t139, t140, t146;
  double t150, t151, t152, t158, t162, t164, t165, t166;
  double t167, t168, t169, t171, t172, t173, t175, t176;
  double t177, t179, t180, t181, t182, t183, t184, t186;
  double t187, t189, t190, t192, t193, t195, t196, t197;
  double t199, t200, t207, t208, t209, t210, t211, t212;
  double t214, t216, t217, t218, t219, t220, t223, t224;
  double t225, t227, t232, t234, t235, t236, t240, t241;
  double t242, t246, t248, t249, t250, t251, t252, t253;
  double t254, t256, t257, t258, t260, t261, t262, t263;
  double t265, t266, t267, t269, t270, t271, t273, t274;
  double t275, t276, t278, t281, t283, t285, t288, t289;
  double t290, t292, t296, t297, t298, t299, t301, t304;
  double t306, t307, t309, t312, t314, t317, t319, t322;
  double t323, t325, t326, t327, t328, t329, t331, t332;
  double t333, t334, t336, t337, t338, t339, t341, t342;
  double t343, t345, t346, t347, t348, t350, t351, t358;
  double t359, t360, t362, t364, t367, t369, t374, t376;
  double t377, t378, t382, t383, t384, t388, t390, t391;
  double t392, t395, t397, t398, t402, t410, t411, t412;
  double t415, t420, t421, t422, t427, t432, t435, t443;
  double t444, t445, t448, t449, t453, t458, t459, t461;
  double t464, t465, t469, t474, t475, t477, t480, t481;
  double t486, t488, t498, t500, t510, t512, t514, t522;
  double t524, t534, t537, t540, t544, t560, t561, t566;
  double t571, t577, t584, t592, t593, t599, t601, t607;
  double t609, t612, t613, t619, t621, t627, t629, t631;
  double t638, t639, t649, t660, t665, t667, t670, t677;
  double t681, t687, t695, t708, t714, t722, t723, t729;
  double t737, t738, t741, t749, t766, t771, t785, t788;
  double t791, t794, t797, t827, t830, t841, t865, t881;
  double t882, t891, t897, t904, t936, t940, t944, t946;
  double t958, t975, t979, t991, t992, t995, t1005, t1011;
  double t1021, t1048, t1064, t1070, t1082, t1089, t1103, t1115;
  double t1122, t1125, t1136, t1160, t1163, t1174;

  gga_x_fd_lb94_params *params;

  assert(p->params != NULL);
  params = (gga_x_fd_lb94_params * )(p->params);

  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = t4 * t6;
  t8 = rho[0] - rho[1];
  t9 = rho[0] + rho[1];
  t10 = 0.1e1 / t9;
  t11 = t8 * t10;
  t13 = 0.1e1 / 0.2e1 + t11 / 0.2e1;
  t14 = POW_1_3(t13);
  t15 = t14 * t13;
  t16 = POW_1_3(t9);
  t17 = t15 * t16;
  t18 = M_CBRT6;
  t19 = t18 * t18;
  t20 = M_PI * M_PI;
  t21 = POW_1_3(t20);
  t22 = 0.1e1 / t21;
  t23 = t19 * t22;
  t24 = sqrt(sigma[0]);
  t25 = POW_1_3(rho[0]);
  t27 = 0.1e1 / t25 / rho[0];
  t28 = t24 * t27;
  t30 = t23 * t28 / 0.12e2;
  t31 = xc_integrate(func0, NULL, 0.0, t30);
  t32 = log(t30);
  t34 = xc_integrate(func1, NULL, 0.0, t30);
  t35 = t31 * t32 - t34;
  t39 = 0.1e1 - t23 * t28 * t35 / 0.12e2;
  t41 = t7 * t17 * t39;
  t43 = 0.1e1 / 0.2e1 - t11 / 0.2e1;
  t44 = POW_1_3(t43);
  t45 = t44 * t43;
  t46 = t45 * t16;
  t47 = sqrt(sigma[2]);
  t48 = POW_1_3(rho[1]);
  t50 = 0.1e1 / t48 / rho[1];
  t51 = t47 * t50;
  t53 = t23 * t51 / 0.12e2;
  t54 = xc_integrate(func0, NULL, 0.0, t53);
  t55 = log(t53);
  t57 = xc_integrate(func1, NULL, 0.0, t53);
  t58 = t54 * t55 - t57;
  t62 = 0.1e1 - t23 * t51 * t58 / 0.12e2;
  t64 = t7 * t46 * t62;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.8e1 * t41 - 0.3e1 / 0.8e1 * t64;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t66 = 0.3e1 / 0.8e1 * t41;
  t67 = 0.3e1 / 0.8e1 * t64;
  t68 = t14 * t16;
  t69 = t9 * t9;
  t70 = 0.1e1 / t69;
  t71 = t8 * t70;
  t73 = t10 / 0.2e1 - t71 / 0.2e1;
  t74 = t39 * t73;
  t76 = t7 * t68 * t74;
  t77 = t76 / 0.2e1;
  t78 = t16 * t16;
  t79 = 0.1e1 / t78;
  t80 = t15 * t79;
  t82 = t7 * t80 * t39;
  t83 = t82 / 0.8e1;
  t84 = rho[0] * rho[0];
  t86 = 0.1e1 / t25 / t84;
  t87 = t24 * t86;
  t93 = t23 * t87 * t31 / 0.9e1 + t23 * t87 * t35 / 0.9e1;
  t95 = t7 * t17 * t93;
  t96 = 0.3e1 / 0.8e1 * t95;
  t97 = t44 * t16;
  t98 = -t73;
  t99 = t62 * t98;
  t101 = t7 * t97 * t99;
  t102 = t101 / 0.2e1;
  t103 = t45 * t79;
  t105 = t7 * t103 * t62;
  t106 = t105 / 0.8e1;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t66 - t67 + t9 * (-t77 - t83 - t96 - t102 - t106);

  t110 = -t10 / 0.2e1 - t71 / 0.2e1;
  t111 = t39 * t110;
  t113 = t7 * t68 * t111;
  t114 = t113 / 0.2e1;
  t115 = -t110;
  t116 = t62 * t115;
  t118 = t7 * t97 * t116;
  t119 = t118 / 0.2e1;
  t120 = rho[1] * rho[1];
  t122 = 0.1e1 / t48 / t120;
  t123 = t47 * t122;
  t129 = t23 * t123 * t54 / 0.9e1 + t23 * t123 * t58 / 0.9e1;
  t131 = t7 * t46 * t129;
  t132 = 0.3e1 / 0.8e1 * t131;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = -t66 - t67 + t9 * (-t114 - t83 - t119 - t106 - t132);

  t136 = t16 * t9 * t1;
  t137 = t136 * t3;
  t138 = t6 * t15;
  t139 = 0.1e1 / t24;
  t140 = t139 * t27;
  t146 = -t23 * t140 * t31 / 0.24e2 - t23 * t140 * t35 / 0.24e2;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.3e1 / 0.8e1 * t137 * t138 * t146;

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[1] = 0.0e0;

  t150 = t6 * t45;
  t151 = 0.1e1 / t47;
  t152 = t151 * t50;
  t158 = -t23 * t152 * t54 / 0.24e2 - t23 * t152 * t58 / 0.24e2;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[2] = -0.3e1 / 0.8e1 * t137 * t150 * t158;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t162 = t82 / 0.4e1;
  t164 = t105 / 0.4e1;
  t165 = t14 * t14;
  t166 = 0.1e1 / t165;
  t167 = t166 * t16;
  t168 = t73 * t73;
  t169 = t39 * t168;
  t171 = t7 * t167 * t169;
  t172 = t171 / 0.6e1;
  t173 = t14 * t79;
  t175 = t7 * t173 * t74;
  t176 = t175 / 0.3e1;
  t177 = t93 * t73;
  t179 = t7 * t68 * t177;
  t180 = t69 * t9;
  t181 = 0.1e1 / t180;
  t182 = t8 * t181;
  t183 = -t70 + t182;
  t184 = t39 * t183;
  t186 = t7 * t68 * t184;
  t187 = t186 / 0.2e1;
  t189 = 0.1e1 / t78 / t9;
  t190 = t15 * t189;
  t192 = t7 * t190 * t39;
  t193 = t192 / 0.12e2;
  t195 = t7 * t80 * t93;
  t196 = t195 / 0.4e1;
  t197 = t84 * rho[0];
  t199 = 0.1e1 / t25 / t197;
  t200 = t24 * t199;
  t207 = t21 * t21;
  t208 = 0.1e1 / t207;
  t209 = t18 * t208;
  t210 = t209 * sigma[0];
  t211 = t84 * t84;
  t212 = t25 * t25;
  t214 = 0.1e1 / t212 / t211;
  t216 = M_CBRT2;
  t217 = params->beta * t216;
  t218 = t217 * t19;
  t219 = t22 * t24;
  t220 = t216 * t19;
  t223 = t216 * t216;
  t224 = t223 * t18;
  t225 = t208 * sigma[0];
  t227 = 0.1e1 / t212 / t84;
  t232 = sqrt(0.6e1 * t224 * t225 * t227 + 0.144e3);
  t234 = t220 * t219 * t27 / 0.12e2 + t232 / 0.12e2;
  t235 = log(t234);
  t236 = t27 * t235;
  t240 = 0.1e1 + t218 * t219 * t236 / 0.4e1;
  t241 = 0.1e1 / t240;
  t242 = t216 * t241;
  t246 = -0.7e1 / 0.27e2 * t23 * t200 * t35 - 0.11e2 / 0.27e2 * t23 * t200 * t31 + t210 * t214 * params->beta * t242 / 0.18e2;
  t248 = t7 * t17 * t246;
  t249 = 0.3e1 / 0.8e1 * t248;
  t250 = t44 * t44;
  t251 = 0.1e1 / t250;
  t252 = t251 * t16;
  t253 = t98 * t98;
  t254 = t62 * t253;
  t256 = t7 * t252 * t254;
  t257 = t256 / 0.6e1;
  t258 = t44 * t79;
  t260 = t7 * t258 * t99;
  t261 = t260 / 0.3e1;
  t262 = -t183;
  t263 = t62 * t262;
  t265 = t7 * t97 * t263;
  t266 = t265 / 0.2e1;
  t267 = t45 * t189;
  t269 = t7 * t267 * t62;
  t270 = t269 / 0.12e2;
  t271 = -t172 - t176 - t179 - t187 + t193 - t196 - t249 - t257 - t261 - t266 + t270;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t76 - t162 - 0.3e1 / 0.4e1 * t95 - t101 - t164 + t9 * t271;

  t273 = t6 * t166;
  t274 = t4 * t273;
  t275 = t16 * t39;
  t276 = t110 * t73;
  t278 = t274 * t275 * t276;
  t281 = t7 * t173 * t111;
  t283 = t93 * t110;
  t285 = t7 * t68 * t283;
  t288 = 0.1e1 / t78 / t69;
  t289 = t14 * t288;
  t290 = t39 * t8;
  t292 = t7 * t289 * t290;
  t296 = t6 * t251;
  t297 = t4 * t296;
  t298 = t16 * t62;
  t299 = t115 * t98;
  t301 = t297 * t298 * t299;
  t304 = t7 * t258 * t116;
  t306 = t44 * t288;
  t307 = t62 * t8;
  t309 = t7 * t306 * t307;
  t312 = t129 * t98;
  t314 = t7 * t97 * t312;
  t317 = t7 * t103 * t129;
  t319 = -t278 / 0.6e1 - t281 / 0.6e1 - t285 / 0.2e1 - t292 / 0.2e1 - t175 / 0.6e1 + t193 - t195 / 0.8e1 - t301 / 0.6e1 - t304 / 0.6e1 + t309 / 0.2e1 - t260 / 0.6e1 + t270 - t314 / 0.2e1 - t317 / 0.8e1;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = t9 * t319 - t102 - t114 - t119 - t132 - t162 - t164 - t77 - t96;

  t322 = t110 * t110;
  t323 = t39 * t322;
  t325 = t7 * t167 * t323;
  t326 = t325 / 0.6e1;
  t327 = t281 / 0.3e1;
  t328 = t70 + t182;
  t329 = t39 * t328;
  t331 = t7 * t68 * t329;
  t332 = t331 / 0.2e1;
  t333 = t115 * t115;
  t334 = t62 * t333;
  t336 = t7 * t252 * t334;
  t337 = t336 / 0.6e1;
  t338 = t304 / 0.3e1;
  t339 = t129 * t115;
  t341 = t7 * t97 * t339;
  t342 = -t328;
  t343 = t62 * t342;
  t345 = t7 * t97 * t343;
  t346 = t345 / 0.2e1;
  t347 = t317 / 0.4e1;
  t348 = t120 * rho[1];
  t350 = 0.1e1 / t48 / t348;
  t351 = t47 * t350;
  t358 = t209 * sigma[2];
  t359 = t120 * t120;
  t360 = t48 * t48;
  t362 = 0.1e1 / t360 / t359;
  t364 = t22 * t47;
  t367 = t208 * sigma[2];
  t369 = 0.1e1 / t360 / t120;
  t374 = sqrt(0.6e1 * t224 * t367 * t369 + 0.144e3);
  t376 = t220 * t364 * t50 / 0.12e2 + t374 / 0.12e2;
  t377 = log(t376);
  t378 = t50 * t377;
  t382 = 0.1e1 + t218 * t364 * t378 / 0.4e1;
  t383 = 0.1e1 / t382;
  t384 = t216 * t383;
  t388 = -0.7e1 / 0.27e2 * t23 * t351 * t58 - 0.11e2 / 0.27e2 * t23 * t351 * t54 + t358 * t362 * params->beta * t384 / 0.18e2;
  t390 = t7 * t46 * t388;
  t391 = 0.3e1 / 0.8e1 * t390;
  t392 = -t326 - t327 - t332 + t193 - t337 - t338 - t341 - t346 + t270 - t347 - t391;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = -t113 - t162 - t118 - t164 - 0.3e1 / 0.4e1 * t131 + t9 * t392;

  t395 = t7 * t17 * t146;
  t397 = t6 * t14;
  t398 = t146 * t73;
  t402 = t139 * t86;
  t410 = 0.1e1 / t212 / t197;
  t411 = t209 * t410;
  t412 = t217 * t241;
  t415 = t23 * t402 * t35 / 0.18e2 + t23 * t402 * t31 / 0.9e1 - t411 * t412 / 0.48e2;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t395 / 0.2e1 - t137 * t397 * t398 / 0.2e1 - 0.3e1 / 0.8e1 * t137 * t138 * t415;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[1] = 0.0e0;

  t420 = t7 * t46 * t158;
  t421 = t6 * t44;
  t422 = t158 * t98;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[2] = -t137 * t421 * t422 / 0.2e1 - t420 / 0.2e1;

  t427 = t397 * t146 * t110;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[3] = -t137 * t427 / 0.2e1 - t395 / 0.2e1;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[4] = 0.0e0;

  t432 = t421 * t158 * t115;
  t435 = t151 * t122;
  t443 = 0.1e1 / t360 / t348;
  t444 = t209 * t443;
  t445 = t217 * t383;
  t448 = t23 * t435 * t58 / 0.18e2 + t23 * t435 * t54 / 0.9e1 - t444 * t445 / 0.48e2;
  t449 = t150 * t448;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[5] = -t420 / 0.2e1 - t137 * t432 / 0.2e1 - 0.3e1 / 0.8e1 * t137 * t449;

  t453 = 0.1e1 / t24 / sigma[0];
  t458 = 0.1e1 / sigma[0];
  t459 = t209 * t458;
  t461 = t227 * params->beta * t242;
  t464 = t23 * t453 * t27 * t35 / 0.48e2 + t459 * t461 / 0.128e3;
  t465 = t138 * t464;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.3e1 / 0.8e1 * t137 * t465;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[1] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[2] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[3] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[4] = 0.0e0;

  t469 = 0.1e1 / t47 / sigma[2];
  t474 = 0.1e1 / sigma[2];
  t475 = t209 * t474;
  t477 = t369 * params->beta * t384;
  t480 = t23 * t469 * t50 * t58 / 0.48e2 + t475 * t477 / 0.128e3;
  t481 = t150 * t480;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[5] = -0.3e1 / 0.8e1 * t137 * t481;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t486 = t192 / 0.4e1;
  t488 = t269 / 0.4e1;
  t498 = t7 * t173 * t177;
  t500 = t7 * t173 * t184;
  t510 = t69 * t69;
  t512 = t8 / t510;
  t514 = 0.3e1 * t181 - 0.3e1 * t512;
  t522 = 0.5e1 / 0.36e2 * t7 * t15 * t288 * t39;
  t524 = t7 * t258 * t263;
  t534 = 0.5e1 / 0.36e2 * t7 * t45 * t288 * t62;
  t537 = t7 * t190 * t93;
  t540 = t7 * t80 * t246;
  t544 = t24 / t25 / t211;
  t560 = t240 * t240;
  t561 = 0.1e1 / t560;
  t566 = t217 * t23;
  t571 = 0.1e1 / t232 * t223;
  t577 = 0.1e1 / t234;
  t584 = t217 * t561 * (-t218 * t219 * t86 * t235 / 0.3e1 + t566 * t28 * (-t220 * t219 * t86 / 0.9e1 - 0.2e1 / 0.3e1 * t571 * t18 * t225 * t410) * t577 / 0.4e1);
  t592 = 0.1e1 / t165 / t13;
  t593 = t592 * t16;
  t599 = t166 * t79;
  t601 = t7 * t599 * t169;
  t607 = t14 * t189;
  t609 = t7 * t607 * t74;
  t612 = 0.1e1 / t250 / t43;
  t613 = t612 * t16;
  t619 = t251 * t79;
  t621 = t7 * t619 * t254;
  t627 = t44 * t189;
  t629 = t7 * t627 * t99;
  t631 = t537 / 0.4e1 - 0.3e1 / 0.8e1 * t540 - 0.3e1 / 0.8e1 * t7 * t17 * (0.70e2 / 0.81e2 * t23 * t544 * t35 + 0.46e2 / 0.27e2 * t23 * t544 * t31 - 0.25e2 / 0.54e2 * t210 / t212 / t211 / rho[0] * params->beta * t242 - t209 * sigma[0] * t214 * t584 / 0.18e2) + t7 * t593 * t39 * t168 * t73 / 0.9e1 - t601 / 0.6e1 - t274 * t275 * t73 * t183 / 0.2e1 + t609 / 0.3e1 + t7 * t613 * t62 * t253 * t98 / 0.9e1 - t621 / 0.6e1 - t297 * t298 * t98 * t262 / 0.2e1 + t629 / 0.3e1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.3e1 * t179 - 0.3e1 / 0.2e1 * t186 + t486 - 0.3e1 / 0.2e1 * t265 + t488 - 0.3e1 / 0.4e1 * t195 - 0.9e1 / 0.8e1 * t248 - t171 / 0.2e1 - t175 - t256 / 0.2e1 - t260 + t9 * (-t7 * t167 * t93 * t168 / 0.2e1 - t498 - t500 / 0.2e1 - 0.3e1 / 0.2e1 * t7 * t68 * t246 * t73 - 0.3e1 / 0.2e1 * t7 * t68 * t93 * t183 - t7 * t68 * t39 * t514 / 0.2e1 - t522 - t524 / 0.2e1 + t7 * t97 * t62 * t514 / 0.2e1 - t534 + t631);

  t638 = t278 / 0.3e1;
  t639 = t301 / 0.3e1;
  t649 = t7 * t267 * t129;
  t660 = t7 * t173 * t283 / 0.3e1;
  t665 = -t522 - t534 + t537 / 0.6e1 - t540 / 0.8e1 - t7 * t289 * t39 / 0.2e1 + t7 * t306 * t62 / 0.2e1 + t649 / 0.12e2 - t498 / 0.3e1 - t500 / 0.6e1 - t524 / 0.6e1 - t601 / 0.18e2 + 0.2e1 / 0.9e1 * t609 - t621 / 0.18e2 + 0.2e1 / 0.9e1 * t629 - t660 - t7 * t68 * t246 * t110 / 0.2e1;
  t667 = 0.1e1 / t78 / t180;
  t670 = t7 * t44 * t667 * t307;
  t677 = t7 * t607 * t111;
  t681 = t7 * t14 * t667 * t290;
  t687 = t7 * t627 * t116;
  t695 = t7 * t258 * t312 / 0.3e1;
  t708 = t288 * t62;
  t714 = t4 * t6 * t592;
  t722 = t274 * t79 * t39 * t276 / 0.9e1;
  t723 = t288 * t39;
  t729 = t4 * t6 * t612;
  t737 = t297 * t79 * t62 * t299 / 0.9e1;
  t738 = -0.7e1 / 0.6e1 * t670 - t7 * t97 * t129 * t262 / 0.2e1 + t677 / 0.9e1 + 0.7e1 / 0.6e1 * t681 - t7 * t289 * t93 * t8 + t687 / 0.9e1 - t7 * t252 * t129 * t253 / 0.6e1 - t695 - t274 * t16 * t93 * t276 / 0.3e1 - t274 * t275 * t110 * t183 / 0.6e1 - t297 * t298 * t115 * t262 / 0.6e1 + t297 * t708 * t8 * t98 / 0.3e1 + t714 * t275 * t110 * t168 / 0.9e1 - t722 - t274 * t723 * t8 * t73 / 0.3e1 + t729 * t298 * t115 * t253 / 0.9e1 - t737;
  t741 = -t249 - t172 - 0.2e1 / 0.3e1 * t175 - t257 - 0.2e1 / 0.3e1 * t260 - t638 - t327 - t292 - t639 - t338 + t9 * (t665 + t738);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = -t179 - t187 + t486 - t266 + t488 - t285 + t309 - t314 - t347 - t195 / 0.2e1 + t741;

  t749 = t7 * t103 * t388;
  t766 = -t181 - 0.3e1 * t512;
  t771 = -t522 - t534 + t537 / 0.12e2 + t649 / 0.6e1 - t749 / 0.8e1 + t609 / 0.9e1 + t629 / 0.9e1 - t660 + t670 / 0.3e1 + 0.2e1 / 0.9e1 * t677 - t681 / 0.3e1 + 0.2e1 / 0.9e1 * t687 - t695 - t7 * t167 * t93 * t322 / 0.6e1 - t7 * t68 * t93 * t328 / 0.2e1 - t7 * t68 * t39 * t766 / 0.2e1;
  t785 = t7 * t599 * t323;
  t788 = t7 * t173 * t329;
  t791 = t7 * t619 * t334;
  t794 = t7 * t258 * t339;
  t797 = t7 * t258 * t343;
  t827 = t7 * t306 * t129 * t8 + t7 * t97 * t62 * t766 / 0.2e1 - t7 * t97 * t388 * t98 / 0.2e1 - t785 / 0.18e2 - t788 / 0.6e1 - t791 / 0.18e2 - t794 / 0.3e1 - t797 / 0.6e1 - t722 - t737 + t714 * t275 * t322 * t73 / 0.9e1 - t274 * t275 * t328 * t73 / 0.6e1 + t729 * t298 * t333 * t98 / 0.9e1 + t297 * t708 * t115 * t8 / 0.3e1 - t297 * t16 * t129 * t299 / 0.3e1 - t297 * t298 * t342 * t98 / 0.6e1 - t274 * t723 * t110 * t8 / 0.3e1;
  t830 = -t391 - t176 - t261 - t638 - 0.2e1 / 0.3e1 * t281 - t292 - t639 - 0.2e1 / 0.3e1 * t304 - t326 - t337 + t9 * (t771 + t827);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = t486 + t488 - t285 + t309 - t314 - t317 / 0.2e1 - t332 - t341 - t346 - t196 + t830;

  t841 = -0.3e1 * t181 - 0.3e1 * t512;
  t865 = t47 / t48 / t359;
  t881 = t382 * t382;
  t882 = 0.1e1 / t881;
  t891 = 0.1e1 / t374 * t223;
  t897 = 0.1e1 / t376;
  t904 = t217 * t882 * (-t218 * t364 * t122 * t377 / 0.3e1 + t566 * t51 * (-t220 * t364 * t122 / 0.9e1 - 0.2e1 / 0.3e1 * t891 * t18 * t367 * t443) * t897 / 0.4e1);
  t936 = t677 / 0.3e1 + t687 / 0.3e1 - t785 / 0.6e1 - t788 / 0.2e1 - t791 / 0.6e1 - t794 - t797 / 0.2e1 + t7 * t593 * t39 * t322 * t110 / 0.9e1 - t274 * t275 * t110 * t328 / 0.2e1 + t7 * t613 * t62 * t333 * t115 / 0.9e1 - t297 * t298 * t115 * t342 / 0.2e1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = t486 + t488 - 0.3e1 / 0.4e1 * t317 - 0.3e1 / 0.2e1 * t331 - 0.3e1 * t341 - 0.3e1 / 0.2e1 * t345 - 0.9e1 / 0.8e1 * t390 - t281 - t304 - t325 / 0.2e1 - t336 / 0.2e1 + t9 * (-t522 - t534 + t649 / 0.4e1 - 0.3e1 / 0.8e1 * t749 - t7 * t68 * t39 * t841 / 0.2e1 - t7 * t252 * t129 * t333 / 0.2e1 - 0.3e1 / 0.2e1 * t7 * t97 * t388 * t115 - 0.3e1 / 0.2e1 * t7 * t97 * t129 * t342 + t7 * t97 * t62 * t841 / 0.2e1 - 0.3e1 / 0.8e1 * t7 * t46 * (0.70e2 / 0.81e2 * t23 * t865 * t58 + 0.46e2 / 0.27e2 * t23 * t865 * t54 - 0.25e2 / 0.54e2 * t358 / t360 / t359 / rho[1] * params->beta * t384 - t209 * sigma[2] * t362 * t904 / 0.18e2) + t936);

  t940 = t7 * t68 * t398;
  t944 = t7 * t80 * t146 / 0.6e1;
  t946 = t7 * t17 * t415;
  t958 = t139 * t199;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.4e1 / 0.3e1 * t940 - t944 - t946 - t137 * t273 * t146 * t168 / 0.6e1 - t137 * t397 * t415 * t73 - t137 * t397 * t146 * t183 / 0.2e1 - 0.3e1 / 0.8e1 * t137 * t138 * (-0.7e1 / 0.54e2 * t23 * t958 * t35 - t23 * t958 * t31 / 0.3e1 + 0.19e2 / 0.144e3 * t209 * t214 * t412 + t411 * t584 / 0.48e2);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[1] = 0.0e0;

  t975 = t7 * t97 * t422;
  t979 = t7 * t103 * t158 / 0.6e1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[2] = -0.4e1 / 0.3e1 * t975 - t979 - t137 * t296 * t158 * t253 / 0.6e1 - t137 * t421 * t158 * t262 / 0.2e1;

  t991 = t16 * t1 * t3;
  t992 = t991 * t427;
  t995 = t136 * t3 * t6;
  t1005 = t189 * t1 * t3;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[3] = -0.2e1 / 0.3e1 * t940 - t944 - t946 / 0.2e1 - 0.2e1 / 0.3e1 * t992 - t995 * t166 * t146 * t276 / 0.6e1 - t137 * t397 * t415 * t110 / 0.2e1 - t1005 * t397 * t146 * t8 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[4] = 0.0e0;

  t1011 = t991 * t432;
  t1021 = t991 * t449;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[5] = -0.2e1 / 0.3e1 * t975 - t979 - 0.2e1 / 0.3e1 * t1011 - t995 * t251 * t158 * t299 / 0.6e1 + t1005 * t421 * t158 * t8 / 0.2e1 - t1021 / 0.2e1 - t137 * t421 * t448 * t98 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[6] = -0.4e1 / 0.3e1 * t992 - t944 - t137 * t273 * t146 * t322 / 0.6e1 - t137 * t397 * t146 * t328 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[7] = 0.0e0;

  t1048 = t151 * t350;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[8] = -0.4e1 / 0.3e1 * t1011 - t979 - t1021 - t137 * t296 * t158 * t333 / 0.6e1 - t137 * t421 * t448 * t115 - t137 * t421 * t158 * t342 / 0.2e1 - 0.3e1 / 0.8e1 * t137 * t150 * (-0.7e1 / 0.54e2 * t23 * t1048 * t58 - t23 * t1048 * t54 / 0.3e1 + 0.19e2 / 0.144e3 * t209 * t362 * t445 + t444 * t904 / 0.48e2);

  t1064 = t991 * t465;
  t1070 = t453 * t86;
  t1082 = t209 * t458 * t227;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t1064 / 0.2e1 - t137 * t397 * t464 * t73 / 0.2e1 - 0.3e1 / 0.8e1 * t137 * t138 * (-t23 * t1070 * t35 / 0.36e2 - t23 * t1070 * t31 / 0.36e2 - t459 * t410 * params->beta * t242 / 0.48e2 - t1082 * t584 / 0.128e3);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[1] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[2] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[3] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[4] = 0.0e0;

  t1089 = t991 * t481;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[5] = -t137 * t421 * t480 * t98 / 0.2e1 - t1089 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[6] = -t137 * t397 * t464 * t110 / 0.2e1 - t1064 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[8] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[9] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[10] = 0.0e0;

  t1103 = t469 * t122;
  t1115 = t209 * t474 * t369;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[11] = -t1089 / 0.2e1 - t137 * t421 * t480 * t115 / 0.2e1 - 0.3e1 / 0.8e1 * t137 * t150 * (-t23 * t1103 * t58 / 0.36e2 - t23 * t1103 * t54 / 0.36e2 - t475 * t443 * params->beta * t384 / 0.48e2 - t1115 * t904 / 0.128e3);

  t1122 = sigma[0] * sigma[0];
  t1125 = 0.1e1 / t24 / t1122 * t27;
  t1136 = t22 * t139;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.3e1 / 0.8e1 * t137 * t138 * (-t23 * t1125 * t35 / 0.32e2 + t23 * t1125 * t31 / 0.96e2 - t209 / t1122 * t461 / 0.128e3 - t1082 * t217 * t561 * (t218 * t1136 * t236 / 0.8e1 + t566 * t28 * (t220 * t1136 * t27 / 0.24e2 + t571 * t209 * t227 / 0.4e1) * t577 / 0.4e1) / 0.128e3);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[1] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[2] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[3] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[4] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[5] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[6] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[8] = 0.0e0;

  t1160 = sigma[2] * sigma[2];
  t1163 = 0.1e1 / t47 / t1160 * t50;
  t1174 = t22 * t151;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[9] = -0.3e1 / 0.8e1 * t137 * t150 * (-t23 * t1163 * t58 / 0.32e2 + t23 * t1163 * t54 / 0.96e2 - t209 / t1160 * t477 / 0.128e3 - t1115 * t217 * t882 * (t218 * t1174 * t378 / 0.8e1 + t566 * t51 * (t220 * t1174 * t50 / 0.24e2 + t891 * t209 * t369 / 0.4e1) * t897 / 0.4e1) / 0.128e3);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}

