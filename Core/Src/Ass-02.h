/*
 * 	File Name:		Ass-02.h
 *  Created on:		Apr 19, 2023
 *  Author: 		Sean Crocker
 *  Description:	Header file which contains all the necessary function declarations and macro definitions to be
 *  				shared between task source files.
 */

#ifndef SRC_ASS_02_H_
#define SRC_ASS_02_H_

// Includes from freertos.c
#include "FreeRTOS.h"
#include "task.h"

// Includes from main.c
#include "main.h"
#include "cmsis_os.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"
#include "fsmc.h"

#include "openx07v_c_lcd.h"
#include "touch_panel.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Constants
#define DAC_SAMPLES 8
#define BTN_HEIGHT 30
#define BTN_WIDTH 100
#define BTN1_X_POS 40
#define BTN2_X_POS 180
#define BTN_Y_POS 140
#define BTN_TEXT_Y_POS 145

// Global variables
enum State {OFF, GRINDING, PAUSED};
enum CountState {RESTART, COUNT, PAUSE};

// Operating System Handles
extern osThreadId controlTaskHandle;
extern osThreadId touchPanelTaskHandle;
extern osThreadId grindTimerTaskHandle;
extern osThreadId adcTaskHandle;
extern osMessageQId messageQueueHandle;
extern osTimerId pauseTimerHandle;

extern TIM_HandleTypeDef htim2;
extern ADC_HandleTypeDef hadc1;
extern DAC_HandleTypeDef hdac;

// Functions
void StartControlTask(void const * argument);
void StartTouchPanelTask(void const * argument);
void StartGrindTimerTask(void const * argument);
void StartADCTask(void const * argument);
void PauseTimerCallback(void const * argument);

#endif /* SRC_ASS_02_H_ */
