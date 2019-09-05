LibXC CUDA
==========

This directory contains a version of LibXC that has been ported to GPUs using
Nvidia's CUDA programming model. Ideally we do not want to duplicate the
source code as that complicates the maintenance efforts but there are some
serious challenges in trying to avoid doing that:

- CUDA is an extended C++ language for GPUs. I.e. a different programming
  language than the original C code.
- CUDA distinguishes between CPU "host" devices and GPU "device" devices.
  Problematic is that global constant data structures cannot be declared as
  both host and device data structures. This forces that host and device
  data structures be given different names. Subsequently these changes
  percolate throughout the source code.
- The external interface should be 'extern "C"'. However, that means that
  the API routines for the host and device code will clash. 

As a result a large part of the source code had to be copied. Many routine
and variable names have been changed by prepending them with `dvc_` to 
indicate that they are device functions and data structures. Most of the 
Maple generated code could be left untouched. It is simply included and
inlined in the top-level functional functions. In a few cases the functionals
use special functions that have been explicitly turned into device functions.
Those few functional functions had to be changed to call the `dvc_` versions
of these functions. 


