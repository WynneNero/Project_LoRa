
#include "vt100.h"

/* Structure for diagnostic information */
typedef struct
{
    struct
    {
        IfxCcu6_PwmBc pwmBc;    /* PWMBC interface */
    }      drivers;

    uint32 speed;               /* to store value of the speed */
} App_Ccu6PwmBc;

/* If you do not care where variables end up, declare them here! */

App_Ccu6PwmBc g_Ccu6PwmBc; /* Structure of demo information */

/* Motor control table */
uint8 controlTable[6][3] = {{1, 5, 17},
                            {2, 3, 36},
                            {3, 1, 6 },
                            {4, 6, 18},
                            {5, 4, 24},
                            {6, 2, 9 }};


/* Hall Sensor Interrupt Function Prototype */
void ccu6_ISR_PwmBc(void);


/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	SerialASC.begin(9600);

	/* Assume that a VT100-compatible terminal is being used */
	SerialASC.print(VT100_CURSOR_OFF);
	SerialASC.print(VT100_CLR_SCREEN);

	/* Initialise CCU for 3phase brushless drives */
    /* disable interrupts */
    boolean              interruptState = IfxCpu_disableInterrupts();

    /* create configuration */
    IfxCcu6_PwmBc_Config pwmBcConfig;
    IfxCcu6_PwmBc_initModuleConfig(&pwmBcConfig, &MODULE_CCU60);

    /* configure the frequencies of both the timers */
    pwmBcConfig.base.t12Frequency = 400000;
    pwmBcConfig.base.t13Frequency = 400000;

    /* configure the periods of both the timers */
    pwmBcConfig.base.t12Period = 100;
    pwmBcConfig.base.t13Period = 100;

    /* configure the phase delay and noise filter for hall input */
    pwmBcConfig.base.phaseDelay  = 20;
    pwmBcConfig.base.noiseFilter = 10;

    /* select the active state of the output */
    pwmBcConfig.base.activeState = Ifx_ActiveState_high;

    /* configure timer12 */
    pwmBcConfig.timer12.countMode    = IfxCcu6_T12CountMode_edgeAligned;
    pwmBcConfig.timer12.counterValue = 0;

    /* configure timer13 */
    pwmBcConfig.timer13.counterValue = 0;
    pwmBcConfig.timer13.compareValue = 100;

    /* configure hall sync event that starts the hall input pattern evaluation */
    pwmBcConfig.hallSyncEvent = IfxCcu6_HallSensorTriggerMode_t13PM;

    /* configure multi channel control */
    pwmBcConfig.multiChannelControl.switchingSelect = IfxCcu6_MultiChannelSwitchingSelect_t12Channel1CompareMatch;
    pwmBcConfig.multiChannelControl.switchingSync   = IfxCcu6_MultiChannelSwitchingSync_t13ZeroMatch;

    /* pin configuration */
    IfxCcu6_PwmBc_Pins pins = {
        &IfxCcu60_CC60_P02_0_OUT,              /* CC60Out pin */
        &IfxCcu60_CC61_P02_7_OUT,              /* CC61Out pin IfxCcu60_CC61_P02_2_OUT */
        &IfxCcu60_CC62_P02_4_OUT,              /* CC62Out pin */
        &IfxCcu60_COUT60_P02_1_OUT,            /* COUT60 pin */
        &IfxCcu60_COUT61_P02_3_OUT,            /* COUT61 pin */
        &IfxCcu60_COUT62_P02_5_OUT,            /* COUT62 pin */
        NULL_PTR,                              /* COUT63 pin not used */

        &IfxCcu60_CCPOS0A_P02_6_IN,            /* CCPOS0In pin IfxCcu60_CCPOS0A_P02_6_IN */
        &IfxCcu60_CCPOS1C_P10_7_IN,            /* CCPOS1In pin IfxCcu60_CCPOS1A_P02_7_IN */
        &IfxCcu60_CCPOS2A_P02_8_IN,            /* CCPOS2In pin IfxCcu60_CCPOS2A_P02_8_IN */

        IfxPort_OutputMode_pushPull,
        IfxPort_PadDriver_cmosAutomotiveSpeed1,
        IfxPort_InputMode_pullUp,

        NULL_PTR,
        NULL_PTR,
        IfxPort_InputMode_pullUp
    };
    pwmBcConfig.pins = &pins;

    /* configure the interrupts */
    pwmBcConfig.interrupt1.source = IfxCcu6_InterruptSource_cc61FallingEdge;
    pwmBcConfig.interrupt1.serviceRequest = IfxCcu6_ServiceRequest_2;
    pwmBcConfig.interrupt1.priority       = ISR_PRIORITY_CCU6_PWMBC;
    pwmBcConfig.interrupt1.typeOfService  = IfxSrc_Tos_cpu0;

    /* configure input and output triggers */
    pwmBcConfig.trigger.t12ExtInputTrigger   = NULL_PTR;
    pwmBcConfig.trigger.t13ExtInputTrigger   = NULL_PTR;
    pwmBcConfig.trigger.t13InSyncWithT12     = FALSE;

    pwmBcConfig.trigger.outputTriggerEnabled = TRUE;
    pwmBcConfig.trigger.outputLine           = IfxCcu6_TrigOut_0;
    pwmBcConfig.trigger.outputTrigger        = IfxCcu6_TrigSel_cout63;

    /* initialize the module */
    IfxCcu6_PwmBc_initModule(&g_Ccu6PwmBc.drivers.pwmBc, &pwmBcConfig);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

	/* Start the 3phase brushless driver */
    IfxCcu6_PwmBc_start(&g_Ccu6PwmBc.drivers.pwmBc);

}

