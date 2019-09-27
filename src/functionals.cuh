#ifndef _FUNCTIONALS_CUH
#define _FUNCTIONALS_CUH

#ifdef __CUDACC__

extern xc_func_type *xc_func_data;

#ifdef __cplusplus
extern "C" {
#endif

int xc_func_init_all(int nspin);
void xc_func_end_all();

#ifdef __cplusplus
}
#endif

#endif
#endif
