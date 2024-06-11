
/*
 * Filename: swc_joystick.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: SWC for reading/sending joystick data
 */

#ifndef _H_DEFINE_SWC_JOYSTICK
#define _H_DEFINE_SWC_JOYSTICK

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SWC_JOYSTICK_INCLUDES */

/* USER CODE END SWC_JOYSTICK_INCLUDES */



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
void JOYSTICK_joystick_rx_run(RTE_event ev);


#endif