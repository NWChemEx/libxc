#ifndef _XC_DEVICE_H
#define _XC_DEVICE_H

#define _DEBUG
 
/* For CUDA code set DEVICE to __host__ __device__ to generate proper object files.
 * Note that src/file.cu is simply a softlink to src/file.c. The different 
 * extension is there so that tools like configure and CMake can figure out
 * what they are supposed to do with the file.
 */
#ifdef __CUDACC__ 
#define DEVICE __host__ __device__

#include <stdio.h>
#include <assert.h>
#include <cublas_v2.h>

// Convenience function for checking CUDA runtime API results
// can be wrapped around any runtime API call. No-op in release builds.
inline static
cudaError_t checkCuda(char *file, int line, cudaError_t result)
{
#if defined(DEBUG) || defined(_DEBUG)
  if (result != cudaSuccess) {
    fprintf(stderr, "%s,%d: CUDA Runtime Error: %s\n", 
            file,line,cudaGetErrorString(result));
    assert(result == cudaSuccess);
  }
#endif
  return result;
}


inline static
cublasStatus_t checkCublas(char *file, int line, cublasStatus_t result)
{
#if defined(DEBUG) || defined(_DEBUG)
  if (result != CUBLAS_STATUS_SUCCESS) {
    fprintf(stderr, "%s,%d: cuBlas failure.\n",file,line);
    assert(result == CUBLAS_STATUS_SUCCESS);
  }
#endif
  return result;
}
#else
#define DEVICE 
#endif

#endif
