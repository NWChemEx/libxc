cmake_policy(SET CMP0048 NEW)  # project_VERSION* variables populated from project(... VERSION x.x.x) string
project(Libxc
        VERSION 4.3.4
        LANGUAGES C)
set(Libxc_AUTHORS      "Miguel A.L. Marques and others")
set(Libxc_DESCRIPTION  "Exchange-correlation functionals for density-functional theory")
set(Libxc_EMAIL        "libxc@tddft.org")
set(Libxc_URL          "http://www.tddft.org/programs/Libxc")
set(Libxc_LICENSE      "Mozilla Public License, version 2.0 (MPL-2.0)")

cmake_minimum_required(VERSION 3.0)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

################################### Options ####################################
include(psi4OptionsTools)
option_with_default(CMAKE_BUILD_TYPE "Build type" Release)
option_with_print(BUILD_SHARED_LIBS "Build final library as shared, not static" OFF)
option_with_print(BUILD_TESTING "Compile the testing infrastructure" ON)
option_with_default(BUILD_FPIC "Libraries will be compiled with position independent code" ON)
if((${BUILD_SHARED_LIBS}) AND NOT ${BUILD_FPIC})
    message(FATAL_ERROR "BUILD_SHARED_LIBS ON and BUILD_FPIC OFF are incompatible, as shared library requires position independent code")
endif()
option_with_default(NAMESPACE_INSTALL_INCLUDEDIR "Location within CMAKE_INSTALL_INCLUDEDIR to which headers are installed. Psi4 wants namespace (e.g., /libxc)" /)
option_with_print(ENABLE_GENERIC "Enable mostly static linking in shared library" OFF)
option_with_flags(ENABLE_XHOST "Enable processor-specific optimization" ON
  "-xHost" "-march=native")
option_with_print(ENABLE_FORTRAN "Build Fortran 90 interface" OFF)
option_with_print(ENABLE_FORTRAN03 "Build Fortran 2003 interface" OFF)

option_with_print(DISABLE_VXC "Don't compile first derivative code" OFF)
option_with_print(DISABLE_FXC "Don't compile second derivative code" OFF)
option_with_print(DISABLE_KXC "Don't compile third derivative code" OFF)

######################### Process & Validate Options ###########################
include(autocmake_safeguards)
include(custom_static_library)

################################# Main Project #################################
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Check for CUDA support
find_package(CUDA)
if (CUDA_FOUND)
    enable_language(CUDA)
    # Never use CUDA_NVCC_FLAGS and company as these variables are a complete
    # red herring. Setting these variables does not actually do anything!
    #
    #list(APPEND CUDA_NVCC_FLAGS                "--relocatable-device-code true")
    #list(APPEND CUDA_NVCC_FLAGS_DEBUG          "--relocatable-device-code true")
    #list(APPEND CUDA_NVCC_FLAGS_MINSIZEREL     "--relocatable-device-code true")
    #list(APPEND CUDA_NVCC_FLAGS_RELEASE        "--relocatable-device-code true")
    #list(APPEND CUDA_NVCC_FLAGS_RELWITHDEBINFO "--relocatable-device-code true")
    #
    # Setting CMAKE_CUDA_FLAGS will pass the flags to the invocation of nvcc. However,
    # you may need to specify CMAKE_CUDA_FLAGS on the CMake command line or edit
    # the CMakeCache.txt file. Setting this variable here typically has no effect.
    # Also do not add "--relocatable-device-code true" to any of the other 
    # CMAKE_CUDA_FLAGS variables as in that case the flag will be passed to nvcc multiple
    # times. Note, nvcc considers passing --relocatable-device-code twice a fatal
    # error.
    #
    # Note: setting CMAKE_CUDA_FLAGS on the CMake command line causes the configure
    # stage to fail (cmake/3.15.2). Instead running the CMake command without it works,
    # and then you have to edit the resulting CMakeCache.txt so the right compiler
    # flags are used with compiling the library.
    #
    #list(APPEND CMAKE_CUDA_FLAGS                "--relocatable-device-code true")
    #list(APPEND CMAKE_CUDA_FLAGS_DEBUG          "--relocatable-device-code true")
    #list(APPEND CMAKE_CUDA_FLAGS_MINSIZEREL     "--relocatable-device-code true")
    #list(APPEND CMAKE_CUDA_FLAGS_RELEASE        "--relocatable-device-code true")
    #list(APPEND CMAKE_CUDA_FLAGS_RELWITHDEBINFO "--relocatable-device-code true")
else()
    # Check for OpenMP to support GPU offloading
    find_package(OpenMP)
    if (OPENMP_FOUND)
        set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
        set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
    endif()
endif()

set(PN ${PROJECT_NAME})

