## Process this file with automake to produce Makefile.in

## Copyright (C) 2002 M. Marques, A. Castro, A. Rubio, G. Bertsch
##
## This Source Code Form is subject to the terms of the Mozilla Public
## License, v. 2.0. If a copy of the MPL was not distributed with this
## file, You can obtain one at http://mozilla.org/MPL/2.0/.
##

SUBDIRS = maple2c

bin_PROGRAMS = xc-info xc-threshold
noinst_PROGRAMS = genwiki xc-sanity

xc_info_SOURCES = xc-info.c
xc_info_LDADD = libxc.la -lm
xc_info_LDFLAGS =

xc_threshold_SOURCES = xc-threshold.c
xc_threshold_LDADD = libxc.la -lm
xc_threshold_LDFLAGS =

genwiki_SOURCES = genwiki.c
genwiki_LDADD = libxc.la -lm
genwiki_LDFLAGS =

xc_sanity_SOURCES = xc-sanity.c
xc_sanity_LDADD = libxc.la -lm
xc_sanity_LDFLAGS =

lib_LTLIBRARIES = libxc.la

libxc_la_FUNC_SOURCES = \
	special_functions.cu bessel.cu expint_e1.cu integrate.cu util.cu	\
	mix_func.cu func_info.cu functionals.cu version.cu func_reference.cu 	\
	lda.cu 									\
	lda_x.cu lda_x_2d.cu lda_c_wigner.cu lda_c_gombas.cu lda_c_rpa.cu	\
	lda_c_hl.cu lda_c_vwn.cu lda_c_vwn_1.cu lda_c_vwn_2.cu			\
	lda_c_vwn_3.cu lda_c_vwn_4.cu lda_c_vwn_rpa.cu lda_c_pz.cu		\
	lda_c_pw.cu lda_c_pk09.cu lda_c_lp96.cu lda_c_ml1.cu lda_c_rc04.cu	\
	lda_xc_teter93.cu lda_c_1d_csc.cu lda_c_1d_loos.cu			\
	lda_c_2d_amgb.cu lda_c_2d_prm.cu lda_k_tf.cu lda_xc_zlp.cu		\
	lda_xc_ksdt.cu lda_c_chachiyo.cu lda_xc_1d_ehwlrg.cu lda_x_rel.cu	\
	lda_x_erf.cu lda_k_zlp.cu lda_c_gk72.cu lda_xc_bn05.cu			\
	lda_c_pmgb06.cu lda_k_gds08_worker.cu lda_xc_tih.cu			\
	lda_x_1d_exponential.cu lda_x_1d_soft.cu 				\
	gga.cu 									\
	gga_x_lg93.cu gga_x_pbe.cu gga_x_rpbe.cu gga_x_pbea.cu			\
	gga_x_mpbe.cu gga_x_herman.cu gga_x_b86.cu gga_x_b88.cu			\
	gga_x_g96.cu gga_x_pw86.cu gga_x_pw91.cu gga_x_optx.cu			\
	gga_x_airy.cu gga_x_c09x.cu gga_x_dk87.cu gga_x_ft97.cu			\
	gga_x_wc.cu gga_x_am05.cu gga_x_bayesian.cu gga_x_kt.cu			\
	gga_x_htbs.cu gga_c_pbe.cu gga_c_lyp.cu gga_c_p86.cu gga_c_pw91.cu	\
	gga_c_am05.cu gga_c_lm.cu gga_c_wl.cu gga_c_wi.cu gga_x_lb.cu		\
	gga_xc_b97.cu gga_xc_edf1.cu gga_xc_1w.cu gga_c_optc.cu			\
	gga_c_tca.cu gga_x_bpccac.cu gga_x_sogga11.cu gga_c_sogga11.cu		\
	gga_xc_th1.cu gga_x_wpbeh.cu gga_x_hjs.cu gga_x_ityh.cu			\
	gga_x_sfat.cu gga_x_sfat_pbe.cu gga_x_ev93.cu gga_x_ak13.cu		\
	gga_x_q2d.cu gga_c_q2d.cu gga_x_ssb_sw.cu gga_c_ft97.cu			\
	gga_x_n12.cu gga_x_lv_rpw86.cu gga_x_2d_b86.cu gga_k_llp.cu		\
	gga_x_2d_b86_mgc.cu gga_x_2d_b88.cu gga_x_2d_pbe.cu			\
	gga_x_lspbe.cu gga_x_lsrpbe.cu gga_k_tflw.cu gga_k_pearson.cu		\
	gga_x_ol2.cu gga_k_ol1.cu gga_k_ol2.cu gga_k_dk.cu gga_k_meyer.cu	\
	gga_x_vmt.cu gga_x_hcth_a.cu gga_x_cap.cu gga_x_beefvdw.cu		\
	gga_x_sg4.cu gga_x_gg99.cu gga_x_pbepow.cu gga_x_lag.cu			\
	gga_k_thakkar.cu gga_xc_oblyp_d.cu hyb_gga_xc_b3lyp.cu			\
	hyb_gga_xc_o3lyp.cu gga_x_pbeint.cu gga_x_rge2.cu gga_x_vmt84.cu	\
	gga_x_hjs_b88_v2.cu gga_c_revtca.cu gga_c_acgga.cu			\
	gga_c_acggap.cu gga_c_zpbeint.cu gga_c_pbeloc.cu gga_c_sg4.cu		\
	gga_c_regtpss.cu gga_c_scan_e0.cu gga_xc_th2.cu gga_xc_th3.cu		\
	gga_c_hcth_a.cu hyb_gga_xc_wb97.cu gga_c_bmk.cu gga_c_gapc.cu		\
	gga_c_gaploc.cu gga_c_zvpbeint.cu gga_c_w94.cu gga_c_cs1.cu		\
	gga_c_op_xalpha.cu gga_c_op_b88.cu gga_c_op_pbe.cu			\
	gga_c_op_g96.cu gga_c_op_pw91.cu gga_x_pbetrans.cu gga_k_apbeint.cu	\
	gga_x_chachiyo.cu gga_k_gds08.cu gga_k_exp4.cu hyb_gga_xc_pbeh.cu	\
	hyb_gga_xc_b1wc.cu hyb_gga_xc_hse.cu hyb_gga_xc_cam_b3lyp.cu		\
	hyb_gga_xc_cam_qtp.cu gga_k_lc94.cu gga_c_zvpbeloc.cu 			\
	hyb_gga_xc_camy_blyp.cu hyb_gga_xc_camy_b3lyp.cu			\
	hyb_gga_xc_lcy_pbe.cu hyb_gga_xc_lcy_blyp.cu gga_xc_vv10.cu		\
	hyb_gga_xc_edf2.cu gga_k_pw86.cu gga_k_mpbe.cu gga_k_apbe.cu        	\
        gga_x_fd_lb94.cu 							\
	mgga.cu 								\
	mgga_x_lta.cu mgga_x_tpss.cu mgga_x_br89.cu mgga_x_gvt4.cu		\
	mgga_x_m06l.cu mgga_x_tau_hcth.cu mgga_x_2d_prhg07.cu			\
	mgga_x_pkzb.cu hyb_mgga_x_m05.cu mgga_x_m08.cu mgga_x_ms.cu		\
	mgga_x_mn12.cu mgga_x_mk00.cu mgga_c_vsxc.cu mgga_c_pkzb.cu		\
	mgga_c_bc95.cu mgga_c_m08.cu mgga_xc_cc06.cu mgga_c_cs.cu		\
	mgga_xc_otpss_d.cu mgga_xc_zlp.cu hyb_mgga_xc_b88b95.cu			\
	mgga_x_mbeef.cu mgga_xc_b97mv.cu mgga_x_scan.cu mgga_c_scan.cu		\
	hyb_mgga_xc_tpssh.cu mgga_x_mvs.cu hyb_mgga_x_mvsh.cu			\
	mgga_x_tm.cu mgga_x_vt84.cu mgga_x_sa_tpss.cu mgga_k_pc07.cu		\
	mgga_x_mbeefvdw.cu mgga_x_m11.cu mgga_x_m11_l.cu			\
	hyb_mgga_xc_wb97mv.cu mgga_c_m05.cu mgga_c_m06l.cu			\
	hyb_mgga_x_dldf.cu mgga_c_tpss.cu mgga_c_revtpss.cu			\
	mgga_c_tpssloc.cu mgga_xc_hle17.cu mgga_c_kcis.cu mgga_xc_lp90.cu	\
	hyb_mgga_xc_kcis.cu mgga_c_b88.cu mgga_x_gx.cu mgga_x_pbe_gx.cu		\
	mgga_c_revscan.cu mgga_x_br89_explicit.cu mgga_xc_b98.cu		\
	mgga_x_rtpss.cu mgga_x_msb.cu mgga_x_mvsb.cu mgga_x_regtpss.cu

