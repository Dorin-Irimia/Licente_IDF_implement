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

#include "SRVL/SCHEDULER/scheduler.h"

#include "BSW/MCAL/ADC/adc.h"
#include "BSW/MCAL/GPIO/gpio.h"
#include "BSW/MCAL/PWM/pwm.h"
#include "BSW/MCAL/WIFI/wifi.h"

#include "BSW/HAL/Buzzer/buzzer.h"
#include "BSW/HAL/Color_Change/Color_Change.h"
#include "BSW/HAL/Com/com.h"
#include "BSW/HAL/DC_Motor/dc_motor.h"
#include "BSW/HAL/Line_Read/line_read.h"
#include "BSW/HAL/Photo_Resistor/photo_resistor.h"
#include "BSW/HAL/Proximity_Sensor/proximity_sensor.h"
#include "BSW/HAL/Servo_Motor/servo_motor.h"
#include "BSW/HAL/Shift_Register/shift_register.h"
#include "BSW/HAL/Temp_Sensor/temp_sensor.h"

#include "RTE/rte.h"

#include "ASW/Ambient_Light/ambient_light.h"
#include "ASW/Climate_Control_System/climate_control_system.h"
#include "ASW/Headlights/headlights.h"
#include "ASW/Horn/horn.h"
#include "ASW/Locking_System/locking_system.h"
#include "ASW/Run_Movements/run_movements.h"
#include "ASW/Security/security.h"
#include "ASW/Trunk/trunk.h"
#include "ASW/Write_Movements/write_movements.h"

#include "nvs_flash.h"
/**
#define SERVOMOTOR_CW_DC_1 530
#define SERVOMOTOR_STOP_DC_1 1500
#define SERVOMOTOR_CCW_DC_1 1600
**/
static const char *TAG = "SRVL SCHEDULER";

static httpd_handle_t server = NULL;

void SYSTEM_vInit(void)
{
	//Initialize NVS
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES)
	{
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	ADC_vInit();

	GPIO_vInit();

	PWM_vInit();

	WIFI_vInit(&server);
}


void vTask50ms(void)
{
	LS_vLineRead(); 	//citeste linia 
	Run_Movement();		//activeaza toate functiile pentru miscare

}

void vTask100ms(void)
{
	
	COM_vTaskProcessServer();	//Primeste comenzile de la telefon
	PROX_u16Read();				//Citeste detectia unui obiect
}

void vTask200ms(void)
{
	SERVO_vChangeAngle();		//Miscarea servo motoarelor dupa citirea comenzii de la server
	autorun();					//Executa miscarea servo motoarelor dupa ce a fost detectat un obiect si o culoare a acestuia 	
}

void vTask500ms(void)
{

	//vASW_SET_FAN();

	 //vASW_LockSystem();
	
	 //vASW_Fan();
	
     //PHRES_vTaskCalculate();

	 //SHIFTREG_vOutput8Bits(1);
	  vASW_Honk();
	//  
  

	

	
	/******************************************
	DCMOT_vChangeSpeed (20000);
	SERVO_vChangeAngle (1600);
	//BUZZER_vChangeDutyCycle(1000);
	PHRES_vTaskCalculate();
	DHT11_vTaskTempAndHumCalculate();
	SHIFTREG_vOutput8Bits(255);
	********************************************/
}

void vTask800ms(void)
{
	
}

void vTask1000ms(void)
{
		
}

void vTask2000ms(void)
{
	
}

void vTask5000ms(void)
{
	//DHT11_vTaskTempAndHumCalculate();
}

void SYSTEM_vTaskScheduler(void)
{
	uint16_t u16TickCount = 0;

	while (1)
	{
		if (u16TickCount % TASK_50MS == 0)
		{
			vTask50ms();
		}

		if (u16TickCount % TASK_100MS == 0)
		{
			vTask100ms();
		}

		if (u16TickCount % TASK_200MS == 0)
		{
			vTask200ms();
		}

		if (u16TickCount % TASK_500MS == 0)
		{
			vTask500ms();
		}

		if (u16TickCount % TASK_800MS == 0)
		{
			vTask800ms();
		}

		if (u16TickCount % TASK_1000MS == 0)
		{
			vTask1000ms();
		}

		if (u16TickCount % TASK_2000MS == 0)
		{
			vTask2000ms();
		}

		if (u16TickCount % TASK_5000MS == 0)
		{
			vTask5000ms();
		}

		u16TickCount++;
		if (u16TickCount >= TASK_5000MS)
		{
			u16TickCount = 0;
		}

		vTaskDelay(100);
	}
}