# link -lm only if necessary
find_package(StandardMathLibraryC)
# check if cbrt exists and declare HAVE_CBRT if it does
check_c_source_compiles (
  "#include <math.h>
int main() {
  return (int)(cbrt(0.8));
}" HAVE_CBRT)
if (HAVE_CBRT)
  add_definitions (-DHAVE_CBRT)
endif (HAVE_CBRT)

# Turn off derivative code
if(DISABLE_VXC)
  add_definitions (-DXC_DONT_COMPILE_VXC)
  add_definitions (-DXC_DONT_COMPILE_FXC)
  add_definitions (-DXC_DONT_COMPILE_KXC)
endif(DISABLE_VXC)
if(DISABLE_FXC)
  add_definitions (-DXC_DONT_COMPILE_FXC)
  add_definitions (-DXC_DONT_COMPILE_KXC)
endif(DISABLE_FXC)
if(DISABLE_KXC)
  add_definitions (-DXC_DONT_COMPILE_KXC)
endif(DISABLE_KXC)

# <<<  Build  >>>

# repurpose xc_version from Make for CMake
set(VERSION ${PROJECT_VERSION})
set(XC_MAJOR_VERSION ${PROJECT_VERSION_MAJOR})
set(XC_MINOR_VERSION ${PROJECT_VERSION_MINOR})
set(XC_MICRO_VERSION ${PROJECT_VERSION_PATCH})
configure_file(xc_version.h.in xc_version.h @ONLY)

# create dummy config.h
configure_file(config.h.cmake.in config.h @ONLY)
configure_file(cmake/libxc.pc.in libxc.pc @ONLY)

# extract project soversion from source
file(STRINGS "configure.ac" _libxc_configure_ac
     REGEX "XC_(CURRENT|REVISION|AGE)=")
foreach(ver ${_libxc_configure_ac})
  if (ver MATCHES "XC_(CURRENT|REVISION|AGE)=+([^ ]+)$")
    set(XC_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" CACHE INTERNAL "")
  endif()
endforeach()
set(${PROJECT_NAME}_SOVERSION ${XC_CURRENT}:${XC_REVISION}:${XC_AGE})
math(EXPR ${PROJECT_NAME}_SOMAJOR "${XC_CURRENT} - ${XC_AGE}")
message(STATUS "Libxc SO Full ${${PROJECT_NAME}_SOVERSION} Major ${${PROJECT_NAME}_SOMAJOR}")

# Always include the CUDA sources. If the language CUDA is not enabled (see enable_language
# above) then CMake will simply check the CUDA files exist and subsequently ignore them.
if (CUDA_FOUND)
set(raw_sources_list
cuda/bessel.cu
cuda/expint_e1.cu
cuda/func_info.cu
cuda/functionals.cu
cuda/gga.cu
cuda/gga_c_acgga.cu
cuda/gga_c_acggap.cu
cuda/gga_c_am05.cu
cuda/gga_c_bmk.cu
cuda/gga_c_cs1.cu
cuda/gga_c_ft97.cu
cuda/gga_c_gapc.cu
cuda/gga_c_gaploc.cu
cuda/gga_c_hcth_a.cu
cuda/gga_c_lm.cu
cuda/gga_c_lyp.cu
cuda/gga_c_op_b88.cu
cuda/gga_c_op_g96.cu
cuda/gga_c_op_pbe.cu
cuda/gga_c_op_pw91.cu
cuda/gga_c_op_xalpha.cu
cuda/gga_c_optc.cu
cuda/gga_c_p86.cu
cuda/gga_c_pbe.cu
cuda/gga_c_pbeloc.cu
cuda/gga_c_pw91.cu
cuda/gga_c_q2d.cu
cuda/gga_c_regtpss.cu
cuda/gga_c_revtca.cu
cuda/gga_c_scan_e0.cu
cuda/gga_c_sg4.cu
cuda/gga_c_sogga11.cu
cuda/gga_c_tca.cu
cuda/gga_c_w94.cu
cuda/gga_c_wi.cu
cuda/gga_c_wl.cu
cuda/gga_c_zpbeint.cu
cuda/gga_c_zvpbeint.cu
cuda/gga_c_zvpbeloc.cu
cuda/gga_k_dk.cu
cuda/gga_k_meyer.cu
cuda/gga_k_ol1.cu
cuda/gga_k_ol2.cu
cuda/gga_x_ol2.cu
cuda/gga_k_pearson.cu
cuda/gga_k_tflw.cu
cuda/gga_k_thakkar.cu
cuda/gga_k_gds08.cu
cuda/gga_k_exp4.cu
cuda/gga_x_2d_b86.cu
cuda/gga_x_2d_b86_mgc.cu
cuda/gga_x_2d_b88.cu
cuda/gga_x_2d_pbe.cu
cuda/gga_x_airy.cu
cuda/gga_x_ak13.cu
cuda/gga_x_am05.cu
cuda/gga_x_b86.cu
cuda/gga_x_b88.cu
cuda/gga_k_llp.cu
cuda/gga_k_pw86.cu
cuda/gga_k_mpbe.cu
cuda/gga_k_apbe.cu
cuda/gga_k_apbeint.cu
cuda/gga_k_lc94.cu
cuda/gga_x_bayesian.cu
cuda/gga_x_beefvdw.cu
cuda/gga_x_bpccac.cu
cuda/gga_x_c09x.cu
cuda/gga_x_cap.cu
cuda/gga_x_chachiyo.cu
cuda/gga_x_dk87.cu
cuda/gga_x_ev93.cu
cuda/gga_x_ft97.cu
cuda/gga_x_g96.cu
cuda/gga_x_gg99.cu
cuda/gga_x_hcth_a.cu
cuda/gga_x_herman.cu
cuda/gga_x_hjs.cu
cuda/gga_x_hjs_b88_v2.cu
cuda/gga_x_htbs.cu
cuda/gga_x_ityh.cu
cuda/gga_x_kt.cu
cuda/gga_x_lag.cu
cuda/gga_x_lb.cu
cuda/gga_x_lg93.cu
cuda/gga_x_lspbe.cu
cuda/gga_x_lsrpbe.cu
cuda/gga_x_lv_rpw86.cu
cuda/gga_x_mpbe.cu
cuda/gga_x_n12.cu
cuda/gga_x_optx.cu
cuda/gga_x_pbe.cu
cuda/gga_x_pbea.cu
cuda/gga_x_pbeint.cu
cuda/gga_x_pbepow.cu
cuda/gga_x_pbetrans.cu
cuda/gga_x_pw86.cu
cuda/gga_x_pw91.cu
cuda/gga_x_q2d.cu
cuda/gga_x_rge2.cu
cuda/gga_x_rpbe.cu
cuda/gga_x_sfat.cu
cuda/gga_x_sfat_pbe.cu
cuda/gga_x_sg4.cu
cuda/gga_x_sogga11.cu
cuda/gga_x_ssb_sw.cu
cuda/gga_x_vmt.cu
cuda/gga_x_vmt84.cu
cuda/gga_x_wc.cu
cuda/gga_x_wpbeh.cu
cuda/gga_x_fd_lb94.cu
cuda/gga_xc_1w.cu
cuda/gga_xc_b97.cu
cuda/gga_xc_edf1.cu
cuda/gga_xc_oblyp_d.cu
cuda/gga_xc_th1.cu
cuda/gga_xc_th2.cu
cuda/gga_xc_th3.cu
cuda/gga_xc_vv10.cu
cuda/hyb_gga_xc_b1wc.cu
cuda/hyb_gga_xc_b3lyp.cu
cuda/hyb_gga_xc_cam_b3lyp.cu
cuda/hyb_gga_xc_cam_qtp.cu
cuda/hyb_gga_xc_camy_b3lyp.cu
cuda/hyb_gga_xc_camy_blyp.cu
cuda/hyb_gga_xc_edf2.cu
cuda/hyb_gga_xc_hse.cu
cuda/hyb_gga_xc_lcy_blyp.cu
cuda/hyb_gga_xc_lcy_pbe.cu
cuda/hyb_gga_xc_o3lyp.cu
cuda/hyb_gga_xc_pbeh.cu
cuda/hyb_gga_xc_wb97.cu
cuda/hyb_mgga_x_dldf.cu
cuda/hyb_mgga_x_m05.cu
cuda/hyb_mgga_x_mvsh.cu
cuda/hyb_mgga_xc_b88b95.cu
cuda/hyb_mgga_xc_kcis.cu
cuda/hyb_mgga_xc_tpssh.cu
cuda/hyb_mgga_xc_wb97mv.cu
cuda/integrate.cu
cuda/lda.cu
cuda/lda_c_1d_csc.cu
cuda/lda_c_1d_loos.cu
cuda/lda_c_2d_amgb.cu
cuda/lda_c_2d_prm.cu
cuda/lda_c_chachiyo.cu
cuda/lda_c_gombas.cu
cuda/lda_c_hl.cu
cuda/lda_c_lp96.cu
cuda/lda_c_ml1.cu
cuda/lda_c_pk09.cu
cuda/lda_c_pw.cu
cuda/lda_c_pz.cu
cuda/lda_c_rc04.cu
cuda/lda_c_rpa.cu
cuda/lda_c_vwn.cu
cuda/lda_c_vwn_1.cu
cuda/lda_c_vwn_2.cu
cuda/lda_c_vwn_3.cu
cuda/lda_c_vwn_4.cu
cuda/lda_c_vwn_rpa.cu
cuda/lda_c_wigner.cu
cuda/lda_c_gk72.cu
cuda/lda_k_tf.cu
cuda/lda_k_zlp.cu
cuda/lda_k_gds08_worker.cu
cuda/lda_x.cu
cuda/lda_x_1d_soft.cu
cuda/lda_x_1d_exponential.cu
cuda/lda_x_2d.cu
cuda/lda_x_erf.cu
cuda/lda_x_rel.cu
cuda/lda_xc_1d_ehwlrg.cu
cuda/lda_xc_ksdt.cu
cuda/lda_xc_teter93.cu
cuda/lda_xc_zlp.cu
cuda/lda_xc_bn05.cu
cuda/lda_c_pmgb06.cu
cuda/lda_xc_tih.cu
cuda/mgga.cu
cuda/mgga_c_b88.cu
cuda/mgga_c_bc95.cu
cuda/mgga_c_cs.cu
cuda/mgga_c_kcis.cu
cuda/mgga_xc_lp90.cu
cuda/mgga_c_m05.cu
cuda/mgga_c_m06l.cu
cuda/mgga_c_m08.cu
cuda/mgga_c_pkzb.cu
cuda/mgga_c_revscan.cu
cuda/mgga_c_revtpss.cu
cuda/mgga_c_scan.cu
cuda/mgga_c_tpss.cu
cuda/mgga_c_tpssloc.cu
cuda/mgga_c_vsxc.cu
cuda/mgga_k_pc07.cu
cuda/mgga_x_2d_prhg07.cu
cuda/mgga_x_br89.cu
cuda/mgga_x_br89_explicit.cu
cuda/mgga_x_gvt4.cu
cuda/mgga_x_gx.cu
cuda/mgga_x_lta.cu
cuda/mgga_x_m06l.cu
cuda/mgga_x_m08.cu
cuda/mgga_x_m11.cu
cuda/mgga_x_m11_l.cu
cuda/mgga_x_mbeef.cu
cuda/mgga_x_mbeefvdw.cu
cuda/mgga_x_mk00.cu
cuda/mgga_x_mn12.cu
cuda/mgga_x_ms.cu
cuda/mgga_x_msb.cu
cuda/mgga_x_mvs.cu
cuda/mgga_x_mvsb.cu
cuda/mgga_x_pbe_gx.cu
cuda/mgga_x_pkzb.cu
cuda/mgga_x_sa_tpss.cu
cuda/mgga_x_scan.cu
cuda/mgga_x_tau_hcth.cu
cuda/mgga_x_tm.cu
cuda/mgga_x_tpss.cu
cuda/mgga_x_regtpss.cu
cuda/mgga_x_vt84.cu
cuda/mgga_x_rtpss.cu
cuda/mgga_xc_b97mv.cu
cuda/mgga_xc_cc06.cu
cuda/mgga_xc_hle17.cu
cuda/mgga_xc_otpss_d.cu
cuda/mgga_xc_zlp.cu
cuda/mgga_xc_b98.cu
cuda/mix_func.cu
cuda/references.cu
cuda/special_functions.cu
cuda/util.cu
bessel.c
expint_e1.c
func_info.c
func_reference.c
functionals.c
gga.c
gga_c_acgga.c
gga_c_acggap.c
gga_c_am05.c
gga_c_bmk.c
gga_c_cs1.c
gga_c_ft97.c
gga_c_gapc.c
gga_c_gaploc.c
gga_c_hcth_a.c
gga_c_lm.c
gga_c_lyp.c
gga_c_op_b88.c
gga_c_op_g96.c
gga_c_op_pbe.c
gga_c_op_pw91.c
gga_c_op_xalpha.c
gga_c_optc.c
gga_c_p86.c
gga_c_pbe.c
gga_c_pbeloc.c
gga_c_pw91.c
gga_c_q2d.c
gga_c_regtpss.c
gga_c_revtca.c
gga_c_scan_e0.c
gga_c_sg4.c
gga_c_sogga11.c
gga_c_tca.c
gga_c_w94.c
gga_c_wi.c
gga_c_wl.c
gga_c_zpbeint.c
gga_c_zvpbeint.c
gga_c_zvpbeloc.c
gga_k_dk.c
gga_k_meyer.c
gga_k_ol1.c
gga_k_ol2.c
gga_x_ol2.c
gga_k_pearson.c
gga_k_tflw.c
gga_k_thakkar.c
gga_k_gds08.c
gga_k_exp4.c
gga_x_2d_b86.c
gga_x_2d_b86_mgc.c
gga_x_2d_b88.c
gga_x_2d_pbe.c
gga_x_airy.c
gga_x_ak13.c
gga_x_am05.c
gga_x_b86.c
gga_x_b88.c
gga_k_llp.c
gga_k_pw86.c
gga_k_mpbe.c
gga_k_apbe.c
gga_k_apbeint.c
gga_k_lc94.c
gga_x_bayesian.c
gga_x_beefvdw.c
gga_x_bpccac.c
gga_x_c09x.c
gga_x_cap.c
gga_x_chachiyo.c
gga_x_dk87.c
gga_x_ev93.c
gga_x_ft97.c
gga_x_g96.c
gga_x_gg99.c
gga_x_hcth_a.c
gga_x_herman.c
gga_x_hjs.c
gga_x_hjs_b88_v2.c
gga_x_htbs.c
gga_x_ityh.c
gga_x_kt.c
gga_x_lag.c
gga_x_lb.c
gga_x_lg93.c
gga_x_lspbe.c
gga_x_lsrpbe.c
gga_x_lv_rpw86.c
gga_x_mpbe.c
gga_x_n12.c
gga_x_optx.c
gga_x_pbe.c
gga_x_pbea.c
gga_x_pbeint.c
gga_x_pbepow.c
gga_x_pbetrans.c
gga_x_pw86.c
gga_x_pw91.c
gga_x_q2d.c
gga_x_rge2.c
gga_x_rpbe.c
gga_x_sfat.c
gga_x_sfat_pbe.c
gga_x_sg4.c
gga_x_sogga11.c
gga_x_ssb_sw.c
gga_x_vmt.c
gga_x_vmt84.c
gga_x_wc.c
gga_x_wpbeh.c
gga_x_fd_lb94.c
gga_xc_1w.c
gga_xc_b97.c
gga_xc_edf1.c
gga_xc_oblyp_d.c
gga_xc_th1.c
gga_xc_th2.c
gga_xc_th3.c
gga_xc_vv10.c
hyb_gga_xc_b1wc.c
hyb_gga_xc_b3lyp.c
hyb_gga_xc_cam_b3lyp.c
hyb_gga_xc_cam_qtp.c
hyb_gga_xc_camy_b3lyp.c
hyb_gga_xc_camy_blyp.c
hyb_gga_xc_edf2.c
hyb_gga_xc_hse.c
hyb_gga_xc_lcy_blyp.c
hyb_gga_xc_lcy_pbe.c
hyb_gga_xc_o3lyp.c
hyb_gga_xc_pbeh.c
hyb_gga_xc_wb97.c
hyb_mgga_x_dldf.c
hyb_mgga_x_m05.c
hyb_mgga_x_mvsh.c
hyb_mgga_xc_b88b95.c
hyb_mgga_xc_kcis.c
hyb_mgga_xc_tpssh.c
hyb_mgga_xc_wb97mv.c
integrate.c
lda.c
lda_c_1d_csc.c
lda_c_1d_loos.c
lda_c_2d_amgb.c
lda_c_2d_prm.c
lda_c_chachiyo.c
lda_c_gombas.c
lda_c_hl.c
lda_c_lp96.c
lda_c_ml1.c
lda_c_pk09.c
lda_c_pw.c
lda_c_pz.c
lda_c_rc04.c
lda_c_rpa.c
lda_c_vwn.c
lda_c_vwn_1.c
lda_c_vwn_2.c
lda_c_vwn_3.c
lda_c_vwn_4.c
lda_c_vwn_rpa.c
lda_c_wigner.c
lda_c_gk72.c
lda_k_tf.c
lda_k_zlp.c
lda_k_gds08_worker.c
lda_x.c
lda_x_1d_soft.c
lda_x_1d_exponential.c
lda_x_2d.c
lda_x_erf.c
lda_x_rel.c
lda_xc_1d_ehwlrg.c
lda_xc_ksdt.c
lda_xc_teter93.c
lda_xc_zlp.c
lda_xc_bn05.c
lda_c_pmgb06.c
lda_xc_tih.c
mgga.c
mgga_c_b88.c
mgga_c_bc95.c
mgga_c_cs.c
mgga_c_kcis.c
mgga_xc_lp90.c
mgga_c_m05.c
mgga_c_m06l.c
mgga_c_m08.c
mgga_c_pkzb.c
mgga_c_revscan.c
mgga_c_revtpss.c
mgga_c_scan.c
mgga_c_tpss.c
mgga_c_tpssloc.c
mgga_c_vsxc.c
mgga_k_pc07.c
mgga_x_2d_prhg07.c
mgga_x_br89.c
mgga_x_br89_explicit.c
mgga_x_gvt4.c
mgga_x_gx.c
mgga_x_lta.c
mgga_x_m06l.c
mgga_x_m08.c
mgga_x_m11.c
mgga_x_m11_l.c
mgga_x_mbeef.c
mgga_x_mbeefvdw.c
mgga_x_mk00.c
mgga_x_mn12.c
mgga_x_ms.c
mgga_x_msb.c
mgga_x_mvs.c
mgga_x_mvsb.c
mgga_x_pbe_gx.c
mgga_x_pkzb.c
mgga_x_sa_tpss.c
mgga_x_scan.c
mgga_x_tau_hcth.c
mgga_x_tm.c
mgga_x_tpss.c
mgga_x_regtpss.c
mgga_x_vt84.c
mgga_x_rtpss.c
mgga_xc_b97mv.c
mgga_xc_cc06.c
mgga_xc_hle17.c
mgga_xc_otpss_d.c
mgga_xc_zlp.c
mgga_xc_b98.c
mix_func.c
references.c
special_functions.c
util.c
version.c
)
else()
set(raw_sources_list
bessel.c
expint_e1.c
func_info.c
functionals.c
gga.c
gga_c_acgga.c
gga_c_acggap.c
gga_c_am05.c
gga_c_bmk.c
gga_c_cs1.c
gga_c_ft97.c
gga_c_gapc.c
gga_c_gaploc.c
gga_c_hcth_a.c
gga_c_lm.c
gga_c_lyp.c
gga_c_op_b88.c
gga_c_op_g96.c
gga_c_op_pbe.c
gga_c_op_pw91.c
gga_c_op_xalpha.c
gga_c_optc.c
gga_c_p86.c
gga_c_pbe.c
gga_c_pbeloc.c
gga_c_pw91.c
gga_c_q2d.c
gga_c_regtpss.c
gga_c_revtca.c
gga_c_scan_e0.c
gga_c_sg4.c
gga_c_sogga11.c
gga_c_tca.c
gga_c_w94.c
gga_c_wi.c
gga_c_wl.c
gga_c_zpbeint.c
gga_c_zvpbeint.c
gga_c_zvpbeloc.c
gga_k_dk.c
gga_k_meyer.c
gga_k_ol1.c
gga_k_ol2.c
gga_x_ol2.c
gga_k_pearson.c
gga_k_tflw.c
gga_k_thakkar.c
gga_k_gds08.c
gga_k_exp4.c
gga_x_2d_b86.c
gga_x_2d_b86_mgc.c
gga_x_2d_b88.c
gga_x_2d_pbe.c
gga_x_airy.c
gga_x_ak13.c
gga_x_am05.c
gga_x_b86.c
gga_x_b88.c
gga_k_llp.c
gga_k_pw86.c
gga_k_mpbe.c
gga_k_apbe.c
gga_k_apbeint.c
gga_k_lc94.c
gga_x_bayesian.c
gga_x_beefvdw.c
gga_x_bpccac.c
gga_x_c09x.c
gga_x_cap.c
gga_x_chachiyo.c
gga_x_dk87.c
gga_x_ev93.c
gga_x_ft97.c
gga_x_g96.c
gga_x_gg99.c
gga_x_hcth_a.c
gga_x_herman.c
gga_x_hjs.c
gga_x_hjs_b88_v2.c
gga_x_htbs.c
gga_x_ityh.c
gga_x_kt.c
gga_x_lag.c
gga_x_lb.c
gga_x_lg93.c
gga_x_lspbe.c
gga_x_lsrpbe.c
gga_x_lv_rpw86.c
gga_x_mpbe.c
gga_x_n12.c
gga_x_optx.c
gga_x_pbe.c
gga_x_pbea.c
gga_x_pbeint.c
gga_x_pbepow.c
gga_x_pbetrans.c
gga_x_pw86.c
gga_x_pw91.c
gga_x_q2d.c
gga_x_rge2.c
gga_x_rpbe.c
gga_x_sfat.c
gga_x_sfat_pbe.c
gga_x_sg4.c
gga_x_sogga11.c
gga_x_ssb_sw.c
gga_x_vmt.c
gga_x_vmt84.c
gga_x_wc.c
gga_x_wpbeh.c
gga_x_fd_lb94.c
gga_xc_1w.c
gga_xc_b97.c
gga_xc_edf1.c
gga_xc_oblyp_d.c
gga_xc_th1.c
gga_xc_th2.c
gga_xc_th3.c
gga_xc_vv10.c
hyb_gga_xc_b1wc.c
hyb_gga_xc_b3lyp.c
hyb_gga_xc_cam_b3lyp.c
hyb_gga_xc_cam_qtp.c
hyb_gga_xc_camy_b3lyp.c
hyb_gga_xc_camy_blyp.c
hyb_gga_xc_edf2.c
hyb_gga_xc_hse.c
hyb_gga_xc_lcy_blyp.c
hyb_gga_xc_lcy_pbe.c
hyb_gga_xc_o3lyp.c
hyb_gga_xc_pbeh.c
hyb_gga_xc_wb97.c
hyb_mgga_x_dldf.c
hyb_mgga_x_m05.c
hyb_mgga_x_mvsh.c
hyb_mgga_xc_b88b95.c
hyb_mgga_xc_kcis.c
hyb_mgga_xc_tpssh.c
hyb_mgga_xc_wb97mv.c
integrate.c
lda.c
lda_c_1d_csc.c
lda_c_1d_loos.c
lda_c_2d_amgb.c
lda_c_2d_prm.c
lda_c_chachiyo.c
lda_c_gombas.c
lda_c_hl.c
lda_c_lp96.c
lda_c_ml1.c
lda_c_pk09.c
lda_c_pw.c
lda_c_pz.c
lda_c_rc04.c
lda_c_rpa.c
lda_c_vwn.c
lda_c_vwn_1.c
lda_c_vwn_2.c
lda_c_vwn_3.c
lda_c_vwn_4.c
lda_c_vwn_rpa.c
lda_c_wigner.c
lda_c_gk72.c
lda_k_tf.c
lda_k_zlp.c
lda_k_gds08_worker.c
lda_x.c
lda_x_1d_soft.c
lda_x_1d_exponential.c
lda_x_2d.c
lda_x_erf.c
lda_x_rel.c
lda_xc_1d_ehwlrg.c
lda_xc_ksdt.c
lda_xc_teter93.c
lda_xc_zlp.c
lda_xc_bn05.c
lda_c_pmgb06.c
lda_xc_tih.c
mgga.c
mgga_c_b88.c
mgga_c_bc95.c
mgga_c_cs.c
mgga_c_kcis.c
mgga_xc_lp90.c
mgga_c_m05.c
mgga_c_m06l.c
mgga_c_m08.c
mgga_c_pkzb.c
mgga_c_revscan.c
mgga_c_revtpss.c
mgga_c_scan.c
mgga_c_tpss.c
mgga_c_tpssloc.c
mgga_c_vsxc.c
mgga_k_pc07.c
mgga_x_2d_prhg07.c
mgga_x_br89.c
mgga_x_br89_explicit.c
mgga_x_gvt4.c
mgga_x_gx.c
mgga_x_lta.c
mgga_x_m06l.c
mgga_x_m08.c
mgga_x_m11.c
mgga_x_m11_l.c
mgga_x_mbeef.c
mgga_x_mbeefvdw.c
mgga_x_mk00.c
mgga_x_mn12.c
mgga_x_ms.c
mgga_x_msb.c
mgga_x_mvs.c
mgga_x_mvsb.c
mgga_x_pbe_gx.c
mgga_x_pkzb.c
mgga_x_sa_tpss.c
mgga_x_scan.c
mgga_x_tau_hcth.c
mgga_x_tm.c
mgga_x_tpss.c
mgga_x_regtpss.c
mgga_x_vt84.c
mgga_x_rtpss.c
mgga_xc_b97mv.c
mgga_xc_cc06.c
mgga_xc_hle17.c
mgga_xc_otpss_d.c
mgga_xc_zlp.c
mgga_xc_b98.c
mix_func.c
references.c
special_functions.c
util.c
version.c
)
endif()

set(src_prefix "src/")
set(src_prefix_cuda "src/cuda")
string(REGEX REPLACE "([^;]+)" "${src_prefix}\\1" sources_list "${raw_sources_list}")

set(raw_sources_list_f90
    src/xc_f.c
    src/libxc_master.F90
    gen_funcidx/libxc_funcs.f90
)
set(raw_sources_list_f03
    src/libxc_master.F03
)

# when headers namespaced, xc_version include in xc.h needs to be local, not
#   system to be found
file(READ ${src_prefix}xc.h _src_contents)
string(REPLACE "<xc_version.h>" "\"xc_version.h\"" _quoted_src "${_src_contents}")
file(WRITE ${PROJECT_BINARY_DIR}/${src_prefix}xc.h "${_quoted_src}")

# STATIC/SHARED on below governed by BUILD_SHARED_LIBS
list(APPEND CMAKE_C_FLAGS "-std=c99")
add_library(xc ${sources_list})
target_link_libraries(xc INTERFACE ${STANDARD_MATH_LIBRARY})
set_target_properties(xc PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC}
                                    SOVERSION ${${PROJECT_NAME}_SOMAJOR})
if(${BUILD_SHARED_LIBS})
    target_link_libraries(xc PRIVATE ${LIBC_INTERJECT})
    if(APPLE)
        set_target_properties(xc PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
    endif()
endif()

if(CUDA_FOUND)
    set_property(TARGET xc PROPERTY CUDA_SEPARABLE_COMPILATION ON)
endif()

if(ENABLE_FORTRAN OR ENABLE_FORTRAN03)
    enable_language(Fortran)
    include(FortranCInterface)
    # This is needed for the mangling
    add_definitions(-DHAVE_FORTRAN)

    add_library(xcf90 ${raw_sources_list_f90})
    target_link_libraries(xcf90 xc)
    set_target_properties(xcf90 PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC})
    target_compile_definitions(xcf90
      PUBLIC
        CC_FORTRAN_INT=int
        )

    FortranCInterface_HEADER(Libxc_MANGLE.h
                             MACRO_NAMESPACE "FC_FUNC_"
                             SYMBOL_NAMESPACE "FC_FUNC_")

    if(ENABLE_FORTRAN03)
        set(CMAKE_Fortran_SOURCE_FILE_EXTENSIONS ${CMAKE_Fortran_SOURCE_FILE_EXTENSIONS} "f03;F03")
        set_source_files_properties(${raw_sources_list_f03} PROPERTIES LANGUAGE Fortran)
        add_library(xcf03 ${raw_sources_list_f03})
        target_link_libraries(xcf03 xc)
        set_target_properties(xcf03 PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC})
    endif()
