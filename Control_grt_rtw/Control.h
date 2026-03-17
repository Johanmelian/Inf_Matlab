/*
 * Control.h
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

#ifndef Control_h_
#define Control_h_
#ifndef Control_COMMON_INCLUDES_
#define Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Control_COMMON_INCLUDES_ */

#include "Control_types.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T DiscreteTimeIntegrator;       /* '<S2>/Discrete-Time Integrator' */
  real_T Gain1;                        /* '<S2>/Gain1' */
  boolean_T OR;                        /* '<S3>/OR' */
} B_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  nav_slalgs_internal_PurePursu_T obj; /* '<S1>/Pure Pursuit' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  boolean_T objisempty;                /* '<S1>/Pure Pursuit' */
} DW_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T spd_ref;                      /* '<Root>/spd_ref' */
  real_T pos_ref[440];                 /* '<Root>/pos_ref' */
  real_T fb[5];                        /* '<Root>/fb' */
} ExtU_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T u[2];                         /* '<Root>/u' */
} ExtY_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_Control_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Control_T Control_B;

/* Block states (default storage) */
extern DW_Control_T Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Control_T Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Control_T Control_Y;

/* Model entry point functions */
extern void Control_initialize(void);
extern void Control_step(void);
extern void Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Control_T *const Control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Ackerman_simulation/Control')    - opens subsystem Ackerman_simulation/Control
 * hilite_system('Ackerman_simulation/Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Ackerman_simulation'
 * '<S1>'   : 'Ackerman_simulation/Control'
 * '<S2>'   : 'Ackerman_simulation/Control/PID spd'
 * '<S3>'   : 'Ackerman_simulation/Control/spd ref '
 * '<S4>'   : 'Ackerman_simulation/Control/spd ref /Compare To Constant'
 * '<S5>'   : 'Ackerman_simulation/Control/spd ref /Compare To Constant1'
 */
#endif                                 /* Control_h_ */
