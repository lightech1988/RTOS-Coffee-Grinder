/*
 * 	File Name:		Ass-02-touchPanelTask.c
 *  Created on:		Apr 19, 2023
 *  Author: 		Sean Crocker
 *  Description:	Records user's touches on the LCD screen and tells control task if and which button has been
 *  				pressed.
 */

#include "Ass-02.h"

/*
 * 	Function:	StartTouchPanelTask
 * 	--------------------------------------------------------------------------------------------------------------------
 * 		@brief Function that implements the touch panel task which checks for user input from the LCD display in a
 * 		looping executive.
 * 		@param argument: Not used
 * 		@retval: None
 */
void StartTouchPanelTask(void const * argument)
{
	while (1) {
		getDisplayPoint(&display, Read_Ads7846(), &matrix);
		// If touched within correct y coordinates, check x coordinates
		if (display.y >= BTN_Y_POS && display.y <= BTN_Y_POS + BTN_HEIGHT) {
			switch (display.x) {
				case BTN1_X_POS ... BTN1_X_POS + BTN_WIDTH:
					// Tell Control Task that button one has been pressed
					osMessagePut(messageQueueHandle, GRINDING, osWaitForever);
					break;
				case BTN2_X_POS ... BTN2_X_POS + BTN_WIDTH:
					// Tell Control Task that button two has been pressed
					osMessagePut(messageQueueHandle, PAUSED, osWaitForever);
					break;
			}
		}
		osDelay(100);
	}
}
