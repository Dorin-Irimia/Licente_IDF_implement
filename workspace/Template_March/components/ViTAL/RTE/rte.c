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
#include "BSW/HAL/Temp_Sensor/temp_sensor.h"

static const char *TAG = "RTE";

extern COM_GET_struct g_GET_DataStructure;
extern COM_POST_struct g_POST_DataStructure;

bool RTE_bGET_Trunk_status()
{
    return g_POST_DataStructure.bButtonTrunk;

}
bool RTE_bGET_Dors_Lock_Status()
{
    return g_POST_DataStructure.bButtonDoorLock;
}
bool RTE_bGET_Fan_Status()
{
    return g_POST_DataStructure.bButtonFan;
}
bool RTE_bGET_Honk_Status()
{
    return g_POST_DataStructure.bButtonHonk;
}


 bool RTE_bGET_Humidity_Status()
 {
     return g_GET_DataStructure.u8Humidity;
 }

bool RTE_bGET_UserTemp()
{
    return g_POST_DataStructure.u8UserTemperature;
}

bool RTE_bGET_Temperature_Status()
{
    return g_GET_DataStructure.u8Temperature;
}



// uint8_t RTE_Confort();
// {

// // formula confort :  = -8.78469475556 + 1.61139411*temp + 2.33854883889*hum - 1.14611605*temo*hum - 0.012308094*pow(temp,2)- 0.01642482777778*pow(hum,2)+0.002211732*pow(temp,2)*hum+0.00072546*temp*pow(hum,2)-0.000003582*pow(temp,2)*pow(hum,2);
// }




void RTE_vChangeSpeed(uint32_t u32DCMotorSpeed)
{
    DCMOT_vChangeSpeed(u32DCMotorSpeed);
}

void RTE_vChangeDutyCycle(uint32_t u32BuzzerDutyCycle)
{
    BUZZER_vChangeDutyCycle(u32BuzzerDutyCycle);
}

void RTE_vChangeAngle(uint32_t u32ServoAngle)
{
    SERVO_vChangeAngle(u32ServoAngle);
}


void RTE_SetConfort(uint8_t u8Confort)
{
    g_GET_DataStructure.u8Comfort=u8Confort;
}


void RTE_SET_DC_MOTOR_SPEED(uint32_t u32DCMotorSpeed)
{
    DCMOT_vChangeSpeed(u32DCMotorSpeed);
}


