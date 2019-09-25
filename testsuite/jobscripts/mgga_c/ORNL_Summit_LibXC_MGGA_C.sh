#!/bin/bash
#BSUB -P      chm136                    # Project ID
#BSUB -o      libxc.oe%J                # Job output name
#BSUB -J      libxc_mgga_c              # Job name
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
  mgga_c_b88
  mgga_c_bc95
  mgga_c_cs
  mgga_c_dldf
  mgga_c_kcis
  mgga_c_m05
  mgga_c_m05_2x
  mgga_c_m06
  mgga_c_m06_2x
  mgga_c_m06_hf
  mgga_c_m06_l
  mgga_c_m08_hx
  mgga_c_m08_so
  mgga_c_m11
  mgga_c_m11_l
  mgga_c_mn12_l
  mgga_c_mn12_sx
  mgga_c_mn15
  mgga_c_mn15_l
  mgga_c_pkzb
  mgga_c_revm06_l
  mgga_c_revm11
  mgga_c_revscan
  mgga_c_revtpss
  mgga_c_scan
  mgga_c_scan_rvv10
  mgga_c_tm
  mgga_c_tpss
  mgga_c_tpssloc
  mgga_c_vsxc
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
