/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/gga_exc/gga_x_pbe.mpl
  Type of functional: gga_exc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t4, t5, t6, t7, t8, t9;
  double t10, t12, t14, t15, t16, t17, t18, t20;
  double t21, t27, t32, t34, t40, t41, t42, t43;
  double t44, t46, t50, t57, t65, t66, t70, t73;
  double t74, t77, t78, t80, t81, t82, t83, t85;
  double t86, t87, t89, t96, t99, t108, t122, t129;
  double t135, t136, t137, t138, t139, t140;

  gga_x_pbe_params *params;

  assert(p->params != NULL);
  params = (gga_x_pbe_params * )(p->params);

  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = t4 * t6;
  t8 = M_CBRT2;
  t9 = t8 * t8;
  t10 = POW_1_3(rho[0]);
  t12 = M_CBRT6;
  t14 = M_PI * M_PI;
  t15 = POW_1_3(t14);
  t16 = t15 * t15;
  t17 = 0.1e1 / t16;
  t18 = params->mu * t12 * t17;
  t20 = rho[0] * rho[0];
  t21 = t10 * t10;
  t27 = params->kappa + t18 * sigma[0] * t9 / t21 / t20 / 0.24e2;
  t32 = 0.1e1 + params->kappa * (0.1e1 - params->kappa / t27);
  t34 = t7 * t9 * t10 * t32;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.16e2 * t34;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t40 = t3 * t6;
  t41 = t40 * t8;
  t42 = 0.1e1 / t10 / t20 * t1 * t41;
  t43 = params->kappa * params->kappa;
  t44 = t27 * t27;
  t46 = t43 / t44;
  t50 = t46 * params->mu * t12 * t17 * sigma[0];
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t34 / 0.4e1 + t42 * t50 / 0.24e2;

  t57 = t46 * t18;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.1e1 / t10 / rho[0] * t1 * t41 * t57 / 0.64e2;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t65 = t6 * t8;
  t66 = t20 * rho[0];
  t70 = t4 * t65 / t10 / t66;
  t73 = t20 * t20;
  t74 = t73 * t20;
  t77 = t40 * t43;
  t78 = 0.1e1 / t74 * t1 * t77;
  t80 = 0.1e1 / t44 / t27;
  t81 = params->mu * params->mu;
  t82 = t80 * t81;
  t83 = t12 * t12;
  t85 = 0.1e1 / t15 / t14;
  t86 = t83 * t85;
  t87 = sigma[0] * sigma[0];
  t89 = t82 * t86 * t87;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t7 * t9 / t21 * t32 / 0.12e2 - t70 * t50 / 0.24e2 + t78 * t89 / 0.54e2;

  t96 = 0.1e1 / t73 / rho[0] * t1;
  t99 = t82 * t86 * sigma[0];
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = t42 * t57 / 0.48e2 - t96 * t77 * t99 / 0.144e3;

  t108 = t43 * t80 * t81 * t83 * t85;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = 0.1e1 / t73 * t1 * t40 * t108 / 0.384e3;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t122 = t73 * t66;
  t129 = t73 * t73;
  t135 = t44 * t44;
  t136 = 0.1e1 / t135;
  t137 = t81 * params->mu;
  t138 = t136 * t137;
  t139 = t14 * t14;
  t140 = 0.1e1 / t139;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t7 * t9 / t21 / rho[0] * t32 / 0.18e2 + 0.17e2 / 0.108e3 * t4 * t65 / t10 / t73 * t50 - 0.7e1 / 0.54e2 * t4 * t6 / t122 * t43 * t89 + 0.1e1 / t21 / t129 / rho[0] * t1 * t77 * t138 * t140 * t87 * sigma[0] * t9 / 0.27e2;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.7e1 / 0.144e3 * t70 * t57 + 0.19e2 / 0.432e3 * t78 * t99 - 0.1e1 / t21 / t129 * t1 * t77 * t138 * t140 * t87 * t9 / 0.72e2;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t96 * t40 * t108 / 0.96e2 + 0.1e1 / t21 / t122 * t1 * t77 * t138 * t140 * sigma[0] * t9 / 0.192e3;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.1e1 / t21 / t74 * t1 * t40 * t43 * t136 * t137 * t140 * t9 / 0.512e3;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t4, t5, t6, t7, t9, t10;
  double t11, t12, t13, t14, t16, t17, t23, t28;
  double t30, t35, t36, t37, t38, t40, t41, t45;
  double t54, t62, t64, t70, t71, t74, t76, t77;
  double t78, t79, t81, t82, t83, t85, t93, t96;
  double t105, t120, t127, t133, t135, t137, t139;

  gga_x_pbe_params *params;

  assert(p->params != NULL);
  params = (gga_x_pbe_params * )(p->params);

  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = POW_1_3(rho[0]);
  t9 = M_CBRT6;
  t10 = params->mu * t9;
  t11 = M_PI * M_PI;
  t12 = POW_1_3(t11);
  t13 = t12 * t12;
  t14 = 0.1e1 / t13;
  t16 = rho[0] * rho[0];
  t17 = t7 * t7;
  t23 = params->kappa + t10 * t14 * sigma[0] / t17 / t16 / 0.24e2;
  t28 = 0.1e1 + params->kappa * (0.1e1 - params->kappa / t23);
  t30 = t4 * t6 * t7 * t28;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.8e1 * t30;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t35 = 0.1e1 / t7 / t16 * t1;
  t36 = t3 * t6;
  t37 = params->kappa * params->kappa;
  t38 = t36 * t37;
  t40 = t23 * t23;
  t41 = 0.1e1 / t40;
  t45 = t41 * params->mu * t9 * t14 * sigma[0];
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t30 / 0.2e1 + t35 * t38 * t45 / 0.24e2;

  t54 = t37 * t41 * t10 * t14;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.1e1 / t7 / rho[0] * t1 * t36 * t54 / 0.64e2;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t62 = t16 * rho[0];
  t64 = 0.1e1 / t7 / t62;
  t70 = t16 * t16;
  t71 = t70 * t16;
  t74 = 0.1e1 / t71 * t1 * t38;
  t76 = 0.1e1 / t40 / t23;
  t77 = params->mu * params->mu;
  t78 = t76 * t77;
  t79 = t9 * t9;
  t81 = 0.1e1 / t12 / t11;
  t82 = t79 * t81;
  t83 = sigma[0] * sigma[0];
  t85 = t78 * t82 * t83;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t4 * t6 / t17 * t28 / 0.6e1 - t4 * t6 * t64 * t37 * t45 / 0.24e2 + t74 * t85 / 0.108e3;

  t93 = 0.1e1 / t70 / rho[0] * t1;
  t96 = t78 * t82 * sigma[0];
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = t35 * t36 * t54 / 0.48e2 - t93 * t38 * t96 / 0.288e3;

  t105 = t37 * t76 * t77 * t79 * t81;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = 0.1e1 / t70 * t1 * t36 * t105 / 0.768e3;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t120 = t70 * t62;
  t127 = t70 * t70;
  t133 = t40 * t40;
  t135 = t37 / t133;
  t137 = t11 * t11;
  t139 = t77 * params->mu / t137;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t4 * t6 / t17 / rho[0] * t28 / 0.9e1 + 0.17e2 / 0.108e3 * t4 * t6 / t7 / t70 * t37 * t45 - 0.7e1 / 0.108e3 * t4 * t6 / t120 * t37 * t85 + 0.1e1 / t17 / t127 / rho[0] * t1 * t36 * t135 * t139 * t83 * sigma[0] / 0.54e2;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.7e1 / 0.144e3 * t64 * t1 * t36 * t54 + 0.19e2 / 0.864e3 * t74 * t96 - 0.1e1 / t17 / t127 * t1 * t36 * t135 * t139 * t83 / 0.144e3;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t93 * t36 * t105 / 0.192e3 + 0.1e1 / t17 / t120 * t1 * t36 * t135 * t139 * sigma[0] / 0.384e3;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.1e1 / t17 / t71 * t1 * t36 * t135 * t139 / 0.1024e4;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


