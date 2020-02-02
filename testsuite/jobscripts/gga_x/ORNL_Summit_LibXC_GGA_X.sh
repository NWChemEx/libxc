#!/bin/bash
#BSUB -P      chm136                    # Project ID
#BSUB -o      libxc.oe%J                # Job output name
#BSUB -J      libxc_gga_x               # Job name
#BSUB -W      00:10                     # Walltime
#BSUB -nnodes 1                         # Number of nodes
#pwd
#ls
#env | sort
export ISSUE_DIR=`pwd`
export SCRATCH_DIR=$MEMBERWORK/chm136/$LSB_JOBNAME.$LSB_BATCH_JID
export RUNLINE="jsrun --nrs=1 --rs_per_host=1 --cpu_per_rs=1 --gpu_per_rs=1"
mkdir $SCRATCH_DIR
cp ../../xc-regression           $SCRATCH_DIR
cp ../../input/H                 $SCRATCH_DIR
cp ../../input/Li                $SCRATCH_DIR
cp ../../input/BrOH              $SCRATCH_DIR
cp ../../input/BrOH+             $SCRATCH_DIR
cd $SCRATCH_DIR
#
# xc-regression <functional> <nspin> <norder> <input> <output>
#
#    - functional: name
#    - nspin     : integer number, 1 = unpolarized, 2 = polarized
#    - norder    : integer number, order of derivatives <= 3
#    - input     : input file name
#    - output    : output file name
#
functionals=(
  gga_x_2d_b86
  gga_x_2d_b88
  gga_x_2d_pbe
  gga_x_airy
  gga_x_ak13
  gga_x_am05
  gga_x_apbe
  gga_x_b86
  gga_x_b86_mgc
  gga_x_b86_r
  gga_x_b88
  gga_x_b88m
  gga_x_bayesian
  gga_x_bcgp
  gga_x_beefvdw
  gga_x_bpccac
  gga_x_c09x
  gga_x_cap
  gga_x_chachiyo
  gga_x_dk87_r1
  gga_x_dk87_r2
  gga_x_eb88
  gga_x_ev93
  gga_x_fd_lb94
  gga_x_fd_revlb94
  gga_x_ft97_a
  gga_x_ft97_b
  gga_x_g96
  gga_x_gam
  gga_x_gg99
  gga_x_hcth_a
  gga_x_herman
  gga_x_hjs_b88
  gga_x_hjs_b97x
  gga_x_hjs_pbe
  gga_x_hjs_pbe_sol
  gga_x_htbs
  gga_x_ityh
  gga_x_kgg99
  gga_x_kt1
  gga_x_lag
  gga_x_lambda_ch_n
  gga_x_lambda_lo_n
  gga_x_lambda_oc2_n
  gga_x_lb
  gga_x_lbm
  gga_x_lg93
  gga_x_lspbe
  gga_x_lsrpbe
  gga_x_lv_rpw86
  gga_x_mb88
  gga_x_mpbe
  gga_x_mpw91
  gga_x_n12
  gga_x_ol2
  gga_x_optb86b_vdw
  gga_x_optb88_vdw
  gga_x_optpbe_vdw
  gga_x_optx
  gga_x_pbe
  gga_x_pbe_jsjr
  gga_x_pbe_mol
  gga_x_pbe_r
  gga_x_pbe_sol
  gga_x_pbe_tca
  gga_x_pbea
  gga_x_pbefe
  gga_x_pbeint
  gga_x_pbek1_vdw
  gga_x_pbepow
  gga_x_pbetrans
  gga_x_pw86
  gga_x_pw91
  gga_x_q2d
  gga_x_rge2
  gga_x_rpbe
  gga_x_rpw86
  gga_x_sfat
  gga_x_sfat_pbe
  gga_x_sg4
  gga_x_sogga11
  gga_x_ssb
  gga_x_ssb_d
  gga_x_ssb_sw
  gga_x_vmt84_ge
  gga_x_vmt84_pbe
  gga_x_vmt_ge
  gga_x_vmt_pbe
  gga_x_wc
  gga_x_wpbeh
  gga_x_xpbe
)
#
for func in "${functionals[@]}"; do
    $RUNLINE ./xc-regression $func 1 0 H     ${func}.H.unpol.0.out 
    $RUNLINE ./xc-regression $func 1 1 H     ${func}.H.unpol.1.out 
    $RUNLINE ./xc-regression $func 1 2 H     ${func}.H.unpol.2.out 
#
    $RUNLINE ./xc-regression $func 2 0 H     ${func}.H.pol.0.out 
    $RUNLINE ./xc-regression $func 2 1 H     ${func}.H.pol.1.out 
    $RUNLINE ./xc-regression $func 2 2 H     ${func}.H.pol.2.out 
#
    $RUNLINE ./xc-regression $func 1 0 Li    ${func}.Li.unpol.0.out 
    $RUNLINE ./xc-regression $func 1 1 Li    ${func}.Li.unpol.1.out 
    $RUNLINE ./xc-regression $func 1 2 Li    ${func}.Li.unpol.2.out 
#
    $RUNLINE ./xc-regression $func 2 0 Li    ${func}.Li.pol.0.out 
    $RUNLINE ./xc-regression $func 2 1 Li    ${func}.Li.pol.1.out 
    $RUNLINE ./xc-regression $func 2 2 Li    ${func}.Li.pol.2.out 
#
    $RUNLINE ./xc-regression $func 1 0 BrOH  ${func}.BrOH.unpol.0.out 
    $RUNLINE ./xc-regression $func 1 1 BrOH  ${func}.BrOH.unpol.1.out 
    $RUNLINE ./xc-regression $func 1 2 BrOH  ${func}.BrOH.unpol.2.out 
#
    $RUNLINE ./xc-regression $func 2 0 BrOH  ${func}.BrOH.pol.0.out 
    $RUNLINE ./xc-regression $func 2 1 BrOH  ${func}.BrOH.pol.1.out 
    $RUNLINE ./xc-regression $func 2 2 BrOH  ${func}.BrOH.pol.2.out 
#
    $RUNLINE ./xc-regression $func 1 0 BrOH+ ${func}.BrOH+.unpol.0.out 
    $RUNLINE ./xc-regression $func 1 1 BrOH+ ${func}.BrOH+.unpol.1.out 
    $RUNLINE ./xc-regression $func 1 2 BrOH+ ${func}.BrOH+.unpol.2.out 
#
    $RUNLINE ./xc-regression $func 2 0 BrOH+ ${func}.BrOH+.pol.0.out 
    $RUNLINE ./xc-regression $func 2 1 BrOH+ ${func}.BrOH+.pol.1.out 
    $RUNLINE ./xc-regression $func 2 2 BrOH+ ${func}.BrOH+.pol.2.out 
done
#
cp *.out  $ISSUE_DIR
#
rm -rf $SCRATCH_DIR
