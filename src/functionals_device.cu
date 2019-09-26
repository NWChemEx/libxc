/* Functions associated with those that appear in functionals.c but
 * these functions are all associated with GPU device implementations.
 */
#include "xc_device.h"
#include "xc_func_data.cuh"

__host__ void xc_copy_func_type_to_device(xc_func_type *dest, xc_func_type *source)
{
    checkCuda(cudaMemcpy(&(dest->nspin),&(source->nspin),sizeof(source->nspin), cudaMemcpyHostToDevice));
    checkCuda(cudaMemcpy(&(dest->cam_omega),&(source->cam_omega),sizeof(source->cam_omega), cudaMemcpyHostToDevice));
    checkCuda(cudaMemcpy(&(dest->cam_alpha),&(source->cam_alpha),sizeof(source->cam_alpha), cudaMemcpyHostToDevice));
    checkCuda(cudaMemcpy(&(dest->cam_beta),&(source->cam_beta),sizeof(source->cam_beta), cudaMemcpyHostToDevice));
    checkCuda(cudaMemcpy(&(dest->nlc_b),&(source->nlc_b),sizeof(source->nlc_b), cudaMemcpyHostToDevice));
    checkCuda(cudaMemcpy(&(dest->nlc_C),&(source->nlc_C),sizeof(source->nlc_C), cudaMemcpyHostToDevice));
    checkCuda(cudaMemcpy(&(dest->dim),&(source->dim),sizeof(source->dim), cudaMemcpyHostToDevice));
    checkCuda(cudaMemcpy(&(dest->dens_threshold),&(source->dens_threshold),sizeof(source->dens_threshold), cudaMemcpyHostToDevice));
}

__host__ void xc_copy_func_params_to_device(xc_func_type *dest, xc_func_type *source, size_t params_size)
{
    checkCuda(cudaMalloc((void**)&(dest->params),params_size));
    checkCuda(cudaMemcpy(dest->params,source->params,params_size, cudaMemcpyHostToDevice));
}

__host__ void xc_free_func_params(xc_func_type *dest)
{
    checkCuda(cudaFree(dest->params));
}

/* Initialize the functional parameters on the device
 */
__host__ void xc_func_init_device(xc_func_type *p)
{
    xc_copy_func_type_to_device(&xc_func_data[p->func_rank],p);
    if (p->params != NULL)
        xc_copy_func_params_to_device(&xc_func_data[p->func_rank],p,p->sizeof_params);
    for (int ii=0; ii<p->n_func_aux; ii++)
        xc_func_init_device(p->func_aux[ii]);
}

/* Free all the functional params on the device
 */
__host__ void xc_func_end_device(xc_func_type *p)
{
    if (p->params != NULL) xc_free_func_params(&xc_func_data[p->func_rank]);
    for (int ii=0; ii<p->n_func_aux; ii++)
        xc_func_end_device(p->func_aux[ii]);
}
