/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "xc.h"
#include "util.h"
#include "dvc_util.h"
#include "funcs_key.h"
//ifdef __CUDACC__
//undef max
//undef min
//include <string>
//else
#ifndef __CUDACC__
#include <string.h>
#endif
#ifdef _MSC_VER
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#else
#include <strings.h>
#endif

#pragma omp declare target
/* This does not work in C++ as the language insists that the
 * size of the arrays be known. It does not let you to just
 * get a pointer to an array. Hence we replace this code 
 * with the code that actually defines the arrays.

extern DEVICE xc_func_info_type *xc_lda_known_funct[]; 
extern DEVICE xc_func_info_type *xc_gga_known_funct[];
extern DEVICE xc_func_info_type *xc_hyb_gga_known_funct[];
extern DEVICE xc_func_info_type *xc_mgga_known_funct[];
extern DEVICE xc_func_info_type *xc_hyb_mgga_known_funct[];
*/
#include "funcs_lda.h"
#include "funcs_gga.h"
#include "funcs_hyb_gga.h"
#include "funcs_mgga.h"
#include "funcs_hyb_mgga.h"


/*------------------------------------------------------*/
DEVICE int dvc_xc_functional_get_number(const char *name)
{
  int ii;
  int key=-1;
  const char *p;

  /* Does name begin with xc_? */
  if(dvc_strncasecmp(name,"XC_",3) == 0) {
    p=name+3;
  } else {
    p=name;
  }

  for(ii=0;;ii++){
    if(dvc_xc_functional_keys[ii].number == -1)
      break;
    if(dvc_strcasecmp(dvc_xc_functional_keys[ii].name, p) == 0){
      key = dvc_xc_functional_keys[ii].number;
      break;
    }
  }
  
  return key;
}


/*------------------------------------------------------*/
DEVICE char *dvc_xc_functional_get_name(int number)
{
  int ii;
  char *p;

  for(ii=0;;ii++){
    if(dvc_xc_functional_keys[ii].number == -1)
      return NULL;
    if(dvc_xc_functional_keys[ii].number == number) {
      /* return duplicated: caller has the responsibility to dealloc string.
         Do this the old way since strdup and strndup aren't C standard. */
      p=(char*)malloc(dvc_strlen(dvc_xc_functional_keys[ii].name)+1);
      dvc_strcpy(p,dvc_xc_functional_keys[ii].name);
      return p;
    }
  }
}


/*------------------------------------------------------*/
DEVICE int dvc_xc_family_from_id(int id, int *family, int *number)
{
  int ii;

  /* first let us check if it is an LDA */
  for(ii=0; dvc_xc_lda_known_funct[ii]!=NULL; ii++){
    if(dvc_xc_lda_known_funct[ii]->number == id){
      if(family != NULL) *family = XC_FAMILY_LDA;
      if(number != NULL) *number = ii;
      return XC_FAMILY_LDA;
    }
  }

  /* or is it a GGA? */
  for(ii=0; dvc_xc_gga_known_funct[ii]!=NULL; ii++){
    if(dvc_xc_gga_known_funct[ii]->number == id){
      if(family != NULL) *family = XC_FAMILY_GGA;
      if(number != NULL) *number = ii;
      return XC_FAMILY_GGA;
    }
  }

  /* or is it a hybrid GGA? */
  for(ii=0; dvc_xc_hyb_gga_known_funct[ii]!=NULL; ii++){
    if(dvc_xc_hyb_gga_known_funct[ii]->number == id){
      if(family != NULL) *family = XC_FAMILY_HYB_GGA;
      if(number != NULL) *number = ii;
      return XC_FAMILY_HYB_GGA;
    }
  }

  /* or is it a meta GGA? */
  for(ii=0; dvc_xc_mgga_known_funct[ii]!=NULL; ii++){
    if(dvc_xc_mgga_known_funct[ii]->number == id){
      if(family != NULL) *family = XC_FAMILY_MGGA;
      if(number != NULL) *number = ii;
      return XC_FAMILY_MGGA;
    }
  }

  /* or is it a hybrid meta GGA? */
  for(ii=0; dvc_xc_hyb_mgga_known_funct[ii]!=NULL; ii++){
    if(dvc_xc_hyb_mgga_known_funct[ii]->number == id){
      if(family != NULL) *family = XC_FAMILY_HYB_MGGA;
      if(number != NULL) *number = ii;
      return XC_FAMILY_HYB_MGGA;
    }
  }

  return XC_FAMILY_UNKNOWN;
}

/*------------------------------------------------------*/
DEVICE int dvc_xc_number_of_functionals()
{
  int num;

  for(num=0;;num++){
    if(dvc_xc_functional_keys[num].number == -1)
      return num;
  }

  #ifndef __CUDACC__
  fprintf(stderr, "Internal error in functionals.c\n");
  exit(1);
  #endif
}

DEVICE int dvc_xc_maximum_name_length()
{
  int i, N, maxlen, tmp;

  N=dvc_xc_number_of_functionals();

  maxlen=0;
  for(i=0;i<N;i++){
    tmp=dvc_strlen(dvc_xc_functional_keys[i].name);
    if(tmp > maxlen) maxlen=tmp;
  }

  return maxlen;
}

