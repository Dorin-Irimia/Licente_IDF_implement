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

#include "RTE/rte.h"

#include "BSW/HAL/Buzzer/buzzer.h"
#include "BSW/HAL/Com/com.h"
#include "BSW/HAL/DC_Motor/dc_motor.h"
#include "BSW/HAL/Proximity_Sensor/proximity_sensor.h"
#include "BSW/HAL/Servo_Motor/servo_motor.h"
#include "BSW/HAL/Shift_Register/shift_register.h"

static const char *TAG = "RTE";

extern COM_GET_struct g_GET_DataStructure;
extern COM_POST_struct g_POST_DataStructure;

void RTE_vSetAmbientalLightsState(bool bState,uint8_t variabila)
{	
	
	static uint8_t s_u8ColorState = STATE_RED;
	
	if (bState == ON)
	{		
		switch (s_u8ColorState)
		{
		case STATE_RED:
			RTE_vSetShiftRegisterOutput(RED, HIGH);
			if(variabila == 3)
			{
			s_u8ColorState = STATE_RED_GREEN;
			}
			break;
		case STATE_GREEN:
			RTE_vSetShiftRegisterOutput(GREEN, HIGH);
			if(variabila == 3)
			{
			s_u8ColorState = STATE_GREEN_BLUE;
			}
			break;
		case STATE_BLUE:
			RTE_vSetShiftRegisterOutput(BLUE, HIGH);
			if(variabila == 3)
			{
			s_u8ColorState = STATE_RED_BLUE;
			}
			break;
		case STATE_RED_GREEN:
			RTE_vSetShiftRegisterOutput(RED_GREEN, HIGH);
			if(variabila == 3)
			{
			s_u8ColorState = STATE_GREEN;
			}
			break;
		case STATE_RED_BLUE:
			RTE_vSetShiftRegisterOutput(RED_BLUE, HIGH);
			if(variabila == 3)
			{
			s_u8ColorState = STATE_ALL_COLORS;
			}
			break;
		case STATE_GREEN_BLUE:
			RTE_vSetShiftRegisterOutput(GREEN_BLUE, HIGH);
			if(variabila == 3)
			{
			s_u8ColorState = STATE_BLUE;
			}
			break;
		case STATE_ALL_COLORS:
			RTE_vSetShiftRegisterOutput(ALL_COLORS, HIGH);
			if(variabila == 3)
			{
			s_u8ColorState = STATE_RED;
			}
			break;
		default:
			ESP_LOGI(TAG, "RGB ERROR");
			break;
		}
	}
	else if (bState == OFF)
	{	
		RTE_vSetShiftRegisterOutput(ALL_COLORS ^ ALL_COLORS,LOW);
		s_u8ColorState = STATE_RED;
	}
	else
	{
		ESP_LOGI(TAG, "AMBIENTAL LIGHTS ERROR");
	}
}

void RTE_vSetShiftRegisterOutput(shift_register_positions_t u8ComponentMask,
uint8_t bLevel)
{	
	static uint8_t s_u8Buffer=0 ,s_u8Buffer1=0;
	static uint8_t s_u8CurrentData = 0;
	if(u8ComponentMask==1)
	{
	s_u8Buffer1 = u8ComponentMask;
	}
	else {s_u8Buffer1 =0;}

	if(u8ComponentMask == 12 && bLevel == 1)
	{
	s_u8Buffer = u8ComponentMask ;
	}
	if(u8ComponentMask == 13 && bLevel == 1)
	{
	s_u8Buffer = u8ComponentMask ;
	bLevel=3;
	}
	else if(u8ComponentMask == 12 && bLevel == 2) 
			{
				s_u8Buffer =0;}
	
	s_u8Buffer = s_u8Buffer | s_u8Buffer1  ;

	if (bLevel)
	{ 	
		s_u8CurrentData = u8ComponentMask | (1<<1) | s_u8Buffer	;
		if(bLevel==3){
		s_u8CurrentData = u8ComponentMask | s_u8Buffer	;}
	}
	else if (bLevel == LOW)
	{	
		
		s_u8CurrentData = u8ComponentMask | (1<<1) | s_u8Buffer ;

		if (RTE_GET_bIsLocked() == ON)
		{
			s_u8CurrentData = u8ComponentMask ;
		}

	}
	else
	{
		ESP_LOGI(TAG, "Invalid level for shift register");
	}
	if(s_u8CurrentData>=0)
	{
		
	SHIFTREG_vOutput8Bits(s_u8CurrentData);
	}
}

uint8_t RTE_GET_TEMPERATURE()
{
    return g_GET_DataStructure.u8Temperature;
}

uint8_t RTE_GET_HUMIDITY()
{   
    return g_GET_DataStructure.u8Humidity;
}

uint8_t RTE_GET_COMFORT()
{
    return g_GET_DataStructure.u8Comfort;
}

