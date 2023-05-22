/*
 * 	File Name:		Ass-02-pauseTimer.c
 *  Created on:		Apr 19, 2023
 *  Author: 		Sean Crocker
 *  Description:	Tells the control task to stop grinding process if the operation has been paused for too long.
 */

#include "Ass-02.h"

/*
 * 	Function:	PauseTimerCallback
 * 	--------------------------------------------------------------------------------------------------------------------
 * 		@brief Callback function for when virtual timer ends. When timer ends, send off state to control task.
 * 		@param argument: Not used
 * 		@retval: None
 */
void PauseTimerCallback(void const * argument)
{
	osMessagePut(messageQueueHandle, OFF, osWaitForever);
}
