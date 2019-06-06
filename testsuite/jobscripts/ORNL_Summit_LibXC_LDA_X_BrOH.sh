#!/bin/bash
#BSUB -P      chm136                    # Project ID
#BSUB -o      libxc.oe%J                # Job output name
#BSUB -J      libxc_lda                 # Job name
#BSUB -W      00:10                     # Walltime
#BSUB -nnodes 1                         # Number of nodes
pwd
ls
env | sort
export ISSUE_DIR=`pwd`
export SCRATCH_DIR=$MEMBERWORK/chm136/$LSB_JOBNAME.$LSB_BATCH_JID
mkdir $SCRATCH_DIR
cp ../xc-regression           $SCRATCH_DIR
cp ../input/BrOH              $SCRATCH_DIR
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
# LDA_X = 1
jsrun --nrs=1 --rs_per_host=1 --cpu_per_rs=1 --gpu_per_rs=1 \
      ./xc-regression "lda_x" 1 0 BrOH BrOH_LDA_X_unpol_0.out 
jsrun --nrs=1 --rs_per_host=1 --cpu_per_rs=1 --gpu_per_rs=1 \
      ./xc-regression "lda_x" 1 1 BrOH BrOH_LDA_X_unpol_1.out 
jsrun --nrs=1 --rs_per_host=1 --cpu_per_rs=1 --gpu_per_rs=1 \
      ./xc-regression "lda_x" 1 2 BrOH BrOH_LDA_X_unpol_2.out 
cp BrOH_LDA_X_unpol_?.out  $ISSUE_DIR
#
rm -rf $SCRATCH_DIR
