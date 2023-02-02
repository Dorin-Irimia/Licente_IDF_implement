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

#include "BSW/HAL/Proximity_Sensor/proximity_sensor.h"

#include "BSW/MCAL/GPIO/gpio.h"

static const char *TAG = "HAL PROXIMITY SENSOR";

/*******************************************************************************
 *  Function name    : PROX_vRequest
 *
 *  Description      : Send a pulse on the trigger pin
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 *******************************************************************************/
void PROX_vRequest(void)
{
	GPIO_vSetLevel(HC_SR04_TRIGGER_PIN, LOW_LEVEL);
	ets_delay_us(2);
	GPIO_vSetLevel(HC_SR04_TRIGGER_PIN, HIGH_LEVEL);
	ets_delay_us(10);
	GPIO_vSetLevel(HC_SR04_TRIGGER_PIN, LOW_LEVEL);
}

/*******************************************************************************
 *  Function name    : PROX_u16Read
 *
 *  Description      : Measure echo time and convert it to distance
 *
 *  List of arguments: -
 *
 *  Return value     : uint16_t -> Distance in cm
 *
 *******************************************************************************/
uint16_t PROX_u16Read(void)
{
	PROX_vRequest();

	while (GPIO_iGetLevel(HC_SR04_ECHO_PIN) == 0)
		;

	int64_t echo_start = esp_timer_get_time();

	while (GPIO_iGetLevel(HC_SR04_ECHO_PIN))
		;

	return (uint16_t) (((esp_timer_get_time() - echo_start) * 0.034) / 2);
}
