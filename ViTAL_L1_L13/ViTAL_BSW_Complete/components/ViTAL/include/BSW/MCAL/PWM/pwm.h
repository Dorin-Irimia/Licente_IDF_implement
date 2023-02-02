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

#ifndef COMPONENTS_VITAL_BSW_MCAL_PWM_H
#define COMPONENTS_VITAL_BSW_MCAL_PWM_H

#include "global.h"

void PWM_vInit(void);

void PWM_vSetDutyCycle(uint8_t u8Channel, uint32_t u32DutyCycle);

/* Configuration */
#define PWM_FREQUENCY 50 /* F = 50HZ -> T = 20,000us */
#define PWM_CHANNELS 3   /* Total number of channels */

/* Channels */
#define SERVO_MOTOR_PWM_CHANNEL 0
#define DC_MOTOR_PWM_CHANNEL 1
#define BUZZER_PWM_CHANNEL 2

/* Pins */
#define SERVO_MOTOR_PWM_PIN 8
#define DC_MOTOR_PWM_PIN 9
#define BUZZER_PWM_PIN 10

#endif