libxc_la_SOURCES = references.c $(libxc_la_FUNC_SOURCES)
libxc_la_LDFLAGS = -version-info $(XC_LT_VERSION)

if COMPILE_FORTRAN
  lib_LTLIBRARIES += libxcf90.la

  libxcf90_la_SOURCES = xc_f.c
  nodist_libxcf90_la_SOURCES = libxc_funcs.f90 libxc.f90

  # libtool stuff
  libxcf90_la_LDFLAGS = -version-info $(XC_LT_VERSION)
  libxcf90_la_LIBADD = libxc.la
endif

if COMPILE_FORTRAN03
  lib_LTLIBRARIES += libxcf03.la

  nodist_libxcf03_la_SOURCES = libxcf03.f90

  # libtool stuff
  libxcf03_la_LDFLAGS = -version-info $(XC_LT_VERSION)
  libxcf03_la_LIBADD = libxc.la
endif


noinst_HEADERS = \
	string_f.cuh references.cuh util.cuh work_lda_new.cu \
	work_gga_new.cu \
	work_mgga_x.cu work_mgga_new.cu \
	libxc_master.F90 libxc_master.F03
include_HEADERS = xc.cuh xc_funcs_removed.cuh
nodist_include_HEADERS = xc_funcs.cuh xc_funcs_worker.cuh