/*------------------------------------------------------*/
DEVICE void dvc_xc_available_functional_numbers(int *list)
{
  int ii, N;
  N=dvc_xc_number_of_functionals();
  for(ii=0;ii<N;ii++){
    list[ii]=dvc_xc_functional_keys[ii].number;
  }
}

DEVICE void dvc_xc_available_functional_names(char **list)
{
  int ii, N;

  N=dvc_xc_number_of_functionals();
  for(ii=0;ii<N;ii++) {
    dvc_strcpy(list[ii],dvc_xc_functional_keys[ii].name);
  }
}

/*------------------------------------------------------*/
DEVICE xc_func_type *dvc_xc_func_alloc()
{
  xc_func_type *func;

  func = (xc_func_type *) malloc (sizeof (xc_func_type));
  return func;
}

/*------------------------------------------------------*/
DEVICE int dvc_xc_func_init(xc_func_type *func, int functional, int nspin)
{
  int number;

  assert(func != NULL);
  assert(nspin==XC_UNPOLARIZED || nspin==XC_POLARIZED);

  /* initialize structure */
  func->nspin       = nspin;

  func->params     = NULL;

  func->n_func_aux = 0;
  func->func_aux   = NULL;
  func->mix_coef   = NULL;
  func->cam_omega = func->cam_alpha = func->cam_beta = 0.0;
  func->nlc_b = func->nlc_C = 0.0;

  switch(dvc_xc_family_from_id(functional, NULL, &number)){
  case(XC_FAMILY_LDA):
    func->info = dvc_xc_lda_known_funct[number];
    dvc_internal_counters_set_lda(func->nspin, &(func->dim));
    break;

  case(XC_FAMILY_GGA):
    func->info = dvc_xc_gga_known_funct[number];
    dvc_internal_counters_set_gga(func->nspin, &(func->dim));
    break;

  case(XC_FAMILY_HYB_GGA):
    func->info = dvc_xc_hyb_gga_known_funct[number];
    dvc_internal_counters_set_gga(func->nspin, &(func->dim));
    break;

  case(XC_FAMILY_MGGA):
    func->info = dvc_xc_mgga_known_funct[number];
    dvc_internal_counters_set_mgga(func->nspin, &(func->dim));
    break;

  case(XC_FAMILY_HYB_MGGA):
    func->info = dvc_xc_hyb_mgga_known_funct[number];
    dvc_internal_counters_set_mgga(func->nspin, &(func->dim));
    break;

  default:
    return -2; /* family not found */
  }

  /* see if we need to initialize the functional */
  if(func->info->init != NULL)
    func->info->init(func);

  /* see if we need to initialize the external parameters */
  if(func->info->n_ext_params > 0)
    func->info->set_ext_params(func, NULL);

  func->dens_threshold = func->info->dens_threshold;

  return 0;
}


/*------------------------------------------------------*/
DEVICE void dvc_xc_func_end(xc_func_type *func)
{
  assert(func != NULL && func->info != NULL);

  /* call internal termination routine */
  if(func->info->end != NULL)
    func->info->end(func);

  /* terminate any auxiliary functional */
  if(func->n_func_aux > 0){
    int ii;

    for(ii=0; ii<func->n_func_aux; ii++){
      dvc_xc_func_end(func->func_aux[ii]);
      free(func->func_aux[ii]);
    }
    free(func->func_aux);
    func->n_func_aux = 0;
  }

  if(func->mix_coef != NULL){
    free(func->mix_coef);
    func->mix_coef = NULL;
  }

  /* deallocate any used parameter */
  if(func->params != NULL){
    free(func->params);
    func->params = NULL;
  }

  func->info = NULL;  
}

/*------------------------------------------------------*/
DEVICE void  dvc_xc_func_free(xc_func_type *p)
{
  free(p);
}

/*------------------------------------------------------*/
DEVICE const xc_func_info_type *dvc_xc_func_get_info(const xc_func_type *p)
{
  return p->info;
}

/*------------------------------------------------------*/
DEVICE void dvc_xc_func_set_dens_threshold(xc_func_type *p, double dens_threshold)
{
  int ii;

  p->dens_threshold = dens_threshold;

  for(ii=0; ii<p->n_func_aux; ii++) {
    dvc_xc_func_set_dens_threshold(p->func_aux[ii], dens_threshold);
  }
}

/*------------------------------------------------------*/
DEVICE void dvc_xc_func_set_ext_params(xc_func_type *p, double *ext_params)
{
  assert(p->info->n_ext_params > 0);
  p->info->set_ext_params(p, ext_params);
}

/* returns the mixing coefficient for the hybrid GGAs */
DEVICE double dvc_xc_hyb_exx_coef(const xc_func_type *p)
{
  assert(p!=NULL);
 
  return p->cam_alpha;
}

/* returns the CAM parameters for screened hybrids */
DEVICE void dvc_xc_hyb_cam_coef(const xc_func_type *p, double *omega, double *alpha, double *beta)
{
  assert(p!=NULL);

  *omega = p->cam_omega;
  *alpha = p->cam_alpha;
  *beta  = p->cam_beta;
}

/* returns the NLC parameters */
DEVICE void dvc_xc_nlc_coef(const xc_func_type *p, double *nlc_b, double *nlc_C)
{
  assert(p!=NULL);

  *nlc_b = p->nlc_b;
  *nlc_C = p->nlc_C;
}
#pragma omp end declare target
