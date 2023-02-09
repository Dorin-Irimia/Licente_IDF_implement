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

#include "ASW/Trunk/trunk.h"
#include "BSW/HAL/Servo_Motor/servo_motor.h"
#include "RTE/rte.h"

static const char *TAG = "ASW TRUNK";
#include "BSW\HAL\Com\com.h"
extern COM_POST_struct g_POST_DataStructure;

void vASW_TRUNK()
{
    static int constt=0;
    if( RTE_bGET_TRUNK_STATUS() == 0 && constt == 0 &&  RTE_GET_bIsLocked()== UNLOCKED)
    {  
        RTE_SERVO_vChangeAngle(OPEN_TRUNK);
        constt = 1;
    }
    else if( RTE_bGET_TRUNK_STATUS() == 1 && constt == 1 &&  RTE_GET_bIsLocked()== UNLOCKED)
    { 
        RTE_SERVO_vChangeAngle(CLOSE_TRUNK);
        constt =0;
    }



    // if( RTE_bGET_TRUNK_STATUS() &&  RTE_GET_bIsLocked()== UNLOCKED )
    // {  ESP_LOGI(TAG, "\t\t deschis");
    //     RTE_SERVO_vChangeAngle (OPEN_TRUNK);
    // }
    // else if( RTE_bGET_TRUNK_STATUS()==0 &&  RTE_GET_bIsLocked()== UNLOCKED )
    // { 
    //     RTE_SERVO_vChangeAngle (CLOSE_TRUNK);
    // }   

}
