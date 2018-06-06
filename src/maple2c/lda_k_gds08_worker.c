/* 
  This file was generated automatically with ./scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : .//maple/lda_k_gds08_worker.mpl
  Type of functional: work_lda
*/

static void
func0(const xc_func_type *p, xc_lda_work_t *r)
{
  double t2, t4, t7, t9, t11, t14, t17;

  lda_k_gds08_params *params;

  assert(p->params != NULL);
  params = (lda_k_gds08_params * )(p->params);

  t2 = r->rs * r->rs;
  t4 = 0.1e1 / t2 / r->rs;
  t7 = log(0.3e1 / 0.4e1 / 0.31415926535897932385e1 * t4);
  t9 = t7 * t7;
  r->f = params->B * t7 + params->C * t9 + params->A;

  if(r->order < 1) return;

  t11 = 0.1e1 / r->rs;
  t14 = params->C * t7;
  r->dfdrs = -0.6e1 * t14 * t11 - 0.3e1 * params->B * t11;

  if(r->order < 2) return;

  t17 = 0.1e1 / t2;
  r->d2fdrs2 = 0.6e1 * t14 * t17 + 0.3e1 * params->B * t17 + 0.18e2 * params->C * t17;

  if(r->order < 3) return;

  r->d3fdrs3 = -0.12e2 * t14 * t4 - 0.6e1 * params->B * t4 - 0.54e2 * params->C * t4;

  if(r->order < 4) return;


}

static void
func1(const xc_func_type *p, xc_lda_work_t *r)
{
  double t2, t4, t7, t9, t11, t14, t17;

  lda_k_gds08_params *params;

  assert(p->params != NULL);
  params = (lda_k_gds08_params * )(p->params);

  t2 = r->rs * r->rs;
  t4 = 0.1e1 / t2 / r->rs;
  t7 = log(0.3e1 / 0.4e1 / 0.31415926535897932385e1 * t4);
  t9 = t7 * t7;
  r->f = t7 * params->B + t9 * params->C + params->A;

  if(r->order < 1) return;

  t11 = 0.1e1 / r->rs;
  t14 = params->C * t7;
  r->dfdrs = -0.6e1 * t11 * t14 - 0.3e1 * t11 * params->B;
  r->dfdz = 0.0e0;

  if(r->order < 2) return;

  t17 = 0.1e1 / t2;
  r->d2fdrs2 = 0.6e1 * t14 * t17 + 0.3e1 * params->B * t17 + 0.18e2 * params->C * t17;
  r->d2fdrsz = 0.0e0;
  r->d2fdz2 = 0.0e0;

  if(r->order < 3) return;

  r->d3fdrs3 = -0.12e2 * t14 * t4 - 0.6e1 * params->B * t4 - 0.54e2 * params->C * t4;
  r->d3fdrs2z = 0.0e0;
  r->d3fdrsz2 = 0.0e0;
  r->d3fdz3 = 0.0e0;

  if(r->order < 4) return;


}

void 
xc_lda_k_gds08_worker_func(const xc_func_type *p, xc_lda_work_t *r)
{
  if(p->nspin == XC_UNPOLARIZED)
    func0(p, r);
  else
    func1(p, r);
}

#define maple2c_order 3
#define maple2c_func  xc_lda_k_gds08_worker_func