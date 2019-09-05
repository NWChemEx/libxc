/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/lda_exc/lda_k_tf.mpl
  Type of functional: lda_exc
*/

#define maple2c_order 3

DEVICE static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t2, t4, t5, t7, t8, t9, t10;
  double t11, t13;

  lda_k_tf_params *params;

  assert(p->params != NULL);
  params = (lda_k_tf_params * )(p->params);

  t1 = M_CBRT3;
  t2 = params->ax * t1;
  t4 = POW_1_3(0.1e1 / M_PI);
  t5 = t4 * t4;
  t7 = M_CBRT4;
  t8 = t7 * t7;
  t9 = 0.1e1 / t5 * t8;
  t10 = POW_1_3(rho[0]);
  t11 = t10 * t10;
  t13 = t2 * t9 * t11;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t13 / 0.3e1;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = 0.5e1 / 0.9e1 * t13;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = 0.10e2 / 0.27e2 * t2 * t9 / t10;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.10e2 / 0.81e2 * t2 * t9 / t10 / rho[0];

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


DEVICE static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t2, t4, t5, t7, t8, t10, t11;
  double t12, t13, t14, t16;

  lda_k_tf_params *params;

  assert(p->params != NULL);
  params = (lda_k_tf_params * )(p->params);

  t1 = M_CBRT2;
  t2 = t1 * t1;
  t4 = M_CBRT3;
  t5 = params->ax * t2 * t4;
  t7 = POW_1_3(0.1e1 / M_PI);
  t8 = t7 * t7;
  t10 = M_CBRT4;
  t11 = t10 * t10;
  t12 = 0.1e1 / t8 * t11;
  t13 = POW_1_3(rho[0]);
  t14 = t13 * t13;
  t16 = t5 * t12 * t14;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t16 / 0.3e1;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = 0.5e1 / 0.9e1 * t16;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = 0.10e2 / 0.27e2 * t5 * t12 / t13;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.10e2 / 0.81e2 * t5 * t12 / t13 / rho[0];

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


