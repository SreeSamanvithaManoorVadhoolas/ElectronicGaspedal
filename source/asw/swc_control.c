/*
 * Filename: swc_control.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: SWC for setting speed value
 * name: swc_control
 * shortname: control
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "swc_control.h"



/* USER CODE START SWC_CONTROL_INCLUDE */
#include "stdio.h"
#include "stdlib.h"
/* USER CODE END SWC_CONTROL_INCLUDE */


#include "sp_common.h"

/* USER CODE START SWC_CONTROL_USERDEFINITIONS */

/* USER CODE END SWC_CONTROL_USERDEFINITIONS */



/*
 * component: swc_control
 * cycletime: 0
 * description: Runnable to update speed signal on basis of incoming joystick signal
 * events: ev_on_joystick_update
 * name: CONTROL_calcControl_run
 * shortname: calcControl
 * signalIN: so_joystick
 * signalOUT: so_speed
 * task: tsk_control
 */
void CONTROL_calcControl_run(RTE_event ev){
	
	/* USER CODE START CONTROL_calcControl_run */
    sint8_t joystick_x = 0;
    sint8_t joystick_y = 0;
    SC_SPEED_data_t speed = SC_SPEED_INIT_DATA;
    
    if(RTE_SC_JOYSTICK_getStatus(&SO_JOYSTICK_signal) == RTE_SIGNALSTATUS_VALID)
    {
        joystick_x = RTE_SC_JOYSTICK_get(&SO_JOYSTICK_signal).x;
        joystick_y = RTE_SC_JOYSTICK_get(&SO_JOYSTICK_signal).y;
    }
    if(joystick_y > 0)
    {
        speed.speed_value = 2 * joystick_y;
    }
    else if(joystick_y <= 0)
    {
        speed.speed_value = 0;
    }
    RTE_SC_SPEED_set(&SO_SPEED_signal, speed);
    WD_Alive(control_run);
    /* USER CODE END CONTROL_calcControl_run */
}

/* USER CODE START SWC_CONTROL_FUNCTIONS */

/* USER CODE END SWC_CONTROL_FUNCTIONS */