BUILT_SOURCES = xc_funcs.cuh

## declare fortran modules so they are installed
fmoddir = @FMODDIR@
fmod_DATA =

if COMPILE_FORTRAN

if F90_MOD_UPPERCASE
  LIBFUNCMOD = LIBXC_FUNCS_M.@ax_cv_f90_modext@
else
  LIBFUNCMOD = libxc_funcs_m.@ax_cv_f90_modext@
endif
fmod_DATA += $(LIBFUNCMOD)

if F90_MOD_UPPERCASE
  XCLIBMODS = XC_F90_LIB_M.@ax_cv_f90_modext@ XC_F90_TYPES_M.@ax_cv_f90_modext@
else
  XCLIBMODS = xc_f90_lib_m.@ax_cv_f90_modext@ xc_f90_types_m.@ax_cv_f90_modext@
endif
fmod_DATA += $(XCLIBMODS)

endif # COMPILE_FORTRAN


if COMPILE_FORTRAN03

# Double precision modules are always compiled
if F90_MOD_UPPERCASE
  XCF03LIBMODS = XC_F03_LIB_M.@ax_cv_f90_modext@
else
  XCF03LIBMODS = xc_f03_lib_m.@ax_cv_f90_modext@
endif
fmod_DATA += $(XCF03LIBMODS)

endif # COMPILE_FORTRAN03


CLEANFILES = *~ *.bak *.mod *.il *.d *.pc* ifc* funcs_*.c funcs.h \
  libxc.f90 libxc_funcs.f90 libxcf03.f90 libxc_inc.f03 xc_funcs.h xc_funcs_worker.h \
  xc_f_inc.c libxc_docs.txt

xc_f.o : xc_f_inc.cu

xc_funcs.cuh xc_funcs_worker.cuh libxc_inc.f03 libxc_funcs.f90 \
funcs_lda.cu funcs_gga.cu funcs_hyb_gga.cu \
funcs_mgga.cu funcs_hyb_mgga.cu funcs_key.cu: $(srcdir)/../scripts/get_funcs.pl
	$(srcdir)/../scripts/get_funcs.pl $(srcdir) $(top_builddir)/src

LTPREF = $(subst xc_f.lo,,$(firstword $(am_libxcf90_la_OBJECTS)))
# Surprisingly, libtool/automake do not seem to provide a macro or variable for what the object names will be,
# so we have to extract it ourselves. LTPREF=libxcf90_la-, or blank for older libtool/automake versions.
# Produces these warnings on some systems. Does not seem to matter.
#src/Makefile.am:140: subst xc_f.lo,,$(firstword $(am_libxcf90_la_OBJECTS: non-POSIX variable name
#src/Makefile.am:140: (probably a GNU make extension)

$(LIBFUNCMOD) $(LIBSFUNCMOD): $(LTPREF)libxc_funcs.lo

libxc.f90 : libxc_master.F90 $(LIBFUNCMOD)
	@FCCPP@ @CPPFLAGS@ $(AM_CPPFLAGS) -I$(top_builddir)/src $(srcdir)/libxc_master.F90 > $(top_builddir)/src/libxc.f90
	@if [ "@F90_ACCEPTS_LINE_NUMBERS@" = "no" ]; then \
		grep -v "^#" $(top_builddir)/src/libxc.f90 > $(top_builddir)/src/libxc.f91; \
		mv -f $(top_builddir)/src/libxc.f91 $(top_builddir)/src/libxc.f90; \
	fi

$(LTPREF)libxc.lo   $(LTPREF)libxc.o   : $(LIBFUNCMOD)

$(XCLIBMODS)   : $(LTPREF)libxc.lo


LTPREF03 = $(subst libxcf03.lo,,$(firstword $(nodist_libxcf03_la_OBJECTS)))
libxcf03.f90 : libxc_master.F03 libxc_inc.f03
	@FCCPP@ @CPPFLAGS@ $(AM_CPPFLAGS) -I$(top_builddir)/src $(srcdir)/libxc_master.F03 > $(top_builddir)/src/libxcf03.f90
	@if [ "@F90_ACCEPTS_LINE_NUMBERS@" = "no" ]; then \
		grep -v "^#" $(top_builddir)/src/libxcf03.f90 > $(top_builddir)/src/libxcf03.f91; \
		mv -f $(top_builddir)/src/libxcf03.f91 $(top_builddir)/src/libxcf03.f90; \
	fi

$(XCF03LIBMODS)   : $(LTPREF03)libxcf03.lo

