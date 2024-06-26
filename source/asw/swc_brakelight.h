
/*
 * Filename: swc_brakelight.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: SWC for brakelight
 */

#ifndef _H_DEFINE_SWC_BRAKELIGHT
#define _H_DEFINE_SWC_BRAKELIGHT

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SWC_BRAKELIGHT_INCLUDES */
#include "watchdog.h"
/* USER CODE END SWC_BRAKELIGHT_INCLUDES */



/* USER CODE START SWC_BRAKELIGHT_USERDEFINITIONS */

/* USER CODE END SWC_BRAKELIGHT_USERDEFINITIONS */


/*
 * component: swc_brakelight
 * cycletime: 0
 * description: Runnable to set brakelight if speed signal is 0
 * events: ev_on_speed_update
 * name: BRAKELIGHT_set_brakelight_run
 * shortname: set_brakelight
 * signalIN: so_speed
 * signalOUT: so_brakelight
 * task: tsk_io
 */
void BRAKELIGHT_set_brakelight_run(RTE_event ev);


#endif