/*
 Copyright (C) 2006-2007 M.A.L. Marques
 Copyright (C) 2014 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <hipblas.h>
#include <hip/hip_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <xc.h>

/* Buffer size (line length) for file reads */
#define BUFSIZE 1024

typedef struct {
  /* Amount of data points */
  int n;

  /* Input: density, gradient, laplacian and kinetic energy density */
  double *rho;
  double *sigma;
  double *lapl;
  double *tau;

  /* Output: energy density */
  double *zk;

  /* .. and potentials for density, gradient, laplacian and tau */
  double *vrho;
  double *vsigma;
  double *vlapl;
  double *vtau;

  /* ... and second derivatives */
  double *v2rho2;
  double *v2tau2;
  double *v2lapl2;
  double *v2rhotau;
  double *v2rholapl;
  double *v2lapltau;
  double *v2sigma2;
  double *v2rhosigma;
  double *v2sigmatau;
  double *v2sigmalapl;

  /* ... and third derivatives */
  double *v3rho3;
} values_t;

void allocate_memory_host(values_t *data, int nspin, int order)
{
  data->zk = NULL;
  data->vrho = NULL;
  data->vsigma = NULL;
  data->vlapl = NULL;
  data->vtau = NULL;
  data->v2rho2 = NULL;
  data->v2tau2 = NULL;
  data->v2lapl2 = NULL;
  data->v2rhotau = NULL;
  data->v2rholapl = NULL;
  data->v2lapltau = NULL;
  data->v2sigma2 = NULL;
  data->v2rhosigma = NULL;
  data->v2sigmatau = NULL;
  data->v2sigmalapl = NULL;
  data->v3rho3 = NULL;

  switch(nspin) {
    case (XC_UNPOLARIZED):
      data->rho = (double *)calloc(data->n, sizeof(double));
      data->sigma = (double *)calloc(data->n, sizeof(double));
      data->lapl = (double *)calloc(data->n, sizeof(double));
      data->tau = (double *)calloc(data->n, sizeof(double));
      switch (order) {
        case (0):
          data->zk = (double *)calloc(2*data->n, sizeof(double));
          break;
        case (1):
          data->vrho = (double *)calloc(2*data->n, sizeof(double));
          data->vsigma = (double *)calloc(2*data->n, sizeof(double));
          data->vlapl = (double *)calloc(2*data->n, sizeof(double));
          data->vtau = (double *)calloc(2*data->n, sizeof(double));
          break;
        case (2):
          data->v2rho2 = (double *)calloc(2*data->n, sizeof(double));
          data->v2tau2 = (double *)calloc(2*data->n, sizeof(double));
          data->v2lapl2 = (double *)calloc(2*data->n, sizeof(double));
          data->v2rhotau = (double *)calloc(2*data->n, sizeof(double));
          data->v2rholapl = (double *)calloc(2*data->n, sizeof(double));
          data->v2lapltau = (double *)calloc(2*data->n, sizeof(double));
          data->v2sigma2 = (double *)calloc(2*data->n, sizeof(double));
          data->v2rhosigma = (double *)calloc(2*data->n, sizeof(double));
          data->v2sigmatau = (double *)calloc(2*data->n, sizeof(double));
          data->v2sigmalapl = (double *)calloc(2*data->n, sizeof(double));
          break;
        case (3):
          data->v3rho3 = (double *)calloc(2*data->n, sizeof(double));
          break;
        default:
          fprintf(stderr, "allocate_memory_host: order = %i not recognized.\n", order);
          exit(2);
      }
      break;

    case (XC_POLARIZED):
      data->rho = (double *)calloc(2*data->n, sizeof(double));
      data->sigma = (double *)calloc(3*data->n, sizeof(double));
      data->lapl = (double *)calloc(2*data->n, sizeof(double));
      data->tau = (double *)calloc(2*data->n, sizeof(double));
      switch (order) {
        case (0):
          data->zk = (double *)calloc(2*data->n, sizeof(double));
          break;
        case (1):
          data->vrho = (double *)calloc(2*2*data->n, sizeof(double));
          data->vsigma = (double *)calloc(2*3*data->n, sizeof(double));
          data->vlapl = (double *)calloc(2*2*data->n, sizeof(double));
          data->vtau = (double *)calloc(2*2*data->n, sizeof(double));
          break;
        case (2):
          data->v2rho2 = (double *)calloc(2*3*data->n, sizeof(double));
          data->v2tau2 = (double *)calloc(2*3*data->n, sizeof(double));
          data->v2lapl2 = (double *)calloc(2*3*data->n, sizeof(double));
          data->v2rhotau = (double *)calloc(2*4*data->n, sizeof(double));
          data->v2rholapl = (double *)calloc(2*4*data->n, sizeof(double));
          data->v2lapltau = (double *)calloc(2*4*data->n, sizeof(double));
          data->v2sigma2 = (double *)calloc(2*6*data->n, sizeof(double));
          data->v2rhosigma = (double *)calloc(2*6*data->n, sizeof(double));
          data->v2sigmatau = (double *)calloc(2*6*data->n, sizeof(double));
          data->v2sigmalapl = (double *)calloc(2*6*data->n, sizeof(double));
          break;
        case (3):
          data->v3rho3 = (double *)calloc(2*4*data->n, sizeof(double));
          break;
        default:
          fprintf(stderr, "allocate_memory_host: order = %i not recognized.\n", order);
          exit(2);
      }
      break;

    default:
      fprintf(stderr, "allocate_memory_host: nspin = %i not recognized.\n", nspin);
      exit(2);
  }

}

