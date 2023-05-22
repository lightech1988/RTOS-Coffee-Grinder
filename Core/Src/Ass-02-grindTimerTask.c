/*
 * 	File Name:		Ass-02-grindTimerTask.c
 *  Created on:		Apr 19, 2023
 *  Author: 		Sean Crocker
 *  Description:	Keeps track of the total grinding duration taking the pause state into consideration.
 */

#include "Ass-02.h"

extern uint32_t adc_value;		// Value from ADC conversion
extern enum State state;		// State of the system

/*
 * 	Function:	StartGrindTimerTask
 * 	--------------------------------------------------------------------------------------------------------------------
 * 		@brief Function implementing the grind task/thread that runs a looping executive.
 * 		@param argument: 	Not used
 * 		@retval: 			None
 */
void StartGrindTimerTask(void const * argument)
{
	uint32_t current_grind_time = 0;					// The current grind time
	while(1) {
		switch (state) {
			case OFF:
				current_grind_time = 0;					// Reset the current time in 'off' state
				break;
			case GRINDING:
				if(current_grind_time >= adc_value)		// Send 'off' state message to queue if time exceeds grind time
					osMessagePut(messageQueueHandle, OFF, osWaitForever);
				else									// If time does not exceed, increment it
					current_grind_time++;
				break;
			case PAUSED:
				break;
		}
	osDelay(100);
	}
}
