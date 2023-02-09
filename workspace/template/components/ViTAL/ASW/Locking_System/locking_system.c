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

#include "ASW/Locking_System/locking_system.h"
#include "BSW/HAL/Servo_Motor/servo_motor.h"
#include "RTE/rte.h"
#include "BSW\HAL\Com\com.h"
static const char *TAG = "ASW LOCK";
extern COM_POST_struct g_POST_DataStructure;
void vASW_DOORLOCK()
{   
    static int constt=0;
    if(RTE_bGET_DOORLOCK_STATUS() == 0 && constt == 0)
    {  
        RTE_SERVO_vChangeAngle(UNLOCK_DOOR);
        constt = 1;
    }
    else if(RTE_bGET_DOORLOCK_STATUS() == 1 && constt == 1)
    { 
        RTE_SERVO_vChangeAngle(LOCK_DOOR);
        constt =0;
    }
    // if( RTE_bGET_DOORLOCK_STATUS())
    // {
    //     RTE_SERVO_vChangeAngle(UNLOCK_DOOR);
    // }
    // else
    // {
    //    RTE_SERVO_vChangeAngle(LOCK_DOOR);
    // }
}
