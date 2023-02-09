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

#include "BSW/MCAL/ADC/adc.h"

#include "driver/adc.h"

static const char *TAG = "MCAL ADC";

/*******************************************************************************
 *  Function name    : ADC_vInit
 *
 *  Description      : Initial configuration of MCAL ADC
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 ******************************************************************************/
void ADC_vInit(void)
{
	ESP_ERROR_CHECK(adc_gpio_init(ADC_UNIT_1, ADC_CHANNEL_0));
}

/*******************************************************************************
 *  Function name    : ADC_u16Read
 *
 *  Description      : Read of ADC value
 *
 *  List of arguments: -
 *
 *  Return value     : uint16_t -> ADC value
 *
 ******************************************************************************/
uint16_t ADC_u16Read(void)
{
	return (uint16_t)adc1_get_raw(ADC_CHANNEL_0);
}
