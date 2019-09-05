#ifndef DVC_UTIL_H
#define DVC_UTIL_H

#include "dvc_references.h"

extern "C" {
/* we define this function here, so it can be properly inlined by all compilers */
DEVICE static inline double
dvc_xc_cheb_eval(const double x, const double *cs, const int N)
{
  int i;
  double twox, b0, b1, b2;

  b2 = b1 = b0 = 0.0;

  twox = 2.0*x;
  for(i=N-1; i>=0; i--){
    b2 = b1;
    b1 = b0;
    b0 = twox*b1 - b2 + cs[i];
  }

  return 0.5*(b0 - b2);
}

DEVICE double dvc_LambertW(double z);
DEVICE double dvc_xc_dilogarithm(const double x);
DEVICE double dvc_xc_bessel_I0_scaled(const double x);
DEVICE double dvc_xc_bessel_I0(const double x);
DEVICE double dvc_xc_bessel_I1_scaled(const double x);
DEVICE double dvc_xc_bessel_I1(const double x);
DEVICE double dvc_xc_bessel_K0_scaled(const double x);
DEVICE double dvc_xc_bessel_K0(const double x);
DEVICE double dvc_xc_bessel_K1_scaled(const double x);
DEVICE double dvc_xc_bessel_K1(const double x);
DEVICE double dvc_xc_expint_e1_impl(double x, const int scale);
DEVICE static inline double dvc_expint_e1(const double x)         { return  dvc_xc_expint_e1_impl( x, 0); }
DEVICE static inline double dvc_expint_e1_scaled(const double x)  { return  dvc_xc_expint_e1_impl( x, 1); }
DEVICE static inline double dvc_expint_Ei(const double x)         { return -dvc_xc_expint_e1_impl(-x, 0); }
#define dvc_Ei(x) dvc_expint_Ei(x)
DEVICE static inline double dvc_expint_Ei_scaled(const double x)  { return -dvc_xc_expint_e1_impl(-x, 1); }
DEVICE int dvc_xc_func_info_get_number(const xc_func_info_type *info);
DEVICE int dvc_xc_func_info_get_kind(const xc_func_info_type *info);
DEVICE char const *dvc_xc_func_info_get_name(const xc_func_info_type *info);
DEVICE int dvc_xc_func_info_get_family(const xc_func_info_type *info);
DEVICE int dvc_xc_func_info_get_flags(const xc_func_info_type *info);
DEVICE const func_reference_type *dvc_xc_func_info_get_references(const xc_func_info_type *info, int number);
DEVICE int dvc_xc_func_info_get_n_ext_params(xc_func_info_type *info);
DEVICE char const *dvc_xc_func_info_get_ext_params_description(xc_func_info_type *info, int number);
DEVICE double dvc_xc_func_info_get_ext_params_default_value(xc_func_info_type *info, int number);
DEVICE int dvc_xc_functional_get_number(const char *name);
DEVICE char *dvc_xc_functional_get_name(int number);
DEVICE int dvc_xc_family_from_id(int id, int *family, int *number);
DEVICE int dvc_xc_number_of_functionals();
DEVICE int dvc_xc_maximum_name_length();
DEVICE void dvc_xc_available_functional_numbers(int *list);
DEVICE void dvc_xc_available_functional_names(char **list);
DEVICE xc_func_type *dvc_xc_func_alloc();
DEVICE int dvc_xc_func_init(xc_func_type *func, int functional, int nspin);
DEVICE void dvc_xc_func_end(xc_func_type *func);
DEVICE void  dvc_xc_func_free(xc_func_type *p);
DEVICE const xc_func_info_type *dvc_xc_func_get_info(const xc_func_type *p);
DEVICE void dvc_xc_func_set_dens_threshold(xc_func_type *p, double dens_threshold);
DEVICE void dvc_xc_func_set_ext_params(xc_func_type *p, double *ext_params);
DEVICE double dvc_xc_hyb_exx_coef(const xc_func_type *p);
DEVICE void dvc_xc_hyb_cam_coef(const xc_func_type *p, double *omega, double *alpha, double *beta);
DEVICE void dvc_xc_nlc_coef(const xc_func_type *p, double *nlc_b, double *nlc_C);
DEVICE
void dvc_xc_gga(const xc_func_type *func, int np, const double *rho, const double *sigma,
             double *zk, double *vrho, double *vsigma,
             double *v2rho2, double *v2rhosigma, double *v2sigma2,
             double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3);
DEVICE
void
dvc_xc_gga_exc(const xc_func_type *p, int np, const double *rho, const double *sigma,
            double *zk);
DEVICE
void
dvc_xc_gga_vxc(const xc_func_type *p, int np, const double *rho, const double *sigma,
            double *vrho, double *vsigma);
DEVICE
void
dvc_xc_gga_exc_vxc(const xc_func_type *p, int np, const double *rho, const double *sigma,
                double *zk, double *vrho, double *vsigma);
DEVICE
void
dvc_xc_gga_fxc(const xc_func_type *p, int np, const double *rho, const double *sigma,
            double *v2rho2, double *v2rhosigma, double *v2sigma2);
DEVICE
void
dvc_xc_gga_kxc(const xc_func_type *p, int np, const double *rho, const double *sigma,
            double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3);
DEVICE static void
dvc_work_lda(const XC(func_type) *p, int np, const double *rho,
         double *zk, double *vrho, double *v2rho2, double *v3rho3);
DEVICE static void
dvc_work_gga(const XC(func_type) *p, int np,
         const double *rho, const double *sigma,
         double *zk, double *vrho, double *vsigma,
         double *v2rho2, double *v2rhosigma, double *v2sigma2,
         double *v3rho3, double *v3rho2sigma, double *v3rhosigma2, double *v3sigma3);
DEVICE static void dvc_gga_c_bmk_init(xc_func_type *p);
DEVICE void dvc_xc_gga_c_lyp_init(xc_func_type *p);
DEVICE static void dvc_set_ext_params(xc_func_type *p, const double *ext_params);
DEVICE void dvc_xc_rho2dzeta(int nspin, const double *rho, double *d, double *zeta);
DEVICE const char *dvc_get_kind(const xc_func_type *func);
DEVICE const char *dvc_get_family(const xc_func_type *func);
DEVICE double dvc_get_ext_param(const func_params_type *params, const double *values, int index);
DEVICE void dvc_internal_counters_set_lda(int nspin, xc_dimensions *dim);
DEVICE void dvc_internal_counters_set_gga(int nspin, xc_dimensions *dim);
DEVICE void dvc_internal_counters_set_mgga(int nspin, xc_dimensions *dim);
DEVICE void
dvc_internal_counters_lda_next
  (
   const xc_dimensions *dim, int offset,
   const double **rho, double **zk,
   double **vrho, double **v2rho2, double **v3rho3
   );
DEVICE void
dvc_internal_counters_lda_prev
  (
   const xc_dimensions *dim, int offset,
   const double **rho, double **zk,
   double **vrho, double **v2rho2, double **v3rho3
   );
DEVICE void
dvc_internal_counters_gga_next
  (
   const xc_dimensions *dim, int offset,
   const double **rho, const double **sigma,
   double **zk,
   double **vrho, double **vsigma,
   double **v2rho2, double **v2rhosigma, double **v2sigma2,
   double **v3rho3, double **v3rho2sigma, double **v3rhosigma2, double **v3sigma3
   );
DEVICE void
dvc_internal_counters_gga_prev
  (
   const xc_dimensions *dim, int offset,
   const double **rho, const double **sigma,
   double **zk,
   double **vrho, double **vsigma,
   double **v2rho2, double **v2rhosigma, double **v2sigma2,
   double **v3rho3, double **v3rho2sigma, double **v3rhosigma2, double **v3sigma3
   );
DEVICE void
dvc_xc_mgga_exc(const xc_func_type *p, int np,
            const double *rho, const double *sigma, const double *lapl, const double *tau,
            double *zk);
DEVICE void
dvc_xc_mgga_exc_vxc(const xc_func_type *p, int np,
                const double *rho, const double *sigma, const double *lapl, const double *tau,
                double *zk, double *vrho, double *vsigma, double *vlapl, double *vtau);
DEVICE void
dvc_xc_mgga_vxc(const xc_func_type *p, int np,
            const double *rho, const double *sigma, const double *lapl, const double *tau,
            double *vrho, double *vsigma, double *vlapl, double *vtau);
DEVICE void
dvc_xc_mgga_fxc(const xc_func_type *p, int np,
            const double *rho, const double *sigma, const double *lapl, const double *tau,
            double *v2rho2, double *v2rhosigma, double *v2rholapl, double *v2rhotau,
            double *v2sigma2, double *v2sigmalapl, double *v2sigmatau,
            double *v2lapl2, double *v2lapltau,
            double *v2tau2);
DEVICE
void dvc_xc_mgga_kxc(const xc_func_type *p, int np,
                 const double *rho, const double *sigma, const double *lapl, const double *tau,
                 double *v3rho3, double *v3rho2sigma, double *v3rho2lapl, double *v3rho2tau,
                 double *v3rhosigma2, double *v3rhosigmalapl, double *v3rhosigmatau,
                 double *v3rholapl2, double *v3rholapltau,
                 double *v3rhotau2,
                 double *v3sigma3, double *v3sigma2lapl, double *v3sigma2tau,
                 double *v3sigmalapl2, double *v3sigmalapltau,
                 double *v3sigmatau2,
                 double *v3lapl3, double *v3lapl2tau,
                 double *v3lapltau2,
                 double *v3tau3);
/* This are the derivatives of a mgga */
#define MGGA_OUT_PARAMS_NO_EXC(PTYPE)                                     \
 PTYPE vrho, PTYPE vsigma, PTYPE vlapl, PTYPE vtau,                       \
 PTYPE v2rho2, PTYPE v2rhosigma, PTYPE v2rholapl, PTYPE v2rhotau,         \
 PTYPE v2sigma2, PTYPE v2sigmalapl, PTYPE v2sigmatau,                     \
 PTYPE v2lapl2, PTYPE v2lapltau,                                          \
 PTYPE v2tau2,                                                            \
 PTYPE v3rho3, PTYPE v3rho2sigma, PTYPE v3rho2lapl, PTYPE v3rho2tau,      \
 PTYPE v3rhosigma2, PTYPE v3rhosigmalapl, PTYPE v3rhosigmatau,            \
 PTYPE v3rholapl2, PTYPE v3rholapltau,                                    \
 PTYPE v3rhotau2,                                                         \
 PTYPE v3sigma3, PTYPE v3sigma2lapl, PTYPE v3sigma2tau,                   \
 PTYPE v3sigmalapl2, PTYPE v3sigmalapltau,                                \
 PTYPE v3sigmatau2,                                                       \
 PTYPE v3lapl3, PTYPE v3lapl2tau,                                         \
 PTYPE v3lapltau2,                                                        \
 PTYPE v3tau3
DEVICE void dvc_internal_counters_set_mgga(int nspin, xc_dimensions *dim);
DEVICE void dvc_internal_counters_mgga_next
(const xc_dimensions *dim, int offset,
 const double **rho, const double **sigma, const double **lapl, const double **tau,
 double **zk, MGGA_OUT_PARAMS_NO_EXC(double **));
DEVICE void dvc_internal_counters_mgga_prev
(const xc_dimensions *dim, int offset,
 const double **rho, const double **sigma, const double **lapl, const double **tau,
 double **zk, MGGA_OUT_PARAMS_NO_EXC(double **));
DEVICE void
dvc_xc_mix_init(xc_func_type *p, int n_funcs, const int *funcs_id, const double *mix_coef);
DEVICE void dvc_xc_mix_func
  (const xc_func_type *func, int np,
   const double *rho, const double *sigma, const double *lapl, const double *tau,
   double *zk, MGGA_OUT_PARAMS_NO_EXC(double *));
DEVICE void
dvc_xc_mgga(const xc_func_type *func, int np,
        const double *rho, const double *sigma, const double *lapl, const double *tau,
        double *zk, MGGA_OUT_PARAMS_NO_EXC(double *));
DEVICE void
dvc_xc_lda(const xc_func_type *func, int np, const double *rho,
        double *zk, double *vrho, double *v2rho2, double *v3rho3);
DEVICE void
dvc_xc_lda_exc(const xc_func_type *p, int np, const double *rho, double *zk);
DEVICE void
dvc_xc_lda_exc_vxc(const xc_func_type *p, int np, const double *rho, double *zk, double *vrho);
DEVICE void
dvc_xc_lda_vxc(const xc_func_type *p, int np, const double *rho, double *vrho);
DEVICE void
dvc_xc_lda_fxc(const xc_func_type *p, int np, const double *rho, double *v2rho2);
DEVICE void
dvc_xc_lda_kxc(const xc_func_type *p, int np, const double *rho, double *v3rho3);
DEVICE
double dvc_xc_gga_ak13_get_asymptotic (double homo);
DEVICE void dvc_xc_hyb_gga_xc_cap0_init(xc_func_type *p);
/* integration */
//typedef void integr_fn(double *x, int n, void *ex); // defined in util.h
DEVICE double dvc_xc_integrate(integr_fn func, void *ex, double a, double b);
DEVICE void dvc_xc_rdqagse(integr_fn f, void *ex, double *a, double *b,
                       double *epsabs, double *epsrel, int *limit, double *result,
                       double *abserr, int *neval, int *ier, double *alist__,
                       double *blist, double *rlist, double *elist, int *iord, int *last);
}
#endif