DEVICE static inline void
func_pol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t2, t3, t4, t5, t6, t7, t9;
  double t10, t11, t16, t17, t19, t20, t21, t22;
  double t23, t24, t25, t26, t27, t28, t29, t31;
  double t32, t33, t34, t35, t37, t40, t43, t46;
  double t48, t51, t56, t57, t59, t60, t62, t63;
  double t64, t68, t69, t71, t74, t75, t78, t81;
  double t86, t88, t90, t93, t96, t99, t102, t107;
  double t111, t114, t117, t120, t126, t128, t134, t136;
  double t143, t144, t145, t147, t151, t169, t173, t207;
  double t219, t245;

  lda_k_tf_params *params;

  assert(p->params != NULL);
  params = (lda_k_tf_params * )(p->params);

  t1 = rho[0] - rho[1];
  t2 = rho[0] + rho[1];
  t3 = 0.1e1 / t2;
  t4 = t1 * t3;
  t5 = 0.1e1 + t4;
  t6 = POW_1_3(t5);
  t7 = t6 * t6;
  t9 = 0.1e1 - t4;
  t10 = POW_1_3(t9);
  t11 = t10 * t10;
  t16 = M_CBRT3;
  t17 = params->ax * (t11 * t9 / 0.2e1 + t7 * t5 / 0.2e1) * t16;
  t19 = POW_1_3(0.1e1 / M_PI);
  t20 = t19 * t19;
  t21 = 0.1e1 / t20;
  t22 = M_CBRT4;
  t23 = t22 * t22;
  t24 = t21 * t23;
  t25 = POW_1_3(t2);
  t26 = t25 * t25;
  t27 = t24 * t26;
  t28 = t17 * t27;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t28 / 0.3e1;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t29 = 0.5e1 / 0.9e1 * t28;
  t31 = t26 * t2 * params->ax;
  t32 = t2 * t2;
  t33 = 0.1e1 / t32;
  t34 = t1 * t33;
  t35 = t3 - t34;
  t37 = -t35;
  t40 = 0.5e1 / 0.6e1 * t11 * t37 + 0.5e1 / 0.6e1 * t7 * t35;
  t43 = t16 * t21 * t23;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = t29 + t31 * t40 * t43 / 0.3e1;

  t46 = -t3 - t34;
  t48 = -t46;
  t51 = 0.5e1 / 0.6e1 * t11 * t48 + 0.5e1 / 0.6e1 * t7 * t46;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = t29 + t31 * t51 * t43 / 0.3e1;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t56 = params->ax * t40 * t16;
  t57 = t56 * t27;
  t59 = 0.1e1 / t25;
  t60 = t24 * t59;
  t62 = 0.10e2 / 0.27e2 * t17 * t60;
  t63 = 0.1e1 / t6;
  t64 = t35 * t35;
  t68 = 0.1e1 / t32 / t2;
  t69 = t1 * t68;
  t71 = -0.2e1 * t33 + 0.2e1 * t69;
  t74 = 0.1e1 / t10;
  t75 = t37 * t37;
  t78 = -t71;
  t81 = 0.5e1 / 0.9e1 * t63 * t64 + 0.5e1 / 0.6e1 * t7 * t71 + 0.5e1 / 0.9e1 * t74 * t75 + 0.5e1 / 0.6e1 * t11 * t78;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = 0.10e2 / 0.9e1 * t57 + t62 + t31 * t81 * t43 / 0.3e1;

  t86 = t26 * params->ax;
  t88 = t86 * t51 * t43;
  t90 = t63 * t46;
  t93 = t7 * t1;
  t96 = t74 * t48;
  t99 = t11 * t1;
  t102 = 0.5e1 / 0.9e1 * t90 * t35 + 0.5e1 / 0.3e1 * t93 * t68 + 0.5e1 / 0.9e1 * t96 * t37 - 0.5e1 / 0.3e1 * t99 * t68;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = 0.5e1 / 0.9e1 * t57 + t62 + 0.5e1 / 0.9e1 * t88 + t31 * t102 * t43 / 0.3e1;

  t107 = t46 * t46;
  t111 = 0.2e1 * t33 + 0.2e1 * t69;
  t114 = t48 * t48;
  t117 = -t111;
  t120 = 0.5e1 / 0.9e1 * t63 * t107 + 0.5e1 / 0.6e1 * t7 * t111 + 0.5e1 / 0.9e1 * t74 * t114 + 0.5e1 / 0.6e1 * t11 * t117;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = 0.10e2 / 0.9e1 * t88 + t62 + t31 * t120 * t43 / 0.3e1;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t126 = params->ax * t81 * t16 * t27;
  t128 = t56 * t60;
  t134 = 0.10e2 / 0.81e2 * t17 * t24 / t25 / t2;
  t136 = 0.1e1 / t6 / t5;
  t143 = t32 * t32;
  t144 = 0.1e1 / t143;
  t145 = t1 * t144;
  t147 = 0.6e1 * t68 - 0.6e1 * t145;
  t151 = 0.1e1 / t10 / t9;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.5e1 / 0.3e1 * t126 + 0.10e2 / 0.9e1 * t128 - t134 + t31 * (-0.5e1 / 0.27e2 * t136 * t64 * t35 + 0.5e1 / 0.3e1 * t63 * t35 * t71 + 0.5e1 / 0.6e1 * t7 * t147 - 0.5e1 / 0.27e2 * t151 * t75 * t37 + 0.5e1 / 0.3e1 * t74 * t37 * t78 - 0.5e1 / 0.6e1 * t11 * t147) * t43 / 0.3e1;

  t169 = t59 * params->ax * t51 * t43;
  t173 = 0.10e2 / 0.9e1 * t86 * t102 * t43;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = 0.5e1 / 0.9e1 * t126 + 0.20e2 / 0.27e2 * t128 - t134 + 0.10e2 / 0.27e2 * t169 + t173 + t31 * (-0.5e1 / 0.27e2 * t136 * t46 * t64 + 0.20e2 / 0.9e1 * t63 * t1 * t68 * t35 + 0.5e1 / 0.9e1 * t90 * t71 + 0.5e1 / 0.3e1 * t7 * t68 - 0.5e1 * t93 * t144 - 0.5e1 / 0.27e2 * t151 * t48 * t75 - 0.20e2 / 0.9e1 * t74 * t1 * t68 * t37 + 0.5e1 / 0.9e1 * t96 * t78 - 0.5e1 / 0.3e1 * t11 * t68 + 0.5e1 * t99 * t144) * t43 / 0.3e1;

  t207 = t86 * t120 * t43;
  t219 = -0.2e1 * t68 - 0.6e1 * t145;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = 0.20e2 / 0.27e2 * t169 + t173 + 0.10e2 / 0.27e2 * t128 - t134 + 0.5e1 / 0.9e1 * t207 + t31 * (-0.5e1 / 0.27e2 * t136 * t107 * t35 + 0.20e2 / 0.9e1 * t90 * t69 + 0.5e1 / 0.9e1 * t63 * t111 * t35 + 0.5e1 / 0.6e1 * t7 * t219 - 0.5e1 / 0.27e2 * t151 * t114 * t37 - 0.20e2 / 0.9e1 * t96 * t69 + 0.5e1 / 0.9e1 * t74 * t117 * t37 - 0.5e1 / 0.6e1 * t11 * t219) * t43 / 0.3e1;

  t245 = -0.6e1 * t68 - 0.6e1 * t145;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = 0.10e2 / 0.9e1 * t169 + 0.5e1 / 0.3e1 * t207 - t134 + t31 * (-0.5e1 / 0.27e2 * t136 * t107 * t46 + 0.5e1 / 0.3e1 * t90 * t111 + 0.5e1 / 0.6e1 * t7 * t245 - 0.5e1 / 0.27e2 * t151 * t114 * t48 + 0.5e1 / 0.3e1 * t96 * t117 - 0.5e1 / 0.6e1 * t11 * t245) * t43 / 0.3e1;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}

