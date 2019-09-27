/* Functions associated with those that appear in functionals.c but
 * these functions are all associated with GPU device implementations.
 */
#include "xc.h"
#include "xc_device.h"
#include "xc_extern.h"

xc_func_type *xc_func_data_device;


/* Initialize the functional parameters on the device
 */
__host__ void xc_func_init_device(xc_func_type *p)
{
    int number = xc_number_of_functionals();
    checkCuda(cudaMalloc(&xc_func_data_device,number*sizeof(xc_func_type)));
    checkCuda(cudaMemcpy(xc_func_data_device,p,number*sizeof(xc_func_type),cudaMemcpyHostToDevice));
}

/* Free all the functional params on the device
 */
__host__ void xc_func_end_device()
{
    checkCuda(cudaFree(xc_func_data_device));
}
