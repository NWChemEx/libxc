/* Functions associated with those that appear in functionals.c but
 * these functions are all associated with GPU device implementations.
 */
#include "hip/hip_runtime.h"
#include "xc.h"
#include "xc_device.h"
#include "xc_extern.h"
#include "util.h"

xc_func_type *xc_func_data_device;
xc_func_info_type *xc_func_info_data_device;


/* Initialize the functional parameters on the device
 */
__host__ void xc_func_init_device(xc_func_type *p)
{
    /* An issue is that xc_func_type->info->flags is used during the functional 
       evaluation. Because the pointers xc_func_type->info are initialized on the
       host with host data they point to nothing useful on the device. This would
       cause memory access errors on the device.

       So, we need to create a copy xc_func_type data where we point ->info to
       memory locations that make sense on the device. We also need to set
       xc_func_info_type->flags to a sensible value in the table for the device.
       Then we need to copy both the xc_func_type and the xc_func_info_type tables
       to the device. 

       Once the data is safely on the device we can clean the host copies of the
       tables up.
     */
    xc_func_type      *xc_func_data_host;
    xc_func_info_type *xc_func_info_data_host;
    int number = xc_number_of_functionals();

    xc_func_data_host      = (xc_func_type *)     malloc(number*sizeof(xc_func_type));
    xc_func_info_data_host = (xc_func_info_type *)malloc(number*sizeof(xc_func_info_type));

    for (int ii=0; ii < number; ii++) {
      xc_func_info_data_host[ii] = *(p[ii].info);
      //xc_func_info_data_host[ii].flags  = p[ii].info->flags;
      //xc_func_info_data_host[ii].family = p[ii].info->family;
    }
    for (int ii=0; ii < number; ii++) xc_func_data_host[ii] = p[ii];

    checkHip(__FILE__,__LINE__,hipMalloc(&xc_func_data_device,
                                         number*sizeof(xc_func_type)));
    checkHip(__FILE__,__LINE__,hipMalloc(&xc_func_info_data_device,
                                         number*sizeof(xc_func_info_type)));

    for (int ii=0; ii < number; ii++) {
      xc_func_data_host[ii].info = xc_func_info_data_device+ii;
      // Next replace the host pointers for the auxilary functionals with device pointer to the same
      for (int jj=0; jj < xc_func_data_host[ii].n_func_aux; jj++) {
        int rank = xc_func_data_host[ii].func_aux[jj]->func_rank;
        xc_func_data_host[ii].func_aux[jj] = xc_func_data_device+rank;
      }
    }

    checkHip(__FILE__,__LINE__,hipMemcpy(xc_func_data_device,xc_func_data_host,
                                         number*sizeof(xc_func_type),hipMemcpyHostToDevice));
    checkHip(__FILE__,__LINE__,hipMemcpy(xc_func_info_data_device,xc_func_info_data_host,
                                         number*sizeof(xc_func_info_type),hipMemcpyHostToDevice));

    free(xc_func_data_host);
    free(xc_func_info_data_host);
    xc_mix_func_init_hipblas();
}

/* Free all the functional params on the device
 */
__host__ void xc_func_end_device()
{
    xc_mix_func_end_hipblas();
    checkHip(__FILE__,__LINE__,hipFree(xc_func_data_device));
    checkHip(__FILE__,__LINE__,hipFree(xc_func_info_data_device));
}
