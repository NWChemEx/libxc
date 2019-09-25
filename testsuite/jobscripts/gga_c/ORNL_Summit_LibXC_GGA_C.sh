#!/bin/bash
#BSUB -P      chm136                    # Project ID
#BSUB -o      libxc.oe%J                # Job output name
#BSUB -J      libxc_gga_c               # Job name
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
  gga_c_acgga
  gga_c_acggap
  gga_c_am05
  gga_c_apbe
  gga_c_bmk
  gga_c_cs1
  gga_c_ft97
  gga_c_gam
  gga_c_gapc
  gga_c_gaploc
  gga_c_hcth_a
  gga_c_hyb_tau_hcth
  gga_c_lm
  gga_c_lyp
  gga_c_n12
  gga_c_n12_sx
  gga_c_op_b88
  gga_c_op_g96
  gga_c_op_pbe
  gga_c_op_pw91
  gga_c_op_xalpha
  gga_c_optc
  gga_c_p86
  gga_c_pbe
  gga_c_pbe_jrgx
  gga_c_pbe_mol
  gga_c_pbe_sol
  gga_c_pbefe
  gga_c_pbeint
  gga_c_pbeloc
  gga_c_pw91
  gga_c_q2d
  gga_c_regtpss
  gga_c_revtca
  gga_c_rge2
  gga_c_scan_e0
  gga_c_sg4
  gga_c_sogga11
  gga_c_sogga11_x
  gga_c_spbe
  gga_c_tau_hcth
  gga_c_tca
  gga_c_tm_lyp
  gga_c_tm_pbe
  gga_c_w94
  gga_c_wi
  gga_c_wi0
  gga_c_wl
  gga_c_xpbe
  gga_c_zpbeint
  gga_c_zpbesol
  gga_c_zvpbeint
  gga_c_zvpbeloc
  gga_c_zvpbesol
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
