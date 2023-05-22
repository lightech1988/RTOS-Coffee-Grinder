/*
 * 	File Name:		Ass-02-controlTask.c
 *  Created on:		Apr 19, 2023
 *  Author: 		Sean Crocker
 *  Description:	A finite-state machine to control the state of the coffee grinder system. Depending on the state,
 *  				the LCD screen is updated.
 */

#include "Ass-02.h"

enum State state = OFF;		// State of the system

/*
 * 	Function:	display_state_lcd
 * 	--------------------------------------------------------------------------------------------------------------------
 * 		@brief Function to display the state and buttons on the LCD display.
 * 		@param state[]:		String for the current state to display as a title.
 * 		@param isPaused:	Boolean as to whether the system is in the paused state.
 * 		@retval: 			None
 */
void display_state_lcd(char state[], bool isPaused)
{
	BSP_LCD_Clear(LCD_COLOR_WHITE);										// Clear the LCD and set background to white
	BSP_LCD_SetFont(&Font24);											// Set the font to be used
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);								// Set the text colour to black
	BSP_LCD_DisplayStringAt(0, 80, (uint8_t*)state, CENTER_MODE);		// Display status as OFF

	BSP_LCD_SetFont(&Font20);											// Set the font to be used for buttons

	BSP_LCD_DrawRect(BTN1_X_POS, BTN_Y_POS, BTN_WIDTH, BTN_HEIGHT);		// Draw a rectangle for the first button
	BSP_LCD_DrawRect(BTN2_X_POS, BTN_Y_POS, BTN_WIDTH, BTN_HEIGHT);		// Draw a rectangle for the second button

	if (isPaused)														// Show 'resume' button if paused
		BSP_LCD_DisplayStringAt((BTN1_X_POS + 8), BTN_TEXT_Y_POS, (uint8_t*)"Resume", LEFT_MODE);
	else																// Otherwise, show 'start' button
		BSP_LCD_DisplayStringAt((BTN1_X_POS + 15), BTN_TEXT_Y_POS, (uint8_t*)"Start", LEFT_MODE);

	BSP_LCD_DisplayStringAt((BTN2_X_POS + 15), BTN_TEXT_Y_POS, (uint8_t*)"Pause", LEFT_MODE);
}

/*
 * 	Function:	StartControlTask
 * 	--------------------------------------------------------------------------------------------------------------------
 * 		@brief Function implementing the control task/thread that runs a looping executive with a finite state machine.
 * 		@param argument: 	Not used
 * 		@retval: 			None
 */
void StartControlTask(void const * argument)
{
	BSP_LCD_Init();							// Initialize the LCD
	BSP_LCD_DisplayOn();					// Enable the LCD
	TouchPanel_Calibrate();					// Touch Panel configuration
	osEvent event;							// Event structure to receive message from queue
	uint16_t dac_data[DAC_SAMPLES] = {128, 218, 255, 218, 128, 37, 0, 37};

	display_state_lcd("OFF", 0);			// Initial display of off state on the lcd

	while (1) {
		event = osMessageGet(messageQueueHandle, osWaitForever);	// Wait and get message
		if (event.status == 0x10 && state != event.value.v) {
			switch (event.value.v) {
				case (OFF):
					display_state_lcd("OFF", 0);					// Display the 'off' state
					osTimerStop(pauseTimerHandle);					// Stop the pause timer
					HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);			// Stop the speaker
					break;
				case(GRINDING):
					display_state_lcd("GRINDING", 0);				// Display the 'grind' state
					osTimerStop(pauseTimerHandle);					// Stop the pause timer
					HAL_TIM_Base_Start(&htim2);						// Start the speaker
					HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)dac_data, DAC_SAMPLES, DAC_ALIGN_12B_R);
					break;
				case(PAUSED):
					if (state != OFF) {
						display_state_lcd("PAUSED", 1);				// Display the 'paused' state
						osTimerStart(pauseTimerHandle, 20000);		// Start the pause timer
						HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);		// Stop the speaker
					}
					break;
			}
			state = event.value.v;									// Change states
		}
		osDelay(100);
	}
}