void allocate_memory_device(values_t *data, int nspin, int order)
{
  data->zk = NULL;
  data->vrho = NULL;
  data->vsigma = NULL;
  data->vlapl = NULL;
  data->vtau = NULL;
  data->v2rho2 = NULL;
  data->v2tau2 = NULL;
  data->v2lapl2 = NULL;
  data->v2rhotau = NULL;
  data->v2rholapl = NULL;
  data->v2lapltau = NULL;
  data->v2sigma2 = NULL;
  data->v2rhosigma = NULL;
  data->v2sigmatau = NULL;
  data->v2sigmalapl = NULL;
  data->v3rho3 = NULL;

  switch(nspin) {
    case (XC_UNPOLARIZED):
      checkHip(__FILE__,__LINE__,hipMalloc(&(data->rho), data->n*sizeof(double)));
      checkHip(__FILE__,__LINE__,hipMalloc(&(data->sigma), data->n*sizeof(double)));
      checkHip(__FILE__,__LINE__,hipMalloc(&(data->lapl), data->n*sizeof(double)));
      checkHip(__FILE__,__LINE__,hipMalloc(&(data->tau), data->n*sizeof(double)));
      switch (order) {
        case (0):
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->zk), 2*data->n*sizeof(double)));
          break;
        case (1):
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->vrho), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->vsigma), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->vlapl), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->vtau), 2*data->n*sizeof(double)));
          break;
        case (2):
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2rho2), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2tau2), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2lapl2), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2rhotau), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2rholapl), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2lapltau), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2sigma2), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2rhosigma), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2sigmatau), 2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2sigmalapl), 2*data->n*sizeof(double)));
          break;
        case (3):
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v3rho3), 2*data->n*sizeof(double)));
          break;
        default:
          fprintf(stderr, "allocate_memory_device: order = %i not recognized.\n", order);
          exit(2);
      }
      break;

    case (XC_POLARIZED):
      checkHip(__FILE__,__LINE__,hipMalloc(&(data->rho), 2*data->n*sizeof(double)));
      checkHip(__FILE__,__LINE__,hipMalloc(&(data->sigma), 3*data->n*sizeof(double)));
      checkHip(__FILE__,__LINE__,hipMalloc(&(data->lapl), 2*data->n*sizeof(double)));
      checkHip(__FILE__,__LINE__,hipMalloc(&(data->tau), 2*data->n*sizeof(double)));
      switch (order) {
        case (0):
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->zk), 2*data->n*sizeof(double)));
          break;
        case (1):
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->vrho), 2*2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->vsigma), 2*3*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->vlapl), 2*2*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->vtau), 2*2*data->n*sizeof(double)));
          break;
        case (2):
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2rho2), 2*3*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2tau2), 2*3*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2lapl2), 2*3*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2rhotau), 2*4*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2rholapl), 2*4*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2lapltau), 2*4*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2sigma2), 2*6*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2rhosigma), 2*6*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2sigmatau), 2*6*data->n*sizeof(double)));
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v2sigmalapl), 2*6*data->n*sizeof(double)));
          break;
        case (3):
          checkHip(__FILE__,__LINE__,hipMalloc(&(data->v3rho3), 2*4*data->n*sizeof(double)));
          break;
        default:
          fprintf(stderr, "allocate_memory_device: order = %i not recognized.\n", order);
          exit(2);
      }
      break;

    default:
      fprintf(stderr, "allocate_memory_device: nspin = %i not recognized.\n", nspin);
      exit(2);
  }

}

