Test OpenMP GPU offloading
==========================

This directory contains some jobscripts to run the regression tests on Summit.
The tests take density from a file (one of four different systems) and 
evaluates a functional and prints the requested order of derivative. 

The input files with the density data can be found in
```
	libxc/testsuite/input
```
There are files for four different systems

* H
* Li
* BrOH
* BrOH+

The H, Li, and BrOH+ densities are all spin-polarized. The BrOH data can be used
for unpolarized and polarized calculations.

Reference data for the test cases can be found in
```
	libxc/testsuite/regression/<functional-family>
```
The data is stored in a bzip2-ed format.
The job scripts for running the regression tests on Summit are stored in
```
	libxc/testsuite/jobscripts/<functional-family>
```

Note that the regression testsuite has been developed as a tool for the LibXC
developer. It is not expected that the results match to full precision.
See [this explanation](https://tddft.org/pipermail/libxc/2013-November/000166.html)
for more information.
