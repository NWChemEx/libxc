/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/lda_exc/lda_c_2d_prm.mpl
  Type of functional: lda_exc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t3, t5, t6, t7, t9, t10, t11;
  double t12, t13, t15, t16, t17, t19, t20, t21;
  double t23, t25, t26, t27, t28, t30, t31, t33;
  double t34, t35, t36, t38, t41, t42, t43, t45;
  double t48, t50, t51, t54, t57, t58, t60, t62;
  double t64, t66, t68, t82, t83, t84, t86, t87;
  double t89, t91, t92, t96, t97, t98, t100, t102;
  double t104, t107, t108, t111, t113, t114, t117, t120;
  double t122, t123, t125, t127, t129, t131, t133, t135;
  double t138, t140, t160, t162, t163, t168, t169, t174;
  double t190, t194, t202, t205, t208, t211, t238;

  lda_c_2d_prm_params *params;

  assert(p->params != NULL);
  params = (lda_c_2d_prm_params * )(p->params);

  assert(params->N > 1);

  t1 = sqrt(rho[0]);
  t3 = sqrt(M_PI);
  t5 = 0.39274000000000000001e1 * t1 + t3 / 0.2e1;
  t6 = 0.1e1 / t5;
  t7 = t1 * t6;
  t9 = 0.39274000000000000001e1 * t7 - 0.1e1;
  t10 = t1 * t9;
  t11 = 0.2e1 + params->c;
  t12 = sqrt(t11);
  t13 = 0.1e1 / t12;
  t15 = 0.35445383694248789566e0 * t10 * t13;
  t16 = 0.1e1 / t11;
  t17 = t9 * t16;
  t19 = 0.39995832530297311691e0 * t7 * t17;
  t20 = t5 * t5;
  t21 = 0.1e1 / t20;
  t23 = 0.1e1/POW_3_2(t11);
  t25 = 0.17722691847124394783e0 * t1 * t21 * t23;
  t26 = 0.1e1 + params->c;
  t27 = sqrt(t26);
  t28 = 0.1e1 / t27;
  t30 = 0.70890767388497579132e0 * t10 * t28;
  t31 = 0.1e1 / t26;
  t33 = 0.39995832530297311691e0 * t7 * t31;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t15 + t19 + t25 + t30 + t33;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t34 = 0.1e1 / t1;
  t35 = t34 * t9;
  t36 = t35 * t13;
  t38 = t34 * t6;
  t41 = 0.19637000000000000000e1 * t38 - 0.77122353800000000002e1 * t21;
  t42 = t1 * t41;
  t43 = t42 * t13;
  t45 = t38 * t17;
  t48 = t21 * t9 * t16;
  t50 = t41 * t16;
  t51 = t7 * t50;
  t54 = t34 * t21 * t23;
  t57 = 0.1e1 / t20 / t5;
  t58 = t57 * t23;
  t60 = t35 * t28;
  t62 = t42 * t28;
  t64 = t38 * t31;
  t66 = t21 * t31;
  t68 = 0.17722691847124394783e0 * t36 + 0.35445383694248789566e0 * t43 + 0.19997916265148655846e0 * t45 - 0.78539816339744830968e0 * t48 + 0.39995832530297311691e0 * t51 + 0.88613459235621973915e-1 * t54 - 0.69604099960396348071e0 * t58 + 0.35445383694248789566e0 * t60 + 0.70890767388497579132e0 * t62 + 0.19997916265148655846e0 * t64 - 0.78539816339744830968e0 * t66;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = rho[0] * t68 + t15 + t19 + t25 + t30 + t33;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t82 = 0.1e1 / t1 / rho[0];
  t83 = t82 * t9;
  t84 = t83 * t13;
  t86 = t34 * t41;
  t87 = t86 * t13;
  t89 = t82 * t6;
  t91 = 0.1e1 / rho[0];
  t92 = t91 * t21;
  t96 = -0.98185000000000000000e0 * t89 - 0.38561176900000000000e1 * t92 + 0.30289033231412000001e2 * t57 * t34;
  t97 = t1 * t96;
  t98 = t97 * t13;
  t100 = t89 * t17;
  t102 = t92 * t17;
  t104 = t38 * t50;
  t107 = t16 * t34;
  t108 = t57 * t9 * t107;
  t111 = t21 * t41 * t16;
  t113 = t96 * t16;
  t114 = t7 * t113;
  t117 = t82 * t21 * t23;
  t120 = t91 * t57 * t23;
  t122 = t20 * t20;
  t123 = 0.1e1 / t122;
  t125 = t123 * t23 * t34;
  t127 = t83 * t28;
  t129 = t86 * t28;
  t131 = t97 * t28;
  t133 = t89 * t31;
  t135 = t92 * t31;
  t138 = t57 * t31 * t34;
  t140 = -0.88613459235621973915e-1 * t84 + 0.35445383694248789566e0 * t87 + 0.35445383694248789566e0 * t98 - 0.99989581325743279230e-1 * t100 - 0.39269908169872415485e0 * t102 + 0.39995832530297311692e0 * t104 + 0.30845727469271384914e1 * t108 - 0.15707963267948966194e1 * t111 + 0.39995832530297311691e0 * t114 - 0.44306729617810986958e-1 * t117 - 0.34802049980198174035e0 * t120 + 0.41004471327669092612e1 * t125 - 0.17722691847124394783e0 * t127 + 0.70890767388497579132e0 * t129 + 0.70890767388497579132e0 * t131 - 0.99989581325743279230e-1 * t133 - 0.39269908169872415485e0 * t135 + 0.30845727469271384914e1 * t138;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = 0.35445383694248789566e0 * t36 + 0.70890767388497579132e0 * t43 + 0.39995832530297311692e0 * t45 - 0.15707963267948966194e1 * t48 + 0.79991665060594623382e0 * t51 + 0.17722691847124394783e0 * t54 - 0.13920819992079269614e1 * t58 + 0.70890767388497579132e0 * t60 + 0.14178153477699515826e1 * t62 + 0.39995832530297311692e0 * t64 - 0.15707963267948966194e1 * t66 + rho[0] * t140;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t160 = rho[0] * rho[0];
  t162 = 0.1e1 / t1 / t160;
  t163 = t162 * t6;
  t168 = 0.1e1 / t160;
  t169 = t168 * t21;
  t174 = t82 * t57;
  t190 = 0.14727750000000000000e1 * t163 + 0.57841765350000000000e1 * t169 - 0.17843572366957123321e3 * t123 * t91;
  t194 = t162 * t9;
  t202 = 0.14998437198861491884e0 * t163 * t17 - 0.29996874397722983769e0 * t89 * t50 + 0.58904862254808623227e0 * t169 * t17 - 0.11780972450961724646e1 * t92 * t50 + 0.1e-18 * t174 * t17 + 0.59993748795445967538e0 * t38 * t113 + 0.92537182407814154744e1 * t57 * t41 * t107 - 0.18171526509422465567e2 * t123 * t9 * t16 * t91 + 0.39995832530297311691e0 * t7 * t190 * t16 + 0.13292018885343296087e0 * t194 * t13 + 0.66460094426716480437e-1 * t162 * t21 * t23 + 0.26584037770686592174e0 * t194 * t28;
  t205 = t82 * t41;
  t208 = t34 * t96;
  t211 = t1 * t190;
  t238 = 0.14998437198861491884e0 * t163 * t31 - 0.26584037770686592174e0 * t205 * t13 + 0.53168075541373184349e0 * t208 * t13 + 0.35445383694248789566e0 * t211 * t13 - 0.23561944901923449291e1 * t21 * t96 * t16 + 0.52203074970297261053e0 * t168 * t57 * t23 - 0.32208192138457518865e2 / t122 / t5 * t23 * t91 - 0.53168075541373184349e0 * t205 * t28 + 0.10633615108274636870e1 * t208 * t28 + 0.70890767388497579132e0 * t211 * t28 + 0.58904862254808623227e0 * t169 * t31 + 0.1e-18 * t174 * t31 - 0.18171526509422465567e2 * t123 * t31 * t91;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.29996874397722983769e0 * t100 - 0.26584037770686592174e0 * t84 + 0.11998749759089193508e1 * t104 - 0.11780972450961724646e1 * t102 + 0.92537182407814154744e1 * t108 + 0.11998749759089193507e1 * t114 - 0.13292018885343296087e0 * t117 - 0.53168075541373184349e0 * t127 - 0.29996874397722983769e0 * t133 + 0.10633615108274636870e1 * t87 + 0.10633615108274636870e1 * t98 - 0.47123889803846898582e1 * t111 - 0.10440614994059452211e1 * t120 + 0.12301341398300727784e2 * t125 + 0.21267230216549273739e1 * t129 + 0.21267230216549273739e1 * t131 - 0.11780972450961724646e1 * t135 + 0.92537182407814154744e1 * t138 + rho[0] * (t202 + t238);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t3, t5, t6, t7, t9, t10, t11;
  double t12, t13, t15, t16, t17, t19, t20, t21;
  double t23, t25, t26, t27, t28, t30, t31, t33;
  double t34, t35, t36, t38, t41, t42, t43, t45;
  double t48, t50, t51, t54, t57, t58, t60, t62;
  double t64, t66, t68, t82, t83, t84, t86, t87;
  double t89, t91, t92, t96, t97, t98, t100, t102;
  double t104, t107, t108, t111, t113, t114, t117, t120;
  double t122, t123, t125, t127, t129, t131, t133, t135;
  double t138, t140, t160, t162, t163, t168, t169, t174;
  double t190, t194, t202, t205, t208, t211, t238;

  lda_c_2d_prm_params *params;

  assert(p->params != NULL);
  params = (lda_c_2d_prm_params * )(p->params);

  assert(params->N > 1);

  t1 = sqrt(rho[0]);
  t3 = sqrt(M_PI);
  t5 = 0.39274000000000000001e1 * t1 + t3 / 0.2e1;
  t6 = 0.1e1 / t5;
  t7 = t1 * t6;
  t9 = 0.39274000000000000001e1 * t7 - 0.1e1;
  t10 = t1 * t9;
  t11 = 0.2e1 + params->c;
  t12 = sqrt(t11);
  t13 = 0.1e1 / t12;
  t15 = 0.35445383694248789566e0 * t10 * t13;
  t16 = 0.1e1 / t11;
  t17 = t9 * t16;
  t19 = 0.39995832530297311691e0 * t7 * t17;
  t20 = t5 * t5;
  t21 = 0.1e1 / t20;
  t23 = 0.1e1/POW_3_2(t11);
  t25 = 0.17722691847124394783e0 * t1 * t21 * t23;
  t26 = 0.1e1 + params->c;
  t27 = sqrt(t26);
  t28 = 0.1e1 / t27;
  t30 = 0.70890767388497579132e0 * t10 * t28;
  t31 = 0.1e1 / t26;
  t33 = 0.39995832530297311691e0 * t7 * t31;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t15 + t19 + t25 + t30 + t33;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t34 = 0.1e1 / t1;
  t35 = t34 * t9;
  t36 = t35 * t13;
  t38 = t34 * t6;
  t41 = 0.19637000000000000000e1 * t38 - 0.77122353800000000002e1 * t21;
  t42 = t1 * t41;
  t43 = t42 * t13;
  t45 = t38 * t17;
  t48 = t21 * t9 * t16;
  t50 = t41 * t16;
  t51 = t7 * t50;
  t54 = t34 * t21 * t23;
  t57 = 0.1e1 / t20 / t5;
  t58 = t57 * t23;
  t60 = t35 * t28;
  t62 = t42 * t28;
  t64 = t38 * t31;
  t66 = t21 * t31;
  t68 = 0.17722691847124394783e0 * t36 + 0.35445383694248789566e0 * t43 + 0.19997916265148655846e0 * t45 - 0.78539816339744830968e0 * t48 + 0.39995832530297311691e0 * t51 + 0.88613459235621973915e-1 * t54 - 0.69604099960396348071e0 * t58 + 0.35445383694248789566e0 * t60 + 0.70890767388497579132e0 * t62 + 0.19997916265148655846e0 * t64 - 0.78539816339744830968e0 * t66;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = rho[0] * t68 + t15 + t19 + t25 + t30 + t33;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t82 = 0.1e1 / t1 / rho[0];
  t83 = t82 * t9;
  t84 = t83 * t13;
  t86 = t34 * t41;
  t87 = t86 * t13;
  t89 = t82 * t6;
  t91 = 0.1e1 / rho[0];
  t92 = t91 * t21;
  t96 = -0.98185000000000000000e0 * t89 - 0.38561176900000000000e1 * t92 + 0.30289033231412000001e2 * t57 * t34;
  t97 = t1 * t96;
  t98 = t97 * t13;
  t100 = t89 * t17;
  t102 = t92 * t17;
  t104 = t38 * t50;
  t107 = t16 * t34;
  t108 = t57 * t9 * t107;
  t111 = t21 * t41 * t16;
  t113 = t96 * t16;
  t114 = t7 * t113;
  t117 = t82 * t21 * t23;
  t120 = t91 * t57 * t23;
  t122 = t20 * t20;
  t123 = 0.1e1 / t122;
  t125 = t123 * t23 * t34;
  t127 = t83 * t28;
  t129 = t86 * t28;
  t131 = t97 * t28;
  t133 = t89 * t31;
  t135 = t92 * t31;
  t138 = t57 * t31 * t34;
  t140 = -0.88613459235621973915e-1 * t84 + 0.35445383694248789566e0 * t87 + 0.35445383694248789566e0 * t98 - 0.99989581325743279230e-1 * t100 - 0.39269908169872415485e0 * t102 + 0.39995832530297311692e0 * t104 + 0.30845727469271384914e1 * t108 - 0.15707963267948966194e1 * t111 + 0.39995832530297311691e0 * t114 - 0.44306729617810986958e-1 * t117 - 0.34802049980198174035e0 * t120 + 0.41004471327669092612e1 * t125 - 0.17722691847124394783e0 * t127 + 0.70890767388497579132e0 * t129 + 0.70890767388497579132e0 * t131 - 0.99989581325743279230e-1 * t133 - 0.39269908169872415485e0 * t135 + 0.30845727469271384914e1 * t138;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = 0.35445383694248789566e0 * t36 + 0.70890767388497579132e0 * t43 + 0.39995832530297311692e0 * t45 - 0.15707963267948966194e1 * t48 + 0.79991665060594623382e0 * t51 + 0.17722691847124394783e0 * t54 - 0.13920819992079269614e1 * t58 + 0.70890767388497579132e0 * t60 + 0.14178153477699515826e1 * t62 + 0.39995832530297311692e0 * t64 - 0.15707963267948966194e1 * t66 + rho[0] * t140;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t160 = rho[0] * rho[0];
  t162 = 0.1e1 / t1 / t160;
  t163 = t162 * t6;
  t168 = 0.1e1 / t160;
  t169 = t168 * t21;
  t174 = t82 * t57;
  t190 = 0.14727750000000000000e1 * t163 + 0.57841765350000000000e1 * t169 - 0.17843572366957123321e3 * t123 * t91;
  t194 = t162 * t9;
  t202 = 0.14998437198861491884e0 * t163 * t17 - 0.29996874397722983769e0 * t89 * t50 + 0.58904862254808623227e0 * t169 * t17 - 0.11780972450961724646e1 * t92 * t50 + 0.1e-18 * t174 * t17 + 0.59993748795445967538e0 * t38 * t113 + 0.92537182407814154744e1 * t57 * t41 * t107 - 0.18171526509422465567e2 * t123 * t9 * t16 * t91 + 0.39995832530297311691e0 * t7 * t190 * t16 + 0.13292018885343296087e0 * t194 * t13 + 0.66460094426716480437e-1 * t162 * t21 * t23 + 0.26584037770686592174e0 * t194 * t28;
  t205 = t82 * t41;
  t208 = t34 * t96;
  t211 = t1 * t190;
  t238 = 0.14998437198861491884e0 * t163 * t31 - 0.26584037770686592174e0 * t205 * t13 + 0.53168075541373184349e0 * t208 * t13 + 0.35445383694248789566e0 * t211 * t13 - 0.23561944901923449291e1 * t21 * t96 * t16 + 0.52203074970297261053e0 * t168 * t57 * t23 - 0.32208192138457518865e2 / t122 / t5 * t23 * t91 - 0.53168075541373184349e0 * t205 * t28 + 0.10633615108274636870e1 * t208 * t28 + 0.70890767388497579132e0 * t211 * t28 + 0.58904862254808623227e0 * t169 * t31 + 0.1e-18 * t174 * t31 - 0.18171526509422465567e2 * t123 * t31 * t91;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.29996874397722983769e0 * t100 - 0.26584037770686592174e0 * t84 + 0.11998749759089193508e1 * t104 - 0.11780972450961724646e1 * t102 + 0.92537182407814154744e1 * t108 + 0.11998749759089193507e1 * t114 - 0.13292018885343296087e0 * t117 - 0.53168075541373184349e0 * t127 - 0.29996874397722983769e0 * t133 + 0.10633615108274636870e1 * t87 + 0.10633615108274636870e1 * t98 - 0.47123889803846898582e1 * t111 - 0.10440614994059452211e1 * t120 + 0.12301341398300727784e2 * t125 + 0.21267230216549273739e1 * t129 + 0.21267230216549273739e1 * t131 - 0.11780972450961724646e1 * t135 + 0.92537182407814154744e1 * t138 + rho[0] * (t202 + t238);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