void copy_host_2_device(values_t data_host, values_t data_device, int nspin)
{
  // checkHip(hipMemcpy(&(data_device.n), &(data_host.n), sizeof(int), hipMemcpyHostToDevice));
  switch(nspin) {
    case (XC_UNPOLARIZED):
      checkHip(__FILE__,__LINE__,hipMemcpy(data_device.rho, data_host.rho, data_host.n*sizeof(double), hipMemcpyHostToDevice));
      checkHip(__FILE__,__LINE__,hipMemcpy(data_device.sigma, data_host.sigma, data_host.n*sizeof(double), hipMemcpyHostToDevice));
      checkHip(__FILE__,__LINE__,hipMemcpy(data_device.lapl, data_host.lapl, data_host.n*sizeof(double), hipMemcpyHostToDevice));
      checkHip(__FILE__,__LINE__,hipMemcpy(data_device.tau, data_host.tau, data_host.n*sizeof(double), hipMemcpyHostToDevice));
      break;

    case (XC_POLARIZED):
      checkHip(__FILE__,__LINE__,hipMemcpy(data_device.rho, data_host.rho, 2*data_host.n*sizeof(double), hipMemcpyHostToDevice));
      checkHip(__FILE__,__LINE__,hipMemcpy(data_device.sigma, data_host.sigma, 3*data_host.n*sizeof(double), hipMemcpyHostToDevice));
      checkHip(__FILE__,__LINE__,hipMemcpy(data_device.lapl, data_host.lapl, 2*data_host.n*sizeof(double), hipMemcpyHostToDevice));
      checkHip(__FILE__,__LINE__,hipMemcpy(data_device.tau, data_host.tau, 2*data_host.n*sizeof(double), hipMemcpyHostToDevice));
      break;

    default:
      fprintf(stderr, "copy_host_2_device: nspin = %i not recognized.\n", nspin);
      exit(3);
  }
}