static inline void
func_pol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t4, t5, t6, t7, t8, t9;
  double t10, t11, t13, t14, t15, t16, t17, t18;
  double t19, t20, t21, t22, t23, t24, t25, t26;
  double t27, t29, t33, t38, t40, t42, t43, t44;
  double t45, t46, t47, t48, t49, t51, t55, t60;
  double t62, t64, t65, t66, t67, t68, t69, t71;
  double t72, t74, t75, t76, t77, t78, t80, t81;
  double t82, t84, t85, t86, t88, t89, t91, t93;
  double t94, t95, t96, t97, t98, t100, t101, t102;
  double t104, t105, t109, t110, t112, t113, t114, t115;
  double t117, t118, t120, t121, t122, t124, t125, t127;
  double t129, t130, t131, t135, t136, t138, t139, t140;
  double t141, t143, t147, t148, t149, t151, t154, t156;
  double t157, t158, t159, t160, t161, t163, t164, t165;
  double t167, t168, t170, t173, t174, t175, t176, t177;
  double t178, t179, t180, t182, t183, t185, t186, t188;
  double t189, t191, t192, t193, t195, t196, t198, t199;
  double t201, t202, t203, t204, t207, t209, t210, t211;
  double t213, t215, t216, t217, t218, t219, t220, t221;
  double t222, t224, t225, t226, t228, t229, t230, t231;
  double t233, t234, t235, t237, t238, t239, t241, t242;
  double t243, t244, t246, t249, t253, t254, t257, t258;
  double t259, t261, t265, t266, t267, t268, t270, t273;
  double t275, t276, t278, t282, t285, t286, t289, t290;
  double t292, t295, t296, t298, t299, t300, t301, t302;
  double t304, t305, t306, t307, t309, t310, t311, t314;
  double t315, t316, t317, t318, t320, t321, t322, t324;
  double t326, t327, t328, t329, t332, t334, t335, t336;
  double t338, t340, t341, t342, t343, t345, t347, t348;
  double t350, t352, t353, t354, t356, t360, t363, t364;
  double t366, t370, t373, t375, t376, t378, t379, t380;
  double t382, t386, t391, t395, t398, t399, t401, t405;
  double t409, t410, t411, t413, t415, t418, t419, t421;
  double t423, t430, t432, t444, t446, t448, t450, t456;
  double t464, t465, t471, t473, t475, t477, t480, t481;
  double t487, t489, t491, t493, t495, t498, t500, t502;
  double t504, t520, t524, t526, t533, t534, t551, t553;
  double t554, t555, t556, t557, t566, t569, t572, t573;
  double t574, t576, t579, t586, t594, t595, t601, t609;
  double t618, t630, t633, t636, t638, t641, t644, t651;
  double t661, t685, t692, t694, t695, t698, t701, t717;
  double t728, t731, t734, t737, t741, t742, t744, t773;
  double t799, t802, t818, t840, t842, t884, t886, t887;
  double t896, t899, t904, t905, t907, t910, t920, t945;
  double t950, t952, t964, t980, t987, t998, t1005, t1007;
  double t1057, t1059, t1075, t1076, t1101;

  gga_x_pbe_params *params;

  assert(p->params != NULL);
  params = (gga_x_pbe_params * )(p->params);

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
  t19 = params->mu * t18;
  t20 = M_PI * M_PI;
  t21 = POW_1_3(t20);
  t22 = t21 * t21;
  t23 = 0.1e1 / t22;
  t24 = t23 * sigma[0];
  t25 = rho[0] * rho[0];
  t26 = POW_1_3(rho[0]);
  t27 = t26 * t26;
  t29 = 0.1e1 / t27 / t25;
  t33 = params->kappa + t19 * t24 * t29 / 0.24e2;
  t38 = 0.1e1 + params->kappa * (0.1e1 - params->kappa / t33);
  t40 = t7 * t17 * t38;
  t42 = 0.1e1 / 0.2e1 - t11 / 0.2e1;
  t43 = POW_1_3(t42);
  t44 = t43 * t42;
  t45 = t44 * t16;
  t46 = t23 * sigma[2];
  t47 = rho[1] * rho[1];
  t48 = POW_1_3(rho[1]);
  t49 = t48 * t48;
  t51 = 0.1e1 / t49 / t47;
  t55 = params->kappa + t19 * t46 * t51 / 0.24e2;
  t60 = 0.1e1 + params->kappa * (0.1e1 - params->kappa / t55);
  t62 = t7 * t45 * t60;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.8e1 * t40 - 0.3e1 / 0.8e1 * t62;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t64 = 0.3e1 / 0.8e1 * t40;
  t65 = 0.3e1 / 0.8e1 * t62;
  t66 = t14 * t16;
  t67 = t9 * t9;
  t68 = 0.1e1 / t67;
  t69 = t8 * t68;
  t71 = t10 / 0.2e1 - t69 / 0.2e1;
  t72 = t38 * t71;
  t74 = t7 * t66 * t72;
  t75 = t74 / 0.2e1;
  t76 = t16 * t16;
  t77 = 0.1e1 / t76;
  t78 = t15 * t77;
  t80 = t7 * t78 * t38;
  t81 = t80 / 0.8e1;
  t82 = params->kappa * params->kappa;
  t84 = t7 * t17 * t82;
  t85 = t33 * t33;
  t86 = 0.1e1 / t85;
  t88 = t86 * params->mu * t18;
  t89 = t25 * rho[0];
  t91 = 0.1e1 / t27 / t89;
  t93 = t88 * t24 * t91;
  t94 = t84 * t93;
  t95 = t94 / 0.24e2;
  t96 = t43 * t16;
  t97 = -t71;
  t98 = t60 * t97;
  t100 = t7 * t96 * t98;
  t101 = t100 / 0.2e1;
  t102 = t44 * t77;
  t104 = t7 * t102 * t60;
  t105 = t104 / 0.8e1;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t64 - t65 + t9 * (-t75 - t81 + t95 - t101 - t105);

  t109 = -t10 / 0.2e1 - t69 / 0.2e1;
  t110 = t38 * t109;
  t112 = t7 * t66 * t110;
  t113 = t112 / 0.2e1;
  t114 = -t109;
  t115 = t60 * t114;
  t117 = t7 * t96 * t115;
  t118 = t117 / 0.2e1;
  t120 = t7 * t45 * t82;
  t121 = t55 * t55;
  t122 = 0.1e1 / t121;
  t124 = t122 * params->mu * t18;
  t125 = t47 * rho[1];
  t127 = 0.1e1 / t49 / t125;
  t129 = t124 * t46 * t127;
  t130 = t120 * t129;
  t131 = t130 / 0.24e2;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = -t64 - t65 + t9 * (-t113 - t81 - t118 - t105 + t131);

  t135 = t16 * t9 * t1;
  t136 = t3 * t6;
  t138 = t135 * t136 * t15;
  t139 = t82 * t86;
  t140 = t139 * params->mu;
  t141 = t18 * t23;
  t143 = t140 * t141 * t29;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -t138 * t143 / 0.64e2;

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[1] = 0.0e0;

  t147 = t135 * t136 * t44;
  t148 = t82 * t122;
  t149 = t148 * params->mu;
  t151 = t149 * t141 * t51;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[2] = -t147 * t151 / 0.64e2;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t154 = t80 / 0.4e1;
  t156 = t104 / 0.4e1;
  t157 = t14 * t14;
  t158 = 0.1e1 / t157;
  t159 = t158 * t16;
  t160 = t71 * t71;
  t161 = t38 * t160;
  t163 = t7 * t159 * t161;
  t164 = t163 / 0.6e1;
  t165 = t14 * t77;
  t167 = t7 * t165 * t72;
  t168 = t167 / 0.3e1;
  t170 = t7 * t66 * t82;
  t173 = t88 * t24 * t91 * t71;
  t174 = t170 * t173;
  t175 = t174 / 0.9e1;
  t176 = t67 * t9;
  t177 = 0.1e1 / t176;
  t178 = t8 * t177;
  t179 = -t68 + t178;
  t180 = t38 * t179;
  t182 = t7 * t66 * t180;
  t183 = t182 / 0.2e1;
  t185 = 0.1e1 / t76 / t9;
  t186 = t15 * t185;
  t188 = t7 * t186 * t38;
  t189 = t188 / 0.12e2;
  t191 = t7 * t78 * t82;
  t192 = t191 * t93;
  t193 = t192 / 0.36e2;
  t195 = 0.1e1 / t85 / t33;
  t196 = params->mu * params->mu;
  t198 = t18 * t18;
  t199 = t195 * t196 * t198;
  t201 = 0.1e1 / t21 / t20;
  t202 = sigma[0] * sigma[0];
  t203 = t201 * t202;
  t204 = t25 * t25;
  t207 = 0.1e1 / t26 / t204 / t89;
  t209 = t199 * t203 * t207;
  t210 = t84 * t209;
  t211 = t210 / 0.108e3;
  t213 = 0.1e1 / t27 / t204;
  t215 = t88 * t24 * t213;
  t216 = t84 * t215;
  t217 = 0.11e2 / 0.72e2 * t216;
  t218 = t43 * t43;
  t219 = 0.1e1 / t218;
  t220 = t219 * t16;
  t221 = t97 * t97;
  t222 = t60 * t221;
  t224 = t7 * t220 * t222;
  t225 = t224 / 0.6e1;
  t226 = t43 * t77;
  t228 = t7 * t226 * t98;
  t229 = t228 / 0.3e1;
  t230 = -t179;
  t231 = t60 * t230;
  t233 = t7 * t96 * t231;
  t234 = t233 / 0.2e1;
  t235 = t44 * t185;
  t237 = t7 * t235 * t60;
  t238 = t237 / 0.12e2;
  t239 = -t164 - t168 + t175 - t183 + t189 + t193 + t211 - t217 - t225 - t229 - t234 + t238;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t74 - t154 + t94 / 0.12e2 - t100 - t156 + t9 * t239;

  t241 = t6 * t158;
  t242 = t4 * t241;
  t243 = t16 * t38;
  t244 = t109 * t71;
  t246 = t242 * t243 * t244;
  t249 = t7 * t165 * t110;
  t253 = t88 * t24 * t91 * t109;
  t254 = t170 * t253;
  t257 = 0.1e1 / t76 / t67;
  t258 = t14 * t257;
  t259 = t38 * t8;
  t261 = t7 * t258 * t259;
  t265 = t6 * t219;
  t266 = t4 * t265;
  t267 = t16 * t60;
  t268 = t114 * t97;
  t270 = t266 * t267 * t268;
  t273 = t7 * t226 * t115;
  t275 = t43 * t257;
  t276 = t60 * t8;
  t278 = t7 * t275 * t276;
  t282 = t7 * t96 * t82;
  t285 = t124 * t46 * t127 * t97;
  t286 = t282 * t285;
  t289 = t7 * t102 * t82;
  t290 = t289 * t129;
  t292 = -t246 / 0.6e1 - t249 / 0.6e1 + t254 / 0.18e2 - t261 / 0.2e1 - t167 / 0.6e1 + t189 + t192 / 0.72e2 - t270 / 0.6e1 - t273 / 0.6e1 + t278 / 0.2e1 - t228 / 0.6e1 + t238 + t286 / 0.18e2 + t290 / 0.72e2;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = t9 * t292 - t101 - t113 - t118 + t131 - t154 - t156 - t75 + t95;

  t295 = t109 * t109;
  t296 = t38 * t295;
  t298 = t7 * t159 * t296;
  t299 = t298 / 0.6e1;
  t300 = t249 / 0.3e1;
  t301 = t68 + t178;
  t302 = t38 * t301;
  t304 = t7 * t66 * t302;
  t305 = t304 / 0.2e1;
  t306 = t114 * t114;
  t307 = t60 * t306;
  t309 = t7 * t220 * t307;
  t310 = t309 / 0.6e1;
  t311 = t273 / 0.3e1;
  t314 = t124 * t46 * t127 * t114;
  t315 = t282 * t314;
  t316 = t315 / 0.9e1;
  t317 = -t301;
  t318 = t60 * t317;
  t320 = t7 * t96 * t318;
  t321 = t320 / 0.2e1;
  t322 = t290 / 0.36e2;
  t324 = 0.1e1 / t121 / t55;
  t326 = t324 * t196 * t198;
  t327 = sigma[2] * sigma[2];
  t328 = t201 * t327;
  t329 = t47 * t47;
  t332 = 0.1e1 / t48 / t329 / t125;
  t334 = t326 * t328 * t332;
  t335 = t120 * t334;
  t336 = t335 / 0.108e3;
  t338 = 0.1e1 / t49 / t329;
  t340 = t124 * t46 * t338;
  t341 = t120 * t340;
  t342 = 0.11e2 / 0.72e2 * t341;
  t343 = -t299 - t300 - t305 + t189 - t310 - t311 + t316 - t321 + t238 + t322 + t336 - t342;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = -t112 - t154 - t117 - t156 + t130 / 0.12e2 + t9 * t343;

  t345 = t6 * t15;
  t347 = t4 * t345 * t16;
  t348 = t347 * t143;
  t350 = t135 * t3;
  t352 = t6 * t14 * t82;
  t353 = t350 * t352;
  t354 = t23 * t29;
  t356 = t88 * t354 * t71;
  t360 = t350 * t345 * t82;
  t363 = 0.1e1 / t26 / t204 / t25;
  t364 = t201 * t363;
  t366 = t199 * t364 * sigma[0];
  t370 = t140 * t141 * t91;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t348 / 0.48e2 - t353 * t356 / 0.48e2 - t360 * t366 / 0.288e3 + t138 * t370 / 0.24e2;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[1] = 0.0e0;

  t373 = t6 * t44;
  t375 = t4 * t373 * t16;
  t376 = t375 * t151;
  t378 = t6 * t43 * t82;
  t379 = t350 * t378;
  t380 = t23 * t51;
  t382 = t124 * t380 * t97;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[2] = -t379 * t382 / 0.48e2 - t376 / 0.48e2;

  t386 = t88 * t354 * t109;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[3] = -t353 * t386 / 0.48e2 - t348 / 0.48e2;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[4] = 0.0e0;

  t391 = t124 * t380 * t114;
  t395 = t350 * t373 * t82;
  t398 = 0.1e1 / t48 / t329 / t47;
  t399 = t201 * t398;
  t401 = t326 * t399 * sigma[2];
  t405 = t149 * t141 * t127;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[5] = -t376 / 0.48e2 - t379 * t391 / 0.48e2 - t395 * t401 / 0.288e3 + t147 * t405 / 0.24e2;

  t409 = t82 * t195 * t196;
  t410 = t198 * t201;
  t411 = t204 * rho[0];
  t413 = 0.1e1 / t26 / t411;
  t415 = t409 * t410 * t413;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = t138 * t415 / 0.768e3;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[1] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[2] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[3] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[4] = 0.0e0;

  t418 = t82 * t324 * t196;
  t419 = t329 * rho[1];
  t421 = 0.1e1 / t48 / t419;
  t423 = t418 * t410 * t421;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[5] = t147 * t423 / 0.768e3;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t430 = t188 / 0.4e1;
  t432 = t237 / 0.4e1;
  t444 = t7 * t165 * t180;
  t446 = t67 * t67;
  t448 = t8 / t446;
  t450 = 0.3e1 * t177 - 0.3e1 * t448;
  t456 = t7 * t226 * t231;
  t464 = 0.1e1 / t157 / t13;
  t465 = t464 * t16;
  t471 = t158 * t77;
  t473 = t7 * t471 * t161;
  t475 = t14 * t185;
  t477 = t7 * t475 * t72;
  t480 = 0.1e1 / t218 / t42;
  t481 = t480 * t16;
  t487 = t219 * t77;
  t489 = t7 * t487 * t222;
  t491 = t43 * t185;
  t493 = t7 * t491 * t98;
  t495 = -t242 * t243 * t71 * t179 / 0.2e1 - t266 * t267 * t97 * t230 / 0.2e1 - t444 / 0.2e1 - t7 * t66 * t38 * t450 / 0.2e1 - t456 / 0.2e1 + t7 * t96 * t60 * t450 / 0.2e1 + t7 * t465 * t38 * t160 * t71 / 0.9e1 - t473 / 0.6e1 + t477 / 0.3e1 + t7 * t481 * t60 * t221 * t97 / 0.9e1 - t489 / 0.6e1 + t493 / 0.3e1;
  t498 = t7 * t186 * t82 * t93;
  t500 = t191 * t209;
  t502 = t191 * t215;
  t504 = t204 * t204;
  t520 = 0.5e1 / 0.36e2 * t7 * t15 * t257 * t38;
  t524 = 0.5e1 / 0.36e2 * t7 * t44 * t257 * t60;
  t526 = t7 * t159 * t82;
  t533 = t7 * t165 * t82;
  t534 = t533 * t173;
  t551 = t85 * t85;
  t553 = t82 / t551;
  t554 = t196 * params->mu;
  t555 = t553 * t554;
  t556 = t20 * t20;
  t557 = 0.1e1 / t556;
  t566 = -t498 / 0.36e2 + t500 / 0.108e3 - 0.11e2 / 0.72e2 * t502 - 0.11e2 / 0.108e3 * t84 * t199 * t203 / t26 / t504 + 0.77e2 / 0.108e3 * t84 * t88 * t24 / t27 / t411 - t520 - t524 + t526 * t88 * t24 * t91 * t160 / 0.18e2 + t534 / 0.9e1 + t170 * t88 * t24 * t91 * t179 / 0.6e1 + t170 * t199 * t203 * t207 * t71 / 0.27e2 - 0.11e2 / 0.18e2 * t170 * t88 * t24 * t213 * t71 + t347 * t555 * t557 * t202 * sigma[0] / t504 / t89 / 0.54e2;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t174 / 0.3e1 - 0.11e2 / 0.24e2 * t216 - t163 / 0.2e1 - t167 - t224 / 0.2e1 - t228 - 0.3e1 / 0.2e1 * t182 + t430 - 0.3e1 / 0.2e1 * t233 + t432 + t192 / 0.12e2 + t210 / 0.36e2 + t9 * (t495 + t566);

  t569 = t254 / 0.9e1;
  t572 = t246 / 0.3e1;
  t573 = t270 / 0.3e1;
  t574 = t175 - t217 + t569 - t164 - 0.2e1 / 0.3e1 * t167 - t225 - 0.2e1 / 0.3e1 * t228 - t572 - t300 - t261 - t573;
  t576 = t286 / 0.9e1;
  t579 = t19 * t23;
  t586 = t4 * t6 * t464;
  t594 = t242 * t77 * t38 * t244 / 0.9e1;
  t595 = t257 * t38;
  t601 = t4 * t6 * t480;
  t609 = t266 * t77 * t60 * t268 / 0.9e1;
  t618 = t257 * t60;
  t630 = 0.1e1 / t76 / t176;
  t633 = t7 * t43 * t630 * t276;
  t636 = t7 * t475 * t110;
  t638 = t7 * t159 * t139 * t579 * sigma[0] * t91 * t244 / 0.27e2 + t586 * t243 * t109 * t160 / 0.9e1 - t594 - t242 * t595 * t8 * t71 / 0.3e1 + t601 * t267 * t114 * t221 / 0.9e1 - t609 - t242 * t243 * t109 * t179 / 0.6e1 - t266 * t267 * t114 * t230 / 0.6e1 + t266 * t618 * t8 * t97 / 0.3e1 - t444 / 0.6e1 - t456 / 0.6e1 - t473 / 0.18e2 + 0.2e1 / 0.9e1 * t477 - t489 / 0.18e2 + 0.2e1 / 0.9e1 * t493 - 0.7e1 / 0.6e1 * t633 + t636 / 0.9e1;
  t641 = t7 * t14 * t630 * t259;
  t644 = t7 * t491 * t115;
  t651 = t7 * t235 * t82 * t129;
  t661 = t533 * t253 / 0.27e2;
  t685 = t7 * t220 * t82;
  t692 = t7 * t226 * t82;
  t694 = t692 * t285 / 0.27e2;
  t695 = 0.7e1 / 0.6e1 * t641 + t644 / 0.9e1 - t498 / 0.54e2 + t500 / 0.324e3 - 0.11e2 / 0.216e3 * t502 - t651 / 0.108e3 - t520 - t524 - t7 * t258 * t38 / 0.2e1 + t7 * t275 * t60 / 0.2e1 + t534 / 0.27e2 + t661 + t170 * t199 * t203 * t207 * t109 / 0.81e2 + t282 * t124 * t46 * t127 * t230 / 0.18e2 - 0.11e2 / 0.54e2 * t170 * t88 * t24 * t213 * t109 + t7 * t258 * t82 * t88 * t24 * t91 * t8 / 0.9e1 + t685 * t124 * t46 * t127 * t221 / 0.54e2 + t694;
  t698 = -t311 - t183 + t430 - t234 + t432 + t278 + t192 / 0.18e2 + t211 + t576 + t322 + t9 * (t638 + t695);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = t574 + t698;

  t701 = t569 - t168 - t229 - t572 - 0.2e1 / 0.3e1 * t249 - t261 - t573 - 0.2e1 / 0.3e1 * t273 + t430 + t432 + t278;
  t717 = -t177 - 0.3e1 * t448;
  t728 = t7 * t471 * t296;
  t731 = t7 * t165 * t302;
  t734 = t7 * t487 * t307;
  t737 = t7 * t226 * t318;
  t741 = t7 * t220 * t148 * t579 * sigma[2] * t127 * t268 / 0.27e2 - t594 - t609 + t477 / 0.9e1 + t493 / 0.9e1 + t633 / 0.3e1 + 0.2e1 / 0.9e1 * t636 - t641 / 0.3e1 + 0.2e1 / 0.9e1 * t644 - t7 * t66 * t38 * t717 / 0.2e1 + t7 * t96 * t60 * t717 / 0.2e1 - t728 / 0.18e2 - t731 / 0.6e1 - t734 / 0.18e2 - t737 / 0.6e1 - t498 / 0.108e3 - t651 / 0.54e2;
  t742 = t289 * t334;
  t744 = t289 * t340;
  t773 = t692 * t314;
  t799 = t742 / 0.324e3 - 0.11e2 / 0.216e3 * t744 - t520 - t524 + t661 + t694 + t526 * t88 * t24 * t91 * t295 / 0.54e2 + t170 * t88 * t24 * t91 * t301 / 0.18e2 - t7 * t275 * t82 * t124 * t46 * t127 * t8 / 0.9e1 + t282 * t326 * t328 * t332 * t97 / 0.81e2 - 0.11e2 / 0.54e2 * t282 * t124 * t46 * t338 * t97 + t773 / 0.27e2 - t242 * t595 * t109 * t8 / 0.3e1 + t586 * t243 * t295 * t71 / 0.9e1 - t242 * t243 * t301 * t71 / 0.6e1 + t601 * t267 * t306 * t97 / 0.9e1 + t266 * t618 * t114 * t8 / 0.3e1 - t266 * t267 * t317 * t97 / 0.6e1;
  t802 = -t305 - t321 + t193 + t336 + t576 + t290 / 0.18e2 + t316 - t342 - t299 - t310 + t9 * (t741 + t799);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = t701 + t802;

  t818 = -0.3e1 * t177 - 0.3e1 * t448;
  t840 = t636 / 0.3e1 + t644 / 0.3e1 - t728 / 0.6e1 - t731 / 0.2e1 - t734 / 0.6e1 - t737 / 0.2e1 - t7 * t66 * t38 * t818 / 0.2e1 + t7 * t96 * t60 * t818 / 0.2e1 + t7 * t465 * t38 * t295 * t109 / 0.9e1 + t7 * t481 * t60 * t306 * t114 / 0.9e1 - t651 / 0.36e2 + t742 / 0.108e3;
  t842 = t329 * t329;
  t884 = t121 * t121;
  t886 = t82 / t884;
  t887 = t886 * t554;
  t896 = -0.11e2 / 0.72e2 * t744 - 0.11e2 / 0.108e3 * t120 * t326 * t328 / t48 / t842 + 0.77e2 / 0.108e3 * t120 * t124 * t46 / t49 / t419 - t520 - t524 + t773 / 0.9e1 + t685 * t124 * t46 * t127 * t306 / 0.18e2 + t282 * t124 * t46 * t127 * t317 / 0.6e1 + t282 * t326 * t328 * t332 * t114 / 0.27e2 - 0.11e2 / 0.18e2 * t282 * t124 * t46 * t338 * t114 - t242 * t243 * t109 * t301 / 0.2e1 - t266 * t267 * t114 * t317 / 0.2e1 + t375 * t887 * t557 * t327 * sigma[2] / t842 / t125 / 0.54e2;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = -t249 - t273 + t430 + t432 - 0.3e1 / 0.2e1 * t304 - 0.3e1 / 0.2e1 * t320 + t335 / 0.36e2 + t290 / 0.12e2 + t315 / 0.3e1 - 0.11e2 / 0.24e2 * t341 - t298 / 0.2e1 - t309 / 0.2e1 + t9 * (t840 + t896);

  t899 = t170 * t356;
  t904 = t4 * t345 * t77 * t143 / 0.144e3;
  t905 = t84 * t366;
  t907 = t347 * t370;
  t910 = t350 * t241 * t82;
  t920 = t23 * t91;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -t899 / 0.18e2 - t904 - t905 / 0.108e3 + t907 / 0.9e1 - t910 * t88 * t354 * t160 / 0.144e3 - t353 * t199 * t364 * t71 * sigma[0] / 0.108e3 + t353 * t88 * t920 * t71 / 0.9e1 - t353 * t88 * t354 * t179 / 0.48e2 - t138 * t555 * t557 / t504 / t25 * t202 / 0.144e3 + t360 * t199 * t201 * t207 * sigma[0] / 0.32e2 - 0.11e2 / 0.72e2 * t138 * t140 * t141 * t213;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[1] = 0.0e0;

  t945 = t282 * t382;
  t950 = t4 * t373 * t77 * t151 / 0.144e3;
  t952 = t350 * t265 * t82;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[2] = -t945 / 0.18e2 - t950 - t952 * t124 * t380 * t221 / 0.144e3 - t379 * t124 * t380 * t230 / 0.48e2;

  t964 = t170 * t386;
  t980 = t185 * t1 * t3;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[3] = -t899 / 0.36e2 - t904 - t905 / 0.216e3 + t907 / 0.18e2 - t964 / 0.36e2 - t910 * t88 * t354 * t244 / 0.144e3 - t353 * t199 * t364 * t109 * sigma[0] / 0.216e3 + t353 * t88 * t920 * t109 / 0.18e2 - t980 * t352 * t88 * t354 * t8 / 0.48e2;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[4] = 0.0e0;

  t987 = t282 * t391;
  t998 = t120 * t401;
  t1005 = t375 * t405;
  t1007 = t23 * t127;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[5] = -t945 / 0.36e2 - t950 - t987 / 0.36e2 - t952 * t124 * t380 * t268 / 0.144e3 + t980 * t378 * t124 * t380 * t8 / 0.48e2 - t998 / 0.216e3 - t379 * t326 * t399 * sigma[2] * t97 / 0.216e3 + t1005 / 0.18e2 + t379 * t124 * t1007 * t97 / 0.18e2;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[6] = -t964 / 0.18e2 - t904 - t910 * t88 * t354 * t295 / 0.144e3 - t353 * t88 * t354 * t301 / 0.48e2;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[8] = -t987 / 0.18e2 - t950 - t998 / 0.108e3 + t1005 / 0.9e1 - t952 * t124 * t380 * t306 / 0.144e3 - t379 * t326 * t399 * t114 * sigma[2] / 0.108e3 + t379 * t124 * t1007 * t114 / 0.9e1 - t379 * t124 * t380 * t317 / 0.48e2 - t147 * t887 * t557 / t842 / t47 * t327 / 0.144e3 + t395 * t326 * t201 * t332 * sigma[2] / 0.32e2 - 0.11e2 / 0.72e2 * t147 * t149 * t141 * t338;

  t1057 = t347 * t415;
  t1059 = t201 * t413;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = t1057 / 0.576e3 + t353 * t199 * t1059 * t71 / 0.576e3 + t138 * t555 * t557 / t504 / rho[0] * sigma[0] / 0.384e3 - t138 * t409 * t410 * t363 / 0.144e3;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[1] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[2] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[3] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[4] = 0.0e0;

  t1075 = t375 * t423;
  t1076 = t201 * t421;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[5] = t379 * t326 * t1076 * t97 / 0.576e3 + t1075 / 0.576e3;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[6] = t353 * t199 * t1059 * t109 / 0.576e3 + t1057 / 0.576e3;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[8] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[9] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[10] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[11] = t1075 / 0.576e3 + t379 * t326 * t1076 * t114 / 0.576e3 + t147 * t887 * t557 / t842 / rho[1] * sigma[2] / 0.384e3 - t147 * t418 * t410 * t398 / 0.144e3;

  t1101 = t554 * t557;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -t138 * t553 * t1101 / t504 / 0.1024e4;

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

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[9] = -t147 * t886 * t1101 / t842 / 0.1024e4;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}

