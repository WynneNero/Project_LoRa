#include "Ifx_Types.h"
#include "IfxCpu_Intrinsics.h"
#include "Ifx_reg.h"
#include <Port/Io/IfxPort_Io.h>
#include <Vadc/Adc/IfxVadc_Adc.h>

#include "Test_Time.h"

// VADC handle
IfxVadc_Adc vadc;

// create configuration
IfxVadc_Adc_Config adcConfig;
//IfxVadc_Adc_initModuleConfig(&adcConfig, &MODULE_VADC);

// initialize module
// IfxVadc_Adc vadc; // declared globally
//IfxVadc_Adc_initModule(&vadc, &adcConfig);

// create group config
IfxVadc_Adc_GroupConfig adcGroupConfig;
//IfxVadc_Adc_initGroupConfig(&adcGroupConfig, &vadc);


Ifx_VADC_RES conversionResult;
static uint32 actual;
uint8 error = 0;

int core0_main (void)
{

    IfxVadc_Adc_initModuleConfig(&adcConfig, &MODULE_VADC);
    IfxVadc_Adc_initModule(&vadc, &adcConfig);
    IfxVadc_Adc_initGroupConfig(&adcGroupConfig, &vadc);


    // change group (default is GroupId_0, change to GroupId_3)
    adcGroupConfig.groupId = IfxVadc_GroupId_1;
    // IMPORTANT: usually we use the same group as master!
    adcGroupConfig.master = adcGroupConfig.groupId;
    // enable all arbiter request sources
    adcGroupConfig.arbiter.requestSlotQueueEnabled          = TRUE; // enable Queue mode
    adcGroupConfig.arbiter.requestSlotScanEnabled           = TRUE; // enable Scan mode
    adcGroupConfig.arbiter.requestSlotBackgroundScanEnabled = TRUE; // enable Background scan
    // enable all gates in "always" mode (no edge detection)
    adcGroupConfig.queueRequest.triggerConfig.gatingMode          = IfxVadc_GatingMode_always;
    adcGroupConfig.scanRequest.triggerConfig.gatingMode           = IfxVadc_GatingMode_always;
    adcGroupConfig.backgroundScanRequest.triggerConfig.gatingMode = IfxVadc_GatingMode_always;

    adcGroupConfig.groupId = IfxVadc_GroupId_0;
    adcGroupConfig.master = adcGroupConfig.groupId;
    adcGroupConfig.backgroundScanRequest.autoBackgroundScanEnabled = TRUE;
    adcGroupConfig.backgroundScanRequest.triggerConfig.gatingMode  = IfxVadc_GatingMode_always;
    adcGroupConfig.arbiter.requestSlotBackgroundScanEnabled        = TRUE;

    // initialize the group
    IfxVadc_Adc_Group adcGroup;
    IfxVadc_Adc_initGroup(&adcGroup, &adcGroupConfig);

    // IMPORTANT: for deterministic results we have to disable the queue gate
    // while filling the queue, otherwise results could be output in the wrong order
    unsigned savedGate = adcGroup.module.vadc->G[adcGroup.groupId].QMR0.B.ENGT;
    adcGroup.module.vadc->G[adcGroup.groupId].QMR0.B.ENGT = 0;


    IfxCpu_enableInterrupts();


    // create channel config
    IfxVadc_Adc_ChannelConfig adcChannelConfig;
    IfxVadc_Adc_Channel adcChannel;


    IfxVadc_Adc_initChannelConfig(&adcChannelConfig, &adcGroup);
    adcChannelConfig.channelId = IfxVadc_ChannelId_4;
    adcChannelConfig.resultRegister = IfxVadc_ChannelResult_1; // use result register #1 for all channels
    // initialize the channel
    IfxVadc_Adc_initChannel(&adcChannel, &adcChannelConfig);
    // Add channel to queue with refill enabled
    IfxVadc_Adc_addToQueue(&adcChannel, IFXVADC_QUEUE_REFILL);
    // restore previous gate config
    adcGroup.module.vadc->G[adcGroup.groupId].QMR0.B.ENGT = savedGate;
    // start the Queue
    IfxVadc_Adc_startQueue(&adcGroup); // just for the case that somebody copy&pastes the code - the queue has already been started in previous test
    // get 10 results for all 3 channels and store in temporary buffer
    // (the usage of a buffer is required, since the print statements used by the checks take more time than the conversions)
    while(1)
    {
    	do {
    	    conversionResult = IfxVadc_Adc_getResult(&adcChannel);
    	    actual = conversionResult.B.RESULT;
    	    if(actual> 5000)
    	    {
    	    	error = 0x01;
    	    }
    	} while( !conversionResult.B.VF );
    }
    IfxVadc_Adc_clearQueue(&adcGroup);



    while(1)
	{
    	;
	}
    return (0);
}


