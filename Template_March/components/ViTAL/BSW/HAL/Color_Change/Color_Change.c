
#include "ASW/Run_Movement/run_movements.h"

#include "BSW/HAL/Color_Change/Color_Change.h"

#include "BSW/MCAL/GPIO/gpio.h"


static const char *TAG = "HAL COLOR CHANGE";

extern Run_struct Start_Structure;

/*******************************************************************************
 *  Function name    : Read_Colors
 *
 *  Description      : Get a value for 3 period
 *
 *  List of arguments: -
 *
 *  Return value     : -  uint16_t ---> RedFreq, BlueFreq, GreenFreq
 *
 *******************************************************************************/

void Read_Colors(void)
{
    GPIO_vSetLevel(COLOR_S0_PIN, HIGH_LEVEL);
	GPIO_vSetLevel(COLOR_S1_PIN, LOW_LEVEL);

	Color_RED();
	Color_BLUE();
	Color_GREEN();
}

void Color_RED(void)
{
    GPIO_vSetLevel(COLOR_S2_PIN, LOW_LEVEL);
	GPIO_vSetLevel(COLOR_S3_PIN, LOW_LEVEL);
    while (GPIO_iGetLevel(COLOR_OUTPUT_PIN) == 1)
	;
	int64_t echo_start = esp_timer_get_time();

	while (GPIO_iGetLevel(COLOR_OUTPUT_PIN) == 0 )
	;

    Start_Structure.u16RED_color = (uint16_t) (esp_timer_get_time() - echo_start);
}

void Color_BLUE(void)
{
    GPIO_vSetLevel(COLOR_S2_PIN, LOW_LEVEL);
	GPIO_vSetLevel(COLOR_S3_PIN, HIGH_LEVEL);
    while (GPIO_iGetLevel(COLOR_OUTPUT_PIN) == 1)
	;
        
	int64_t echo_start = esp_timer_get_time();

	while (GPIO_iGetLevel(COLOR_OUTPUT_PIN) == 0)
	;
	
    	Start_Structure.u16BLUE_color = (uint16_t) (esp_timer_get_time() - echo_start);
}

void Color_GREEN(void)
{
    GPIO_vSetLevel(COLOR_S2_PIN, HIGH_LEVEL);
	GPIO_vSetLevel(COLOR_S3_PIN, HIGH_LEVEL);
    while (GPIO_iGetLevel(COLOR_OUTPUT_PIN) == 1)
	;
        
	int64_t echo_start = esp_timer_get_time();

	while (GPIO_iGetLevel(COLOR_OUTPUT_PIN) == 0)
	;
    	Start_Structure.u16GREEN_color = (uint16_t) ( esp_timer_get_time() - echo_start);
 
}
