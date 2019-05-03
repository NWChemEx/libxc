/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/gga_exc/gga_x_rge2.mpl
  Type of functional: gga_exc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t5, t6, t7, t8, t9, t10;
  double t11, t12, t13, t14, t15, t17, t18, t19;
  double t20, t22, t26, t28, t29, t30, t31, t32;
  double t33, t35, t39, t42, t44, t48, t49, t50;
  double t51, t52, t53, t55, t61, t65, t66, t73;
  double t77, t79, t82, t83, t91, t92, t93, t98;
  double t104, t108, t109, t113, t114, t117, t118, t119;
  double t121, t130, t132, t135, t137, t141, t144, t162;
  double t163, t178, t198, t237;


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
  t13 = M_PI * M_PI;
  t14 = POW_1_3(t13);
  t15 = t14 * t14;
  t17 = t12 / t15;
  t18 = sigma[0] * t9;
  t19 = rho[0] * rho[0];
  t20 = t10 * t10;
  t22 = 0.1e1 / t20 / t19;
  t26 = t12 * t12;
  t28 = 0.1e1 / t14 / t13;
  t29 = t26 * t28;
  t30 = sigma[0] * sigma[0];
  t31 = t30 * t8;
  t32 = t19 * t19;
  t33 = t32 * rho[0];
  t35 = 0.1e1 / t10 / t33;
  t39 = 0.8040e0 + 0.5e1 / 0.972e3 * t17 * t18 * t22 + 0.65823568907145082055e-4 * t29 * t31 * t35;
  t42 = 0.18040e1 - 0.64641600e0 / t39;
  t44 = t7 * t11 * t42;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.16e2 * t44;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t48 = t10 * rho[0] * t1;
  t49 = t48 * t3;
  t50 = t6 * t9;
  t51 = t39 * t39;
  t52 = 0.1e1 / t51;
  t53 = t19 * rho[0];
  t55 = 0.1e1 / t20 / t53;
  t61 = 0.1e1 / t10 / t32 / t19;
  t65 = -0.10e2 / 0.729e3 * t17 * t18 * t55 - 0.35105903417144043763e-3 * t29 * t31 * t61;
  t66 = t52 * t65;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t44 / 0.4e1 - 0.12120300000000000000e0 * t49 * t50 * t66;

  t73 = sigma[0] * t8;
  t77 = 0.5e1 / 0.972e3 * t17 * t9 * t22 + 0.13164713781429016411e-3 * t29 * t73 * t35;
  t79 = t50 * t52 * t77;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.12120300000000000000e0 * t49 * t79;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t82 = 0.1e1 / t20;
  t83 = t9 * t82;
  t91 = 0.1e1 / t51 / t39;
  t92 = t65 * t65;
  t93 = t91 * t92;
  t98 = 0.1e1 / t20 / t32;
  t104 = 0.1e1 / t10 / t32 / t53;
  t108 = 0.110e3 / 0.2187e4 * t17 * t18 * t98 + 0.22233738830857894383e-2 * t29 * t31 * t104;
  t109 = t52 * t108;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t7 * t83 * t42 / 0.12e2 - 0.32320800000000000000e0 * t7 * t11 * t66 + 0.24240600000000000000e0 * t49 * t50 * t93 - 0.12120300000000000000e0 * t49 * t50 * t109;

  t113 = t10 * t1;
  t114 = t113 * t3;
  t117 = t3 * t6;
  t118 = t48 * t117;
  t119 = t9 * t91;
  t121 = t119 * t77 * t65;
  t130 = -0.10e2 / 0.729e3 * t17 * t9 * t55 - 0.70211806834288087525e-3 * t29 * t73 * t61;
  t132 = t50 * t52 * t130;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -0.16160400000000000000e0 * t114 * t79 + 0.24240600000000000000e0 * t118 * t121 - 0.12120300000000000000e0 * t49 * t132;

  t135 = t77 * t77;
  t137 = t50 * t91 * t135;
  t141 = 0.1e1 / t32 * t1;
  t144 = t6 * t52 * t29;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = 0.24240600000000000000e0 * t49 * t137 - 0.31912056089010821521e-4 * t141 * t3 * t144;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t162 = t51 * t51;
  t163 = 0.1e1 / t162;
  t178 = t32 * t32;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t7 * t9 / t20 / rho[0] * t42 / 0.18e2 - 0.16160400000000000000e0 * t7 * t83 * t66 + 0.96962400000000000000e0 * t7 * t11 * t93 - 0.48481200000000000000e0 * t7 * t11 * t109 - 0.72721800000000000000e0 * t49 * t50 * t163 * t92 * t65 + 0.72721800000000000000e0 * t118 * t119 * t65 * t108 - 0.12120300000000000000e0 * t49 * t50 * t52 * (-0.1540e4 / 0.6561e4 * t17 * t18 / t20 / t33 - 0.16304741809295789214e-1 * t29 * t31 / t10 / t178);

  t198 = t9 * t163;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.53868000000000000000e-1 * t82 * t1 * t3 * t79 + 0.64641600000000000000e0 * t113 * t117 * t121 - 0.32320800000000000000e0 * t114 * t132 - 0.72721800000000000000e0 * t118 * t198 * t77 * t92 + 0.48481200000000000000e0 * t118 * t119 * t130 * t65 + 0.24240600000000000000e0 * t118 * t119 * t77 * t108 - 0.12120300000000000000e0 * t49 * t50 * t52 * (0.110e3 / 0.2187e4 * t17 * t9 * t98 + 0.44467477661715788766e-2 * t29 * t73 * t104);

  t237 = t141 * t117;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = 0.32320800000000000000e0 * t114 * t137 - 0.72721800000000000000e0 * t118 * t198 * t135 * t65 + 0.48481200000000000000e0 * t118 * t119 * t77 * t130 + 0.12764822435604328608e-3 / t33 * t1 * t3 * t144 + 0.63824112178021643042e-4 * t237 * t91 * t26 * t28 * t65;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.72721800000000000000e0 * t49 * t50 * t163 * t135 * t77 + 0.19147233653406492912e-3 * t237 * t91 * t77 * t29;

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
  double t11, t12, t14, t15, t16, t18, t22, t24;
  double t25, t26, t27, t28, t30, t34, t37, t39;
  double t44, t45, t46, t47, t48, t50, t56, t60;
  double t69, t70, t73, t78, t79, t84, t85, t86;
  double t91, t97, t101, t106, t110, t118, t119, t122;
  double t123, t127, t129, t149, t151, t165, t220;


  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = POW_1_3(rho[0]);
  t9 = M_CBRT6;
  t10 = M_PI * M_PI;
  t11 = POW_1_3(t10);
  t12 = t11 * t11;
  t14 = t9 / t12;
  t15 = rho[0] * rho[0];
  t16 = t7 * t7;
  t18 = 0.1e1 / t16 / t15;
  t22 = t9 * t9;
  t24 = 0.1e1 / t11 / t10;
  t25 = t22 * t24;
  t26 = sigma[0] * sigma[0];
  t27 = t15 * t15;
  t28 = t27 * rho[0];
  t30 = 0.1e1 / t7 / t28;
  t34 = 0.8040e0 + 0.5e1 / 0.972e3 * t14 * sigma[0] * t18 + 0.32911784453572541027e-4 * t25 * t26 * t30;
  t37 = 0.18040e1 - 0.64641600e0 / t34;
  t39 = t4 * t6 * t7 * t37;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.8e1 * t39;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t44 = t7 * rho[0] * t1 * t3;
  t45 = t34 * t34;
  t46 = 0.1e1 / t45;
  t47 = t6 * t46;
  t48 = t15 * rho[0];
  t50 = 0.1e1 / t16 / t48;
  t56 = 0.1e1 / t7 / t27 / t15;
  t60 = -0.10e2 / 0.729e3 * t14 * sigma[0] * t50 - 0.17552951708572021881e-3 * t25 * t26 * t56;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t39 / 0.2e1 - 0.24240600000000000000e0 * t44 * t47 * t60;

  t69 = 0.5e1 / 0.972e3 * t14 * t18 + 0.65823568907145082054e-4 * t25 * sigma[0] * t30;
  t70 = t47 * t69;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.24240600000000000000e0 * t44 * t70;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t73 = 0.1e1 / t16;
  t78 = t4 * t6;
  t79 = t7 * t46;
  t84 = 0.1e1 / t45 / t34;
  t85 = t6 * t84;
  t86 = t60 * t60;
  t91 = 0.1e1 / t16 / t27;
  t97 = 0.1e1 / t7 / t27 / t48;
  t101 = 0.110e3 / 0.2187e4 * t14 * sigma[0] * t91 + 0.11116869415428947191e-2 * t25 * t26 * t97;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t4 * t6 * t73 * t37 / 0.6e1 - 0.64641600000000000000e0 * t78 * t79 * t60 + 0.48481200000000000000e0 * t44 * t85 * t86 - 0.24240600000000000000e0 * t44 * t47 * t101;

  t106 = t7 * t1 * t3;
  t110 = t85 * t69 * t60;
  t118 = -0.10e2 / 0.729e3 * t14 * t50 - 0.35105903417144043762e-3 * t25 * sigma[0] * t56;
  t119 = t47 * t118;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -0.32320800000000000000e0 * t106 * t70 + 0.48481200000000000000e0 * t44 * t110 - 0.24240600000000000000e0 * t44 * t119;

  t122 = t69 * t69;
  t123 = t85 * t122;
  t127 = 0.1e1 / t27 * t1;
  t129 = t47 * t25;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = 0.48481200000000000000e0 * t44 * t123 - 0.15956028044505410760e-4 * t127 * t3 * t129;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t149 = t45 * t45;
  t151 = t6 / t149;
  t165 = t27 * t27;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t4 * t6 / t16 / rho[0] * t37 / 0.9e1 - 0.32320800000000000000e0 * t78 * t73 * t46 * t60 + 0.19392480000000000000e1 * t78 * t7 * t84 * t86 - 0.96962400000000000000e0 * t78 * t79 * t101 - 0.14544360000000000000e1 * t44 * t151 * t86 * t60 + 0.14544360000000000000e1 * t44 * t85 * t60 * t101 - 0.24240600000000000000e0 * t44 * t47 * (-0.1540e4 / 0.6561e4 * t14 * sigma[0] / t16 / t28 - 0.81523709046478946067e-2 * t25 * t26 / t7 / t165);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.10773600000000000000e0 * t73 * t1 * t3 * t70 + 0.12928320000000000000e1 * t106 * t110 - 0.64641600000000000000e0 * t106 * t119 - 0.14544360000000000000e1 * t44 * t151 * t69 * t86 + 0.96962400000000000000e0 * t44 * t85 * t118 * t60 + 0.48481200000000000000e0 * t44 * t85 * t69 * t101 - 0.24240600000000000000e0 * t44 * t47 * (0.110e3 / 0.2187e4 * t14 * t91 + 0.22233738830857894383e-2 * t25 * sigma[0] * t97);

  t220 = t127 * t3 * t6;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = 0.64641600000000000000e0 * t106 * t123 - 0.14544360000000000000e1 * t44 * t151 * t122 * t60 + 0.96962400000000000000e0 * t44 * t85 * t69 * t118 + 0.63824112178021643040e-4 / t28 * t1 * t3 * t129 + 0.31912056089010821520e-4 * t220 * t84 * t22 * t24 * t60;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.14544360000000000000e1 * t44 * t151 * t122 * t69 + 0.95736168267032464562e-4 * t220 * t84 * t69 * t25;

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
  double t19, t20, t21, t23, t24, t25, t26, t28;
  double t32, t34, t35, t36, t37, t38, t40, t44;
  double t47, t49, t51, t52, t53, t54, t55, t56;
  double t57, t59, t63, t64, t65, t67, t71, t74;
  double t76, t78, t79, t80, t81, t82, t83, t85;
  double t86, t88, t89, t90, t91, t92, t94, t95;
  double t96, t97, t98, t100, t106, t110, t111, t113;
  double t114, t115, t116, t117, t119, t120, t121, t123;
  double t124, t128, t129, t131, t132, t133, t134, t136;
  double t137, t138, t139, t140, t142, t148, t152, t153;
  double t155, t156, t160, t161, t162, t168, t169, t173;
  double t179, t180, t184, t186, t187, t188, t189, t190;
  double t191, t193, t194, t195, t197, t198, t200, t201;
  double t202, t204, t205, t206, t207, t208, t209, t210;
  double t212, t213, t215, t216, t218, t219, t221, t222;
  double t224, t225, t226, t228, t229, t231, t237, t241;
  double t242, t244, t245, t246, t247, t248, t249, t250;
  double t252, t253, t254, t256, t257, t258, t259, t261;
  double t262, t263, t265, t266, t267, t270, t271, t272;
  double t274, t277, t279, t281, t284, t285, t286, t288;
  double t293, t294, t295, t297, t300, t302, t303, t305;
  double t309, t310, t311, t313, t316, t318, t321, t322;
  double t324, t325, t326, t327, t328, t330, t331, t332;
  double t333, t335, t336, t337, t338, t340, t341, t342;
  double t343, t345, t346, t347, t349, t350, t351, t353;
  double t354, t356, t362, t366, t367, t369, t370, t371;
  double t375, t376, t377, t378, t379, t383, t384, t393;
  double t394, t400, t401, t402, t406, t407, t410, t411;
  double t414, t415, t416, t424, t426, t429, t431, t434;
  double t435, t436, t439, t441, t444, t445, t446, t452;
  double t456, t460, t462, t464, t466, t472, t475, t482;
  double t494, t502, t503, t509, t511, t513, t515, t518;
  double t520, t521, t527, t529, t530, t536, t538, t540;
  double t542, t547, t551, t560, t562, t572, t573, t586;
  double t591, t593, t595, t596, t598, t601, t604, t608;
  double t611, t614, t629, t643, t652, t662, t670, t671;
  double t686, t694, t699, t702, t703, t706, t708, t725;
  double t756, t762, t765, t776, t779, t781, t783, t786;
  double t789, t803, t806, t846, t861, t877, t883, t884;
  double t899, t903, t907, t909, t912, t914, t919, t932;
  double t956, t960, t961, t973, t974, t975, t990, t996;
  double t1006, t1008, t1013, t1014, t1048, t1072, t1086, t1088;
  double t1089, t1090, t1096, t1107, t1113, t1115, t1116, t1117;
  double t1147;


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
  t19 = M_PI * M_PI;
  t20 = POW_1_3(t19);
  t21 = t20 * t20;
  t23 = t18 / t21;
  t24 = rho[0] * rho[0];
  t25 = POW_1_3(rho[0]);
  t26 = t25 * t25;
  t28 = 0.1e1 / t26 / t24;
  t32 = t18 * t18;
  t34 = 0.1e1 / t20 / t19;
  t35 = t32 * t34;
  t36 = sigma[0] * sigma[0];
  t37 = t24 * t24;
  t38 = t37 * rho[0];
  t40 = 0.1e1 / t25 / t38;
  t44 = 0.8040e0 + 0.5e1 / 0.972e3 * t23 * sigma[0] * t28 + 0.32911784453572541027e-4 * t35 * t36 * t40;
  t47 = 0.18040e1 - 0.64641600e0 / t44;
  t49 = t7 * t17 * t47;
  t51 = 0.1e1 / 0.2e1 - t11 / 0.2e1;
  t52 = POW_1_3(t51);
  t53 = t52 * t51;
  t54 = t53 * t16;
  t55 = rho[1] * rho[1];
  t56 = POW_1_3(rho[1]);
  t57 = t56 * t56;
  t59 = 0.1e1 / t57 / t55;
  t63 = sigma[2] * sigma[2];
  t64 = t55 * t55;
  t65 = t64 * rho[1];
  t67 = 0.1e1 / t56 / t65;
  t71 = 0.8040e0 + 0.5e1 / 0.972e3 * t23 * sigma[2] * t59 + 0.32911784453572541027e-4 * t35 * t63 * t67;
  t74 = 0.18040e1 - 0.64641600e0 / t71;
  t76 = t7 * t54 * t74;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.8e1 * t49 - 0.3e1 / 0.8e1 * t76;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t78 = 0.3e1 / 0.8e1 * t49;
  t79 = 0.3e1 / 0.8e1 * t76;
  t80 = t14 * t16;
  t81 = t9 * t9;
  t82 = 0.1e1 / t81;
  t83 = t8 * t82;
  t85 = t10 / 0.2e1 - t83 / 0.2e1;
  t86 = t47 * t85;
  t88 = t7 * t80 * t86;
  t89 = t88 / 0.2e1;
  t90 = t16 * t16;
  t91 = 0.1e1 / t90;
  t92 = t15 * t91;
  t94 = t7 * t92 * t47;
  t95 = t94 / 0.8e1;
  t96 = t44 * t44;
  t97 = 0.1e1 / t96;
  t98 = t24 * rho[0];
  t100 = 0.1e1 / t26 / t98;
  t106 = 0.1e1 / t25 / t37 / t24;
  t110 = -0.10e2 / 0.729e3 * t23 * sigma[0] * t100 - 0.17552951708572021881e-3 * t35 * t36 * t106;
  t111 = t97 * t110;
  t113 = t7 * t17 * t111;
  t114 = 0.24240600000000000000e0 * t113;
  t115 = t52 * t16;
  t116 = -t85;
  t117 = t74 * t116;
  t119 = t7 * t115 * t117;
  t120 = t119 / 0.2e1;
  t121 = t53 * t91;
  t123 = t7 * t121 * t74;
  t124 = t123 / 0.8e1;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t78 - t79 + t9 * (-t89 - t95 - t114 - t120 - t124);

  t128 = -t10 / 0.2e1 - t83 / 0.2e1;
  t129 = t47 * t128;
  t131 = t7 * t80 * t129;
  t132 = t131 / 0.2e1;
  t133 = -t128;
  t134 = t74 * t133;
  t136 = t7 * t115 * t134;
  t137 = t136 / 0.2e1;
  t138 = t71 * t71;
  t139 = 0.1e1 / t138;
  t140 = t55 * rho[1];
  t142 = 0.1e1 / t57 / t140;
  t148 = 0.1e1 / t56 / t64 / t55;
  t152 = -0.10e2 / 0.729e3 * t23 * sigma[2] * t142 - 0.17552951708572021881e-3 * t35 * t63 * t148;
  t153 = t139 * t152;
  t155 = t7 * t54 * t153;
  t156 = 0.24240600000000000000e0 * t155;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = -t78 - t79 + t9 * (-t132 - t95 - t137 - t124 - t156);

  t160 = t16 * t9 * t1;
  t161 = t160 * t3;
  t162 = t6 * t15;
  t168 = 0.5e1 / 0.972e3 * t23 * t28 + 0.65823568907145082054e-4 * t35 * sigma[0] * t40;
  t169 = t97 * t168;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.24240600000000000000e0 * t161 * t162 * t169;

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[1] = 0.0e0;

  t173 = t6 * t53;
  t179 = 0.5e1 / 0.972e3 * t23 * t59 + 0.65823568907145082054e-4 * t35 * sigma[2] * t67;
  t180 = t139 * t179;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[2] = -0.24240600000000000000e0 * t161 * t173 * t180;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t184 = t94 / 0.4e1;
  t186 = t123 / 0.4e1;
  t187 = t14 * t14;
  t188 = 0.1e1 / t187;
  t189 = t188 * t16;
  t190 = t85 * t85;
  t191 = t47 * t190;
  t193 = t7 * t189 * t191;
  t194 = t193 / 0.6e1;
  t195 = t14 * t91;
  t197 = t7 * t195 * t86;
  t198 = t197 / 0.3e1;
  t200 = t4 * t6 * t14;
  t201 = t16 * t97;
  t202 = t110 * t85;
  t204 = t200 * t201 * t202;
  t205 = 0.64641600000000000000e0 * t204;
  t206 = t81 * t9;
  t207 = 0.1e1 / t206;
  t208 = t8 * t207;
  t209 = -t82 + t208;
  t210 = t47 * t209;
  t212 = t7 * t80 * t210;
  t213 = t212 / 0.2e1;
  t215 = 0.1e1 / t90 / t9;
  t216 = t15 * t215;
  t218 = t7 * t216 * t47;
  t219 = t218 / 0.12e2;
  t221 = t7 * t92 * t111;
  t222 = 0.16160400000000000000e0 * t221;
  t224 = 0.1e1 / t96 / t44;
  t225 = t110 * t110;
  t226 = t224 * t225;
  t228 = t7 * t17 * t226;
  t229 = 0.48481200000000000000e0 * t228;
  t231 = 0.1e1 / t26 / t37;
  t237 = 0.1e1 / t25 / t37 / t98;
  t241 = 0.110e3 / 0.2187e4 * t23 * sigma[0] * t231 + 0.11116869415428947191e-2 * t35 * t36 * t237;
  t242 = t97 * t241;
  t244 = t7 * t17 * t242;
  t245 = 0.24240600000000000000e0 * t244;
  t246 = t52 * t52;
  t247 = 0.1e1 / t246;
  t248 = t247 * t16;
  t249 = t116 * t116;
  t250 = t74 * t249;
  t252 = t7 * t248 * t250;
  t253 = t252 / 0.6e1;
  t254 = t52 * t91;
  t256 = t7 * t254 * t117;
  t257 = t256 / 0.3e1;
  t258 = -t209;
  t259 = t74 * t258;
  t261 = t7 * t115 * t259;
  t262 = t261 / 0.2e1;
  t263 = t53 * t215;
  t265 = t7 * t263 * t74;
  t266 = t265 / 0.12e2;
  t267 = -t194 - t198 - t205 - t213 + t219 - t222 + t229 - t245 - t253 - t257 - t262 + t266;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t88 - t184 - 0.48481200000000000000e0 * t113 - t119 - t186 + t9 * t267;

  t270 = t4 * t6 * t188;
  t271 = t16 * t47;
  t272 = t128 * t85;
  t274 = t270 * t271 * t272;
  t277 = t7 * t195 * t129;
  t279 = t110 * t128;
  t281 = t200 * t201 * t279;
  t284 = 0.1e1 / t90 / t81;
  t285 = t14 * t284;
  t286 = t47 * t8;
  t288 = t7 * t285 * t286;
  t293 = t4 * t6 * t247;
  t294 = t16 * t74;
  t295 = t133 * t116;
  t297 = t293 * t294 * t295;
  t300 = t7 * t254 * t134;
  t302 = t52 * t284;
  t303 = t74 * t8;
  t305 = t7 * t302 * t303;
  t309 = t4 * t6 * t52;
  t310 = t16 * t139;
  t311 = t152 * t116;
  t313 = t309 * t310 * t311;
  t316 = t7 * t121 * t153;
  t318 = -t274 / 0.6e1 - t277 / 0.6e1 - 0.32320800000000000000e0 * t281 - t288 / 0.2e1 - t197 / 0.6e1 + t219 - 0.80802000000000000000e-1 * t221 - t297 / 0.6e1 - t300 / 0.6e1 + t305 / 0.2e1 - t256 / 0.6e1 + t266 - 0.32320800000000000000e0 * t313 - 0.80802000000000000000e-1 * t316;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = t9 * t318 - t114 - t120 - t132 - t137 - t156 - t184 - t186 - t89;

  t321 = t128 * t128;
  t322 = t47 * t321;
  t324 = t7 * t189 * t322;
  t325 = t324 / 0.6e1;
  t326 = t277 / 0.3e1;
  t327 = t82 + t208;
  t328 = t47 * t327;
  t330 = t7 * t80 * t328;
  t331 = t330 / 0.2e1;
  t332 = t133 * t133;
  t333 = t74 * t332;
  t335 = t7 * t248 * t333;
  t336 = t335 / 0.6e1;
  t337 = t300 / 0.3e1;
  t338 = t152 * t133;
  t340 = t309 * t310 * t338;
  t341 = 0.64641600000000000000e0 * t340;
  t342 = -t327;
  t343 = t74 * t342;
  t345 = t7 * t115 * t343;
  t346 = t345 / 0.2e1;
  t347 = 0.16160400000000000000e0 * t316;
  t349 = 0.1e1 / t138 / t71;
  t350 = t152 * t152;
  t351 = t349 * t350;
  t353 = t7 * t54 * t351;
  t354 = 0.48481200000000000000e0 * t353;
  t356 = 0.1e1 / t57 / t64;
  t362 = 0.1e1 / t56 / t64 / t140;
  t366 = 0.110e3 / 0.2187e4 * t23 * sigma[2] * t356 + 0.11116869415428947191e-2 * t35 * t63 * t362;
  t367 = t139 * t366;
  t369 = t7 * t54 * t367;
  t370 = 0.24240600000000000000e0 * t369;
  t371 = -t325 - t326 - t331 + t219 - t336 - t337 - t341 - t346 + t266 - t347 + t354 - t370;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = -t131 - t184 - t136 - t186 - 0.48481200000000000000e0 * t155 + t9 * t371;

  t375 = 0.32320800000000000000e0 * t7 * t17 * t169;
  t376 = t3 * t6;
  t377 = t160 * t376;
  t378 = t14 * t97;
  t379 = t168 * t85;
  t383 = t15 * t224;
  t384 = t168 * t110;
  t393 = -0.10e2 / 0.729e3 * t23 * t100 - 0.35105903417144043762e-3 * t35 * sigma[0] * t106;
  t394 = t97 * t393;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t375 - 0.32320800000000000000e0 * t377 * t378 * t379 + 0.48481200000000000000e0 * t377 * t383 * t384 - 0.24240600000000000000e0 * t161 * t162 * t394;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[1] = 0.0e0;

  t400 = 0.32320800000000000000e0 * t7 * t54 * t180;
  t401 = t52 * t139;
  t402 = t179 * t116;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[2] = -t400 - 0.32320800000000000000e0 * t377 * t401 * t402;

  t406 = t168 * t128;
  t407 = t378 * t406;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[3] = -t375 - 0.32320800000000000000e0 * t377 * t407;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[4] = 0.0e0;

  t410 = t179 * t133;
  t411 = t401 * t410;
  t414 = t53 * t349;
  t415 = t179 * t152;
  t416 = t414 * t415;
  t424 = -0.10e2 / 0.729e3 * t23 * t142 - 0.35105903417144043762e-3 * t35 * sigma[2] * t148;
  t426 = t173 * t139 * t424;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[5] = -t400 - 0.32320800000000000000e0 * t377 * t411 + 0.48481200000000000000e0 * t377 * t416 - 0.24240600000000000000e0 * t161 * t426;

  t429 = t168 * t168;
  t431 = t162 * t224 * t429;
  t434 = t15 * t97;
  t435 = t35 * t40;
  t436 = t434 * t435;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = 0.48481200000000000000e0 * t161 * t431 - 0.15956028044505410760e-4 * t377 * t436;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[1] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[2] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[3] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[4] = 0.0e0;

  t439 = t179 * t179;
  t441 = t173 * t349 * t439;
  t444 = t53 * t139;
  t445 = t35 * t67;
  t446 = t444 * t445;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[5] = 0.48481200000000000000e0 * t161 * t441 - 0.15956028044505410760e-4 * t377 * t446;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t452 = t218 / 0.4e1;
  t456 = t265 / 0.4e1;
  t460 = t7 * t195 * t210;
  t462 = t81 * t81;
  t464 = t8 / t462;
  t466 = 0.3e1 * t207 - 0.3e1 * t464;
  t472 = t7 * t216 * t111;
  t475 = t7 * t92 * t242;
  t482 = t37 * t37;
  t494 = t7 * t254 * t259;
  t502 = 0.1e1 / t187 / t13;
  t503 = t502 * t16;
  t509 = t188 * t91;
  t511 = t7 * t509 * t191;
  t513 = t14 * t215;
  t515 = t7 * t513 * t86;
  t518 = t7 * t92 * t226;
  t520 = t96 * t96;
  t521 = 0.1e1 / t520;
  t527 = -t460 / 0.2e1 - t7 * t80 * t47 * t466 / 0.2e1 + 0.16160400000000000000e0 * t472 - 0.24240600000000000000e0 * t475 - 0.24240600000000000000e0 * t7 * t17 * t97 * (-0.1540e4 / 0.6561e4 * t23 * sigma[0] / t26 / t38 - 0.81523709046478946067e-2 * t35 * t36 / t25 / t482) - t494 / 0.2e1 + t7 * t115 * t74 * t466 / 0.2e1 + t7 * t503 * t47 * t190 * t85 / 0.9e1 - t511 / 0.6e1 + t515 / 0.3e1 + 0.48481200000000000000e0 * t518 - 0.14544360000000000000e1 * t7 * t17 * t521 * t225 * t110;
  t529 = 0.1e1 / t246 / t51;
  t530 = t529 * t16;
  t536 = t247 * t91;
  t538 = t7 * t536 * t250;
  t540 = t52 * t215;
  t542 = t7 * t540 * t117;
  t547 = 0.5e1 / 0.36e2 * t7 * t15 * t284 * t47;
  t551 = 0.5e1 / 0.36e2 * t7 * t53 * t284 * t74;
  t560 = t91 * t97;
  t562 = t200 * t560 * t202;
  t572 = t4 * t162;
  t573 = t16 * t224;
  t586 = t7 * t530 * t74 * t249 * t116 / 0.9e1 - t538 / 0.6e1 + t542 / 0.3e1 - t547 - t551 - t270 * t271 * t85 * t209 / 0.2e1 - 0.32320800000000000000e0 * t270 * t201 * t110 * t190 - 0.64641600000000000000e0 * t562 - 0.96962400000000000000e0 * t200 * t201 * t241 * t85 - 0.96962400000000000000e0 * t200 * t201 * t110 * t209 + 0.14544360000000000000e1 * t572 * t573 * t110 * t241 - t293 * t294 * t116 * t258 / 0.2e1 + 0.19392480000000000000e1 * t200 * t573 * t225 * t85;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -t193 / 0.2e1 - t197 - 0.19392480000000000000e1 * t204 - 0.3e1 / 0.2e1 * t212 + t452 - 0.48481200000000000000e0 * t221 - 0.72721800000000000000e0 * t244 - 0.3e1 / 0.2e1 * t261 + t456 + 0.14544360000000000000e1 * t228 - t252 / 0.2e1 - t256 + t9 * (t527 + t586);

  t591 = -t194 - 0.2e1 / 0.3e1 * t197 - t205 - t213 + t452 - 0.32320800000000000000e0 * t221 - t245 - t262 + t456 + t305 + t229;
  t593 = t274 / 0.3e1;
  t595 = t297 / 0.3e1;
  t596 = 0.64641600000000000000e0 * t313;
  t598 = 0.1e1 / t90 / t206;
  t601 = t7 * t52 * t598 * t303;
  t604 = t7 * t513 * t129;
  t608 = t7 * t14 * t598 * t286;
  t611 = t7 * t540 * t134;
  t614 = t7 * t263 * t153;
  t629 = -0.7e1 / 0.6e1 * t601 + t604 / 0.9e1 + 0.7e1 / 0.6e1 * t608 + t611 / 0.9e1 + 0.53868000000000000000e-1 * t614 - t460 / 0.6e1 + 0.10773600000000000000e0 * t472 - 0.80802000000000000000e-1 * t475 - t494 / 0.6e1 - t511 / 0.18e2 + 0.2e1 / 0.9e1 * t515 + 0.16160400000000000000e0 * t518 - t538 / 0.18e2 + 0.2e1 / 0.9e1 * t542 - 0.21547200000000000000e0 * t270 * t201 * t279 * t85 - t547 - t551;
  t643 = 0.21547200000000000000e0 * t200 * t560 * t279;
  t652 = t284 * t74;
  t662 = t4 * t6 * t502;
  t670 = t270 * t91 * t47 * t272 / 0.9e1;
  t671 = t284 * t47;
  t686 = t4 * t6 * t529;
  t694 = t293 * t91 * t74 * t295 / 0.9e1;
  t699 = t91 * t139;
  t702 = 0.21547200000000000000e0 * t309 * t699 * t311;
  t703 = -t7 * t285 * t47 / 0.2e1 + t7 * t302 * t74 / 0.2e1 - 0.21547200000000000000e0 * t562 - t270 * t271 * t128 * t209 / 0.6e1 - t643 - 0.32320800000000000000e0 * t200 * t201 * t241 * t128 - t293 * t294 * t133 * t258 / 0.6e1 + t293 * t652 * t8 * t116 / 0.3e1 - 0.32320800000000000000e0 * t309 * t310 * t152 * t258 + t662 * t271 * t128 * t190 / 0.9e1 - t670 - t270 * t671 * t8 * t85 / 0.3e1 + 0.64641600000000000000e0 * t200 * t573 * t225 * t128 - 0.64641600000000000000e0 * t200 * t284 * t97 * t110 * t8 + t686 * t294 * t133 * t249 / 0.9e1 - t694 - 0.10773600000000000000e0 * t293 * t310 * t152 * t249 - t702;
  t706 = -t253 - 0.2e1 / 0.3e1 * t256 - t593 - t326 - 0.64641600000000000000e0 * t281 - t288 - t595 - t337 - t596 - t347 + t9 * (t629 + t703);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = t591 + t706;

  t708 = -t198 + t452 - t222 + t456 + t305 - t331 - t346 - t370 - t257 - t593 - 0.2e1 / 0.3e1 * t277;
  t725 = t309 * t699 * t338;
  t756 = t16 * t349;
  t762 = t7 * t509 * t322;
  t765 = -t207 - 0.3e1 * t464;
  t776 = t7 * t195 * t328;
  t779 = t7 * t536 * t333;
  t781 = -0.32320800000000000000e0 * t309 * t310 * t366 * t116 + t662 * t271 * t321 * t85 / 0.9e1 - t270 * t671 * t128 * t8 / 0.3e1 - 0.21547200000000000000e0 * t725 - 0.10773600000000000000e0 * t270 * t201 * t110 * t321 - t270 * t271 * t327 * t85 / 0.6e1 - 0.32320800000000000000e0 * t200 * t201 * t110 * t327 + t686 * t294 * t332 * t116 / 0.9e1 + t293 * t652 * t133 * t8 / 0.3e1 + 0.64641600000000000000e0 * t309 * t284 * t139 * t152 * t8 - t293 * t294 * t342 * t116 / 0.6e1 + 0.64641600000000000000e0 * t309 * t756 * t350 * t116 - t762 / 0.18e2 - t7 * t80 * t47 * t765 / 0.2e1 + t7 * t115 * t74 * t765 / 0.2e1 - t776 / 0.6e1 - t779 / 0.18e2;
  t783 = t7 * t254 * t343;
  t786 = t7 * t121 * t351;
  t789 = t7 * t121 * t367;
  t803 = -t783 / 0.6e1 + 0.16160400000000000000e0 * t786 - 0.80802000000000000000e-1 * t789 + t601 / 0.3e1 + 0.2e1 / 0.9e1 * t604 - t608 / 0.3e1 + 0.2e1 / 0.9e1 * t611 + 0.10773600000000000000e0 * t614 + 0.53868000000000000000e-1 * t472 + t515 / 0.9e1 + t542 / 0.9e1 - 0.21547200000000000000e0 * t293 * t310 * t338 * t116 - t547 - t551 - t643 - t670 - t694 - t702;
  t806 = -0.64641600e0 * t281 - t288 - t595 - 0.2e1 / 0.3e1 * t300 - t596 - 0.32320800000000000000e0 * t316 - t325 - t336 - t341 + t354 + t9 * (t781 + t803);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = t708 + t806;

  t846 = -0.3e1 * t207 - 0.3e1 * t464;
  t861 = t64 * t64;
  t877 = -t293 * t294 * t133 * t342 / 0.2e1 - 0.32320800000000000000e0 * t293 * t310 * t152 * t332 - 0.96962400000000000000e0 * t309 * t310 * t366 * t133 - 0.96962400000000000000e0 * t309 * t310 * t152 * t342 + 0.14544360000000000000e1 * t4 * t173 * t756 * t152 * t366 + 0.19392480000000000000e1 * t309 * t756 * t350 * t133 - t270 * t271 * t128 * t327 / 0.2e1 - 0.64641600000000000000e0 * t725 - t7 * t80 * t47 * t846 / 0.2e1 + t7 * t115 * t74 * t846 / 0.2e1 - 0.24240600000000000000e0 * t7 * t54 * t139 * (-0.1540e4 / 0.6561e4 * t23 * sigma[2] / t57 / t65 - 0.81523709046478946067e-2 * t35 * t63 / t56 / t861) + t7 * t503 * t47 * t321 * t128 / 0.9e1;
  t883 = t138 * t138;
  t884 = 0.1e1 / t883;
  t899 = t7 * t530 * t74 * t332 * t133 / 0.9e1 - 0.14544360000000000000e1 * t7 * t54 * t884 * t350 * t152 - t762 / 0.6e1 - t776 / 0.2e1 - t779 / 0.6e1 - t783 / 0.2e1 + 0.48481200000000000000e0 * t786 - 0.24240600000000000000e0 * t789 + t604 / 0.3e1 + t611 / 0.3e1 + 0.16160400000000000000e0 * t614 - t547 - t551;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = t452 + t456 - 0.3e1 / 0.2e1 * t330 - 0.3e1 / 0.2e1 * t345 - 0.72721800000000000000e0 * t369 - t277 - t300 - 0.48481200000000000000e0 * t316 - t324 / 0.2e1 - t335 / 0.2e1 - 0.19392480000000000000e1 * t340 + 0.14544360000000000000e1 * t353 + t9 * (t877 + t899);

  t903 = t200 * t201 * t379;
  t907 = 0.10773600000000000000e0 * t7 * t92 * t169;
  t909 = t572 * t573 * t384;
  t912 = t7 * t17 * t394;
  t914 = t188 * t97;
  t919 = t14 * t224;
  t932 = t15 * t521;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.86188800000000000000e0 * t903 - t907 + 0.12928320000000000000e1 * t909 - 0.64641600000000000000e0 * t912 - 0.10773600000000000000e0 * t377 * t914 * t168 * t190 + 0.12928320000000000000e1 * t377 * t919 * t379 * t110 - 0.64641600000000000000e0 * t377 * t378 * t393 * t85 - 0.32320800000000000000e0 * t377 * t378 * t168 * t209 - 0.14544360000000000000e1 * t377 * t932 * t168 * t225 + 0.96962400000000000000e0 * t377 * t383 * t393 * t110 + 0.48481200000000000000e0 * t377 * t383 * t168 * t241 - 0.24240600000000000000e0 * t161 * t162 * t97 * (0.110e3 / 0.2187e4 * t23 * t231 + 0.22233738830857894383e-2 * t35 * sigma[0] * t237);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[1] = 0.0e0;

  t956 = t309 * t310 * t402;
  t960 = 0.10773600000000000000e0 * t7 * t121 * t180;
  t961 = t247 * t139;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[2] = -0.86188800000000000000e0 * t956 - t960 - 0.10773600000000000000e0 * t377 * t961 * t179 * t249 - 0.32320800000000000000e0 * t377 * t401 * t179 * t258;

  t973 = t16 * t1;
  t974 = t973 * t376;
  t975 = t974 * t407;
  t990 = t215 * t1 * t376;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[3] = -0.43094400000000000000e0 * t903 - t907 + 0.64641600000000000000e0 * t909 - 0.32320800000000000000e0 * t912 - 0.43094400000000000000e0 * t975 - 0.10773600000000000000e0 * t377 * t914 * t406 * t85 + 0.64641600000000000000e0 * t377 * t919 * t406 * t110 - 0.32320800000000000000e0 * t377 * t378 * t393 * t128 - 0.32320800000000000000e0 * t990 * t378 * t168 * t8;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[4] = 0.0e0;

  t996 = t974 * t411;
  t1006 = t974 * t416;
  t1008 = t52 * t349;
  t1013 = t973 * t3;
  t1014 = t1013 * t426;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[5] = -0.43094400000000000000e0 * t956 - t960 - 0.43094400000000000000e0 * t996 - 0.10773600000000000000e0 * t377 * t961 * t410 * t116 + 0.32320800000000000000e0 * t990 * t401 * t179 * t8 + 0.64641600000000000000e0 * t1006 + 0.64641600000000000000e0 * t377 * t1008 * t415 * t116 - 0.32320800000000000000e0 * t1014 - 0.32320800000000000000e0 * t377 * t401 * t424 * t116;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[6] = -0.86188800000000000000e0 * t975 - t907 - 0.10773600000000000000e0 * t377 * t914 * t168 * t321 - 0.32320800000000000000e0 * t377 * t378 * t168 * t327;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[7] = 0.0e0;

  t1048 = t53 * t884;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[8] = -0.86188800000000000000e0 * t996 - t960 + 0.12928320000000000000e1 * t1006 - 0.64641600000000000000e0 * t1014 - 0.10773600000000000000e0 * t377 * t961 * t179 * t332 + 0.12928320000000000000e1 * t377 * t1008 * t410 * t152 - 0.64641600000000000000e0 * t377 * t401 * t424 * t133 - 0.32320800000000000000e0 * t377 * t401 * t179 * t342 - 0.14544360000000000000e1 * t377 * t1048 * t179 * t350 + 0.96962400000000000000e0 * t377 * t414 * t424 * t152 + 0.48481200000000000000e0 * t377 * t414 * t179 * t366 - 0.24240600000000000000e0 * t161 * t173 * t139 * (0.110e3 / 0.2187e4 * t23 * t356 + 0.22233738830857894383e-2 * t35 * sigma[2] * t362);

  t1072 = 0.64641600000000000000e0 * t1013 * t431;
  t1086 = 0.21274704059340547680e-4 * t974 * t436;
  t1088 = t160 * t376 * t14;
  t1089 = t97 * t32;
  t1090 = t34 * t40;
  t1096 = t160 * t376 * t15;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = t1072 + 0.64641600000000000000e0 * t377 * t919 * t429 * t85 - 0.14544360000000000000e1 * t377 * t932 * t429 * t110 + 0.96962400000000000000e0 * t377 * t383 * t168 * t393 - t1086 - 0.21274704059340547680e-4 * t1088 * t1089 * t1090 * t85 + 0.31912056089010821520e-4 * t1096 * t224 * t32 * t1090 * t110 + 0.85098816237362190720e-4 * t377 * t434 * t35 * t106;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[1] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[2] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[3] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[4] = 0.0e0;

  t1107 = 0.64641600000000000000e0 * t1013 * t441;
  t1113 = 0.21274704059340547680e-4 * t974 * t446;
  t1115 = t160 * t376 * t52;
  t1116 = t139 * t32;
  t1117 = t34 * t67;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[5] = t1107 + 0.64641600000000000000e0 * t377 * t1008 * t439 * t116 - t1113 - 0.21274704059340547680e-4 * t1115 * t1116 * t1117 * t116;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[6] = t1072 + 0.64641600000000000000e0 * t377 * t919 * t429 * t128 - t1086 - 0.21274704059340547680e-4 * t1088 * t1089 * t1090 * t128;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[8] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[9] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[10] = 0.0e0;

  t1147 = t160 * t376 * t53;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[11] = t1107 + 0.64641600000000000000e0 * t377 * t1008 * t439 * t133 - 0.14544360000000000000e1 * t377 * t1048 * t439 * t152 + 0.96962400000000000000e0 * t377 * t414 * t179 * t424 - t1113 - 0.21274704059340547680e-4 * t1115 * t1116 * t1117 * t133 + 0.31912056089010821520e-4 * t1147 * t349 * t32 * t1117 * t152 + 0.85098816237362190720e-4 * t377 * t444 * t35 * t148;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.14544360000000000000e1 * t161 * t162 * t521 * t429 * t168 + 0.95736168267032464562e-4 * t1096 * t224 * t168 * t435;

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
    v3sigma3[9] = -0.14544360000000000000e1 * t161 * t173 * t884 * t439 * t179 + 0.95736168267032464562e-4 * t1147 * t349 * t179 * t445;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}

