#ifndef _FUNCTIONALS_DEVICE_CUH
#define _FUNCTIONALS_DEVICE_CUH

#ifdef __CUDACC__

extern xc_func_type *xc_func_data_device;

__host__ void xc_func_init_device(xc_func_type *p);
__host__ void xc_func_end_device();

#endif
#endif
