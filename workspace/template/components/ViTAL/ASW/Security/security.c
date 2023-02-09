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

#include "ASW/Security/security.h"
#include "BSW/HAL/Proximity_Sensor/proximity_sensor.h"
#include "ASW/Headlights/headlights.h"

#include "RTE/rte.h"
#include "BSW\HAL\Com\com.h"
extern COM_GET_struct g_GET_DataStructure;
extern COM_POST_struct g_POST_DataStructure;
static const char *TAG = "ASW SECURITY";

void vASW_SECURITY()
{
    static int contt;
    if( RTE_GET_bButtonSecurity() == OFF && RTE_GET_bIsLocked() == UNLOCKED)
    {
     g_GET_DataStructure.bIsLocked=LOCKED;
    }
    else if( RTE_GET_bButtonSecurity() == ON && RTE_GET_bIsLocked() == LOCKED)
    {
     g_GET_DataStructure.bIsLocked=UNLOCKED;
    }
    if((RTE_bGETButtonFindMyCar()==1 ||RTE_GET_bIsOccupied() == Occupied ) && RTE_GET_bIsLocked() == LOCKED )
    {   
        if(contt==3)
        { contt=0;}
        if(contt==0)
        {
            RTE_vSetShiftRegisterOutput(HEAD_LIGHTS_POS | (1<<0), HEADLIGHTS_ON);
            RTE_BUZZER_vChangeDutyCycle(1000);
        }
        contt++;
    }
 
    if( RTE_bGETButtonFindMyCar()==1 && RTE_GET_bIsLocked() == UNLOCKED)
    { 
        if(contt==3)
        { contt=0;}
        if(contt==0)
        {
            if(RTE_bGETButtonHeadlights()== HEADLIGHTS_OFF)
            {
            RTE_vSetShiftRegisterOutput(HEAD_LIGHTS_POS | (1<<1), HEADLIGHTS_ON);
            }
            RTE_BUZZER_vChangeDutyCycle(1000);
        }
        contt++;

    }
    else if ( RTE_bGETButtonFindMyCar()==2)
    {
        RTE_BUZZER_vChangeDutyCycle(HORN_OFF);
        g_POST_DataStructure.bButtonFindMyCar = 0;
    }

    
}