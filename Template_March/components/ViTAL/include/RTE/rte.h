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

#ifndef COMPONENTS_VITAL_RTE_H
#define COMPONENTS_VITAL_RTE_H

#include "global.h"
extern bool RTE_bGET_Trunk_status();
extern bool RTE_bGET_Dors_Lock_Status(); 
extern bool RTE_bGET_Fan_Status();
extern bool RTE_bGET_Honk_Status();

extern bool RTE_bGET_Humidity_Status();
extern bool RTE_bGET_UserTemp();
extern bool RTE_bGET_Temperature_Status();




extern void RTE_vChangeSpeed(uint32_t u32DCMotorSpeed);
extern void RTE_vChangeDutyCycle(uint32_t u32BuzzerDutyCycle);
extern void RTE_vChangeAngle(uint32_t u32ServoAngle1,uint32_t u32ServoAngle2);
extern void RTE_SetConfort(uint8_t confort);
extern void RTE_SET_DC_MOTOR_SPEED(uint32_t u32DCMotorSpeed);

#endif


