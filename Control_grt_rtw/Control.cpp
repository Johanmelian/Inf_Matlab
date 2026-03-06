/*
 * Control.cpp
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

#include "Control.h"
#include "rtwtypes.h"

static void rate_scheduler(RT_MODEL_Control_T *const Control_M);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(RT_MODEL_Control_T *const Control_M)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Control_M->Timing.TaskCounters.TID[1])++;
  if ((Control_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    Control_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void Control::step()
{
  real_T rtb_e;

  /* Outputs for Atomic SubSystem: '<Root>/Control' */
  if ((&Control_M)->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S1>/Sum' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<Root>/In2'
     */
    rtb_e = Control_U.ref - Control_U.fb;

    /* Gain: '<S1>/Gain' */
    Control_B.Gain = 27.0 * rtb_e;

    /* Gain: '<S1>/Gain1' */
    Control_B.Gain1 = 5.0 * rtb_e;
  }

  /* Outport: '<Root>/Out1' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Sum: '<S1>/Sum1'
   */
  Control_Y.Out1 = Control_B.Gain + Control_DW.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Control_DW.DiscreteTimeIntegrator_DSTATE += 0.001 * Control_B.Gain1;

  /* End of Outputs for SubSystem: '<Root>/Control' */
  rate_scheduler((&Control_M));
}

/* Model initialize function */
void Control::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Control::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Control::Control() :
  Control_U(),
  Control_Y(),
  Control_B(),
  Control_DW(),
  Control_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
Control::~Control() = default;

/* Real-Time Model get method */
RT_MODEL_Control_T * Control::getRTM()
{
  return (&Control_M);
}
