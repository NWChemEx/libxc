LibXC CUDA
==========

This directory contains a version of LibXC that has been ported to GPUs using
Nvidia's CUDA programming model. Compared to the original code that lives in the
directory one level up, this code has been changed as given below.

1. Source files have been copied to names with the CUDA file name extensions

|----------|----------|
| Original | CUDA     |
|----------|----------|
| name.c   | name.cu  |
| name.h   | name.cuh |
|----------|----------|

2. All functions are annotated with the __device__ tag and the function name
   is extended with _cuda

For example an original function 
```
   void func(int i)
```
becomes
```
   void __device__ func_cuda(int i)
```

3. The makefile is changed to invoke the nvcc compiler


In all other regards the code in this directory should be the same as the
original code.