endif()

# run get_funcs.pl to generate headers for xc inclusion
find_package(Perl REQUIRED)
set(gen_dir      "${PROJECT_BINARY_DIR}/gen_funcidx")
set(gen_dir_cuda "${PROJECT_BINARY_DIR}/gen_funcidx/cuda")
file(MAKE_DIRECTORY ${gen_dir_cuda})
execute_process(
    COMMAND ${PERL_EXECUTABLE} scripts/get_funcs.pl ${src_prefix} ${gen_dir}
    TIMEOUT 60
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
execute_process(
    COMMAND ${PERL_EXECUTABLE} scripts/cuda/get_funcs.pl ${src_prefix_cuda} ${gen_dir_cuda}
    TIMEOUT 60
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(xc-info "${src_prefix}/xc-info.c")
target_link_libraries(xc-info xc)

#if (CUDA_FOUND)
#    add_executable(xc-threshold "${src_prefix}/cuda/xc-threshold.cu")
#else()
    add_executable(xc-threshold "${src_prefix}/xc-threshold.c")
#endif()
target_link_libraries(xc-threshold xc)


include_directories(${PROJECT_SOURCE_DIR}/${src_prefix}       # for util.h
                    ${PROJECT_SOURCE_DIR}/${src_prefix}/cuda  # for dvc_util.h
                    ${PROJECT_BINARY_DIR}/${src_prefix}       # for xc.h
                    ${PROJECT_BINARY_DIR}                     # for xc_version.h, config.h
                    ${gen_dir}                                # for xc_funcs.h, funcs_key.c
                    ${gen_dir}/cuda)                          # for xc_funcs.h, funcs_key.cu

if(BUILD_TESTING)
    find_program(BZip2_EXECUTABLE
             NAMES bzip2
             DOC "Path to zipping utility")
    if(BZip2_EXECUTABLE)
        enable_testing ()
        add_subdirectory(testsuite)  
    else()
        message(FATAL_ERROR "Install `bzip2` command to enable tests")
    endif()
endif()

# <<<  Install  >>>

# by default, headers NOT namespace protected
install(FILES ${PROJECT_BINARY_DIR}/${src_prefix}/xc.h
              ${PROJECT_BINARY_DIR}/${src_prefix}/cuda.h
              ${gen_dir}/xc_funcs.h
              ${gen_dir}/xc_funcs_worker.h
              ${PROJECT_BINARY_DIR}/xc_version.h
              ${PROJECT_SOURCE_DIR}/${src_prefix}/xc_funcs_removed.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR})
install(TARGETS xc xc-info xc-threshold
        EXPORT "${PN}Targets"
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
if(ENABLE_FORTRAN OR ENABLE_FORTRAN03)
    install(TARGETS xcf90
            EXPORT "${PN}Targets"
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
    install(FILES "${PROJECT_BINARY_DIR}/libxc_funcs_m.mod"
                  "${PROJECT_BINARY_DIR}/xc_f90_lib_m.mod"
                  "${PROJECT_BINARY_DIR}/xc_f90_types_m.mod"
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR})

    if(ENABLE_FORTRAN03)
        install(TARGETS xcf03
                EXPORT "${PN}Targets"
                RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
                ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
        install(FILES "${PROJECT_BINARY_DIR}/xc_f03_lib_m.mod"
                DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR})
    endif()
endif()

# <<<  Export Interface  >>>

target_compile_definitions(xc INTERFACE USING_${PN})
target_include_directories(xc INTERFACE
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# <<<  Export Config  >>>

# GNUInstallDirs "DATADIR" wrong here; CMake search path wants "share".
set(CMAKECONFIG_INSTALL_DIR "share/cmake/${PN}")
configure_package_config_file(cmake/${PN}Config.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake"
                              INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR})
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
                                 VERSION ${${PN}_VERSION}
                                 COMPATIBILITY AnyNewerVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
        DESTINATION ${CMAKECONFIG_INSTALL_DIR})
install(EXPORT "${PN}Targets"
        NAMESPACE "${PN}::"
        DESTINATION ${CMAKECONFIG_INSTALL_DIR})

install(FILES ${PROJECT_BINARY_DIR}/libxc.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig/)
