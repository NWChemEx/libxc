/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/gga_x_vmt.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_vmt_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
  double t1, t2, t5, t7, t8, t9, t15, t16;
  double t17, t18, t21, t22, t23, t24, t25, t36;
  double t38, t39, t40, t44, t47, t50, t51, t70;
  double t85, t87;

  gga_x_vmt_params *params;
 
  assert(p->params != NULL);
  params = (gga_x_vmt_params * )(p->params);

  t1 = r->x * r->x;
  t2 = params->mu * t1;
  t5 = exp(-0.16455307846020557507e-1 * params->alpha * t1);
  t7 = 0.10e1 + 0.16455307846020557507e-1 * t2;
  t8 = 0.1e1 / t7;
  t9 = t5 * t8;
  r->f = 0.10e1 + 0.16455307846020557507e-1 * t2 * t9;

  if(r->order < 1) return;

  t15 = t1 * r->x;
  t16 = params->mu * t15;
  t17 = params->alpha * t5;
  t18 = t17 * t8;
  t21 = params->mu * params->mu;
  t22 = t21 * t15;
  t23 = t7 * t7;
  t24 = 0.1e1 / t23;
  t25 = t5 * t24;
  r->dfdx = 0.32910615692041115014e-1 * params->mu * r->x * t9 - 0.54155431261461143986e-3 * t16 * t18 - 0.54155431261461143986e-3 * t22 * t25;

  if(r->order < 2) return;

  t36 = t1 * t1;
  t38 = params->alpha * params->alpha;
  t39 = t38 * t5;
  t40 = t39 * t8;
  t44 = t17 * t24;
  t47 = t21 * params->mu;
  t50 = 0.1e1 / t23 / t7;
  t51 = t5 * t50;
  r->d2fdx2 = 0.32910615692041115014e-1 * params->mu * t5 * t8 - 0.27077715630730571993e-2 * t2 * t18 - 0.27077715630730571993e-2 * t21 * t1 * t25 + 0.17822885858826970814e-4 * params->mu * t36 * t40 + 0.35645771717653941628e-4 * t21 * t36 * t44 + 0.35645771717653941629e-4 * t47 * t36 * t51;

  if(r->order < 3) return;

  t70 = t36 * r->x;
  t85 = t21 * t21;
  t87 = t23 * t23;
  r->d3fdx3 = -0.64986517513753372783e-2 * params->mu * params->alpha * r->x * t5 * t8 - 0.64986517513753372783e-2 * t21 * t5 * t24 * r->x + 0.16040597272944273733e-3 * t16 * t40 + 0.32081194545888547465e-3 * t22 * t44 + 0.32081194545888547466e-3 * t47 * t15 * t51 - 0.58656214702296859059e-6 * params->mu * t70 * t38 * params->alpha * t5 * t8 - 0.17596864410689057718e-5 * t21 * t70 * t39 * t24 - 0.35193728821378115435e-5 * t47 * t70 * t17 * t50 - 0.35193728821378115436e-5 * t85 * t70 * t5 / t87;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_vmt_enhance)
