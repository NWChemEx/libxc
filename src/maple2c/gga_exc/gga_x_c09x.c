/* 
  This file was generated automatically with scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/gga_x_c09x.mpl
  Type of functional: gga_exc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t5, t6, t7, t8, t9, t10;
  double t11, t12, t13, t14, t15, t16, t17, t18;
  double t19, t20, t22, t23, t26, t28, t29, t33;
  double t35, t37, t42, t43, t44, t47, t48, t51;
  double t54, t55, t56, t57, t60, t61, t62, t65;
  double t68, t75, t78, t79, t86, t89, t90, t99;
  double t100, t105, t106, t110, t111, t112, t113, t117;
  double t123, t128, t133, t134, t139, t149, t154, t162;
  double t179, t185, t189, t191, t194, t201, t224, t228;
  double t253;


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
  t16 = 0.1e1 / t15;
  t17 = t12 * t16;
  t18 = t17 * sigma[0];
  t19 = rho[0] * rho[0];
  t20 = t10 * t10;
  t22 = 0.1e1 / t20 / t19;
  t23 = t9 * t22;
  t26 = t17 * sigma[0] * t9 * t22;
  t28 = exp(-0.20125000000000000000e-2 * t26);
  t29 = t23 * t28;
  t33 = exp(-0.10062500000000000000e-2 * t26);
  t35 = 0.2245e1 + 0.25708333333333333333e-2 * t18 * t29 - 0.1245e1 * t33;
  t37 = t7 * t11 * t35;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.16e2 * t37;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t42 = t10 * rho[0] * t1 * t3;
  t43 = t6 * t9;
  t44 = t19 * rho[0];
  t47 = t9 / t20 / t44;
  t48 = t47 * t28;
  t51 = t12 * t12;
  t54 = t51 / t14 / t13;
  t55 = sigma[0] * sigma[0];
  t56 = t54 * t55;
  t57 = t19 * t19;
  t60 = 0.1e1 / t10 / t57 / t19;
  t61 = t8 * t60;
  t62 = t61 * t28;
  t65 = t47 * t33;
  t68 = -0.68555555555555555555e-2 * t18 * t48 + 0.27593611111111111110e-4 * t56 * t62 - 0.33407500000000000000e-2 * t18 * t65;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t37 / 0.4e1 - 0.3e1 / 0.16e2 * t42 * t43 * t68;

  t75 = t57 * rho[0];
  t78 = t8 / t10 / t75;
  t79 = t78 * t28;
  t86 = t43 * (0.25708333333333333333e-2 * t17 * t29 - 0.10347604166666666667e-4 * t54 * sigma[0] * t79 + 0.12527812500000000000e-2 * t17 * t23 * t33);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.3e1 / 0.16e2 * t42 * t86;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t89 = 0.1e1 / t20;
  t90 = t9 * t89;
  t99 = t9 / t20 / t57;
  t100 = t99 * t28;
  t105 = 0.1e1 / t10 / t57 / t44;
  t106 = t8 * t105;
  t110 = t55 * sigma[0];
  t111 = t57 * t57;
  t112 = t111 * t19;
  t113 = 0.1e1 / t112;
  t117 = t99 * t33;
  t123 = 0.25137037037037037037e-1 * t18 * t100 - 0.24834249999999999999e-3 * t56 * t106 * t28 + 0.18242943617400669616e-7 * t110 * t113 * t28 + 0.12249416666666666667e-1 * t18 * t117 - 0.17928691666666666666e-4 * t56 * t106 * t33;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t7 * t90 * t35 / 0.12e2 - t7 * t11 * t68 / 0.2e1 - 0.3e1 / 0.16e2 * t42 * t43 * t123;

  t128 = t10 * t1 * t3;
  t133 = t54 * t8;
  t134 = t60 * sigma[0];
  t139 = 0.1e1 / t111 / rho[0];
  t149 = t43 * (-0.68555555555555555555e-2 * t17 * t48 + 0.82780833333333333334e-4 * t133 * t134 * t28 - 0.68411038565252511063e-8 * t55 * t139 * t28 - 0.33407500000000000000e-2 * t17 * t65 + 0.67232593749999999999e-5 * t133 * t134 * t33);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t128 * t86 / 0.4e1 - 0.3e1 / 0.16e2 * t42 * t149;

  t154 = 0.1e1 / t111;
  t162 = t43 * (-0.20695208333333333334e-4 * t54 * t79 + 0.25654139461969691649e-8 * sigma[0] * t154 * t28 - 0.25212222656250000000e-5 * t54 * t78 * t33);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.3e1 / 0.16e2 * t42 * t162;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t179 = t9 / t20 / t75;
  t185 = t8 / t10 / t111;
  t189 = t111 * t44;
  t191 = t110 / t189;
  t194 = t55 * t55;
  t201 = t16 * t9 * t28;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t7 * t9 / t20 / rho[0] * t35 / 0.18e2 - t7 * t90 * t68 / 0.4e1 - 0.3e1 / 0.4e1 * t7 * t11 * t123 - 0.3e1 / 0.16e2 * t42 * t43 * (-0.11730617283950617284e0 * t18 * t179 * t28 + 0.20909825308641975308e-2 * t56 * t185 * t28 - 0.34661592873061272270e-6 * t191 * t28 + 0.97903797413383593606e-10 * t194 / t20 / t111 / t75 * t12 * t201 - 0.57163944444444444446e-1 * t18 * t179 * t33 + 0.19721560833333333333e-3 * t56 * t185 * t33 - 0.59265913020905627571e-8 * t191 * t33);

  t224 = t105 * sigma[0];
  t228 = t113 * t55;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -t89 * t1 * t3 * t86 / 0.12e2 - t128 * t149 / 0.2e1 - 0.3e1 / 0.16e2 * t42 * t43 * (0.25137037037037037037e-1 * t17 * t100 - 0.59786157407407407408e-3 * t133 * t224 * t28 + 0.11629876556092926881e-6 * t228 * t28 - 0.36713924030018847604e-10 * t110 / t20 / t111 / t57 * t12 * t201 + 0.12249416666666666667e-1 * t17 * t117 - 0.60509334374999999999e-4 * t133 * t224 * t33 + 0.22224717382839610340e-8 * t228 * t33);

  t253 = t139 * sigma[0];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t128 * t162 / 0.4e1 - 0.3e1 / 0.16e2 * t42 * t43 * (0.11037444444444444445e-3 * t54 * t62 - 0.34205519282626255532e-7 * t253 * t28 + 0.13767721511257067852e-10 * t55 / t20 / t189 * t12 * t201 + 0.13446518750000000000e-4 * t54 * t61 * t33 - 0.83342690185648538775e-9 * t253 * t33);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.3e1 / 0.16e2 * t42 * t43 * (0.76962418385909074947e-8 * t154 * t28 - 0.51628955667214004444e-11 * sigma[0] / t20 / t112 * t12 * t201 + 0.31253508819618202039e-9 * t154 * t33);

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
  double t1, t3, t4, t5, t6, t7, t8, t9;
  double t10, t11, t12, t14, t15, t16, t18, t19;
  double t20, t22, t27, t29, t31, t35, t36, t37;
  double t39, t40, t44, t47, t48, t49, t52, t60;
  double t67, t69, t78, t81, t82, t89, t90, t96;
  double t97, t101, t102, t103, t104, t114, t118, t124;
  double t129, t140, t146, t154, t171, t177, t181, t183;
  double t186, t191, t213, t217, t243;


  t1 = M_CBRT3;
  t3 = POW_1_3(0.1e1 / M_PI);
  t4 = t1 * t3;
  t5 = M_CBRT4;
  t6 = t5 * t5;
  t7 = POW_1_3(rho[0]);
  t8 = t6 * t7;
  t9 = M_CBRT6;
  t10 = M_PI * M_PI;
  t11 = POW_1_3(t10);
  t12 = t11 * t11;
  t14 = t9 / t12;
  t15 = rho[0] * rho[0];
  t16 = t7 * t7;
  t18 = 0.1e1 / t16 / t15;
  t19 = sigma[0] * t18;
  t20 = t14 * t19;
  t22 = exp(-0.20125000000000000000e-2 * t20);
  t27 = exp(-0.10062500000000000000e-2 * t20);
  t29 = 0.2245e1 + 0.25708333333333333333e-2 * t14 * t19 * t22 - 0.1245e1 * t27;
  t31 = t4 * t8 * t29;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.3e1 / 0.8e1 * t31;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t35 = t7 * rho[0] * t1;
  t36 = t3 * t6;
  t37 = t15 * rho[0];
  t39 = 0.1e1 / t16 / t37;
  t40 = sigma[0] * t39;
  t44 = t9 * t9;
  t47 = t44 / t11 / t10;
  t48 = sigma[0] * sigma[0];
  t49 = t15 * t15;
  t52 = 0.1e1 / t7 / t49 / t15;
  t60 = -0.68555555555555555555e-2 * t14 * t40 * t22 + 0.13796805555555555555e-4 * t47 * t48 * t52 * t22 - 0.33407500000000000000e-2 * t14 * t40 * t27;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t31 / 0.2e1 - 0.3e1 / 0.8e1 * t35 * t36 * t60;

  t67 = t49 * rho[0];
  t69 = 0.1e1 / t7 / t67;
  t78 = t36 * (0.25708333333333333333e-2 * t14 * t18 * t22 - 0.51738020833333333333e-5 * t47 * sigma[0] * t69 * t22 + 0.12527812500000000000e-2 * t14 * t18 * t27);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.3e1 / 0.8e1 * t35 * t78;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t81 = 0.1e1 / t16;
  t82 = t6 * t81;
  t89 = 0.1e1 / t16 / t49;
  t90 = sigma[0] * t89;
  t96 = 0.1e1 / t7 / t49 / t37;
  t97 = t48 * t96;
  t101 = t48 * sigma[0];
  t102 = t49 * t49;
  t103 = t102 * t15;
  t104 = 0.1e1 / t103;
  t114 = 0.25137037037037037037e-1 * t14 * t90 * t22 - 0.12417125000000000000e-3 * t47 * t97 * t22 + 0.45607359043501674040e-8 * t101 * t104 * t22 + 0.12249416666666666667e-1 * t14 * t90 * t27 - 0.89643458333333333332e-5 * t47 * t97 * t27;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t4 * t82 * t29 / 0.6e1 - t4 * t8 * t60 - 0.3e1 / 0.8e1 * t35 * t36 * t114;

  t118 = t7 * t1;
  t124 = t52 * sigma[0];
  t129 = 0.1e1 / t102 / rho[0];
  t140 = t36 * (-0.68555555555555555555e-2 * t14 * t39 * t22 + 0.41390416666666666666e-4 * t47 * t124 * t22 - 0.17102759641313127765e-8 * t48 * t129 * t22 - 0.33407500000000000000e-2 * t14 * t39 * t27 + 0.33616296875000000000e-5 * t47 * t124 * t27);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t118 * t78 / 0.2e1 - 0.3e1 / 0.8e1 * t35 * t140;

  t146 = 0.1e1 / t102;
  t154 = t36 * (-0.10347604166666666667e-4 * t47 * t69 * t22 + 0.64135348654924229118e-9 * sigma[0] * t146 * t22 - 0.12606111328125000000e-5 * t47 * t69 * t27);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.3e1 / 0.8e1 * t35 * t154;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t171 = sigma[0] / t16 / t67;
  t177 = t48 / t7 / t102;
  t181 = t102 * t37;
  t183 = t101 / t181;
  t186 = t48 * t48;
  t191 = t14 * t22;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t4 * t6 / t16 / rho[0] * t29 / 0.9e1 - t4 * t82 * t60 / 0.2e1 - 0.3e1 / 0.2e1 * t4 * t8 * t114 - 0.3e1 / 0.8e1 * t35 * t36 * (-0.11730617283950617284e0 * t14 * t171 * t22 + 0.10454912654320987654e-2 * t47 * t177 * t22 - 0.86653982182653180677e-7 * t183 * t22 + 0.24475949353345898402e-10 * t186 / t16 / t102 / t67 * t191 - 0.57163944444444444446e-1 * t14 * t171 * t27 + 0.98607804166666666666e-4 * t47 * t177 * t27 - 0.14816478255226406893e-8 * t183 * t27);

  t213 = t96 * sigma[0];
  t217 = t104 * t48;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -t81 * t1 * t78 / 0.6e1 - t118 * t140 - 0.3e1 / 0.8e1 * t35 * t36 * (0.25137037037037037037e-1 * t14 * t89 * t22 - 0.29893078703703703703e-3 * t47 * t213 * t22 + 0.29074691390232317200e-7 * t217 * t22 - 0.91784810075047119006e-11 * t101 / t16 / t102 / t49 * t191 + 0.12249416666666666667e-1 * t14 * t89 * t27 - 0.30254667187500000000e-4 * t47 * t213 * t27 + 0.55561793457099025850e-9 * t217 * t27);

  t243 = t129 * sigma[0];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t118 * t154 / 0.2e1 - 0.3e1 / 0.8e1 * t35 * t36 * (0.55187222222222222224e-4 * t47 * t52 * t22 - 0.85513798206565638826e-8 * t243 * t22 + 0.34419303778142669627e-11 * t48 / t16 / t181 * t191 + 0.67232593750000000000e-5 * t47 * t52 * t27 - 0.20835672546412134694e-9 * t243 * t27);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.3e1 / 0.8e1 * t35 * t36 * (0.19240604596477268736e-8 * t146 * t22 - 0.12907238916803501110e-11 * sigma[0] / t16 / t103 * t191 + 0.78133772049045505101e-10 * t146 * t27);

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
  double t29, t30, t32, t37, t39, t41, t43, t44;
  double t45, t46, t47, t48, t49, t51, t52, t53;
  double t55, t60, t62, t64, t66, t67, t68, t69;
  double t70, t71, t73, t74, t76, t77, t78, t79;
  double t80, t82, t83, t84, t86, t87, t91, t94;
  double t95, t96, t99, t107, t109, t110, t111, t112;
  double t113, t115, t116, t117, t119, t120, t124, t125;
  double t127, t128, t129, t130, t132, t133, t134, t136;
  double t137, t141, t142, t145, t153, t155, t156, t160;
  double t161, t162, t166, t168, t176, t180, t184, t186;
  double t194, t198, t200, t201, t202, t203, t204, t205;
  double t207, t208, t209, t211, t212, t213, t215, t216;
  double t217, t218, t219, t220, t222, t223, t225, t226;
  double t228, t229, t231, t232, t234, t235, t241, t242;
  double t246, t247, t248, t249, t259, t261, t262, t263;
  double t264, t265, t266, t267, t269, t270, t271, t273;
  double t274, t275, t276, t278, t279, t280, t282, t283;
  double t284, t286, t287, t288, t289, t291, t294, t296;
  double t298, t301, t302, t303, t305, t309, t310, t311;
  double t312, t314, t317, t319, t320, t322, t325, t327;
  double t330, t332, t335, t336, t338, t339, t340, t341;
  double t342, t344, t345, t346, t347, t349, t350, t351;
  double t352, t354, t355, t356, t358, t359, t360, t362;
  double t363, t369, t370, t374, t375, t376, t377, t387;
  double t389, t390, t391, t394, t396, t397, t404, t409;
  double t419, t424, t425, t426, t431, t436, t442, t447;
  double t457, t458, t464, t471, t472, t478, t485, t486;
  double t493, t495, t503, t505, t515, t517, t519, t527;
  double t529, t539, t542, t545, t549, t555, t559, t561;
  double t564, t569, t585, t586, t592, t594, t600, t602;
  double t605, t606, t612, t614, t620, t622, t624, t629;
  double t632, t633, t639, t647, t649, t663, t669, t677;
  double t686, t696, t702, t705, t708, t714, t722, t725;
  double t731, t734, t769, t774, t780, t783, t786, t789;
  double t792, t803, t820, t823, t858, t864, t868, t870;
  double t873, t878, t896, t918, t922, t926, t928, t943;
  double t947, t969, t973, t985, t986, t989, t999, t1005;
  double t1015, t1045, t1049, t1070, t1079, t1096, t1113;


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
  t29 = sigma[0] * t28;
  t30 = t23 * t29;
  t32 = exp(-0.20125000000000000000e-2 * t30);
  t37 = exp(-0.10062500000000000000e-2 * t30);
  t39 = 0.2245e1 + 0.25708333333333333333e-2 * t23 * t29 * t32 - 0.1245e1 * t37;
  t41 = t7 * t17 * t39;
  t43 = 0.1e1 / 0.2e1 - t11 / 0.2e1;
  t44 = POW_1_3(t43);
  t45 = t44 * t43;
  t46 = t45 * t16;
  t47 = rho[1] * rho[1];
  t48 = POW_1_3(rho[1]);
  t49 = t48 * t48;
  t51 = 0.1e1 / t49 / t47;
  t52 = sigma[2] * t51;
  t53 = t23 * t52;
  t55 = exp(-0.20125000000000000000e-2 * t53);
  t60 = exp(-0.10062500000000000000e-2 * t53);
  t62 = 0.2245e1 + 0.25708333333333333333e-2 * t23 * t52 * t55 - 0.1245e1 * t60;
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
  t84 = t24 * rho[0];
  t86 = 0.1e1 / t26 / t84;
  t87 = sigma[0] * t86;
  t91 = t18 * t18;
  t94 = t91 / t20 / t19;
  t95 = sigma[0] * sigma[0];
  t96 = t24 * t24;
  t99 = 0.1e1 / t25 / t96 / t24;
  t107 = -0.68555555555555555555e-2 * t23 * t87 * t32 + 0.13796805555555555555e-4 * t94 * t95 * t99 * t32 - 0.33407500000000000000e-2 * t23 * t87 * t37;
  t109 = t7 * t17 * t107;
  t110 = 0.3e1 / 0.8e1 * t109;
  t111 = t44 * t16;
  t112 = -t73;
  t113 = t62 * t112;
  t115 = t7 * t111 * t113;
  t116 = t115 / 0.2e1;
  t117 = t45 * t79;
  t119 = t7 * t117 * t62;
  t120 = t119 / 0.8e1;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t66 - t67 + t9 * (-t77 - t83 - t110 - t116 - t120);

  t124 = -t10 / 0.2e1 - t71 / 0.2e1;
  t125 = t39 * t124;
  t127 = t7 * t68 * t125;
  t128 = t127 / 0.2e1;
  t129 = -t124;
  t130 = t62 * t129;
  t132 = t7 * t111 * t130;
  t133 = t132 / 0.2e1;
  t134 = t47 * rho[1];
  t136 = 0.1e1 / t49 / t134;
  t137 = sigma[2] * t136;
  t141 = sigma[2] * sigma[2];
  t142 = t47 * t47;
  t145 = 0.1e1 / t48 / t142 / t47;
  t153 = -0.68555555555555555555e-2 * t23 * t137 * t55 + 0.13796805555555555555e-4 * t94 * t141 * t145 * t55 - 0.33407500000000000000e-2 * t23 * t137 * t60;
  t155 = t7 * t46 * t153;
  t156 = 0.3e1 / 0.8e1 * t155;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = -t66 - t67 + t9 * (-t128 - t83 - t133 - t120 - t156);

  t160 = t16 * t9 * t1;
  t161 = t160 * t3;
  t162 = t6 * t15;
  t166 = t96 * rho[0];
  t168 = 0.1e1 / t25 / t166;
  t176 = 0.25708333333333333333e-2 * t23 * t28 * t32 - 0.51738020833333333333e-5 * t94 * sigma[0] * t168 * t32 + 0.12527812500000000000e-2 * t23 * t28 * t37;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.3e1 / 0.8e1 * t161 * t162 * t176;

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[1] = 0.0e0;

  t180 = t6 * t45;
  t184 = t142 * rho[1];
  t186 = 0.1e1 / t48 / t184;
  t194 = 0.25708333333333333333e-2 * t23 * t51 * t55 - 0.51738020833333333333e-5 * t94 * sigma[2] * t186 * t55 + 0.12527812500000000000e-2 * t23 * t51 * t60;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[2] = -0.3e1 / 0.8e1 * t161 * t180 * t194;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t198 = t82 / 0.4e1;
  t200 = t119 / 0.4e1;
  t201 = t14 * t14;
  t202 = 0.1e1 / t201;
  t203 = t202 * t16;
  t204 = t73 * t73;
  t205 = t39 * t204;
  t207 = t7 * t203 * t205;
  t208 = t207 / 0.6e1;
  t209 = t14 * t79;
  t211 = t7 * t209 * t74;
  t212 = t211 / 0.3e1;
  t213 = t107 * t73;
  t215 = t7 * t68 * t213;
  t216 = t69 * t9;
  t217 = 0.1e1 / t216;
  t218 = t8 * t217;
  t219 = -t70 + t218;
  t220 = t39 * t219;
  t222 = t7 * t68 * t220;
  t223 = t222 / 0.2e1;
  t225 = 0.1e1 / t78 / t9;
  t226 = t15 * t225;
  t228 = t7 * t226 * t39;
  t229 = t228 / 0.12e2;
  t231 = t7 * t80 * t107;
  t232 = t231 / 0.4e1;
  t234 = 0.1e1 / t26 / t96;
  t235 = sigma[0] * t234;
  t241 = 0.1e1 / t25 / t96 / t84;
  t242 = t95 * t241;
  t246 = t95 * sigma[0];
  t247 = t96 * t96;
  t248 = t247 * t24;
  t249 = 0.1e1 / t248;
  t259 = 0.25137037037037037037e-1 * t23 * t235 * t32 - 0.12417125000000000000e-3 * t94 * t242 * t32 + 0.45607359043501674040e-8 * t246 * t249 * t32 + 0.12249416666666666667e-1 * t23 * t235 * t37 - 0.89643458333333333332e-5 * t94 * t242 * t37;
  t261 = t7 * t17 * t259;
  t262 = 0.3e1 / 0.8e1 * t261;
  t263 = t44 * t44;
  t264 = 0.1e1 / t263;
  t265 = t264 * t16;
  t266 = t112 * t112;
  t267 = t62 * t266;
  t269 = t7 * t265 * t267;
  t270 = t269 / 0.6e1;
  t271 = t44 * t79;
  t273 = t7 * t271 * t113;
  t274 = t273 / 0.3e1;
  t275 = -t219;
  t276 = t62 * t275;
  t278 = t7 * t111 * t276;
  t279 = t278 / 0.2e1;
  t280 = t45 * t225;
  t282 = t7 * t280 * t62;
  t283 = t282 / 0.12e2;
  t284 = -t208 - t212 - t215 - t223 + t229 - t232 - t262 - t270 - t274 - t279 + t283;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t76 - t198 - 0.3e1 / 0.4e1 * t109 - t115 - t200 + t9 * t284;

  t286 = t6 * t202;
  t287 = t4 * t286;
  t288 = t16 * t39;
  t289 = t124 * t73;
  t291 = t287 * t288 * t289;
  t294 = t7 * t209 * t125;
  t296 = t107 * t124;
  t298 = t7 * t68 * t296;
  t301 = 0.1e1 / t78 / t69;
  t302 = t14 * t301;
  t303 = t39 * t8;
  t305 = t7 * t302 * t303;
  t309 = t6 * t264;
  t310 = t4 * t309;
  t311 = t16 * t62;
  t312 = t129 * t112;
  t314 = t310 * t311 * t312;
  t317 = t7 * t271 * t130;
  t319 = t44 * t301;
  t320 = t62 * t8;
  t322 = t7 * t319 * t320;
  t325 = t153 * t112;
  t327 = t7 * t111 * t325;
  t330 = t7 * t117 * t153;
  t332 = -t291 / 0.6e1 - t294 / 0.6e1 - t298 / 0.2e1 - t305 / 0.2e1 - t211 / 0.6e1 + t229 - t231 / 0.8e1 - t314 / 0.6e1 - t317 / 0.6e1 + t322 / 0.2e1 - t273 / 0.6e1 + t283 - t327 / 0.2e1 - t330 / 0.8e1;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = t9 * t332 - t110 - t116 - t128 - t133 - t156 - t198 - t200 - t77;

  t335 = t124 * t124;
  t336 = t39 * t335;
  t338 = t7 * t203 * t336;
  t339 = t338 / 0.6e1;
  t340 = t294 / 0.3e1;
  t341 = t70 + t218;
  t342 = t39 * t341;
  t344 = t7 * t68 * t342;
  t345 = t344 / 0.2e1;
  t346 = t129 * t129;
  t347 = t62 * t346;
  t349 = t7 * t265 * t347;
  t350 = t349 / 0.6e1;
  t351 = t317 / 0.3e1;
  t352 = t153 * t129;
  t354 = t7 * t111 * t352;
  t355 = -t341;
  t356 = t62 * t355;
  t358 = t7 * t111 * t356;
  t359 = t358 / 0.2e1;
  t360 = t330 / 0.4e1;
  t362 = 0.1e1 / t49 / t142;
  t363 = sigma[2] * t362;
  t369 = 0.1e1 / t48 / t142 / t134;
  t370 = t141 * t369;
  t374 = t141 * sigma[2];
  t375 = t142 * t142;
  t376 = t375 * t47;
  t377 = 0.1e1 / t376;
  t387 = 0.25137037037037037037e-1 * t23 * t363 * t55 - 0.12417125000000000000e-3 * t94 * t370 * t55 + 0.45607359043501674040e-8 * t374 * t377 * t55 + 0.12249416666666666667e-1 * t23 * t363 * t60 - 0.89643458333333333332e-5 * t94 * t370 * t60;
  t389 = t7 * t46 * t387;
  t390 = 0.3e1 / 0.8e1 * t389;
  t391 = -t339 - t340 - t345 + t229 - t350 - t351 - t354 - t359 + t283 - t360 - t390;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = -t127 - t198 - t132 - t200 - 0.3e1 / 0.4e1 * t155 + t9 * t391;

  t394 = t7 * t17 * t176;
  t396 = t6 * t14;
  t397 = t176 * t73;
  t404 = t99 * sigma[0];
  t409 = 0.1e1 / t247 / rho[0];
  t419 = -0.68555555555555555555e-2 * t23 * t86 * t32 + 0.41390416666666666666e-4 * t94 * t404 * t32 - 0.17102759641313127765e-8 * t95 * t409 * t32 - 0.33407500000000000000e-2 * t23 * t86 * t37 + 0.33616296875000000000e-5 * t94 * t404 * t37;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t394 / 0.2e1 - t161 * t396 * t397 / 0.2e1 - 0.3e1 / 0.8e1 * t161 * t162 * t419;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[1] = 0.0e0;

  t424 = t7 * t46 * t194;
  t425 = t6 * t44;
  t426 = t194 * t112;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[2] = -t161 * t425 * t426 / 0.2e1 - t424 / 0.2e1;

  t431 = t396 * t176 * t124;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[3] = -t161 * t431 / 0.2e1 - t394 / 0.2e1;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[4] = 0.0e0;

  t436 = t425 * t194 * t129;
  t442 = t145 * sigma[2];
  t447 = 0.1e1 / t375 / rho[1];
  t457 = -0.68555555555555555555e-2 * t23 * t136 * t55 + 0.41390416666666666666e-4 * t94 * t442 * t55 - 0.17102759641313127765e-8 * t141 * t447 * t55 - 0.33407500000000000000e-2 * t23 * t136 * t60 + 0.33616296875000000000e-5 * t94 * t442 * t60;
  t458 = t180 * t457;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[5] = -t424 / 0.2e1 - t161 * t436 / 0.2e1 - 0.3e1 / 0.8e1 * t161 * t458;

  t464 = 0.1e1 / t247;
  t471 = -0.10347604166666666667e-4 * t94 * t168 * t32 + 0.64135348654924229118e-9 * sigma[0] * t464 * t32 - 0.12606111328125000000e-5 * t94 * t168 * t37;
  t472 = t162 * t471;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = -0.3e1 / 0.8e1 * t161 * t472;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[1] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[2] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[3] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[4] = 0.0e0;

  t478 = 0.1e1 / t375;
  t485 = -0.10347604166666666667e-4 * t94 * t186 * t55 + 0.64135348654924229118e-9 * sigma[2] * t478 * t55 - 0.12606111328125000000e-5 * t94 * t186 * t60;
  t486 = t180 * t485;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[5] = -0.3e1 / 0.8e1 * t161 * t486;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t493 = t228 / 0.4e1;
  t495 = t282 / 0.4e1;
  t503 = t7 * t209 * t213;
  t505 = t7 * t209 * t220;
  t515 = t69 * t69;
  t517 = t8 / t515;
  t519 = 0.3e1 * t217 - 0.3e1 * t517;
  t527 = 0.5e1 / 0.36e2 * t7 * t15 * t301 * t39;
  t529 = t7 * t271 * t276;
  t539 = 0.5e1 / 0.36e2 * t7 * t45 * t301 * t62;
  t542 = t7 * t226 * t107;
  t545 = t7 * t80 * t259;
  t549 = sigma[0] / t26 / t166;
  t555 = t95 / t25 / t247;
  t559 = t247 * t84;
  t561 = t246 / t559;
  t564 = t95 * t95;
  t569 = t23 * t32;
  t585 = 0.1e1 / t201 / t13;
  t586 = t585 * t16;
  t592 = t202 * t79;
  t594 = t7 * t592 * t205;
  t600 = t14 * t225;
  t602 = t7 * t600 * t74;
  t605 = 0.1e1 / t263 / t43;
  t606 = t605 * t16;
  t612 = t264 * t79;
  t614 = t7 * t612 * t267;
  t620 = t44 * t225;
  t622 = t7 * t620 * t113;
  t624 = t542 / 0.4e1 - 0.3e1 / 0.8e1 * t545 - 0.3e1 / 0.8e1 * t7 * t17 * (-0.11730617283950617284e0 * t23 * t549 * t32 + 0.10454912654320987654e-2 * t94 * t555 * t32 - 0.86653982182653180677e-7 * t561 * t32 + 0.24475949353345898402e-10 * t564 / t26 / t247 / t166 * t569 - 0.57163944444444444446e-1 * t23 * t549 * t37 + 0.98607804166666666666e-4 * t94 * t555 * t37 - 0.14816478255226406893e-8 * t561 * t37) + t7 * t586 * t39 * t204 * t73 / 0.9e1 - t594 / 0.6e1 - t287 * t288 * t73 * t219 / 0.2e1 + t602 / 0.3e1 + t7 * t606 * t62 * t266 * t112 / 0.9e1 - t614 / 0.6e1 - t310 * t311 * t112 * t275 / 0.2e1 + t622 / 0.3e1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -t207 / 0.2e1 - t211 - t269 / 0.2e1 - t273 - 0.3e1 * t215 - 0.3e1 / 0.2e1 * t222 + t493 - 0.3e1 / 0.2e1 * t278 + t495 - 0.3e1 / 0.4e1 * t231 - 0.9e1 / 0.8e1 * t261 + t9 * (-t7 * t203 * t107 * t204 / 0.2e1 - t503 - t505 / 0.2e1 - 0.3e1 / 0.2e1 * t7 * t68 * t259 * t73 - 0.3e1 / 0.2e1 * t7 * t68 * t107 * t219 - t7 * t68 * t39 * t519 / 0.2e1 - t527 - t529 / 0.2e1 + t7 * t111 * t62 * t519 / 0.2e1 - t539 + t624);

  t629 = t291 / 0.3e1;
  t632 = t314 / 0.3e1;
  t633 = t301 * t39;
  t639 = t4 * t6 * t605;
  t647 = t310 * t79 * t62 * t312 / 0.9e1;
  t649 = t7 * t280 * t153;
  t663 = t301 * t62;
  t669 = t4 * t6 * t585;
  t677 = t287 * t79 * t39 * t289 / 0.9e1;
  t686 = -t287 * t633 * t8 * t73 / 0.3e1 + t639 * t311 * t129 * t266 / 0.9e1 - t647 + t649 / 0.12e2 - t287 * t16 * t107 * t289 / 0.3e1 - t287 * t288 * t124 * t219 / 0.6e1 - t310 * t311 * t129 * t275 / 0.6e1 + t310 * t663 * t8 * t112 / 0.3e1 + t669 * t288 * t124 * t204 / 0.9e1 - t677 - t527 - t539 + t542 / 0.6e1 - t545 / 0.8e1 - t7 * t302 * t39 / 0.2e1 + t7 * t319 * t62 / 0.2e1;
  t696 = t7 * t209 * t296 / 0.3e1;
  t702 = t7 * t600 * t125;
  t705 = 0.1e1 / t78 / t216;
  t708 = t7 * t14 * t705 * t303;
  t714 = t7 * t620 * t130;
  t722 = t7 * t271 * t325 / 0.3e1;
  t725 = t7 * t44 * t705 * t320;
  t731 = -t503 / 0.3e1 - t505 / 0.6e1 - t529 / 0.6e1 - t594 / 0.18e2 + 0.2e1 / 0.9e1 * t602 - t614 / 0.18e2 + 0.2e1 / 0.9e1 * t622 - t696 - t7 * t68 * t259 * t124 / 0.2e1 + t702 / 0.9e1 + 0.7e1 / 0.6e1 * t708 - t7 * t302 * t107 * t8 + t714 / 0.9e1 - t7 * t265 * t153 * t266 / 0.6e1 - t722 - 0.7e1 / 0.6e1 * t725 - t7 * t111 * t153 * t275 / 0.2e1;
  t734 = -t298 + t322 - t327 - t360 - t231 / 0.2e1 - t262 - t340 - t305 - t632 - t351 + t9 * (t686 + t731);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = -t208 - 0.2e1 / 0.3e1 * t211 - t270 - 0.2e1 / 0.3e1 * t273 - t629 - t215 - t223 + t493 - t279 + t495 + t734;

  t769 = t7 * t117 * t387;
  t774 = t639 * t311 * t346 * t112 / 0.9e1 + t310 * t663 * t129 * t8 / 0.3e1 - t310 * t16 * t153 * t312 / 0.3e1 - t310 * t311 * t355 * t112 / 0.6e1 - t287 * t633 * t124 * t8 / 0.3e1 - t647 + t669 * t288 * t335 * t73 / 0.9e1 - t287 * t288 * t341 * t73 / 0.6e1 + t649 / 0.6e1 - t769 / 0.8e1 - t677 - t527 - t539 + t542 / 0.12e2 + t602 / 0.9e1 + t622 / 0.9e1;
  t780 = t7 * t592 * t336;
  t783 = t7 * t209 * t342;
  t786 = t7 * t612 * t347;
  t789 = t7 * t271 * t352;
  t792 = t7 * t271 * t356;
  t803 = -t217 - 0.3e1 * t517;
  t820 = -t696 + 0.2e1 / 0.9e1 * t702 - t708 / 0.3e1 + 0.2e1 / 0.9e1 * t714 - t722 + t725 / 0.3e1 - t780 / 0.18e2 - t783 / 0.6e1 - t786 / 0.18e2 - t789 / 0.3e1 - t792 / 0.6e1 - t7 * t203 * t107 * t335 / 0.6e1 - t7 * t68 * t107 * t341 / 0.2e1 - t7 * t68 * t39 * t803 / 0.2e1 + t7 * t319 * t153 * t8 + t7 * t111 * t62 * t803 / 0.2e1 - t7 * t111 * t387 * t112 / 0.2e1;
  t823 = -t354 - t359 - t232 - t390 - 0.2e1 / 0.3e1 * t294 - t305 - t632 - 0.2e1 / 0.3e1 * t317 - t339 - t350 + t9 * (t774 + t820);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = -t212 - t274 - t629 + t493 + t495 - t298 + t322 - t327 - t330 / 0.2e1 - t345 + t823;

  t858 = sigma[2] / t49 / t184;
  t864 = t141 / t48 / t375;
  t868 = t375 * t134;
  t870 = t374 / t868;
  t873 = t141 * t141;
  t878 = t23 * t55;
  t896 = -0.3e1 * t217 - 0.3e1 * t517;
  t918 = -t287 * t288 * t124 * t341 / 0.2e1 + t7 * t606 * t62 * t346 * t129 / 0.9e1 - t310 * t311 * t129 * t355 / 0.2e1 - 0.3e1 / 0.8e1 * t7 * t46 * (-0.11730617283950617284e0 * t23 * t858 * t55 + 0.10454912654320987654e-2 * t94 * t864 * t55 - 0.86653982182653180677e-7 * t870 * t55 + 0.24475949353345898402e-10 * t873 / t49 / t375 / t184 * t878 - 0.57163944444444444446e-1 * t23 * t858 * t60 + 0.98607804166666666666e-4 * t94 * t864 * t60 - 0.14816478255226406893e-8 * t870 * t60) + t649 / 0.4e1 - 0.3e1 / 0.8e1 * t769 - t7 * t68 * t39 * t896 / 0.2e1 - t7 * t265 * t153 * t346 / 0.2e1 - 0.3e1 / 0.2e1 * t7 * t111 * t387 * t129 - 0.3e1 / 0.2e1 * t7 * t111 * t153 * t355 + t7 * t111 * t62 * t896 / 0.2e1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = t493 + t495 - 0.3e1 / 0.4e1 * t330 - 0.3e1 / 0.2e1 * t344 - 0.3e1 * t354 - 0.3e1 / 0.2e1 * t358 - 0.9e1 / 0.8e1 * t389 - t294 - t317 - t338 / 0.2e1 - t349 / 0.2e1 + t9 * (-t527 - t539 + t702 / 0.3e1 + t714 / 0.3e1 - t780 / 0.6e1 - t783 / 0.2e1 - t786 / 0.6e1 - t789 - t792 / 0.2e1 + t7 * t586 * t39 * t335 * t124 / 0.9e1 + t918);

  t922 = t7 * t68 * t397;
  t926 = t7 * t80 * t176 / 0.6e1;
  t928 = t7 * t17 * t419;
  t943 = t241 * sigma[0];
  t947 = t249 * t95;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.4e1 / 0.3e1 * t922 - t926 - t928 - t161 * t286 * t176 * t204 / 0.6e1 - t161 * t396 * t419 * t73 - t161 * t396 * t176 * t219 / 0.2e1 - 0.3e1 / 0.8e1 * t161 * t162 * (0.25137037037037037037e-1 * t23 * t234 * t32 - 0.29893078703703703703e-3 * t94 * t943 * t32 + 0.29074691390232317200e-7 * t947 * t32 - 0.91784810075047119006e-11 * t246 / t26 / t247 / t96 * t569 + 0.12249416666666666667e-1 * t23 * t234 * t37 - 0.30254667187500000000e-4 * t94 * t943 * t37 + 0.55561793457099025850e-9 * t947 * t37);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[1] = 0.0e0;

  t969 = t7 * t111 * t426;
  t973 = t7 * t117 * t194 / 0.6e1;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[2] = -0.4e1 / 0.3e1 * t969 - t973 - t161 * t309 * t194 * t266 / 0.6e1 - t161 * t425 * t194 * t275 / 0.2e1;

  t985 = t16 * t1 * t3;
  t986 = t985 * t431;
  t989 = t160 * t3 * t6;
  t999 = t225 * t1 * t3;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[3] = -0.2e1 / 0.3e1 * t922 - t926 - t928 / 0.2e1 - 0.2e1 / 0.3e1 * t986 - t989 * t202 * t176 * t289 / 0.6e1 - t161 * t396 * t419 * t124 / 0.2e1 - t999 * t396 * t176 * t8 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[4] = 0.0e0;

  t1005 = t985 * t436;
  t1015 = t985 * t458;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[5] = -0.2e1 / 0.3e1 * t969 - t973 - 0.2e1 / 0.3e1 * t1005 - t989 * t264 * t194 * t312 / 0.6e1 + t999 * t425 * t194 * t8 / 0.2e1 - t1015 / 0.2e1 - t161 * t425 * t457 * t112 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[6] = -0.4e1 / 0.3e1 * t986 - t926 - t161 * t286 * t176 * t335 / 0.6e1 - t161 * t396 * t176 * t341 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[7] = 0.0e0;

  t1045 = t369 * sigma[2];
  t1049 = t377 * t141;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[8] = -0.4e1 / 0.3e1 * t1005 - t973 - t1015 - t161 * t309 * t194 * t346 / 0.6e1 - t161 * t425 * t457 * t129 - t161 * t425 * t194 * t355 / 0.2e1 - 0.3e1 / 0.8e1 * t161 * t180 * (0.25137037037037037037e-1 * t23 * t362 * t55 - 0.29893078703703703703e-3 * t94 * t1045 * t55 + 0.29074691390232317200e-7 * t1049 * t55 - 0.91784810075047119006e-11 * t374 / t49 / t375 / t142 * t878 + 0.12249416666666666667e-1 * t23 * t362 * t60 - 0.30254667187500000000e-4 * t94 * t1045 * t60 + 0.55561793457099025850e-9 * t1049 * t60);

  t1070 = t985 * t472;
  t1079 = t409 * sigma[0];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -t1070 / 0.2e1 - t161 * t396 * t471 * t73 / 0.2e1 - 0.3e1 / 0.8e1 * t161 * t162 * (0.55187222222222222224e-4 * t94 * t99 * t32 - 0.85513798206565638826e-8 * t1079 * t32 + 0.34419303778142669627e-11 * t95 / t26 / t559 * t569 + 0.67232593750000000000e-5 * t94 * t99 * t37 - 0.20835672546412134694e-9 * t1079 * t37);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[1] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[2] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[3] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[4] = 0.0e0;

  t1096 = t985 * t486;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[5] = -t161 * t425 * t485 * t112 / 0.2e1 - t1096 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[6] = -t161 * t396 * t471 * t124 / 0.2e1 - t1070 / 0.2e1;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[8] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[9] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[10] = 0.0e0;

  t1113 = t447 * sigma[2];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[11] = -t1096 / 0.2e1 - t161 * t425 * t485 * t129 / 0.2e1 - 0.3e1 / 0.8e1 * t161 * t180 * (0.55187222222222222224e-4 * t94 * t145 * t55 - 0.85513798206565638826e-8 * t1113 * t55 + 0.34419303778142669627e-11 * t141 / t49 / t868 * t878 + 0.67232593750000000000e-5 * t94 * t145 * t60 - 0.20835672546412134694e-9 * t1113 * t60);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.3e1 / 0.8e1 * t161 * t162 * (0.19240604596477268736e-8 * t464 * t32 - 0.12907238916803501110e-11 * sigma[0] / t26 / t248 * t569 + 0.78133772049045505101e-10 * t464 * t37);

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
    v3sigma3[9] = -0.3e1 / 0.8e1 * t161 * t180 * (0.19240604596477268736e-8 * t478 * t55 - 0.12907238916803501110e-11 * sigma[2] / t49 / t376 * t878 + 0.78133772049045505101e-10 * t478 * t60);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}