void copy_device_2_host(values_t data_device, values_t data_host, int nspin, int order)
{
  switch(nspin) {
    case (XC_UNPOLARIZED):
    switch(order) {
      case(0):
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.zk, data_device.zk, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        break;
      case(1):
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.vrho, data_device.vrho, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.vsigma, data_device.vsigma, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.vlapl, data_device.vlapl, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.vtau, data_device.vtau, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        break;
      case(2):
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2rho2, data_device.v2rho2, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2rhosigma, data_device.v2rhosigma, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2rhotau, data_device.v2rhotau, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2rholapl, data_device.v2rholapl, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2sigma2, data_device.v2sigma2, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2sigmatau, data_device.v2sigmatau, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2sigmalapl, data_device.v2sigmalapl, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2lapl2, data_device.v2lapl2, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2lapltau, data_device.v2lapltau, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2tau2, data_device.v2tau2, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        break;
      case(3):
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v3rho3, data_device.v3rho3, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        break;
      default:
        fprintf(stderr, "order = %i not recognized.\n", order);
        exit(5);
    }
    break;

    case (XC_POLARIZED):
    switch(order) {
      case(0):
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.zk, data_device.zk, data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        break;
      case(1):
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.vrho, data_device.vrho, 2*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.vsigma, data_device.vsigma, 3*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.vlapl, data_device.vlapl, 2*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.vtau, data_device.vtau, 2*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        break;
      case(2):
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2rho2, data_device.v2rho2, 3*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2rhosigma, data_device.v2rhosigma, 6*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2rhotau, data_device.v2rhotau, 4*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2rholapl, data_device.v2rholapl, 4*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2sigma2, data_device.v2sigma2, 6*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2sigmatau, data_device.v2sigmatau, 6*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2sigmalapl, data_device.v2sigmalapl, 6*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2lapl2, data_device.v2lapl2, 3*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2lapltau, data_device.v2lapltau, 4*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2tau2, data_device.v2tau2, 3*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        break;
      case(3):
        checkHip(__FILE__,__LINE__,hipMemcpy(data_host.v2rho2, data_device.v2rho2, 4*data_host.n*sizeof(double), hipMemcpyDeviceToHost));
        break;
      default:
        fprintf(stderr, "order = %i not recognized.\n", order);
        exit(6);
    }
    break;

    default:
      fprintf(stderr, "copy_device_2_host: nspin = %i not recognized.\n", nspin);
      exit(4);
  }
}

void free_memory_host(values_t val)
{
  free(val.rho);
  free(val.sigma);
  free(val.lapl);
  free(val.tau);
  free(val.zk);
  free(val.vrho);
  free(val.vsigma);
  free(val.vlapl);
  free(val.vtau);
  free(val.v2rho2);
  free(val.v2tau2);
  free(val.v2lapl2);
  free(val.v2rhotau);
  free(val.v2rholapl);
  free(val.v2lapltau);
  free(val.v2sigma2);
  free(val.v2rhosigma);
  free(val.v2sigmatau);
  free(val.v2sigmalapl);
  free(val.v3rho3);
}

void free_memory_device(values_t val)
{
  checkHip(__FILE__,__LINE__,hipFree(val.rho));
  checkHip(__FILE__,__LINE__,hipFree(val.sigma));
  checkHip(__FILE__,__LINE__,hipFree(val.lapl));
  checkHip(__FILE__,__LINE__,hipFree(val.tau));
  checkHip(__FILE__,__LINE__,hipFree(val.zk));
  checkHip(__FILE__,__LINE__,hipFree(val.vrho));
  checkHip(__FILE__,__LINE__,hipFree(val.vsigma));
  checkHip(__FILE__,__LINE__,hipFree(val.vlapl));
  checkHip(__FILE__,__LINE__,hipFree(val.vtau));
  checkHip(__FILE__,__LINE__,hipFree(val.v2rho2));
  checkHip(__FILE__,__LINE__,hipFree(val.v2tau2));
  checkHip(__FILE__,__LINE__,hipFree(val.v2lapl2));
  checkHip(__FILE__,__LINE__,hipFree(val.v2rhotau));
  checkHip(__FILE__,__LINE__,hipFree(val.v2rholapl));
  checkHip(__FILE__,__LINE__,hipFree(val.v2lapltau));
  checkHip(__FILE__,__LINE__,hipFree(val.v2sigma2));
  checkHip(__FILE__,__LINE__,hipFree(val.v2rhosigma));
  checkHip(__FILE__,__LINE__,hipFree(val.v2sigmatau));
  checkHip(__FILE__,__LINE__,hipFree(val.v2sigmalapl));
  checkHip(__FILE__,__LINE__,hipFree(val.v3rho3));
}

