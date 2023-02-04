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

void vASW_Trunk()
{
   if (RTE_bGET_Trunk_status())
   {
       SERVO_vChangeAngle(SERVOMOTOR_CW_DC);
   }
   else 
   {
       SERVO_vChangeAngle(SERVOMOTOR_CCW_DC);
   }
}
