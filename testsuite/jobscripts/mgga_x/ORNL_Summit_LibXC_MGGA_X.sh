#!/bin/bash
#BSUB -P      chm136                    # Project ID
#BSUB -o      libxc.oe%J                # Job output name
#BSUB -J      libxc_mgga_x              # Job name
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
  mgga_x_2d_prhg07
  mgga_x_2d_prhg07_prp10
  mgga_x_b00
  mgga_x_bj06
  mgga_x_bloc
  mgga_x_br89
  mgga_x_br89_1
  mgga_x_br89_explicit
  mgga_x_gvt4
  mgga_x_gx
  mgga_x_lta
  mgga_x_m06_l
  mgga_x_m11_l
  mgga_x_mbeef
  mgga_x_mbeefvdw
  mgga_x_mk00
  mgga_x_mk00b
  mgga_x_mn12_l
  mgga_x_mn15_l
  mgga_x_modtpss
  mgga_x_ms0
  mgga_x_ms1
  mgga_x_ms2
  mgga_x_ms2b
  mgga_x_ms2bs
  mgga_x_mvs
  mgga_x_mvsb
  mgga_x_mvsbs
  mgga_x_pbe_gx
  mgga_x_pkzb
  mgga_x_regtpss
  mgga_x_revm06_l
  mgga_x_revscan
  mgga_x_revtpss
  mgga_x_rpp09
  mgga_x_rtpss
  mgga_x_sa_tpss
  mgga_x_scan
  mgga_x_tau_hcth
  mgga_x_tb09
  mgga_x_tm
  mgga_x_tpss
  mgga_x_vt84
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
