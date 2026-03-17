/*
 * Control_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Control".
 *
 * Model version              : 1.19
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Sun Mar 15 16:55:11 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef Control_types_h_
#define Control_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Control_T
#define typedef_cell_wrap_Control_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Control_T;

#endif                                 /* typedef_cell_wrap_Control_T */

#ifndef struct_tag_LU6hEStdhy5sLkAEq3dRqD
#define struct_tag_LU6hEStdhy5sLkAEq3dRqD

struct tag_LU6hEStdhy5sLkAEq3dRqD
{
  int32_T isInitialized;
  cell_wrap_Control_T inputVarSize[2];
  real_T MaxAngularVelocity;
  real_T LookaheadDistance;
  real_T DesiredLinearVelocity;
  real_T ProjectionPoint[2];
  real_T ProjectionLineIndex;
  real_T LookaheadPoint[2];
  real_T LastPose[3];
  real_T WaypointsInternal[440];
};

#endif                                 /* struct_tag_LU6hEStdhy5sLkAEq3dRqD */

#ifndef typedef_nav_slalgs_internal_PurePursu_T
#define typedef_nav_slalgs_internal_PurePursu_T

typedef struct tag_LU6hEStdhy5sLkAEq3dRqD nav_slalgs_internal_PurePursu_T;

#endif                             /* typedef_nav_slalgs_internal_PurePursu_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_Control_T RT_MODEL_Control_T;

#endif                                 /* Control_types_h_ */
