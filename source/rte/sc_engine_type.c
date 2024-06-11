/*
 * Filename: sc_engine_type.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Signalclass representing engine
 * name: sc_engine
 * shortname: engine
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "sc_engine_type.h"



/* USER CODE START SC_ENGINE_INCLUDE */

/* USER CODE END SC_ENGINE_INCLUDE */




/* USER CODE START SC_ENGINE_USERDEFINITIONS */

/* USER CODE END SC_ENGINE_USERDEFINITIONS */


/*****************************************************************************************
 *************** Port Wrapper Implementation for SC_ENGINE signal  ****************
 *****************************************************************************************/
 
 
/**
 * Default OUT driver API
 */
inline RC_t SC_ENGINE_driverOut(const SC_ENGINE_data_t  *const data)
{
	/* USER CODE START driverOutSC_ENGINE */

	//Scale application data to drive format

	//Write scaled data to driver
    if(data->engine_value <= 0)
    {
        RGB_PWM_green_WriteCompare(0);
    }
    else
    {
        RGB_PWM_green_WriteCompare(data->engine_value);
    }

	return RC_SUCCESS;
	/* USER CODE END driverOutSC_ENGINE */
}


