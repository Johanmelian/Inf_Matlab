/*
 * Control.c
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

#include "Control.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "Control_private.h"
#include <emmintrin.h>
#include "rt_defines.h"

/* Block signals (default storage) */
B_Control_T Control_B;

/* Block states (default storage) */
DW_Control_T Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Control_T Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Control_T Control_Y;

/* Real-time model */
static RT_MODEL_Control_T Control_M_;
RT_MODEL_Control_T *const Control_M = &Control_M_;

/* Forward declaration for local functions */
static real_T Control_norm(const real_T x[2]);
static real_T Control_closestPointOnLine(const real_T pt1[2], real_T pt2[2],
  const real_T refPt[2]);
static real_T Control_norm(const real_T x[2])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;

  /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  y = scale * sqrt(y);

  /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
  if (rtIsNaN(y)) {
    int32_T b_k;
    b_k = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (b_k < 2) {
        if (rtIsNaN(x[b_k])) {
          exitg1 = 1;
        } else {
          b_k++;
        }
      } else {
        y = (rtInf);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return y;
}

static real_T Control_closestPointOnLine(const real_T pt1[2], real_T pt2[2],
  const real_T refPt[2])
{
  __m128d tmp;
  real_T refPt_0[2];
  real_T alpha;
  real_T distance;
  real_T v12;
  real_T v12_0;
  int32_T b_k;
  boolean_T exitg1;
  boolean_T p;
  boolean_T p_0;

  /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 2)) {
    if (!(pt1[b_k] == pt2[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (p) {
    pt2[0] = pt1[0];
    refPt_0[0] = refPt[0] - pt1[0];
    pt2[1] = pt1[1];
    refPt_0[1] = refPt[1] - pt1[1];
    distance = Control_norm(refPt_0);
  } else {
    alpha = pt2[0] - pt1[0];
    v12 = (pt2[0] - refPt[0]) * alpha;
    v12_0 = alpha * alpha;
    alpha = pt2[1] - pt1[1];
    alpha = ((pt2[1] - refPt[1]) * alpha + v12) / (alpha * alpha + v12_0);
    if (alpha > 1.0) {
      pt2[0] = pt1[0];
      pt2[1] = pt1[1];
    } else if (!(alpha < 0.0)) {
      tmp = _mm_set1_pd(alpha);
      tmp = _mm_add_pd(_mm_mul_pd(_mm_sub_pd(_mm_set1_pd(1.0), tmp),
        _mm_loadu_pd(&pt2[0])), _mm_mul_pd(tmp, _mm_loadu_pd(&pt1[0])));
      _mm_storeu_pd(&pt2[0], tmp);
    }

    tmp = _mm_sub_pd(_mm_loadu_pd(&refPt[0]), _mm_loadu_pd(&pt2[0]));
    _mm_storeu_pd(&refPt_0[0], tmp);
    distance = Control_norm(refPt_0);
  }

  /* End of Start for MATLABSystem: '<S1>/Pure Pursuit' */
  return distance;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Control_step(void)
{
  __m128d tmp_2;
  __m128d tmp_3;
  real_T lookaheadStartPt[2];
  real_T lookaheadStartPt_0[2];
  real_T tmp_0[2];
  real_T tmp_1[2];
  real_T lookaheadEndPt_idx_0;
  real_T lookaheadEndPt_idx_1;
  real_T lookaheadIdx;
  real_T minDistance;
  real_T rtb_Square;
  real_T rtb_Sum2;
  real_T tmp_4;
  int32_T b_i;
  int32_T b_k;
  int32_T tmp_5;
  int32_T tmp_size_idx_0;
  int32_T trueCount;
  uint8_T tmp_data[220];
  uint8_T rtb_Compare;
  boolean_T b[440];
  boolean_T tmp[220];
  boolean_T exitg1;
  boolean_T p;
  boolean_T searchFlag;

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S4>/Constant'
   *  Inport: '<Root>/fb'
   *  Math: '<S3>/Square'
   *  Math: '<S3>/Square1'
   *  Sqrt: '<S3>/Sqrt'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S3>/Sum1'
   *  Sum: '<S3>/Sum2'
   */
  rtb_Compare = (uint8_T)(sqrt((6.1 - Control_U.fb[0]) * (6.1 - Control_U.fb[0])
    + (12.8 - Control_U.fb[1]) * (12.8 - Control_U.fb[1])) >= 1.0);

  /* Sum: '<S2>/Sum2' incorporates:
   *  DataTypeConversion: '<S3>/Cast To Single'
   *  Inport: '<Root>/fb'
   *  Inport: '<Root>/spd_ref'
   *  Product: '<S3>/Product'
   */
  rtb_Sum2 = Control_U.spd_ref * (real_T)rtb_Compare - Control_U.fb[4];

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Control_B.DiscreteTimeIntegrator = Control_DW.DiscreteTimeIntegrator_DSTATE;

  /* MATLABSystem: '<S1>/Pure Pursuit' incorporates:
   *  Inport: '<Root>/pos_ref'
   */
  if (Control_DW.obj.DesiredLinearVelocity != 1.0) {
    Control_DW.obj.DesiredLinearVelocity = 1.0;
  }

  if (Control_DW.obj.MaxAngularVelocity != 1.0) {
    Control_DW.obj.MaxAngularVelocity = 1.0;
  }

  if (Control_DW.obj.LookaheadDistance != 6.0) {
    Control_DW.obj.LookaheadDistance = 6.0;
  }

  searchFlag = false;
  p = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 440)) {
    if ((Control_DW.obj.WaypointsInternal[b_k] == Control_U.pos_ref[b_k]) ||
        (rtIsNaN(Control_DW.obj.WaypointsInternal[b_k]) && rtIsNaN
         (Control_U.pos_ref[b_k]))) {
      b_k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (p) {
    searchFlag = true;
  }

  if (!searchFlag) {
    memcpy(&Control_DW.obj.WaypointsInternal[0], &Control_U.pos_ref[0], 440U *
           sizeof(real_T));
    Control_DW.obj.ProjectionLineIndex = 0.0;
  }

  for (trueCount = 0; trueCount < 440; trueCount++) {
    b[trueCount] = !rtIsNaN(Control_U.pos_ref[trueCount]);
  }

  trueCount = 0;

  /* MATLABSystem: '<S1>/Pure Pursuit' */
  for (b_k = 0; b_k < 220; b_k++) {
    searchFlag = (b[b_k] && b[b_k + 220]);
    tmp[b_k] = searchFlag;
    if (searchFlag) {
      trueCount++;
    }
  }

  tmp_size_idx_0 = trueCount;
  trueCount = 0;
  for (b_k = 0; b_k < 220; b_k++) {
    /* MATLABSystem: '<S1>/Pure Pursuit' */
    if (tmp[b_k]) {
      /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
      tmp_data[trueCount] = (uint8_T)b_k;
      trueCount++;
    }
  }

  /* MATLABSystem: '<S1>/Pure Pursuit' incorporates:
   *  Inport: '<Root>/fb'
   *  Inport: '<Root>/pos_ref'
   * */
  if (tmp_size_idx_0 == 0) {
    rtb_Square = 0.0;
  } else {
    searchFlag = false;
    if (Control_DW.obj.ProjectionLineIndex == 0.0) {
      searchFlag = true;
      Control_DW.obj.ProjectionPoint[0] = Control_U.pos_ref[tmp_data[0]];
      Control_DW.obj.ProjectionPoint[1] = Control_U.pos_ref[tmp_data[0] + 220];
      Control_DW.obj.ProjectionLineIndex = 1.0;
    }

    if (tmp_size_idx_0 == 1) {
      lookaheadEndPt_idx_0 = Control_U.pos_ref[tmp_data[0]];
      Control_DW.obj.ProjectionPoint[0] = lookaheadEndPt_idx_0;
      lookaheadEndPt_idx_1 = Control_U.pos_ref[tmp_data[0] + 220];
      Control_DW.obj.ProjectionPoint[1] = lookaheadEndPt_idx_1;
    } else {
      b_k = tmp_data[(int32_T)(Control_DW.obj.ProjectionLineIndex + 1.0) - 1];
      lookaheadStartPt[0] = Control_U.pos_ref[b_k];
      lookaheadStartPt[1] = Control_U.pos_ref[b_k + 220];
      minDistance = Control_closestPointOnLine(Control_DW.obj.ProjectionPoint,
        lookaheadStartPt, &Control_U.fb[0]);
      Control_DW.obj.ProjectionPoint[0] = lookaheadStartPt[0];
      lookaheadStartPt_0[0] = lookaheadStartPt[0] - Control_U.pos_ref[tmp_data
        [(int32_T)(Control_DW.obj.ProjectionLineIndex + 1.0) - 1]];
      Control_DW.obj.ProjectionPoint[1] = lookaheadStartPt[1];
      lookaheadStartPt_0[1] = lookaheadStartPt[1] - Control_U.pos_ref[tmp_data
        [(int32_T)(Control_DW.obj.ProjectionLineIndex + 1.0) - 1] + 220];
      rtb_Square = Control_norm(lookaheadStartPt_0);
      lookaheadIdx = Control_DW.obj.ProjectionLineIndex + 1.0;
      b_k = (int32_T)((1.0 - (Control_DW.obj.ProjectionLineIndex + 1.0)) +
                      ((real_T)tmp_size_idx_0 - 1.0)) - 1;
      b_i = 0;
      exitg1 = false;
      while ((!exitg1) && (b_i <= b_k)) {
        lookaheadEndPt_idx_0 = lookaheadIdx + (real_T)b_i;
        if ((!searchFlag) && (rtb_Square > Control_DW.obj.LookaheadDistance)) {
          exitg1 = true;
        } else {
          trueCount = tmp_data[(int32_T)(lookaheadEndPt_idx_0 + 1.0) - 1];
          lookaheadEndPt_idx_1 = Control_U.pos_ref[trueCount];
          tmp_5 = tmp_data[(int32_T)lookaheadEndPt_idx_0 - 1];
          tmp_4 = Control_U.pos_ref[tmp_5];
          lookaheadStartPt_0[0] = tmp_4 - lookaheadEndPt_idx_1;
          lookaheadStartPt[0] = lookaheadEndPt_idx_1;
          tmp_0[0] = tmp_4;
          lookaheadEndPt_idx_1 = Control_U.pos_ref[trueCount + 220];
          tmp_4 = Control_U.pos_ref[tmp_5 + 220];
          lookaheadStartPt_0[1] = tmp_4 - lookaheadEndPt_idx_1;
          lookaheadStartPt[1] = lookaheadEndPt_idx_1;
          tmp_0[1] = tmp_4;
          rtb_Square += Control_norm(lookaheadStartPt_0);
          lookaheadEndPt_idx_1 = Control_closestPointOnLine(tmp_0,
            lookaheadStartPt, &Control_U.fb[0]);
          if (lookaheadEndPt_idx_1 < minDistance) {
            minDistance = lookaheadEndPt_idx_1;
            Control_DW.obj.ProjectionPoint[0] = lookaheadStartPt[0];
            Control_DW.obj.ProjectionPoint[1] = lookaheadStartPt[1];
            Control_DW.obj.ProjectionLineIndex = lookaheadEndPt_idx_0;
          }

          b_i++;
        }
      }

      trueCount = tmp_data[(int32_T)(Control_DW.obj.ProjectionLineIndex + 1.0) -
        1];
      lookaheadEndPt_idx_0 = Control_U.pos_ref[trueCount];
      lookaheadEndPt_idx_1 = Control_U.pos_ref[trueCount + 220];
      tmp_3 = _mm_sub_pd(_mm_loadu_pd(&Control_DW.obj.ProjectionPoint[0]),
                         _mm_set_pd(lookaheadEndPt_idx_1, lookaheadEndPt_idx_0));
      _mm_storeu_pd(&lookaheadStartPt_0[0], tmp_3);
      rtb_Square = Control_norm(lookaheadStartPt_0);
      lookaheadStartPt[0] = Control_DW.obj.ProjectionPoint[0];
      lookaheadStartPt[1] = Control_DW.obj.ProjectionPoint[1];
      minDistance = rtb_Square - Control_DW.obj.LookaheadDistance;
      lookaheadIdx = Control_DW.obj.ProjectionLineIndex;
      while ((minDistance < 0.0) && (lookaheadIdx < (real_T)tmp_size_idx_0 - 1.0))
      {
        lookaheadIdx++;
        b_k = tmp_data[(int32_T)lookaheadIdx - 1];
        minDistance = Control_U.pos_ref[b_k];
        lookaheadStartPt[0] = minDistance;
        trueCount = tmp_data[(int32_T)(lookaheadIdx + 1.0) - 1];
        lookaheadEndPt_idx_0 = Control_U.pos_ref[trueCount];
        lookaheadStartPt_0[0] = minDistance - lookaheadEndPt_idx_0;
        minDistance = Control_U.pos_ref[b_k + 220];
        lookaheadStartPt[1] = minDistance;
        lookaheadEndPt_idx_1 = Control_U.pos_ref[trueCount + 220];
        lookaheadStartPt_0[1] = minDistance - lookaheadEndPt_idx_1;
        rtb_Square += Control_norm(lookaheadStartPt_0);
        minDistance = rtb_Square - Control_DW.obj.LookaheadDistance;
      }

      tmp_3 = _mm_set_pd(lookaheadEndPt_idx_1, lookaheadEndPt_idx_0);
      tmp_2 = _mm_sub_pd(_mm_loadu_pd(&lookaheadStartPt[0]), tmp_3);
      _mm_storeu_pd(&lookaheadStartPt_0[0], tmp_2);
      rtb_Square = minDistance / Control_norm(lookaheadStartPt_0);
      if (rtb_Square > 0.0) {
        tmp_2 = _mm_set1_pd(rtb_Square);
        tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_sub_pd(_mm_set1_pd(1.0), tmp_2), tmp_3),
                           _mm_mul_pd(tmp_2, _mm_loadu_pd(&lookaheadStartPt[0])));
        _mm_storeu_pd(&tmp_1[0], tmp_3);
        lookaheadEndPt_idx_0 = tmp_1[0];
        lookaheadEndPt_idx_1 = tmp_1[1];
      }
    }

    Control_DW.obj.LookaheadPoint[0] = lookaheadEndPt_idx_0;
    Control_DW.obj.LookaheadPoint[1] = lookaheadEndPt_idx_1;
    rtb_Square = rt_atan2d_snf(Control_DW.obj.LookaheadPoint[1] - Control_U.fb[1],
      Control_DW.obj.LookaheadPoint[0] - Control_U.fb[0]) - Control_U.fb[2];
    if (fabs(rtb_Square) > 3.1415926535897931) {
      if (rtIsNaN(rtb_Square + 3.1415926535897931) || rtIsInf(rtb_Square +
           3.1415926535897931)) {
        minDistance = (rtNaN);
      } else if (rtb_Square + 3.1415926535897931 == 0.0) {
        minDistance = 0.0;
      } else {
        minDistance = fmod(rtb_Square + 3.1415926535897931, 6.2831853071795862);
        searchFlag = (minDistance == 0.0);
        if (!searchFlag) {
          lookaheadIdx = fabs((rtb_Square + 3.1415926535897931) /
                              6.2831853071795862);
          searchFlag = !(fabs(lookaheadIdx - floor(lookaheadIdx + 0.5)) >
                         2.2204460492503131E-16 * lookaheadIdx);
        }

        if (searchFlag) {
          minDistance = 0.0;
        } else if (minDistance < 0.0) {
          minDistance += 6.2831853071795862;
        }
      }

      if ((minDistance == 0.0) && (rtb_Square + 3.1415926535897931 > 0.0)) {
        minDistance = 6.2831853071795862;
      }

      rtb_Square = minDistance - 3.1415926535897931;
    }

    Control_DW.obj.LastPose[0] = Control_U.fb[0];
    Control_DW.obj.LastPose[1] = Control_U.fb[1];
    Control_DW.obj.LastPose[2] = Control_U.fb[2];
    if (rtIsNaN(rtb_Square)) {
      rtb_Square = 0.0;
    }
  }

  /* Outport: '<Root>/u' incorporates:
   *  Gain: '<S2>/Gain'
   *  Inport: '<Root>/fb'
   *  MATLABSystem: '<S1>/Pure Pursuit'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S2>/Sum'
   */
  Control_Y.u[0] = 5.0 * rtb_Sum2 + Control_B.DiscreteTimeIntegrator;
  Control_Y.u[1] = rtb_Square - Control_U.fb[3];

  /* Gain: '<S2>/Gain1' */
  Control_B.Gain1 = 1.25 * rtb_Sum2;

  /* Logic: '<S3>/OR' incorporates:
   *  Clock: '<S3>/Clock'
   *  Constant: '<S5>/Constant'
   *  Logic: '<S3>/NOT'
   *  RelationalOperator: '<S5>/Compare'
   */
  Control_B.OR = ((rtb_Compare == 0) || (Control_M->Timing.t[0] >= 1000.0));

  /* Stop: '<S3>/Stop Simulation' */
  if (Control_B.OR) {
    rtmSetStopRequested(Control_M, 1);
  }

  /* End of Stop: '<S3>/Stop Simulation' */

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Control_DW.DiscreteTimeIntegrator_DSTATE += 200.0 * Control_B.Gain1;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Control_M->Timing.clockTick0)) {
    ++Control_M->Timing.clockTickH0;
  }

  Control_M->Timing.t[0] = Control_M->Timing.clockTick0 *
    Control_M->Timing.stepSize0 + Control_M->Timing.clockTickH0 *
    Control_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [200.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 200.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Control_M->Timing.clockTick1++;
    if (!Control_M->Timing.clockTick1) {
      Control_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void Control_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Control_M, 0,
                sizeof(RT_MODEL_Control_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Control_M->solverInfo, &Control_M->Timing.simTimeStep);
    rtsiSetTPtr(&Control_M->solverInfo, &rtmGetTPtr(Control_M));
    rtsiSetStepSizePtr(&Control_M->solverInfo, &Control_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Control_M->solverInfo, (&rtmGetErrorStatus(Control_M)));
    rtsiSetRTModelPtr(&Control_M->solverInfo, Control_M);
  }

  rtsiSetSimTimeStep(&Control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Control_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Control_M->solverInfo, false);
  rtsiSetSolverName(&Control_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Control_M, &Control_M->Timing.tArray[0]);
  Control_M->Timing.stepSize0 = 200.0;

  /* block I/O */
  (void) memset(((void *) &Control_B), 0,
                sizeof(B_Control_T));

  /* states (dwork) */
  (void) memset((void *)&Control_DW, 0,
                sizeof(DW_Control_T));

  /* external inputs */
  (void)memset(&Control_U, 0, sizeof(ExtU_Control_T));

  /* external outputs */
  (void)memset(&Control_Y, 0, sizeof(ExtY_Control_T));

  {
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    Control_DW.DiscreteTimeIntegrator_DSTATE = 0.0;

    /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
    Control_DW.objisempty = true;
    Control_DW.obj.DesiredLinearVelocity = 1.0;
    Control_DW.obj.MaxAngularVelocity = 1.0;
    Control_DW.obj.LookaheadDistance = 6.0;
    Control_DW.obj.isInitialized = 1;
    for (i = 0; i < 440; i++) {
      Control_DW.obj.WaypointsInternal[i] = (rtNaN);
    }

    /* InitializeConditions for MATLABSystem: '<S1>/Pure Pursuit' */
    Control_DW.obj.LookaheadPoint[0] = 0.0;
    Control_DW.obj.LookaheadPoint[1] = 0.0;
    Control_DW.obj.LastPose[0] = 0.0;
    Control_DW.obj.LastPose[1] = 0.0;
    Control_DW.obj.LastPose[2] = 0.0;
    Control_DW.obj.ProjectionPoint[0] = (rtNaN);
    Control_DW.obj.ProjectionPoint[1] = (rtNaN);
    Control_DW.obj.ProjectionLineIndex = 0.0;
  }
}

/* Model terminate function */
void Control_terminate(void)
{
  /* (no terminate code required) */
}
