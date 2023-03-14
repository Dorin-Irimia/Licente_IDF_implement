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

#ifndef COMPONENTS_VITAL_BSW_MCAL_GPIO_H
#define COMPONENTS_VITAL_BSW_MCAL_GPIO_H

#include "global.h"

void GPIO_vInit(void);

void GPIO_vSetDirection(uint8_t u8PinNumber, uint8_t u8Direction);

void GPIO_vSetLevel(uint8_t u8PinNumber, uint32_t u32Level);

int GPIO_iGetLevel(uint8_t u8PinNumber);

/* STEPER_PIN */
#define LEFT_DIR_PIN 2
#define LEFT_DIR_PIN_MASK (1 << LEFT_DIR_PIN)
#define RIGHT_DIR_PIN 3
#define RIGHT_DIR_PIN_MASK (1 << RIGHT_DIR_PIN)
#define LEFT_COMAND_PIN 4
#define LEFT_COMAND_PIN_MASK (1 << LEFT_COMAND_PIN)
#define RIGHT_COMAND_PIN 5
#define RIGHT_COMAND_PIN_MASK (1 << RIGHT_COMAND_PIN)

/* COLOR_SENSOR_HW */
#define COLOR_S0_PIN 6
#define COLOR_S0_PIN_MASK (1 << COLOR_S0_PIN)
#define COLOR_S1_PIN 7
#define COLOR_S1_PIN_MASK (1 << COLOR_S1_PIN)
#define COLOR_S2_PIN 8
#define COLOR_S2_PIN_MASK (1 << COLOR_S2_PIN)
#define COLOR_S3_PIN 9
#define COLOR_S3_PIN_MASK (1 << COLOR_S3_PIN)
#define COLOR_OUTPUT_PIN 10
#define COLOR_OUTPUT_PIN_MASK (1 << COLOR_OUTPUT_PIN)

/* ULTRASONIC_SENSOR_HW */
#define HC_SR04_TRIGGER_PIN 11
#define HC_SR04_TRIGGER_PIN_MASK (1 << HC_SR04_TRIGGER_PIN)
#define HC_SR04_ECHO_PIN 12
#define HC_SR04_ECHO_PIN_MASK (1 << HC_SR04_ECHO_PIN)

/* DHT11_HW */
#define DHT11_PIN 13
#define DHT11_PIN_MASK (1 << DHT11_PIN)

/* SHIFT_REGISTER_HW */
#define SN74HC595N_DS_PIN 14
#define SN74HC595N_DS_PIN_MASK (1 << SN74HC595N_DS_PIN)
#define SN74HC595N_ST_CP_PIN 15
#define SN74HC595N_ST_CP_PIN_MASK (1 << SN74HC595N_ST_CP_PIN)
#define SN74HC595N_SH_CP_PIN 16
#define SN74HC595N_SH_CP_PIN_MASK (1 << SN74HC595N_SH_CP_PIN)

/* LINE_SENSOR_HW */
#define LINE_LEFT_SENSOR_PIN 17
#define LINE_LEFT_SENSOR_PIN_MASK (1 << LINE_LEFT_SENSOR_PIN)
#define LINE_RIGHT_SENSOR_PIN 18
#define LINE_RIGHT_SENSOR_PIN_MASK (1 << LINE_RIGHT_SENSOR_PIN)
#define LINE_CENTER_SENSOR_PIN 19
#define LINE_CENTER_SENSOR_PIN_MASK (1 << LINE_CENTER_SENSOR_PIN)
/* Macros */
#define LOW_LEVEL 0
#define HIGH_LEVEL 1

#define DIR_INPUT 1
#define DIR_OUTPUT 2

#endif
