/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : ./maple/lda_exc/lda_x_1d_soft.mpl
  Type of functional: lda_exc
*/

#define maple2c_order 3

DEVICE static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t2, t3, t4, t5, t7, t8, t15, t20;
  double t22;

  lda_x_1d_exponential_params *params;

  assert(p->params != NULL);
  params = (lda_x_1d_exponential_params * )(p->params);

  t2 = M_PI * params->beta * rho[0];
  t3 = xc_integrate(func1, NULL, 0.0, t2);
  t4 = xc_integrate(func2, NULL, 0.0, t2);
  t5 = 0.1e1 / M_PI;
  t7 = 0.1e1 / params->beta;
  t8 = 0.1e1 / rho[0];
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.15915494309189533577e0 * (-t4 * t5 * t7 * t8 + t3) * t7;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t15 = params->beta * params->beta;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = (-0.15915494309189533577e0 * (-t4 * t5 * t7 * t8 + t3) * t7) - 0.15915494309189533577e0 * t8 * t4 * t5 / t15;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t20 = xc_bessel_K0( t2);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.10000000000000000000e1 * t20;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t22 = xc_bessel_K1( t2);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = M_PI * t22 * params->beta;

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
  double t3, t4, t6, t7, t9, t10, t17, t22;
  double t24;

  lda_x_1d_exponential_params *params;

  assert(p->params != NULL);
  params = (lda_x_1d_exponential_params * )(p->params);

  t3 = 0.2e1 * M_PI * params->beta * rho[0];
  t4 = xc_integrate(func1, NULL, 0.0, t3);
  t6 = xc_integrate(func2, NULL, 0.0, t3);
  t7 = 0.1e1 / M_PI;
  t9 = 0.1e1 / params->beta;
  t10 = 0.1e1 / rho[0];
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -0.79577471545947667883e-1 * (-t6 * t7 * t9 * t10 + 0.2e1 * t4) * t9;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t17 = params->beta * params->beta;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = (-0.79577471545947667883e-1 * (-t6 * t7 * t9 * t10 + 0.2e1 * t4) * t9) - 0.79577471545947667883e-1 * t10 * t6 * t7 / t17;

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t22 = xc_bessel_K0( t3);
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.20000000000000000000e1 * t22;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t24 = xc_bessel_K1( t3);
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.12566370614359172954e2 * t24 * params->beta;

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
  double t1, t2, t3, t4, t5, t6, t7, t8;
  double t9, t11, t12, t13, t14, t15, t19, t20;
  double t21, t22, t23, t25, t26, t30, t31, t32;
  double t33, t34, t36, t37, t39, t40, t41, t43;
  double t45, t46, t49, t52, t53, t54, t57, t58;
  double t64, t65, t67, t69, t71, t72, t74, t77;
  double t78, t80, t81, t83, t85, t86, t87, t89;
  double t91, t92, t94, t97, t98, t100, t102, t104;
  double t105, t114, t122, t129, t131, t133, t134, t137;
  double t141, t142, t143, t145, t147, t148, t151, t155;
  double t156, t161, t162, t163, t165, t172, t174, t178;
  double t180, t185, t188, t189, t191, t192, t193, t194;
  double t195, t197, t208, t210, t214, t216, t221, t224;
  double t225, t227, t228, t229, t230, t232, t238, t239;
  double t274, t283, t284, t285, t302, t305, t315, t316;
  double t333, t336, t344, t352, t356, t381, t385;

  lda_x_1d_exponential_params *params;

  assert(p->params != NULL);
  params = (lda_x_1d_exponential_params * )(p->params);

  t1 = rho[0] - rho[1];
  t2 = rho[0] + rho[1];
  t3 = 0.1e1 / t2;
  t4 = t1 * t3;
  t5 = 0.1e1 + t4;
  t6 = t5 * M_PI;
  t7 = params->beta * t2;
  t8 = t6 * t7;
  t9 = xc_integrate(func1, NULL, 0.0, t8);
  t11 = xc_integrate(func2, NULL, 0.0, t8);
  t12 = 0.1e1 / M_PI;
  t13 = t11 * t12;
  t14 = 0.1e1 / params->beta;
  t15 = t14 * t3;
  t19 = 0.79577471545947667883e-1 * (-t13 * t15 + t5 * t9) * t14;
  t20 = 0.1e1 - t4;
  t21 = t20 * M_PI;
  t22 = t21 * t7;
  t23 = xc_integrate(func1, NULL, 0.0, t22);
  t25 = xc_integrate(func2, NULL, 0.0, t22);
  t26 = t25 * t12;
  t30 = 0.79577471545947667883e-1 * (-t26 * t15 + t20 * t23) * t14;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = -t19 - t30;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t31 = t2 * t2;
  t32 = 0.1e1 / t31;
  t33 = t1 * t32;
  t34 = t3 - t33;
  t36 = t14 * t32;
  t37 = t13 * t36;
  t39 = (t34 * t9 + t37) * t14;
  t40 = 0.79577471545947667883e-1 * t39;
  t41 = -t34;
  t43 = t26 * t36;
  t45 = (t41 * t23 + t43) * t14;
  t46 = 0.79577471545947667883e-1 * t45;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = -t19 - t30 + t2 * (-t40 - t46);

  t49 = -t3 - t33;
  t52 = (t49 * t9 + t37) * t14;
  t53 = 0.79577471545947667883e-1 * t52;
  t54 = -t49;
  t57 = (t54 * t23 + t43) * t14;
  t58 = 0.79577471545947667883e-1 * t57;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = -t19 - t30 + t2 * (-t53 - t58);

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t64 = 0.1e1 / t31 / t2;
  t65 = t1 * t64;
  t67 = -0.2e1 * t32 + 0.2e1 * t65;
  t69 = t34 * M_PI;
  t71 = t6 * params->beta;
  t72 = t69 * t7 + t71;
  t74 = xc_bessel_K0( t8);
  t77 = t72 * t74;
  t78 = t5 * t3;
  t80 = 0.20000000000000000000e1 * t77 * t78;
  t81 = t14 * t64;
  t83 = 0.2e1 * t13 * t81;
  t85 = (t67 * t9 + 0.20e1 * t34 * t72 * t74 + t80 - t83) * t14;
  t86 = 0.79577471545947667883e-1 * t85;
  t87 = -t67;
  t89 = t41 * M_PI;
  t91 = t21 * params->beta;
  t92 = t89 * t7 + t91;
  t94 = xc_bessel_K0( t22);
  t97 = t92 * t94;
  t98 = t20 * t3;
  t100 = 0.20000000000000000000e1 * t97 * t98;
  t102 = 0.2e1 * t26 * t81;
  t104 = (t87 * t23 + 0.20e1 * t41 * t92 * t94 + t100 - t102) * t14;
  t105 = 0.79577471545947667883e-1 * t104;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.15915494309189533577e0 * t39 - 0.15915494309189533577e0 * t45 + t2 * (-t86 - t105);

  t114 = (0.2e1 * t65 * t9 + 0.20e1 * t49 * t72 * t74 + t80 - t83) * t14;
  t122 = (-0.2e1 * t65 * t23 + 0.20e1 * t54 * t92 * t94 + t100 - t102) * t14;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = -t40 - t46 - t53 - t58 + t2 * (-0.79577471545947667883e-1 * t114 - 0.79577471545947667883e-1 * t122);

  t129 = 0.2e1 * t32 + 0.2e1 * t65;
  t131 = t49 * M_PI;
  t133 = t131 * t7 + t71;
  t134 = t49 * t133;
  t137 = t133 * t74;
  t141 = (t129 * t9 + 0.20e1 * t134 * t74 + 0.20000000000000000000e1 * t137 * t78 - t83) * t14;
  t142 = 0.79577471545947667883e-1 * t141;
  t143 = -t129;
  t145 = t54 * M_PI;
  t147 = t145 * t7 + t91;
  t148 = t54 * t147;
  t151 = t147 * t94;
  t155 = (t143 * t23 + 0.20e1 * t148 * t94 + 0.20000000000000000000e1 * t151 * t98 - t102) * t14;
  t156 = 0.79577471545947667883e-1 * t155;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = -0.15915494309189533577e0 * t52 - 0.15915494309189533577e0 * t57 + t2 * (-t142 - t156);

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t161 = t31 * t31;
  t162 = 0.1e1 / t161;
  t163 = t1 * t162;
  t165 = 0.6e1 * t64 - 0.6e1 * t163;
  t172 = t69 * params->beta;
  t174 = t67 * M_PI * t7 + 0.2e1 * t172;
  t178 = t72 * t72;
  t180 = xc_bessel_K1( t8);
  t185 = 0.20000000000000000000e1 * t174 * t74 * t78;
  t188 = 0.20000000000000000000e1 * t178 * t180 * t78;
  t189 = t34 * t3;
  t191 = 0.20000000000000000000e1 * t77 * t189;
  t192 = t5 * t32;
  t193 = t77 * t192;
  t194 = 0.60000000000000000000e1 * t193;
  t195 = t14 * t162;
  t197 = 0.6e1 * t13 * t195;
  t208 = t89 * params->beta;
  t210 = t87 * M_PI * t7 + 0.2e1 * t208;
  t214 = t92 * t92;
  t216 = xc_bessel_K1( t22);
  t221 = 0.20000000000000000000e1 * t210 * t94 * t98;
  t224 = 0.20000000000000000000e1 * t214 * t216 * t98;
  t225 = t41 * t3;
  t227 = 0.20000000000000000000e1 * t97 * t225;
  t228 = t20 * t32;
  t229 = t97 * t228;
  t230 = 0.60000000000000000000e1 * t229;
  t232 = 0.6e1 * t26 * t195;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = -0.23873241463784300365e0 * t85 - 0.23873241463784300365e0 * t104 + t2 * (-0.79577471545947667883e-1 * (t165 * t9 + 0.40e1 * t67 * t72 * t74 + 0.20e1 * t34 * t174 * t74 - 0.20e1 * t34 * t178 * t180 + t185 - t188 + t191 - t194 + t197) * t14 - 0.79577471545947667883e-1 * (-t165 * t23 + 0.40e1 * t87 * t92 * t94 + 0.20e1 * t41 * t210 * t94 - 0.20e1 * t41 * t214 * t216 + t221 - t224 + t227 - t230 + t232) * t14);

  t238 = 0.15915494309189533577e0 * t114;
  t239 = 0.15915494309189533577e0 * t122;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = -t86 - t105 - t238 - t239 + t2 * (-0.79577471545947667883e-1 * (0.2e1 * t64 * t9 - 0.6e1 * t163 * t9 + 0.80e1 * t65 * t77 + 0.20e1 * t49 * t174 * t74 - 0.20e1 * t49 * t178 * t180 + t185 - t188 + t191 - t194 + t197) * t14 - 0.79577471545947667883e-1 * (-0.2e1 * t64 * t23 + 0.6e1 * t163 * t23 - 0.80e1 * t65 * t97 + 0.20e1 * t54 * t210 * t94 - 0.20e1 * t54 * t214 * t216 + t221 - t224 + t227 - t230 + t232) * t14);

  t274 = -0.2e1 * t64 - 0.6e1 * t163;
  t283 = 0.2e1 * t33 * M_PI * params->beta;
  t284 = t131 * params->beta;
  t285 = t283 + t284 + t172;
  t302 = t137 * t192;
  t305 = t274 * t9 + 0.20e1 * t129 * t72 * t74 + 0.40e1 * t65 * t137 + 0.20e1 * t49 * t285 * t74 - 0.20e1 * t134 * t180 * t72 + 0.20000000000000000000e1 * t285 * t74 * t78 - 0.20000000000000000000e1 * t133 * t180 * t72 * t5 * t3 + 0.20000000000000000000e1 * t137 * t189 - 0.20000000000000000000e1 * t302 - 0.40000000000000000000e1 * t193 + t197;
  t315 = t145 * params->beta;
  t316 = -t283 + t315 + t208;
  t333 = t151 * t228;
  t336 = -t274 * t23 + 0.20e1 * t143 * t92 * t94 - 0.40e1 * t65 * t151 + 0.20e1 * t54 * t316 * t94 - 0.20e1 * t148 * t216 * t92 + 0.20000000000000000000e1 * t316 * t94 * t98 - 0.20000000000000000000e1 * t147 * t216 * t92 * t20 * t3 + 0.20000000000000000000e1 * t151 * t225 - 0.20000000000000000000e1 * t333 - 0.40000000000000000000e1 * t229 + t232;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = -t238 - t239 - t142 - t156 + t2 * (-0.79577471545947667883e-1 * t305 * t14 - 0.79577471545947667883e-1 * t336 * t14);

  t344 = -0.6e1 * t64 - 0.6e1 * t163;
  t352 = t129 * M_PI * t7 + 0.2e1 * t284;
  t356 = t133 * t133;
  t381 = t143 * M_PI * t7 + 0.2e1 * t315;
  t385 = t147 * t147;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = -0.23873241463784300365e0 * t141 - 0.23873241463784300365e0 * t155 + t2 * (-0.79577471545947667883e-1 * (t344 * t9 + 0.40e1 * t129 * t133 * t74 + 0.20e1 * t49 * t352 * t74 - 0.20e1 * t49 * t356 * t180 + 0.20000000000000000000e1 * t352 * t74 * t78 - 0.20000000000000000000e1 * t356 * t180 * t78 + 0.20000000000000000000e1 * t137 * t49 * t3 - 0.60000000000000000000e1 * t302 + t197) * t14 - 0.79577471545947667883e-1 * (-t344 * t23 + 0.40e1 * t143 * t147 * t94 + 0.20e1 * t54 * t381 * t94 - 0.20e1 * t54 * t385 * t216 + 0.20000000000000000000e1 * t381 * t94 * t98 - 0.20000000000000000000e1 * t385 * t216 * t98 + 0.20000000000000000000e1 * t151 * t54 * t3 - 0.60000000000000000000e1 * t333 + t232) * t14);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}