values_t read_data(const char *file, int nspin, int order) {
  /* Format string */
  static const char fmt[]="%lf %lf %lf %lf %lf %lf %lf %lf %lf";

  /* Data buffer */
  char buf[BUFSIZE];
  char *cp;
  /* Input data file */
  FILE *in;
  /* Loop index */
  int i;
  /* Amount of points succesfully read */
  int nsucc;
  /* Returned data */
  values_t data;

  /* Helper variables */
  double rhoa, rhob;
  double sigmaaa, sigmaab, sigmabb;
  double lapla, laplb;
  double taua, taub;

  /* Open file */
  in=fopen(file,"r");
  if(!in) {
    fprintf(stderr,"Error opening input file %s.\n",file);
    exit(3);
  }

  /* Read amount of data points */
  cp=fgets(buf,BUFSIZE,in);
  if(cp!=buf) {
    fprintf(stderr,"Error reading amount of data points.\n");
    exit(5);
  }
  nsucc=sscanf(buf,"%i",&data.n);
  if(nsucc!=1) {
    fprintf(stderr,"Error reading amount of input data points.\n");
    exit(4);
  }

  /* Allocate memory */
  allocate_memory_host(&data, nspin, order);

  for(i=0;i<data.n;i++) {
    /* Next line of input */
    cp=fgets(buf,BUFSIZE,in);
    if(cp!=buf) {
      fprintf(stderr,"Read error on line %i.\n",i+1);
      free_memory_host(data);
      exit(5);
    }
    /* Read data */
    nsucc=sscanf(buf, fmt, &rhoa, &rhob, &sigmaaa, &sigmaab, &sigmabb,	\
		 &lapla, &laplb, &taua, &taub);

    /* Error control */
    if(nsucc!=9) {
      fprintf(stderr,"Read error on line %i: only %i entries read.\n",i+1,nsucc);
      free_memory_host(data);
      exit(5);
    }

    /* Store data (if clause suboptimal here but better for code clarity) */
    if(nspin==XC_POLARIZED) {
      data.rho[2*i]=rhoa;
      data.rho[2*i+1]=rhob;
      data.sigma[3*i]=sigmaaa;
      data.sigma[3*i+1]=sigmaab;
      data.sigma[3*i+2]=sigmabb;
      data.lapl[2*i]=lapla;
      data.lapl[2*i+1]=laplb;
      data.tau[2*i]=taua;
      data.tau[2*i+1]=taub;
    } else {
      /* Construct full density data from alpha and beta channels */
      data.rho[i]=rhoa + rhob;
      data.sigma[i]=sigmaaa + sigmabb + 2.0*sigmaab;
      data.lapl[i]=lapla + laplb;
      data.tau[i]=taua + taub;
    }
  }

  /* Close input file */
  fclose(in);

  return data;
}

