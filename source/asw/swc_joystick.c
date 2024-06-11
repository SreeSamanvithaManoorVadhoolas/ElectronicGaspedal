/*
 * Filename: swc_joystick.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: SWC for reading/sending joystick data
 * name: swc_joystick
 * shortname: joystick
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "swc_joystick.h"



/* USER CODE START SWC_JOYSTICK_INCLUDE */

/* USER CODE END SWC_JOYSTICK_INCLUDE */


#include "sp_common.h"

/* USER CODE START SWC_JOYSTICK_USERDEFINITIONS */

/* USER CODE END SWC_JOYSTICK_USERDEFINITIONS */



/*
 * component: swc_joystick
 * cycletime: 10
 * description: Runnable to update joystick signal through pullPort()
 * events: 
 * name: JOYSTICK_joystick_rx_run
 * shortname: joystick_rx
 * signalIN: 
 * signalOUT: so_joystick
 * task: tsk_io
 */
void JOYSTICK_joystick_rx_run(RTE_event ev){
	
	/* USER CODE START JOYSTICK_joystick_rx_run */
    
    RTE_SC_JOYSTICK_pullPort(&SO_JOYSTICK_signal);
    WD_Alive(joystick_run);
    /* USER CODE END JOYSTICK_joystick_rx_run */
}

/* USER CODE START SWC_JOYSTICK_FUNCTIONS */

/* USER CODE END SWC_JOYSTICK_FUNCTIONS */

