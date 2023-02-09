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

#include "ASW/Climate_Control_System/climate_control_system.h"
#include "BSW/HAL/DC_Motor/dc_motor.h"
#include "RTE/rte.h"
#include "BSW/HAL/Servo_Motor/servo_motor.h"

static const char *TAG = "ASW CCS";

void vASW_FAN()
{ 
    RTE_SERVO_vChangeAngle(1600);

    if( RTE_bGET_FAN_STATUS() )
    {
        RTE_DCMOT_vChangeSpeed(FAN_ON);
        //ESP_LOGI(TAG, " FAN_ON");

    }
    else
    {
        RTE_DCMOT_vChangeSpeed(FAN_OFF);
        //ESP_LOGI(TAG, " FAN_OFF");
    }
}

double dASW_Comfort_Level( uint8_t u8Temp , uint8_t u8Hum)
{
    double Comfort_Level;
    
    Comfort_Level= C1 + C2 * u8Temp + C3 * u8Hum + C4 * u8Temp * u8Hum + C5 * u8Temp * u8Temp + C6 * u8Hum * u8Hum + C7 * u8Temp * u8Temp * u8Hum + C8 * u8Temp * u8Hum * u8Hum + C9 * u8Temp * u8Temp * u8Hum * u8Hum;
    
    RTE_SET_COMFORT(Comfort_Level);

    return Comfort_Level;
}

void vASW_Set_Fan()
{
    static uint8_t OK=0;
    uint8_t temp , humidity , userTemp, comfort;

    userTemp = RTE_bGETUserTemp();
    temp = RTE_GET_TEMPERATURE();
    humidity = RTE_GET_HUMIDITY();
    comfort = dASW_Comfort_Level( temp , humidity);
    if( RTE_bGETButtonFan())
    {
        if(comfort >= userTemp)
        {
            OK = 1;
            RTE_DCMOT_vChangeSpeed(FAN_MAX);  
        }
        else
        {
            if(comfort >= (userTemp-2) && OK==1)
            {   
                RTE_DCMOT_vChangeSpeed(FAN_ON);
            }
            else
            {
                OK=0;
                RTE_DCMOT_vChangeSpeed(FAN_OFF);
            }
        }
    }    
    else 
    {   
        OK=0;
        RTE_DCMOT_vChangeSpeed(FAN_OFF);
    }
}
