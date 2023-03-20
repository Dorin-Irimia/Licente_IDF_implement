/*******************************************************************************
 * COPYRIGHT (C) VITESCO TECHNOLOGIES
 * ALL RIGHTS RESERVED.
 *
 * The reproduction, transmission or use of this document or its
 * contents is not permitted without express written authority.
 * Offenders will be liable for damages. All rights, including rights
 * created by patent grant or registration of a utility model or design,
 * are reserved.
 ******************************************************************************/

#include "BSW/HAL/Shift_Register/shift_register.h"
#include "SRVL/SCHEDULER/scheduler.h"
#include "BSW/MCAL/GPIO/gpio.h"

static const char *TAG = "HAL SHIFT REGISTER";

/*******************************************************************************
 *  Function name    : SHIFTREG_vOutput8Bits
 *
 *  Description      : Output an 8 bit data value
 *
 *  List of arguments: u8Data -> Data to be output MSb to LSb
 *
 *  Return value     : -
 *
 ******************************************************************************/
void SHIFTREG_vOutput8Bits(uint16_t u16Data)
{
	for( ;u16Data <=128 ;u16Data*=2)
{
		vTask200ms();
	/* Set all pins low */
	GPIO_vSetLevel(SN74HC595N_DS_PIN, LOW_LEVEL);
	GPIO_vSetLevel(SN74HC595N_SH_CP_PIN, LOW_LEVEL);
	GPIO_vSetLevel(SN74HC595N_ST_CP_PIN, LOW_LEVEL);

	/* Store data */
	 int8_t i8Index = 7;


	for (; i8Index >= 0; i8Index--)
	{
		
		GPIO_vSetLevel(SN74HC595N_DS_PIN, (u16Data & (1 << i8Index)) >> i8Index);		
		/* Send storage clock */
		GPIO_vSetLevel(SN74HC595N_SH_CP_PIN, HIGH_LEVEL);
		GPIO_vSetLevel(SN74HC595N_SH_CP_PIN, LOW_LEVEL);
	
		ESP_LOGI(TAG, "\t u8data :   %d \t  i8Index  : %d ",u16Data,((u16Data & (1 << i8Index)) >> i8Index));	
		ESP_LOGI(TAG, "\t u8data :   %d \t  i8Index  : %d ",u16Data,((u16Data & (1 << i8Index)) >> i8Index));	
		ESP_LOGI(TAG, "\t u8data :   %d \t  i8Index  : %d ",u16Data,((u16Data & (1 << i8Index)) >> i8Index));	
	}


	/* Send latch clock */
	GPIO_vSetLevel(SN74HC595N_ST_CP_PIN, HIGH_LEVEL);
	GPIO_vSetLevel(SN74HC595N_ST_CP_PIN, LOW_LEVEL);
}



		for( ;u16Data >=1 ;u16Data/=2)
{
	vTask200ms();
	/* Set all pins low */
	GPIO_vSetLevel(SN74HC595N_DS_PIN, LOW_LEVEL);
	GPIO_vSetLevel(SN74HC595N_SH_CP_PIN, LOW_LEVEL);
	GPIO_vSetLevel(SN74HC595N_ST_CP_PIN, LOW_LEVEL);

	/* Store data */
	 int8_t i8Index = 7;

	for (; i8Index >= 0; i8Index--)
	{
		
		GPIO_vSetLevel(SN74HC595N_DS_PIN, (u16Data & (1 << i8Index)) >> i8Index);		
		/* Send storage clock */
		GPIO_vSetLevel(SN74HC595N_SH_CP_PIN, HIGH_LEVEL);
		GPIO_vSetLevel(SN74HC595N_SH_CP_PIN, LOW_LEVEL);
		ESP_LOGI(TAG, "\t u8data :   %d \t  i8Index  : %d ",u16Data,((u16Data & (1 << i8Index)) >> i8Index));	
		ESP_LOGI(TAG, "\t u8data :   %d \t  i8Index  : %d ",u16Data,((u16Data & (1 << i8Index)) >> i8Index));	
		ESP_LOGI(TAG, "\t u8data :   %d \t  i8Index  : %d ",u16Data,((u16Data & (1 << i8Index)) >> i8Index));		
	}


	/* Send latch clock */
	GPIO_vSetLevel(SN74HC595N_ST_CP_PIN, HIGH_LEVEL);
	GPIO_vSetLevel(SN74HC595N_ST_CP_PIN, LOW_LEVEL);
}

}


/*
		how to work

		serial uc paralel pin

		8 output pins 

			for data signal = 0 0 0 0 0 0 0 1  output 1 = 1 
			clock signal 	= 101010101010101
		2 - led front for daily light  - 
		2 - led back for daily light
		2 - led front for hige view
		4 - led for signal 
		2 - led for brake 
		1 - led for alert
		
		1				1				1				1					1				1					1						
	Fdailylight		Bdailylight		higelight		brakelight			signalleft		signalright			alarmlight

*/