uint16_t RTE_GET_PhotoRes()
{
    return g_GET_DataStructure.u16PhotoRes;
}

bool RTE_GET_bIsLocked()
{
    return  g_GET_DataStructure.bIsLocked;
}

bool RTE_GET_bIsOccupied()
{
    return g_GET_DataStructure.bIsOccupied;
}

void RTE_SET_ButtonFindMyCar(bool ButtonFindMyCar )
{
    g_POST_DataStructure.bButtonFindMyCar = ButtonFindMyCar;
	
}

void RTE_SET_ButtonHeadlights(bool ButtonHeadlights )
{
    g_POST_DataStructure.bButtonHeadlights = ButtonHeadlights;
}

void RTE_SET_COMFORT(uint8_t Comfort)
{
    g_GET_DataStructure.u8Comfort = Comfort;
}

void RTE_SET_TEMPERATURE(uint8_t Temp)
{
    g_GET_DataStructure.u8Temperature = Temp;
}

void RTE_SET_HUMIDITY(uint8_t Hum)
{
    g_GET_DataStructure.u8Humidity = Hum;
}

void RTE_SET_PHOTORES(uint16_t PhotoRes)
{
    g_GET_DataStructure.u16PhotoRes = PhotoRes;
}

void RTE_SET_BISLOCKED(bool bisLocked)
{
    g_GET_DataStructure.bIsLocked = bisLocked;
}

void RTE_SET_BISOCCUPIED(bool bisOccupied)
{
    g_GET_DataStructure.bIsOccupied = bisOccupied;
}

void RTE_SET_ButtonFan(bool ButtonFan)
{
    g_POST_DataStructure.bButtonFan = ButtonFan;
}

void RTE_SERVO_vChangeAngle(uint32_t u32ServoAngle)
{
    SERVO_vChangeAngle(u32ServoAngle);
}

void RTE_BUZZER_vChangeDutyCycle(uint32_t u32BuzzerDutyCycle)
{
    BUZZER_vChangeDutyCycle(u32BuzzerDutyCycle);
}

void RTE_DCMOT_vChangeSpeed(uint32_t u32DCMotorSpeed)
{
    DCMOT_vChangeSpeed(u32DCMotorSpeed);
}

bool RTE_bGET_TRUNK_STATUS()
{
    return g_POST_DataStructure.bButtonTrunk;
}


bool RTE_bGET_DOORLOCK_STATUS()
{
    return g_POST_DataStructure.bButtonDoorLock;
}


bool RTE_bGET_FAN_STATUS()
{
    return g_POST_DataStructure.bButtonFan;
}

bool RTE_bGET_HEADLIGHTS_STATUS()
{
    return g_POST_DataStructure.bButtonHeadlights;
}

bool RTE_bGET_AMBIENTAL_LIGHTS_STATUS()
{
    return g_POST_DataStructure.bButtonAmbientalLights;
}

int RTE_bGET_FINDMYCAR_STATUS()
{
    return g_POST_DataStructure.bButtonFindMyCar;
}

int RTE_bGETHONK_STATUS()
{
    return g_POST_DataStructure.bButtonHonk;
}

bool RTE_bGET_SECURITY_STATUS()
{
    return g_POST_DataStructure.bButtonSecurity;
}

uint8_t RTE_bGETUserTemp()
{
    return g_POST_DataStructure.u8UserTemperature;
}

bool RTE_bGETButtonFan()
{
    return g_POST_DataStructure.bButtonFan;
}

int RTE_bGETButtonFindMyCar()
{	
    return g_POST_DataStructure.bButtonFindMyCar;
}

bool RTE_bGETButtonHeadlights()
{
    return g_POST_DataStructure.bButtonHeadlights;
}

void RTE_vSETHeadlights_State(bool bState)
{		
	if(bState)
		{
	    	RTE_vSetShiftRegisterOutput(HEAD_LIGHTS_POS, bState);
		}
	else if(bState==0)
		{
	    	RTE_vSetShiftRegisterOutput(HEAD_LIGHTS_POS, bState+2);
		}
}

void RTE_SET_bButtonHeadlights(bool bButtonHeadlights)
{
    g_POST_DataStructure.bButtonHeadlights = bButtonHeadlights;
}

void RTE_SET_bButtonSecurity(bool bButtonSecurity)
{
    g_POST_DataStructure.bButtonSecurity = bButtonSecurity;
}

void RTE_SET_bButtonAmbientalLights(bool bButtonAmbientalLights)
{
    g_POST_DataStructure.bButtonAmbientalLights = bButtonAmbientalLights;
}

bool RTE_GET_bButtonAmbientalLights()
{
    return g_POST_DataStructure.bButtonAmbientalLights;
}

bool RTE_GET_bButtonSecurity()
{
    return g_POST_DataStructure.bButtonSecurity;
}

