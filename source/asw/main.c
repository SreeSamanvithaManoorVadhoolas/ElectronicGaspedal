/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "global.h"
#include "joystick.h"
#include "watchdog.h"


//ISR which will increment the systick counter every ms
ISR(systick_handler)
{
    CounterTick(cnt_systick);
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
   
    // Start Operating System
    for(;;)	    
    	StartOS(OSDEFAULTAPPMODE);
}

void unhandledException()
{
    //Ooops, something terrible happened....check the call stack to see how we got here...
    __asm("bkpt");
}

/********************************************************************************
 * Task Definitions
 ********************************************************************************/

TASK(tsk_init)
{
    
    WD_Start(ticks_2_3s);
    
    //Init MCAL Drivers
    CyGlobalIntDisable;
    JOYSTICK_Init();
    UART_LOG_Start();
    PWM_Clock_Start();
    RGB_PWM_green_Start();
    CyGlobalIntEnable;
    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
    
    if(WD_CheckResetBit())
    {
        UART_LOG_PutString("Reset through Watchdog \n");
    }
    else
    {
        UART_LOG_PutString("Reset through Power \n");
    }
        
	
    //Start the alarm with 1ms cycle time
    SetRelAlarm(alrm_1ms,1,1);
    SetRelAlarm(alrm_system,1,1);
    
    //Task activation
    ActivateTask(tsk_io);
    ActivateTask(tsk_control);
    ActivateTask(tsk_system);
    ActivateTask(tsk_background);
    
    TerminateTask();
    
}


TASK(tsk_background)
{
    while(1)
    {
        //do something with low prioroty
        WD_Trigger();
    }
}


/********************************************************************************
 * ISR Definitions
 ********************************************************************************/
ISR(isr_button)
{
    if(BUTTON_Read() == 1)
    {
        ShutdownOS(0);
    }
}
/* [] END OF FILE */
