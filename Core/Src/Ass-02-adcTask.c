/*
 * 	File Name:		Ass-02-adcTask.c
 *  Created on:		Apr 19, 2023
 *  Author: 		Sean Crocker
 *  Description:	Task that reads the user's input from the potentiometer to set the grind time.
 */

#include "Ass-02.h"

uint32_t adc_value = 0;			// Value from ADC conversion
extern enum State state;		// State of the system

/*
 * 	Function:	HAL_ADC_ConvCpltCallback
 * 	--------------------------------------------------------------------------------------------------------------------
 * 		@brief Callback function for complete ADC. After complete conversion the grind time is set using a linear
 * 		mapping function so that values can range from 50 to 150. The value is used to set the grind time from 5000 to
 * 		15000 milliseconds or 5 to 15 seconds. Time delay of tasks were taken into consideration.
 * 		@param hadc:		Pointer to ADC handler.
 * 		@retval: 			None
 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	adc_value = ((4096.0 - adc_value) * 100.0 / 4096.0) + 50.0;
}

/*
 * 	Function:	StartADCTask
 * 	--------------------------------------------------------------------------------------------------------------------
 * 		@brief Function implementing the ADC task/thread that runs a looping executive.
 * 		@param argument:	Not used
 * 		@retval: 			None
 */
void StartADCTask(void const * argument)
{
	while(1) {
		if (state == OFF) {					// If in the 'off' state, start the timer to trigger adc dma request
			HAL_TIM_Base_Start(&htim2);
			HAL_ADC_Start_DMA(&hadc1, &adc_value, 1);
		}
		osDelay(100);
	}
}
