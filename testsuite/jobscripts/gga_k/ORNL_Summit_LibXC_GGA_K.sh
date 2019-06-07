#!/bin/bash
#BSUB -P      chm136                    # Project ID
#BSUB -o      libxc.oe%J                # Job output name
#BSUB -J      libxc_lda                 # Job name
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
  gga_k_absp1
  gga_k_absp2
  gga_k_absp3
  gga_k_absp4
  gga_k_apbe
  gga_k_apbeint
  gga_k_baltin
  gga_k_dk
  gga_k_ernzerhof
  gga_k_exp4
  gga_k_fr_b88
  gga_k_fr_pw86
  gga_k_gds08
  gga_k_ge2
  gga_k_ghds10
  gga_k_ghds10r
  gga_k_golden
  gga_k_gp85
  gga_k_gr
  gga_k_lc94
  gga_k_lieb
  gga_k_llp
  gga_k_ludena
  gga_k_meyer
  gga_k_ol1
  gga_k_ol2
  gga_k_pbe3
  gga_k_pbe4
  gga_k_pearson
  gga_k_perdew
  gga_k_revapbe
  gga_k_revapbeint
  gga_k_tfvw
  gga_k_thakkar
  gga_k_tkvln
  gga_k_tw1
  gga_k_tw2
  gga_k_tw3
  gga_k_tw4
  gga_k_vjks
  gga_k_vsk
  gga_k_vw
  gga_k_yt65
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
