#!/bin/bash
#BSUB -P      chm136                    # Project ID
#BSUB -o      libxc.oe%J                # Job output name
#BSUB -J      libxc_hyb_gga_xc          # Job name
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
  hyb_gga_xc_cam_qtp_01
  hyb_gga_xc_cam_qtp_02
  hyb_gga_xc_lc_qtp
  hyb_gga_xc_apbe0
  hyb_gga_xc_apf
  hyb_gga_xc_b1lyp
  hyb_gga_xc_b1pw91
  hyb_gga_xc_b1wc
  hyb_gga_xc_b3lyp
  hyb_gga_xc_b3lyp5
  hyb_gga_xc_b3lyps
  hyb_gga_xc_b3p86
  hyb_gga_xc_b3pw91
  hyb_gga_xc_b5050lyp
  hyb_gga_xc_b97
  hyb_gga_xc_b97_1
  hyb_gga_xc_b97_1p
  hyb_gga_xc_b97_2
  hyb_gga_xc_b97_3
  hyb_gga_xc_b97_k
  hyb_gga_xc_bhandh
  hyb_gga_xc_bhandhlyp
  hyb_gga_xc_cam_b3lyp
  hyb_gga_xc_cam_qtp_00
  hyb_gga_xc_camy_b3lyp
  hyb_gga_xc_camy_blyp
  hyb_gga_xc_cap0
  hyb_gga_xc_edf2
  hyb_gga_xc_hapbe
  hyb_gga_xc_hjs_b88
  hyb_gga_xc_hjs_b97x
  hyb_gga_xc_hjs_pbe
  hyb_gga_xc_hjs_pbe_sol
  hyb_gga_xc_hpbeint
  hyb_gga_xc_hse03
  hyb_gga_xc_hse06
  hyb_gga_xc_hse12
  hyb_gga_xc_hse12s
  hyb_gga_xc_hse_sol
  hyb_gga_xc_kmlyp
  hyb_gga_xc_lc_vv10
  hyb_gga_xc_lc_wpbe
  hyb_gga_xc_lc_wpbe08_whs
  hyb_gga_xc_lc_wpbe_whs
  hyb_gga_xc_lc_wpbeh_whs
  hyb_gga_xc_lc_wpbesol_whs
  hyb_gga_xc_lcy_blyp
  hyb_gga_xc_lcy_pbe
  hyb_gga_xc_lrc_wpbe
  hyb_gga_xc_lrc_wpbeh
  hyb_gga_xc_mb3lyp_rc04
  hyb_gga_xc_mpw1k
  hyb_gga_xc_mpw1lyp
  hyb_gga_xc_mpw1pbe
  hyb_gga_xc_mpw1pw
  hyb_gga_xc_mpw3lyp
  hyb_gga_xc_mpw3pw
  hyb_gga_xc_mpwlyp1m
  hyb_gga_xc_o3lyp
  hyb_gga_xc_pbe0_13
  hyb_gga_xc_pbe50
  hyb_gga_xc_pbe_mol0
  hyb_gga_xc_pbe_molb0
  hyb_gga_xc_pbe_sol0
  hyb_gga_xc_pbeb0
  hyb_gga_xc_pbeh
  hyb_gga_xc_revb3lyp
  hyb_gga_xc_sb98_1a
  hyb_gga_xc_sb98_1b
  hyb_gga_xc_sb98_1c
  hyb_gga_xc_sb98_2a
  hyb_gga_xc_sb98_2b
  hyb_gga_xc_sb98_2c
  hyb_gga_xc_tuned_cam_b3lyp
  hyb_gga_xc_wb97
  hyb_gga_xc_wb97x
  hyb_gga_xc_wb97x_d
  hyb_gga_xc_wb97x_v
  hyb_gga_xc_x3lyp
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
