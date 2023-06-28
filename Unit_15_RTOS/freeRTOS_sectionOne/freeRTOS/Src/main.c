/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#include "../STM32F103_DRIVER/01-LIB/01-STD_TYPES/STD_TYPES.h"

#include "../STM32F103_DRIVER/02-MCAL/01-RCC/RCC_interface.h"
#include "../STM32F103_DRIVER/02-MCAL/02-GPIO/GPIO_interface.h"

#include "FreeRTOS.h"
#include "task.h"

#define STACK_SIZE 100


void vBlinkingLed(void* vPTR);

int main(void)
{
	RCC_voidInitSysClocks();

	/*	Task Creation	*/
	TaskHandle_t blinkLEDHandle = NULL;
    /* Create the task, storing the handle. */
    xTaskCreate(
    				vBlinkingLed,     /* Function that implements the task. */
                    "Blink Led",      /* Text name for the task. */
                    STACK_SIZE,      /* Stack size in words, not bytes. */
                    NULL ,   		 /* Parameter passed into the task. */
                    1				,/* Priority at which the task is created. */
                    &blinkLEDHandle );      /* Used to pass out the created task's handle. */

    /*			START SCHEDULER		*/
    vTaskStartScheduler();
    /* Loop forever */
	for(;;);
}

void vBlinkingLed(void* vPTR)
{
	RCC_voidEnableClock(RCC_APB2, PORTA);
	GPIO_voidSetPinDirection(PORTA, PIN13, GPIO_OUTPUT_10MHZ_PUSH_PULL);
	while(1)
	{
		GPIO_voidSetPinValue(PORTA,PIN13,LOW);
		vTaskDelay(50);
		GPIO_voidSetPinValue(PORTA,PIN13,HIGH);
		vTaskDelay(50);

	}

}