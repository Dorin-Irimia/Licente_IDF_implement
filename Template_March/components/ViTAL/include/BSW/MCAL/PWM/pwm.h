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
#define PWM_CHANNELS 8 /* Total number of channels */

/* Channels */
#define SERVO_MOTOR_1_PWM_CHANNEL 0
#define DC_MOTOR_PWM_CHANNEL 1
#define BUZZER_PWM_CHANNEL 2
#define SERVO_MOTOR_2_PWM_CHANNEL 3
#define SERVO_MOTOR_3_PWM_CHANNEL 4
#define SERVO_MOTOR_4_PWM_CHANNEL 5
#define SERVO_MOTOR_5_PWM_CHANNEL 6
#define SERVO_MOTOR_6_PWM_CHANNEL 7

/* Pins */
#define SERVO_MOTOR_1_PWM_PIN 33
#define SERVO_MOTOR_2_PWM_PIN 34
#define SERVO_MOTOR_3_PWM_PIN 35
#define SERVO_MOTOR_4_PWM_PIN 36
#define SERVO_MOTOR_5_PWM_PIN 37
#define SERVO_MOTOR_6_PWM_PIN 38
#define DC_MOTOR_PWM_PIN 39
#define BUZZER_PWM_PIN 40

#endif