/* Hall Sensor Interrupt Function */
void ccu6_ISR_PwmBc(void)
{
    IfxCpu_enableInterrupts();

    IfxCcu6_clearInterruptStatusFlag(&MODULE_CCU60, IfxCcu6_InterruptSource_cc61FallingEdge);

    IfxCcu6_PwmBc_updateHallPattern(&g_Ccu6PwmBc.drivers.pwmBc, controlTable);

    /* get the current motor speed */
    g_Ccu6PwmBc.speed = IfxCcu6_PwmBc_getMotorSpeed(&g_Ccu6PwmBc.drivers.pwmBc);
}

void loop() {
  // put your main code for core 0 here, to run repeatedly:



}


/*** Core 1 ***/

/* CPU1 Uninitialised Data */
StartOfUninitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have no initial values here e.g. uint32 CPU1_var; */
EndOfUninitialised_CPU1_Variables

/* CPU1 Initialised Data */
StartOfInitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have an initial value here e.g. uint32 CPU1_var_init = 1; */
EndOfInitialised_CPU1_Variables

void setup1() {
  // put your setup code for core 1 here, to run once:


}


void loop1() {
  // put your main code for core 1 here, to run repeatedly:

	SerialASC.print(VT100_CURSOR_HOME);
	SerialASC.print("T12 Frequency = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.base.t12Frequency);SerialASC.print("Hz\n\r");
	SerialASC.print("T13 Frequency = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.base.t13Frequency);SerialASC.print("Hz\n\r");
	SerialASC.print("T13 Period    = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.base.t12Period);SerialASC.print("\n\r");
	SerialASC.print("T13 Period    = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.base.t13Period);SerialASC.print("\n\r");

	SerialASC.print("Hall pattern  = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.hallPatternIndex);SerialASC.print("\n\r");
}



/*** Core 2 ***/

/* CPU2 Uninitialised Data */
StartOfUninitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have no initial values here e.g. uint32 CPU2_var; */
EndOfUninitialised_CPU2_Variables

/* CPU2 Initialised Data */
StartOfInitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have an initial value here e.g. uint32 CPU2_var_init = 1; */
EndOfInitialised_CPU2_Variables


void setup2() {
  // put your setup code for core 2 here, to run once:


}


void loop2() {
  // put your main code for core 2 here, to run repeatedly:


}



