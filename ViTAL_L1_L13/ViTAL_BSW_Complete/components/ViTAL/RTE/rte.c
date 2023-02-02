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