static inline void
func_pol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t2, t4, t6, t7, t8, t10, t11;
  double t12, t13, t14, t16, t17, t18, t20, t21;
  double t22, t24, t26, t27, t28, t29, t31, t32;
  double t34, t35, t36, t37, t39, t42, t43, t44;
  double t46, t49, t51, t52, t55, t58, t59, t61;
  double t63, t65, t67, t69, t83, t84, t85, t87;
  double t88, t90, t92, t93, t97, t98, t99, t101;
  double t103, t105, t108, t109, t112, t114, t115, t118;
  double t121, t123, t124, t126, t128, t130, t132, t134;
  double t136, t139, t141, t161, t163, t164, t172, t175;
  double t178, t182, t183, t187, t188, t206, t211, t239;

  lda_c_2d_prm_params *params;

  assert(p->params != NULL);
  params = (lda_c_2d_prm_params * )(p->params);

  assert(params->N > 1);

  t1 = rho[0] + rho[1];
  t2 = sqrt(t1);
  t4 = sqrt(M_PI);
  t6 = 0.39274000000000000001e1 * t2 + t4 / 0.2e1;
  t7 = 0.1e1 / t6;
  t8 = t2 * t7;
  t10 = 0.39274000000000000001e1 * t8 - 0.1e1;
  t11 = t2 * t10;
  t12 = 0.2e1 + params->c;
  t13 = sqrt(t12);
  t14 = 0.1e1 / t13;
  t16 = 0.35445383694248789566e0 * t11 * t14;
  t17 = 0.1e1 / t12;
  t18 = t10 * t17;
  t20 = 0.39995832530297311691e0 * t8 * t18;
  t21 = t6 * t6;
  t22 = 0.1e1 / t21;
  t24 = 0.1e1/POW_3_2(t12);
  t26 = 0.17722691847124394783e0 * t2 * t22 * t24;
  t27 = 0.1e1 + params->c;
  t28 = sqrt(t27);
  t29 = 0.1e1 / t28;
  t31 = 0.70890767388497579132e0 * t11 * t29;
  t32 = 0.1e1 / t27;
  t34 = 0.39995832530297311691e0 * t8 * t32;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t16 + t20 + t26 + t31 + t34;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t35 = 0.1e1 / t2;
  t36 = t35 * t10;
  t37 = t36 * t14;
  t39 = t35 * t7;
  t42 = 0.19637000000000000000e1 * t39 - 0.77122353800000000002e1 * t22;
  t43 = t2 * t42;
  t44 = t43 * t14;
  t46 = t39 * t18;
  t49 = t22 * t10 * t17;
  t51 = t42 * t17;
  t52 = t8 * t51;
  t55 = t35 * t22 * t24;
  t58 = 0.1e1 / t21 / t6;
  t59 = t58 * t24;
  t61 = t36 * t29;
  t63 = t43 * t29;
  t65 = t39 * t32;
  t67 = t22 * t32;
  t69 = 0.17722691847124394783e0 * t37 + 0.35445383694248789566e0 * t44 + 0.19997916265148655846e0 * t46 - 0.78539816339744830968e0 * t49 + 0.39995832530297311691e0 * t52 + 0.88613459235621973915e-1 * t55 - 0.69604099960396348071e0 * t59 + 0.35445383694248789566e0 * t61 + 0.70890767388497579132e0 * t63 + 0.19997916265148655846e0 * t65 - 0.78539816339744830968e0 * t67;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = t1 * t69 + t16 + t20 + t26 + t31 + t34;

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = vrho[0];

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t83 = 0.1e1 / t2 / t1;
  t84 = t83 * t10;
  t85 = t84 * t14;
  t87 = t35 * t42;
  t88 = t87 * t14;
  t90 = t83 * t7;
  t92 = 0.1e1 / t1;
  t93 = t92 * t22;
  t97 = -0.98185000000000000000e0 * t90 - 0.38561176900000000000e1 * t93 + 0.30289033231412000001e2 * t58 * t35;
  t98 = t2 * t97;
  t99 = t98 * t14;
  t101 = t90 * t18;
  t103 = t93 * t18;
  t105 = t39 * t51;
  t108 = t17 * t35;
  t109 = t58 * t10 * t108;
  t112 = t22 * t42 * t17;
  t114 = t97 * t17;
  t115 = t8 * t114;
  t118 = t83 * t22 * t24;
  t121 = t92 * t58 * t24;
  t123 = t21 * t21;
  t124 = 0.1e1 / t123;
  t126 = t124 * t24 * t35;
  t128 = t84 * t29;
  t130 = t87 * t29;
  t132 = t98 * t29;
  t134 = t90 * t32;
  t136 = t93 * t32;
  t139 = t58 * t32 * t35;
  t141 = -0.88613459235621973915e-1 * t85 + 0.35445383694248789566e0 * t88 + 0.35445383694248789566e0 * t99 - 0.99989581325743279230e-1 * t101 - 0.39269908169872415485e0 * t103 + 0.39995832530297311692e0 * t105 + 0.30845727469271384914e1 * t109 - 0.15707963267948966194e1 * t112 + 0.39995832530297311691e0 * t115 - 0.44306729617810986958e-1 * t118 - 0.34802049980198174035e0 * t121 + 0.41004471327669092612e1 * t126 - 0.17722691847124394783e0 * t128 + 0.70890767388497579132e0 * t130 + 0.70890767388497579132e0 * t132 - 0.99989581325743279230e-1 * t134 - 0.39269908169872415485e0 * t136 + 0.30845727469271384914e1 * t139;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = 0.35445383694248789566e0 * t37 + 0.70890767388497579132e0 * t44 + 0.39995832530297311692e0 * t46 - 0.15707963267948966194e1 * t49 + 0.79991665060594623382e0 * t52 + 0.17722691847124394783e0 * t55 - 0.13920819992079269614e1 * t59 + 0.70890767388497579132e0 * t61 + 0.14178153477699515826e1 * t63 + 0.39995832530297311692e0 * t65 - 0.15707963267948966194e1 * t67 + t1 * t141;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = v2rho2[0];

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = v2rho2[1];

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t161 = t1 * t1;
  t163 = 0.1e1 / t2 / t161;
  t164 = t163 * t10;
  t172 = t163 * t7;
  t175 = t83 * t42;
  t178 = t35 * t97;
  t182 = 0.1e1 / t161;
  t183 = t182 * t22;
  t187 = 0.14727750000000000000e1 * t172 + 0.57841765350000000000e1 * t183 - 0.17843572366957123321e3 * t124 * t92;
  t188 = t2 * t187;
  t206 = 0.13292018885343296087e0 * t164 * t14 + 0.66460094426716480437e-1 * t163 * t22 * t24 + 0.26584037770686592174e0 * t164 * t29 + 0.14998437198861491884e0 * t172 * t32 - 0.26584037770686592174e0 * t175 * t14 + 0.53168075541373184349e0 * t178 * t14 + 0.35445383694248789566e0 * t188 * t14 - 0.23561944901923449291e1 * t22 * t97 * t17 + 0.52203074970297261053e0 * t182 * t58 * t24 - 0.32208192138457518865e2 / t123 / t6 * t24 * t92 - 0.53168075541373184349e0 * t175 * t29 + 0.10633615108274636870e1 * t178 * t29;
  t211 = t83 * t58;
  t239 = 0.70890767388497579132e0 * t188 * t29 + 0.58904862254808623227e0 * t183 * t32 + 0.1e-18 * t211 * t32 - 0.18171526509422465567e2 * t124 * t32 * t92 + 0.14998437198861491884e0 * t172 * t18 - 0.29996874397722983769e0 * t90 * t51 + 0.58904862254808623227e0 * t183 * t18 - 0.11780972450961724646e1 * t93 * t51 + 0.1e-18 * t211 * t18 + 0.59993748795445967538e0 * t39 * t114 + 0.92537182407814154744e1 * t58 * t42 * t108 - 0.18171526509422465567e2 * t124 * t10 * t17 * t92 + 0.39995832530297311691e0 * t8 * t187 * t17;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.29996874397722983769e0 * t101 - 0.26584037770686592174e0 * t85 + 0.11998749759089193508e1 * t105 - 0.11780972450961724646e1 * t103 + 0.92537182407814154744e1 * t109 + 0.11998749759089193507e1 * t115 - 0.13292018885343296087e0 * t118 - 0.53168075541373184349e0 * t128 - 0.29996874397722983769e0 * t134 + 0.10633615108274636870e1 * t88 + 0.10633615108274636870e1 * t99 - 0.47123889803846898582e1 * t112 - 0.10440614994059452211e1 * t121 + 0.12301341398300727784e2 * t126 + 0.21267230216549273739e1 * t130 + 0.21267230216549273739e1 * t132 - 0.11780972450961724646e1 * t136 + 0.92537182407814154744e1 * t139 + t1 * (t206 + t239);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = v3rho3[0];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = v3rho3[1];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = v3rho3[2];

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}

