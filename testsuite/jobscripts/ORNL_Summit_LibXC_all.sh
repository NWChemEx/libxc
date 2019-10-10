#!/bin/bash
#BSUB -P      chm136                    # Project ID
#BSUB -o      libxc.oe%J                # Job output name
#BSUB -J      libxc_all                 # Job name
#BSUB -W      00:10                     # Walltime
#BSUB -nnodes 1                         # Number of nodes
#pwd
#ls
#env | sort
#module restore nwx
export ISSUE_DIR=`pwd`
export RUNLINE="jsrun --nrs=1 --rs_per_host=1 --cpu_per_rs=1 --gpu_per_rs=1"
#
cd ${ISSUE_DIR}/..
#
# Example of testing only a selected list of functionals, uncomment the following line
# to test only the gga_x_pbe, gga_c_pbe, and hyb_gga_xc_pbeh functionals:
#
#export CHECK_ONLY="gga_x_pbe gga_c_pbe hyb_gga_xc_pbeh"
#
$RUNLINE ./xc-run_testsuite
