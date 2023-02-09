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

#ifndef COMPONENTS_VITAL_BSW_HAL_SERVO_MOTOR_H
#define COMPONENTS_VITAL_BSW_HAL_SERVO_MOTOR_H

#include "global.h"

void SERVO_vChangeAngle(uint32_t u32ServoAngle);

#define SERVOMOTOR_CW_DC 1343
#define SERVOMOTOR_STOP_DC 3662
#define SERVOMOTOR_CCW_DC 5371

#endif
