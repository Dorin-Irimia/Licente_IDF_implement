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

static const char *TAG = "ASW CCS";
/*


void vASW_Fan()
{
    if(RTE_bGET_Fan_Status())
    {
        DCMOT_vChangeSpeed(DC_MOTOR_FULL_SPEED);
    }
    else
    {
        DCMOT_vChangeSpeed(DC_MOTOR_STOP);
    }
}

uint8_t vASW_ConfortLevel(uint8_t temp, uint8_t hum)
{
   uint8_t confort  = -8.78469475556 + 1.61139411*temp + 2.33854883889*hum - 1.14611605*temp*hum - 0.012308094*pow(temp,2)- 0.01642482777778*pow(hum,2)+0.002211732*pow(temp,2)*hum+0.00072546*temp*pow(hum,2)-0.000003582*pow(temp,2)*pow(hum,2);
    RTE_SetConfort(confort);
    return confort;

}

void vASW_SET_FAN()
{
    static uint8_t ok=0;
    uint8_t temp,hum,UserTemp,Confort;
    UserTemp=RTE_bGET_UserTemp();
    temp=RTE_bGET_Temperature_Status();
    hum=RTE_bGET_Humidity_Status();
   Confort=vASW_ConfortLevel(temp,hum);
    if(Confort>=UserTemp){
        RTE_SET_DC_MOTOR_SPEED(20000);
        ok=1;
      }

    else
    {
       if(Confort>=(UserTemp-2))
        {
            RTE_SET_DC_MOTOR_SPEED(1500);
        }
        else{
        
        RTE_SET_DC_MOTOR_SPEED(0);

        ok=0;
        }
    }
    


}
*/