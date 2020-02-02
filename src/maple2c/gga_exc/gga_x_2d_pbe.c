/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/gga_exc/gga_x_2d_pbe.mpl
  Type of functional: gga_exc
*/

#define maple2c_order 3

DEVICE static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, const double *sigma, double *zk, double *vrho, double *vsigma, double *v2rho2, double *v2rhosigma, double *v2sigma2, double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3)
{
  double t1, t3, t4, t5, t6, t7, t11, t14;
  double t16, t21, t22, t23, t24, t28, t37, t40;
  double t44, t46, t47, t48, t56, t57, t62, t72;
  double t75, t80, t81;


  t1 = sqrt(M_PI);
  t3 = M_SQRT2;
  t4 = 0.1e1 / t1 * t3;
  t5 = sqrt(rho[0]);
  t6 = rho[0] * rho[0];
  t7 = t6 * rho[0];
  t11 = 0.4604e0 + 0.14106971928508582281e-1 * sigma[0] / t7;
  t14 = 0.14604e1 - 0.21196816e0 / t11;
  t16 = t4 * t5 * t14;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.4e1 / 0.3e1 * t16;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t21 = 0.1e1 / t5 / t6 * t3;
  t22 = t11 * t11;
  t23 = 0.1e1 / t22;
  t24 = t23 * sigma[0];
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -0.2e1 * t16 + 0.67482239525276429490e-2 * t21 * t24;

  t28 = 0.1e1 / t5 / rho[0];
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.22494079841758809831e-2 * t28 * t3 * t23;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t37 = t3 / t5 / t7;
  t40 = t6 * t6;
  t44 = 0.1e1 / t5 / t40 / t6 * t3;
  t46 = 0.1e1 / t22 / t11;
  t47 = sigma[0] * sigma[0];
  t48 = t46 * t47;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -t4 / t5 * t14 - 0.6748223952527642948e-2 * t37 * t24 + 0.57118203519358014514e-3 * t44 * t48;

  t56 = 0.1e1 / t5 / t40 / rho[0] * t3;
  t57 = t46 * sigma[0];
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = 0.33741119762638214746e-2 * t21 * t23 - 0.19039401173119338172e-3 * t56 * t57;

  t62 = 0.1e1 / t5 / t40 * t3;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = 0.63464670577064460574e-4 * t62 * t46;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t72 = t3 / t5 / t40 / t7;
  t75 = t40 * t40;
  t80 = t22 * t22;
  t81 = 0.1e1 / t80;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t4 * t28 * t14 / 0.2e1 + 0.28679951798242482530e-1 * t62 * t24 - 0.42838652639518510884e-2 * t72 * t48 + 0.72518840428898125941e-4 / t5 / t75 / t6 * t3 * t81 * t47 * sigma[0];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.84352799406595536865e-2 * t37 * t23 + 0.13327580821183536721e-2 * t44 * t57 - 0.24172946809632708648e-4 / t5 / t75 / rho[0] * t3 * t81 * t47;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -0.28559101759679007258e-3 * t56 * t46 + 0.80576489365442362161e-5 / t5 / t75 * t3 * t81 * sigma[0];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.26858829788480787387e-5 * t72 * t81;

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
  double t1, t2, t3, t5, t6, t10, t13, t14;
  double t19, t20, t21, t25, t34, t37, t42, t43;
  double t44, t51, t55, t64, t68, t72, t73;


  t1 = sqrt(M_PI);
  t2 = 0.1e1 / t1;
  t3 = sqrt(rho[0]);
  t5 = rho[0] * rho[0];
  t6 = t5 * rho[0];
  t10 = 0.4604e0 + 0.70534859642542911404e-2 * sigma[0] / t6;
  t13 = 0.14604e1 - 0.21196816e0 / t10;
  t14 = t2 * t3 * t13;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.8e1 / 0.3e1 * t14;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t19 = t10 * t10;
  t20 = 0.1e1 / t19;
  t21 = 0.1e1 / t3 / t5 * t20;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -0.4e1 * t14 + 0.67482239525276429491e-2 * t21 * sigma[0];

  t25 = 0.1e1 / t3 / rho[0];
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.22494079841758809829e-2 * t25 * t20;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t34 = 0.1e1 / t3 / t6 * t20;
  t37 = t5 * t5;
  t42 = 0.1e1 / t19 / t10;
  t43 = 0.1e1 / t3 / t37 / t5 * t42;
  t44 = sigma[0] * sigma[0];
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.2e1 * t2 / t3 * t13 - 0.6748223952527642949e-2 * t34 * sigma[0] + 0.28559101759679007257e-3 * t43 * t44;

  t51 = 0.1e1 / t3 / t37 / rho[0] * t42;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = 0.33741119762638214744e-2 * t21 - 0.95197005865596690850e-4 * t51 * sigma[0];

  t55 = 0.1e1 / t3 / t37;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = 0.31732335288532230284e-4 * t55 * t42;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t64 = 0.1e1 / t3 / t37 / t6;
  t68 = t37 * t37;
  t72 = t19 * t19;
  t73 = 0.1e1 / t72;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t2 * t25 * t13 + 0.28679951798242482534e-1 * t55 * t20 * sigma[0] - 0.21419326319759255443e-2 * t64 * t42 * t44 + 0.18129710107224531485e-4 / t3 / t68 / t5 * t73 * t44 * sigma[0];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.84352799406595536860e-2 * t34 + 0.66637904105917683596e-3 * t43 * sigma[0] - 0.60432367024081771612e-5 / t3 / t68 / rho[0] * t73 * t44;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = -0.14279550879839503628e-3 * t51 + 0.20144122341360590538e-5 / t3 / t68 * t73 * sigma[0];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.67147074471201968459e-6 * t64 * t73;

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
  double t1, t2, t3, t4, t5, t6, t8, t9;
  double t10, t11, t12, t13, t14, t15, t18, t21;
  double t22, t23, t25, t26, t27, t28, t29, t30;
  double t31, t34, t37, t38, t39, t41, t42, t43;
  double t44, t45, t46, t48, t50, t51, t52, t53;
  double t54, t55, t56, t57, t58, t59, t60, t61;
  double t62, t63, t64, t65, t66, t68, t69, t70;
  double t71, t72, t76, t78, t79, t80, t82, t83;
  double t84, t85, t86, t87, t88, t89, t90, t91;
  double t92, t95, t96, t97, t100, t101, t105, t108;
  double t109, t110, t111, t113, t114, t116, t117, t118;
  double t119, t120, t121, t122, t123, t124, t125, t126;
  double t127, t129, t130, t131, t132, t133, t134, t135;
  double t136, t137, t139, t140, t141, t142, t143, t144;
  double t145, t146, t148, t149, t150, t151, t152, t153;
  double t154, t156, t157, t159, t160, t161, t163, t164;
  double t165, t166, t167, t168, t170, t171, t172, t173;
  double t176, t178, t179, t182, t183, t185, t189, t190;
  double t191, t192, t195, t197, t199, t202, t203, t204;
  double t205, t206, t208, t209, t211, t216, t218, t219;
  double t220, t221, t223, t224, t225, t227, t228, t229;
  double t230, t231, t232, t233, t235, t236, t239, t240;
  double t241, t242, t243, t244, t245, t246, t248, t249;
  double t250, t251, t252, t255, t256, t257, t261, t262;
  double t263, t266, t270, t271, t272, t275, t278, t282;
  double t283, t284, t287, t291, t292, t295, t296, t305;
  double t309, t310, t311, t312, t321, t326, t327, t332;
  double t333, t342, t347, t350, t352, t353, t356, t364;
  double t369, t372, t375, t377, t379, t381, t386, t388;
  double t390, t391, t400, t406, t411, t413, t414, t416;
  double t417, t429, t436, t444, t449, t450, t463, t466;
  double t469, t471, t476, t478, t487, t489, t492, t495;
  double t497, t501, t507, t510, t512, t545, t546, t550;
  double t557, t558, t567, t569, t572, t574, t576, t578;
  double t581, t593, t596, t629, t643, t651, t659, t660;
  double t668, t671, t674, t675, t677, t679, t683, t707;
  double t710, t711, t721, t740, t751, t753, t758, t800;
  double t813;


  t1 = sqrt(M_PI);
  t2 = 0.1e1 / t1;
  t3 = rho[0] - rho[1];
  t4 = rho[0] + rho[1];
  t5 = 0.1e1 / t4;
  t6 = t3 * t5;
  t8 = 0.1e1 / 0.2e1 + t6 / 0.2e1;
  t9 = sqrt(t8);
  t10 = t9 * t8;
  t11 = t2 * t10;
  t12 = sqrt(t4);
  t13 = rho[0] * rho[0];
  t14 = t13 * rho[0];
  t15 = 0.1e1 / t14;
  t18 = 0.4604e0 + 0.70534859642542911404e-2 * sigma[0] * t15;
  t21 = 0.14604e1 - 0.21196816e0 / t18;
  t22 = t12 * t21;
  t23 = t11 * t22;
  t25 = 0.1e1 / 0.2e1 - t6 / 0.2e1;
  t26 = sqrt(t25);
  t27 = t26 * t25;
  t28 = t2 * t27;
  t29 = rho[1] * rho[1];
  t30 = t29 * rho[1];
  t31 = 0.1e1 / t30;
  t34 = 0.4604e0 + 0.70534859642542911404e-2 * sigma[2] * t31;
  t37 = 0.14604e1 - 0.21196816e0 / t34;
  t38 = t12 * t37;
  t39 = t28 * t38;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.8e1 / 0.3e1 * t23 - 0.8e1 / 0.3e1 * t39;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t41 = 0.8e1 / 0.3e1 * t23;
  t42 = 0.8e1 / 0.3e1 * t39;
  t43 = t2 * t9;
  t44 = t4 * t4;
  t45 = 0.1e1 / t44;
  t46 = t3 * t45;
  t48 = t5 / 0.2e1 - t46 / 0.2e1;
  t50 = t43 * t22 * t48;
  t51 = 0.4e1 * t50;
  t52 = 0.1e1 / t12;
  t53 = t52 * t21;
  t54 = t11 * t53;
  t55 = 0.4e1 / 0.3e1 * t54;
  t56 = t10 * t12;
  t57 = t18 * t18;
  t58 = 0.1e1 / t57;
  t59 = t58 * sigma[0];
  t60 = t13 * t13;
  t61 = 0.1e1 / t60;
  t62 = t59 * t61;
  t63 = t56 * t62;
  t64 = 0.67482239525276429491e-2 * t63;
  t65 = t2 * t26;
  t66 = -t48;
  t68 = t65 * t38 * t66;
  t69 = 0.4e1 * t68;
  t70 = t52 * t37;
  t71 = t28 * t70;
  t72 = 0.4e1 / 0.3e1 * t71;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t41 - t42 + t4 * (-t51 - t55 + t64 - t69 - t72);

  t76 = -t5 / 0.2e1 - t46 / 0.2e1;
  t78 = t43 * t22 * t76;
  t79 = 0.4e1 * t78;
  t80 = -t76;
  t82 = t65 * t38 * t80;
  t83 = 0.4e1 * t82;
  t84 = t27 * t12;
  t85 = t34 * t34;
  t86 = 0.1e1 / t85;
  t87 = t86 * sigma[2];
  t88 = t29 * t29;
  t89 = 0.1e1 / t88;
  t90 = t87 * t89;
  t91 = t84 * t90;
  t92 = 0.67482239525276429491e-2 * t91;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = -t41 - t42 + t4 * (-t79 - t55 - t83 - t72 + t92);

  t95 = t12 * t4;
  t96 = t95 * t10;
  t97 = t58 * t15;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[0] = -0.22494079841758809829e-2 * t96 * t97;

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[1] = 0.0e0;

  t100 = t95 * t27;
  t101 = t86 * t31;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vsigma[2] = -0.22494079841758809829e-2 * t100 * t101;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t105 = 0.8e1 / 0.3e1 * t54;
  t108 = 0.8e1 / 0.3e1 * t71;
  t109 = 0.1e1 / t9;
  t110 = t2 * t109;
  t111 = t48 * t48;
  t113 = t110 * t22 * t111;
  t114 = 0.2e1 * t113;
  t116 = t43 * t53 * t48;
  t117 = 0.4e1 * t116;
  t118 = t9 * t12;
  t119 = t118 * t58;
  t120 = sigma[0] * t61;
  t121 = t120 * t48;
  t122 = t119 * t121;
  t123 = 0.20244671857582928848e-1 * t122;
  t124 = t44 * t4;
  t125 = 0.1e1 / t124;
  t126 = t3 * t125;
  t127 = -t45 + t126;
  t129 = t43 * t22 * t127;
  t130 = 0.4e1 * t129;
  t131 = 0.1e1 / t95;
  t132 = t131 * t21;
  t133 = t11 * t132;
  t134 = 0.2e1 / 0.3e1 * t133;
  t135 = t10 * t52;
  t136 = t135 * t62;
  t137 = 0.67482239525276429491e-2 * t136;
  t139 = 0.1e1 / t57 / t18;
  t140 = sigma[0] * sigma[0];
  t141 = t139 * t140;
  t142 = t60 * t60;
  t143 = 0.1e1 / t142;
  t144 = t141 * t143;
  t145 = t56 * t144;
  t146 = 0.28559101759679007257e-3 * t145;
  t148 = 0.1e1 / t60 / rho[0];
  t149 = t59 * t148;
  t150 = t56 * t149;
  t151 = 0.26992895810110571796e-1 * t150;
  t152 = 0.1e1 / t26;
  t153 = t2 * t152;
  t154 = t66 * t66;
  t156 = t153 * t38 * t154;
  t157 = 0.2e1 * t156;
  t159 = t65 * t70 * t66;
  t160 = 0.4e1 * t159;
  t161 = -t127;
  t163 = t65 * t38 * t161;
  t164 = 0.4e1 * t163;
  t165 = t131 * t37;
  t166 = t28 * t165;
  t167 = 0.2e1 / 0.3e1 * t166;
  t168 = -t114 - t117 + t123 - t130 + t134 + t137 + t146 - t151 - t157 - t160 - t164 + t167;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.8e1 * t50 - t105 + 0.13496447905055285898e-1 * t63 - 0.8e1 * t68 - t108 + t4 * t168;

  t170 = t110 * t12;
  t171 = t21 * t76;
  t172 = t171 * t48;
  t173 = t170 * t172;
  t176 = t43 * t53 * t76;
  t178 = t120 * t76;
  t179 = t119 * t178;
  t182 = 0.1e1 / t12 / t44;
  t183 = t182 * t21;
  t185 = t43 * t183 * t3;
  t189 = t153 * t12;
  t190 = t37 * t80;
  t191 = t190 * t66;
  t192 = t189 * t191;
  t195 = t65 * t70 * t80;
  t197 = t182 * t37;
  t199 = t65 * t197 * t3;
  t202 = t26 * t12;
  t203 = t202 * t86;
  t204 = sigma[2] * t89;
  t205 = t204 * t66;
  t206 = t203 * t205;
  t208 = t27 * t52;
  t209 = t208 * t90;
  t211 = -0.2e1 * t173 - 0.2e1 * t176 + 0.10122335928791464424e-1 * t179 - 0.4e1 * t185 - 0.2e1 * t116 + t134 + 0.33741119762638214745e-2 * t136 - 0.2e1 * t192 - 0.2e1 * t195 + 0.4e1 * t199 - 0.2e1 * t159 + t167 + 0.10122335928791464424e-1 * t206 + 0.33741119762638214746e-2 * t209;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = t4 * t211 - t105 - t108 - t51 + t64 - t69 - t79 - t83 + t92;

  t216 = t76 * t76;
  t218 = t110 * t22 * t216;
  t219 = 0.2e1 * t218;
  t220 = 0.4e1 * t176;
  t221 = t45 + t126;
  t223 = t43 * t22 * t221;
  t224 = 0.4e1 * t223;
  t225 = t80 * t80;
  t227 = t153 * t38 * t225;
  t228 = 0.2e1 * t227;
  t229 = 0.4e1 * t195;
  t230 = t204 * t80;
  t231 = t203 * t230;
  t232 = 0.20244671857582928848e-1 * t231;
  t233 = -t221;
  t235 = t65 * t38 * t233;
  t236 = 0.4e1 * t235;
  t239 = 0.1e1 / t85 / t34;
  t240 = sigma[2] * sigma[2];
  t241 = t239 * t240;
  t242 = t88 * t88;
  t243 = 0.1e1 / t242;
  t244 = t241 * t243;
  t245 = t84 * t244;
  t246 = 0.28559101759679007257e-3 * t245;
  t248 = 0.1e1 / t88 / rho[1];
  t249 = t87 * t248;
  t250 = t84 * t249;
  t251 = 0.26992895810110571796e-1 * t250;
  t252 = -t219 - t220 - t224 + t134 - t228 - t229 + t232 - t236 + t167 + 0.67482239525276429491e-2 * t209 + t246 - t251;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = -0.8e1 * t78 - t105 - 0.8e1 * t82 - t108 + 0.13496447905055285898e-1 * t91 + t4 * t252;

  t255 = 0.33741119762638214744e-2 * t56 * t97;
  t256 = t95 * t9;
  t257 = t97 * t48;
  t261 = 0.1e1 / t60 / t14;
  t262 = t139 * t261;
  t263 = t262 * sigma[0];
  t266 = t58 * t61;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[0] = -t255 - 0.33741119762638214744e-2 * t256 * t257 - 0.95197005865596690850e-4 * t96 * t263 + 0.67482239525276429487e-2 * t96 * t266;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[1] = 0.0e0;

  t270 = 0.33741119762638214744e-2 * t84 * t101;
  t271 = t95 * t26;
  t272 = t101 * t66;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[2] = -t270 - 0.33741119762638214744e-2 * t271 * t272;

  t275 = t97 * t76;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[3] = -t255 - 0.33741119762638214744e-2 * t256 * t275;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[4] = 0.0e0;

  t278 = t101 * t80;
  t282 = 0.1e1 / t88 / t30;
  t283 = t239 * t282;
  t284 = t283 * sigma[2];
  t287 = t86 * t89;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rhosigma[5] = -t270 - 0.33741119762638214744e-2 * t271 * t278 - 0.95197005865596690850e-4 * t100 * t284 + 0.67482239525276429487e-2 * t100 * t287;

  t291 = 0.1e1 / t60 / t13;
  t292 = t139 * t291;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[0] = 0.31732335288532230284e-4 * t96 * t292;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[1] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[2] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[3] = 0.0e0;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[4] = 0.0e0;

  t295 = 0.1e1 / t88 / t29;
  t296 = t239 * t295;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2sigma2[5] = 0.31732335288532230284e-4 * t100 * t296;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t305 = 0.2e1 * t133;
  t309 = 0.2e1 * t166;
  t310 = t11 * t183;
  t311 = t28 * t197;
  t312 = sigma[0] * t148;
  t321 = t109 * t12 * t58;
  t326 = t9 * t52 * t58;
  t327 = t326 * t121;
  t332 = t118 * t139;
  t333 = t140 * t143;
  t342 = t2 / t10;
  t347 = t110 * t53 * t111;
  t350 = t43 * t132 * t48;
  t352 = -t310 - t311 - 0.12146803114549757309e0 * t119 * t312 * t48 - 0.6e1 * t170 * t21 * t48 * t127 + 0.15183503893187196636e-1 * t321 * t120 * t111 + 0.30367007786374393272e-1 * t327 + 0.30367007786374393272e-1 * t119 * t120 * t127 + 0.12851595791855553266e-2 * t332 * t333 * t48 - 0.6e1 * t189 * t37 * t66 * t161 + t342 * t22 * t111 * t48 - 0.3e1 * t347 + 0.3e1 * t350;
  t353 = t135 * t149;
  t356 = 0.1e1 / t142 / rho[0];
  t364 = t2 / t27;
  t369 = t153 * t70 * t154;
  t372 = t65 * t165 * t66;
  t375 = t43 * t53 * t127;
  t377 = t44 * t44;
  t379 = t3 / t377;
  t381 = 0.3e1 * t125 - 0.3e1 * t379;
  t386 = t10 * t131 * t62;
  t388 = t135 * t144;
  t390 = t57 * t57;
  t391 = 0.1e1 / t390;
  t400 = t65 * t70 * t161;
  t406 = -0.40489343715165857694e-1 * t353 - 0.34270922111614808708e-2 * t56 * t141 * t356 + 0.13496447905055285898e0 * t56 * t59 * t291 + t364 * t38 * t154 * t66 - 0.3e1 * t369 + 0.3e1 * t372 - 0.6e1 * t375 - 0.4e1 * t43 * t22 * t381 - 0.50611679643957322119e-2 * t386 + 0.42838652639518510885e-3 * t388 + 0.18129710107224531485e-4 * t56 * t391 * t140 * sigma[0] / t142 / t60 - 0.6e1 * t400 + 0.4e1 * t65 * t38 * t381;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.6e1 * t113 - 0.12e2 * t116 + 0.60734015572748786542e-1 * t122 - 0.80978687430331715388e-1 * t150 - 0.6e1 * t156 - 0.12e2 * t159 - 0.12e2 * t129 + t305 + 0.20244671857582928847e-1 * t136 + 0.85677305279037021769e-3 * t145 - 0.12e2 * t163 + t309 + t4 * (t352 + t406);

  t411 = 0.4e1 * t173;
  t413 = -t114 - 0.8e1 * t116 + t123 - t151 - t157 - 0.8e1 * t159 - t411 - t220 - t130 + t305 + 0.13496447905055285898e-1 * t136;
  t414 = 0.8e1 * t199;
  t416 = 0.8e1 * t185;
  t417 = 0.4e1 * t192;
  t429 = 0.10122335928791464424e-1 * t326 * t178;
  t436 = t153 * t182;
  t444 = t342 * t12;
  t449 = 0.2e1 * t110 * t52 * t172;
  t450 = t110 * t182;
  t463 = t364 * t12;
  t466 = -t310 - t311 - 0.4e1 * t43 * t183 + 0.4e1 * t65 * t197 + 0.10122335928791464424e-1 * t327 - 0.2e1 * t170 * t171 * t127 + t429 + 0.42838652639518510886e-3 * t332 * t333 * t76 - 0.2e1 * t189 * t190 * t161 + 0.4e1 * t436 * t37 * t3 * t66 + 0.10122335928791464424e-1 * t203 * t204 * t161 + t444 * t171 * t111 - t449 - 0.4e1 * t450 * t21 * t3 * t48 - 0.40489343715165857696e-1 * t119 * t312 * t76 + 0.20244671857582928848e-1 * t9 * t182 * t58 * t120 * t3 + t463 * t190 * t154;
  t469 = 0.2e1 * t153 * t52 * t191;
  t471 = t152 * t12 * t86;
  t476 = t26 * t52 * t86;
  t478 = 0.10122335928791464424e-1 * t476 * t205;
  t487 = t43 * t132 * t76;
  t489 = 0.1e1 / t12 / t124;
  t492 = t43 * t489 * t21 * t3;
  t495 = t65 * t165 * t80;
  t497 = t27 * t131 * t90;
  t501 = t65 * t489 * t37 * t3;
  t507 = -t469 + 0.50611679643957322120e-2 * t471 * t204 * t154 + t478 - t347 + 0.2e1 * t350 - 0.13496447905055285898e-1 * t353 - t369 + 0.2e1 * t372 - 0.2e1 * t375 - 0.33741119762638214745e-2 * t386 + 0.14279550879839503628e-3 * t388 - 0.2e1 * t400 + t487 + 0.8e1 * t492 + t495 - 0.16870559881319107373e-2 * t497 - 0.8e1 * t501 + 0.10122335928791464424e-1 * t321 * t120 * t76 * t48;
  t510 = t146 - t164 + t309 + t414 + 0.20244671857582928848e-1 * t179 - t416 - t417 - t229 + 0.20244671857582928848e-1 * t206 + 0.67482239525276429492e-2 * t209 + t4 * (t466 + t507);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = t413 + t510;

  t512 = -t117 - t160 - t411 - 0.8e1 * t176 + t305 + t137 + t309 + t414 - t224 - t236 + t246;
  t545 = t202 * t239;
  t546 = t240 * t243;
  t550 = sigma[2] * t248;
  t557 = -t310 - t311 + t429 - t449 - t469 + t478 + t444 * t21 * t216 * t48 + 0.50611679643957322118e-2 * t321 * t120 * t216 - 0.2e1 * t170 * t21 * t221 * t48 + 0.10122335928791464424e-1 * t119 * t120 * t221 + t463 * t37 * t225 * t66 + 0.4e1 * t436 * t190 * t3 - 0.20244671857582928848e-1 * t26 * t182 * t86 * t204 * t3 - 0.2e1 * t189 * t37 * t233 * t66 + 0.42838652639518510886e-3 * t545 * t546 * t66 - 0.40489343715165857694e-1 * t203 * t550 * t66 - 0.4e1 * t450 * t171 * t3;
  t558 = t476 * t230;
  t567 = t110 * t53 * t216;
  t569 = t43 * t53 * t221;
  t572 = t153 * t70 * t225;
  t574 = t65 * t70 * t233;
  t576 = t208 * t244;
  t578 = t208 * t249;
  t581 = -t125 - 0.3e1 * t379;
  t593 = 0.10122335928791464424e-1 * t558 + t350 + t372 - 0.16870559881319107373e-2 * t386 + 0.2e1 * t487 - 0.4e1 * t492 + 0.2e1 * t495 - 0.33741119762638214746e-2 * t497 + 0.4e1 * t501 - t567 - 0.2e1 * t569 - t572 - 0.2e1 * t574 + 0.14279550879839503628e-3 * t576 - 0.13496447905055285898e-1 * t578 - 0.4e1 * t43 * t22 * t581 + 0.4e1 * t65 * t38 * t581 + 0.10122335928791464424e-1 * t471 * t204 * t80 * t66;
  t596 = 0.20244671857582928847e-1 * t179 - t416 - t417 - 0.8e1 * t195 + 0.20244671857582928847e-1 * t206 + 0.13496447905055285898e-1 * t209 - t219 - t228 + t232 - t251 + t4 * (t557 + t593);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = t512 + t596;

  t629 = -t310 - t311 + 0.30367007786374393272e-1 * t558 - 0.6e1 * t170 * t171 * t221 - 0.6e1 * t189 * t190 * t233 + 0.15183503893187196636e-1 * t471 * t204 * t225 + 0.30367007786374393272e-1 * t203 * t204 * t233 + 0.12851595791855553266e-2 * t545 * t546 * t80 - 0.12146803114549757309e0 * t203 * t550 * t80 + 0.3e1 * t487 + 0.3e1 * t495 - 0.50611679643957322119e-2 * t497;
  t643 = 0.1e1 / t242 / rho[1];
  t651 = -0.3e1 * t125 - 0.3e1 * t379;
  t659 = t85 * t85;
  t660 = 0.1e1 / t659;
  t668 = -0.3e1 * t567 - 0.6e1 * t569 - 0.3e1 * t572 - 0.6e1 * t574 + 0.42838652639518510885e-3 * t576 - 0.40489343715165857694e-1 * t578 + t342 * t22 * t216 * t76 + t364 * t38 * t225 * t80 - 0.34270922111614808708e-2 * t84 * t241 * t643 + 0.13496447905055285898e0 * t84 * t87 * t295 - 0.4e1 * t43 * t22 * t651 + 0.4e1 * t65 * t38 * t651 + 0.18129710107224531485e-4 * t84 * t660 * t240 * sigma[2] / t242 / t88;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = -0.12e2 * t176 + t305 + t309 - 0.12e2 * t223 - 0.12e2 * t235 + 0.85677305279037021769e-3 * t245 - 0.12e2 * t195 + 0.20244671857582928847e-1 * t209 - 0.6e1 * t218 - 0.6e1 * t227 + 0.60734015572748786542e-1 * t231 - 0.80978687430331715388e-1 * t250 + t4 * (t629 + t668);

  t671 = t118 * t257;
  t674 = 0.16870559881319107372e-2 * t135 * t97;
  t675 = t56 * t263;
  t677 = t56 * t266;
  t679 = t95 * t109;
  t683 = t256 * t139;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[0] = -0.10122335928791464423e-1 * t671 - t674 - 0.28559101759679007256e-3 * t675 + 0.20244671857582928846e-1 * t677 - 0.16870559881319107372e-2 * t679 * t97 * t111 - 0.28559101759679007256e-3 * t683 * t261 * t48 * sigma[0] + 0.20244671857582928846e-1 * t256 * t266 * t48 - 0.33741119762638214744e-2 * t256 * t97 * t127 - 0.60432367024081771612e-5 * t96 * t391 / t142 / t14 * t140 + 0.95197005865596690850e-3 * t96 * t139 * t143 * sigma[0] - 0.26992895810110571795e-1 * t96 * t58 * t148;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[1] = 0.0e0;

  t707 = t202 * t272;
  t710 = 0.16870559881319107372e-2 * t208 * t101;
  t711 = t95 * t152;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[2] = -0.10122335928791464423e-1 * t707 - t710 - 0.16870559881319107372e-2 * t711 * t101 * t154 - 0.33741119762638214744e-2 * t271 * t101 * t161;

  t721 = t118 * t275;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[3] = -0.50611679643957322116e-2 * t671 - t674 - 0.14279550879839503628e-3 * t675 + 0.10122335928791464423e-1 * t677 - 0.50611679643957322116e-2 * t721 - 0.16870559881319107372e-2 * t679 * t58 * t15 * t76 * t48 - 0.14279550879839503628e-3 * t683 * t261 * t76 * sigma[0] + 0.10122335928791464423e-1 * t256 * t266 * t76 - 0.33741119762638214744e-2 * t131 * t9 * t97 * t3;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[4] = 0.0e0;

  t740 = t202 * t278;
  t751 = t84 * t284;
  t753 = t271 * t239;
  t758 = t84 * t287;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[5] = -0.50611679643957322116e-2 * t707 - t710 - 0.50611679643957322116e-2 * t740 - 0.16870559881319107372e-2 * t711 * t86 * t31 * t80 * t66 + 0.33741119762638214744e-2 * t131 * t26 * t101 * t3 - 0.14279550879839503628e-3 * t751 - 0.14279550879839503628e-3 * t753 * t282 * sigma[2] * t66 + 0.10122335928791464423e-1 * t758 + 0.10122335928791464423e-1 * t271 * t287 * t66;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[6] = -0.10122335928791464423e-1 * t721 - t674 - 0.16870559881319107372e-2 * t679 * t97 * t216 - 0.33741119762638214744e-2 * t256 * t97 * t221;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho2sigma[8] = -0.10122335928791464423e-1 * t740 - t710 - 0.28559101759679007256e-3 * t751 + 0.20244671857582928846e-1 * t758 - 0.16870559881319107372e-2 * t711 * t101 * t225 - 0.28559101759679007256e-3 * t753 * t282 * t80 * sigma[2] + 0.20244671857582928846e-1 * t271 * t287 * t80 - 0.33741119762638214744e-2 * t271 * t101 * t233 - 0.60432367024081771612e-5 * t100 * t660 / t242 / t30 * t240 + 0.95197005865596690850e-3 * t100 * t239 * t243 * sigma[2] - 0.26992895810110571795e-1 * t100 * t86 * t248;

  t800 = 0.47598502932798345426e-4 * t56 * t292;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[0] = t800 + 0.47598502932798345426e-4 * t256 * t292 * t48 + 0.20144122341360590538e-5 * t96 * t391 / t142 / t13 * sigma[0] - 0.19039401173119338170e-3 * t96 * t262;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[1] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[2] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[3] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[4] = 0.0e0;

  t813 = 0.47598502932798345426e-4 * t84 * t296;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[5] = t813 + 0.47598502932798345426e-4 * t271 * t296 * t66;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[6] = t800 + 0.47598502932798345426e-4 * t256 * t292 * t76;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[7] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[8] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[9] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[10] = 0.0e0;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rhosigma2[11] = t813 + 0.47598502932798345426e-4 * t271 * t296 * t80 + 0.20144122341360590538e-5 * t100 * t660 / t242 / t29 * sigma[2] - 0.19039401173119338170e-3 * t100 * t283;

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3sigma3[0] = -0.67147074471201968459e-6 * t96 * t391 * t356;

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
    v3sigma3[9] = -0.67147074471201968459e-6 * t100 * t660 * t643;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}

