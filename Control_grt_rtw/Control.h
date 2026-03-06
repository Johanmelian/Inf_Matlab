/*
 * Control.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Control".
 *
 * Model version              : 1.4
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Sat Feb 28 13:38:30 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef Control_h_
#define Control_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Control_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
struct B_Control_T {
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Gain1;                        /* '<S1>/Gain1' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_Control_T {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_Control_T {
  real_T ref;                          /* '<Root>/In1' */
  real_T fb;                           /* '<Root>/In2' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_Control_T {
  real_T Out1;                         /* '<Root>/Out1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Control_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Class declaration for model Control */
class Control final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  Control(Control const&) = delete;

  /* Assignment Operator */
  Control& operator= (Control const&) & = delete;

  /* Move Constructor */
  Control(Control &&) = delete;

  /* Move Assignment Operator */
  Control& operator= (Control &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_Control_T * getRTM();

  /* Root inports set method */
  void setExternalInputs(const ExtU_Control_T *pExtU_Control_T)
  {
    Control_U = *pExtU_Control_T;
  }

  /* Root outports get method */
  const ExtY_Control_T &getExternalOutputs() const
  {
    return Control_Y;
  }

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  Control();

  /* Destructor */
  ~Control();

  /* private data and function members */
 private:
  /* External inputs */
  ExtU_Control_T Control_U;

  /* External outputs */
  ExtY_Control_T Control_Y;

  /* Block signals */
  B_Control_T Control_B;

  /* Block states */
  DW_Control_T Control_DW;

  /* Real-Time Model */
  RT_MODEL_Control_T Control_M;
};

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
 * hilite_system('Simulink_v1/Control')    - opens subsystem Simulink_v1/Control
 * hilite_system('Simulink_v1/Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Simulink_v1'
 * '<S1>'   : 'Simulink_v1/Control'
 */
#endif                                 /* Control_h_ */