/*----------------------------------------------------------*/
int main(int argc, char *argv[])
{
  int func_id, nspin, order, i, func_rank;
  /* Helpers for properties that may not have been implemented */
  double *zk, *vrho, *v2rho2, *v3rho3;

  static const char efmt[] =" % .16e";
  static const char efmt2[]=" % .16e % .16e";
  static const char efmt3[]=" % .16e % .16e % .16e";
  static const char sfmt[] =" %23s";
  static const char sfmt2[]=" %23s %23s";
  static const char sfmt3[]=" %23s %23s %23s";

  if(argc != 6) {
    fprintf(stderr, "Usage:\n%s funct nspin order input output\n", argv[0]);
    exit(1);
  }

  /* Get functional id */
  func_id = xc_functional_get_number(argv[1]);
  func_rank = xc_functional_get_rank(func_id);
  if(func_id <= 0) {
    fprintf(stderr, "Functional '%s' not found\n", argv[1]);
    exit(1);
  }

  /* Spin-polarized or unpolarized ? */
  nspin = atoi(argv[2]);

  /* Order of derivatives to compute */
  order = atoi(argv[3]);

  /* Data array */
  values_t d_dev, d_host;
  /* Functional evaluator */
  //xc_func_type func;
  /* Flags for functional */
  int flags;
  /* Functional family */
  int family;
  /* Output file */
  FILE *out;
  /* Output file name */
  char *fname;
  /* CUDA status */
  //hipError_t stat;
  hipStream_t stream;

  /* Read in data */
  d_host = read_data(argv[4], nspin, order);
  d_dev.n = d_host.n;
  allocate_memory_device(&d_dev, nspin, order);
  copy_host_2_device(d_host, d_dev, nspin);

  /* Initialize all functionals */
  xc_func_init_all(nspin);
  /* Get flags */
  flags  = xc_func_data[func_rank].info->flags;
  family = xc_func_data[func_rank].info->family;

  /* Set helpers */
  zk     = (flags & XC_FLAGS_HAVE_EXC) ? d_dev.zk     : NULL;
  vrho   = (flags & XC_FLAGS_HAVE_VXC) ? d_dev.vrho   : NULL;
  v2rho2 = (flags & XC_FLAGS_HAVE_FXC) ? d_dev.v2rho2 : NULL;
  v3rho3 = (flags & XC_FLAGS_HAVE_KXC) ? d_dev.v3rho3 : NULL;

  /* Evaluate xc functional */
  checkHip(__FILE__,__LINE__,hipStreamCreate(&stream));
  switch(family) {
  case XC_FAMILY_LDA:
    xc_lda_offload(&xc_func_data[func_rank], d_host.n, d_dev.rho, zk, vrho, v2rho2, v3rho3, stream);
    break;
  case XC_FAMILY_GGA:
  case XC_FAMILY_HYB_GGA:
    xc_gga_offload(&xc_func_data[func_rank], d_host.n, d_dev.rho, d_dev.sigma, zk, vrho, d_dev.vsigma,
                   v2rho2, d_dev.v2rhosigma, d_dev.v2sigma2, NULL, NULL, NULL, NULL, stream);
    break;
  case XC_FAMILY_MGGA:
  case XC_FAMILY_HYB_MGGA:
    xc_mgga_offload(&xc_func_data[func_rank], d_host.n, d_dev.rho, d_dev.sigma, d_dev.lapl, d_dev.tau,
            zk, vrho, d_dev.vsigma, d_dev.vlapl, d_dev.vtau,
            v2rho2, d_dev.v2rhosigma, d_dev.v2rholapl, d_dev.v2rhotau, 
            d_dev.v2sigma2, d_dev.v2sigmalapl, d_dev.v2sigmatau,
            d_dev.v2lapl2, d_dev.v2lapltau,
            d_dev.v2tau2,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, stream);
    break;

  default:
    fprintf(stderr,"Support for family %i not implemented.\n",family);
    free_memory_device(d_dev);
    free_memory_host(d_host);
    exit(1);
  }
  checkHip(__FILE__,__LINE__,hipStreamSynchronize(stream));
  checkHip(__FILE__,__LINE__,hipStreamDestroy(stream));
  copy_device_2_host(d_dev, d_host, nspin, order);

  /* Open output file */
  fname = argv[5];
  out = fopen(fname,"w");
  if(!out) {
    fprintf(stderr,"Error opening output file %s.\n",fname);
    free_memory_device(d_dev);
    free_memory_host(d_host);
    exit(1);
  }

  /* Functional id and amount of lines in output */
  fprintf(out, "%i %i %i\n", func_id, d_host.n, order);

  switch (order) {
    case (0): /* energy */
      fprintf(out, sfmt, "zk");
      break;
    case (1): /* first order derivatives */
      if (nspin == XC_POLARIZED) {
        fprintf(out, sfmt2, "vrho(a)", "vrho(b)");
        if (family & (XC_FAMILY_GGA | XC_FAMILY_HYB_GGA | XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA))
          fprintf(out, sfmt3, "vsigma(aa)", "vsigma(ab)", "vsigma(bb)");
        if (family & (XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
          fprintf(out, sfmt2, "vlapl(a)", "vlapl(b)");
          fprintf(out, sfmt2, "vtau(a)", "vtau(b)");
        }
      } else {
        fprintf(out, sfmt, "vrho");
        if (family & (XC_FAMILY_GGA | XC_FAMILY_HYB_GGA | XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA))
          fprintf(out, sfmt, "vsigma");
        if(family & (XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
          fprintf(out, sfmt, "vlapl");
          fprintf(out, sfmt, "vtau");
        }
      }
      break;

    case (2): /* second order derivatives */
      if (nspin == XC_POLARIZED) {
        fprintf(out,sfmt3,"v2rho(aa)","v2rho(ab)","v2rho(bb)");
        if(family & (XC_FAMILY_GGA | XC_FAMILY_HYB_GGA | XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
          fprintf(out, sfmt3, "v2sigma2(aa-aa)", "v2sigma2(aa-ab)", "v2sigma2(aa-bb)");
          fprintf(out, sfmt3, "v2sigma2(ab-ab)", "v2sigma2(ab-bb)", "v2sigma2(bb-bb)");
          fprintf(out, sfmt3, "v2rho(a)sigma(aa)", "v2rho(a)sigma(ab)", "v2rho(a)sigma(bb)");
          fprintf(out, sfmt3, "v2rho(b)sigma(aa)", "v2rho(b)sigma(ab)", "v2rho(b)sigma(bb)");
        }
        if(family & (XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
          fprintf(out, sfmt3, "v2lapl2(aa)", "v2lapl2(ab)", "v2lapl2(bb)");
          fprintf(out, sfmt3, "v2tau2(aa)", "v2tau2(ab)", "v2tau2(bb)");
          fprintf(out, sfmt3, "v2rholapl(aa)", "v2rholapl(ab)", "v2rholapl(bb)");
          fprintf(out, sfmt3, "v2rhotau(aa)", "v2rhotau(ab)", "v2rhotau(bb)");
          fprintf(out, sfmt3, "v2lapltau(aa)", "v2lapltau(ab)", "v2lapltau(bb)");
          fprintf(out, sfmt3, "v2sigma(aa)tau(a)", "v2sigma(aa)tau(b)", "v2sigma(ab)tau(a)");
          fprintf(out, sfmt3, "v2sigma(ab)tau(b)", "v2sigma(bb)tau(a)", "v2sigma(bb)tau(b)");
          fprintf(out, sfmt3, "v2sigma(aa)lapl(a)", "v2sigma(aa)lapl(b)", "v2sigma(ab)lapl(a)");
          fprintf(out, sfmt3, "v2sigma(ab)lapl(b)", "v2sigma(bb)lapl(a)", "v2sigma(bb)lapl(b)");
        }
      } else {
        fprintf(out,sfmt,"v2rho");
        if(family & (XC_FAMILY_GGA | XC_FAMILY_HYB_GGA | XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
          fprintf(out, sfmt, "v2sigma2");
          fprintf(out, sfmt, "v2rhosigma");
        }

        if(family & (XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
          fprintf(out, sfmt, "v2lapl2");
          fprintf(out, sfmt, "v2tau2");
          fprintf(out, sfmt, "v2rholapl");
          fprintf(out, sfmt, "v2rhotau");
          fprintf(out, sfmt, "v2lapltau");
          fprintf(out, sfmt, "v2sigmatau");
          fprintf(out, sfmt, "v2sigmalapl");
        }
      }
      break;

    default: /* higher order derivatives ... to be done */
      fprintf(stderr, "order = %i not recognized.\n", order);
      exit(2);
  }
  fprintf(out,"\n");

  /* Loop over data points */
  for(i=0;i<d_host.n;i++) {

    switch (order) {
      case (0): /* energy */
        fprintf(out, efmt, d_host.zk[i]);
        break;
      case (1): /* first order derivatives */
        if (nspin == XC_POLARIZED) {
          fprintf(out, efmt2, d_host.vrho[2 * i], d_host.vrho[2 * i + 1]);
          if (family & (XC_FAMILY_GGA | XC_FAMILY_HYB_GGA | XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA))
            fprintf(out, efmt3, d_host.vsigma[3 * i], d_host.vsigma[3 * i + 1], d_host.vsigma[3 * i + 2]);
          if (family & (XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
            fprintf(out, efmt2, d_host.vlapl[2 * i], d_host.vlapl[2 * i + 1]);
            fprintf(out, efmt2, d_host.vtau[2 * i], d_host.vtau[2 * i + 1]);
          }
        } else {
          fprintf(out, efmt, d_host.vrho[i]);
          if (family & (XC_FAMILY_GGA | XC_FAMILY_HYB_GGA | XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA))
            fprintf(out, efmt, d_host.vsigma[i]);
          if (family & (XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
            fprintf(out, efmt, d_host.vlapl[i]);
            fprintf(out, efmt, d_host.vtau[i]);
          }
        }
        break;

      case (2): /* second order derivatives */
        if (nspin == XC_POLARIZED) {
          fprintf(out, efmt3, d_host.v2rho2[3*i], d_host.v2rho2[3*i + 1], d_host.v2rho2[3*i + 2]);
          if(family & (XC_FAMILY_GGA | XC_FAMILY_HYB_GGA | XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
            fprintf(out, efmt3, d_host.v2sigma2[6*i], d_host.v2sigma2[6*i + 1], d_host.v2sigma2[6*i + 2]);
            fprintf(out, efmt3, d_host.v2sigma2[6*i + 3], d_host.v2sigma2[6*i + 4], d_host.v2sigma2[6*i + 5]);
            fprintf(out, efmt3, d_host.v2rhosigma[6*i], d_host.v2rhosigma[6*i + 1], d_host.v2rhosigma[6*i + 2]);
            fprintf(out, efmt3, d_host.v2rhosigma[6*i + 3], d_host.v2rhosigma[6*i + 4], d_host.v2rhosigma[6*i + 5]);
          }
          if(family & (XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
            fprintf(out, efmt3, d_host.v2lapl2[3*i], d_host.v2lapl2[3*i + 1], d_host.v2lapl2[3*i + 2]);
            fprintf(out, efmt3, d_host.v2tau2[3*i], d_host.v2tau2[3*i + 1], d_host.v2tau2[3*i + 2]);
            fprintf(out, efmt3, d_host.v2rholapl[3*i], d_host.v2rholapl[3*i + 1], d_host.v2rholapl[3*i + 2]);
            fprintf(out, efmt3, d_host.v2rhotau[3*i], d_host.v2rhotau[3*i + 1], d_host.v2rhotau[3*i + 2]);
            fprintf(out, efmt3, d_host.v2lapltau[3*i], d_host.v2lapltau[3*i + 1], d_host.v2lapltau[3*i + 2]);
            fprintf(out, efmt3, d_host.v2sigmatau[3*i], d_host.v2sigmatau[3*i + 1], d_host.v2sigmatau[3*i + 2]);
            fprintf(out, efmt3, d_host.v2sigmatau[3*i + 3], d_host.v2sigmatau[3*i + 4], d_host.v2sigmatau[3*i + 5]);
            fprintf(out, efmt3, d_host.v2sigmalapl[3*i], d_host.v2sigmalapl[3*i + 1], d_host.v2sigmalapl[3*i + 2]);
            fprintf(out, efmt3, d_host.v2sigmalapl[3*i + 3], d_host.v2sigmalapl[3*i + 4], d_host.v2sigmalapl[3*i + 5]);
          }
        } else {
          fprintf(out, efmt, d_host.v2rho2[i]);
          if(family & (XC_FAMILY_GGA | XC_FAMILY_HYB_GGA | XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
            fprintf(out, efmt, d_host.v2sigma2[i]);
            fprintf(out, efmt, d_host.v2rhosigma[i]);
          }
          if(family & (XC_FAMILY_MGGA | XC_FAMILY_HYB_MGGA)) {
            fprintf(out, efmt, d_host.v2lapl2[i]);
            fprintf(out, efmt, d_host.v2tau2[i]);
            fprintf(out, efmt, d_host.v2rholapl[i]);
            fprintf(out, efmt, d_host.v2rhotau[i]);
            fprintf(out, efmt, d_host.v2lapltau[i]);
            fprintf(out, efmt, d_host.v2sigmatau[i]);
            fprintf(out, efmt, d_host.v2sigmalapl[i]);
          }
        }
        break;

     default: /* higher order derivatives ... to be done */
        fprintf(stderr, "order = %i not recognized.\n", order);
        exit(2);
    }

    fprintf(out,"\n");
  }

  /* Finalize all functionals */
  xc_func_end_all();
  /* Free all memory buffers */
  free_memory_device(d_dev);
  free_memory_host(d_host);
  fclose(out);

  return 0;
}
