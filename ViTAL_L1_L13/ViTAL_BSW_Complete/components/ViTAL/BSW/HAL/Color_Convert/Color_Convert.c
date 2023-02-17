#include "BSW/HAL/Color_Control/Color_Control.h"

static const char *TAG = "HAL_COLOR_CONTROL";




void COLOR_CONTROL_vInitColor(void)
{
    GPIO_vSetLevel(TCS230_S0_PIN,HIGH_LEVEL);
    GPIO_vSetLevel(TCS230_S1_PIN,HIGH_LEVEL);
}

uint16_t COLOR_CONTROL_vReadColor(void)
{
    GPIO_vSetLevel(TCS230_S0_PIN,LOW_LEVEL);
    GPIO_vSetLevel(TCS230_S1_PIN,HIGH_LEVEL);
    
    while (GPIO_iGetLevel(TCS230_OUTPUT_PIN) == 0)
		;

	int64_t echo_start = esp_timer_get_time();

	while (GPIO_iGetLevel(TCS230_OUTPUT_PIN))
		;


	return (int64_t) (esp_timer_get_time());
}
