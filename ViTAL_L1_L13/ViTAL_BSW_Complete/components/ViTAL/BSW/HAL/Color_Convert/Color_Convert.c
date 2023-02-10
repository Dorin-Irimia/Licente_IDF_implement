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
    const uint8_t ValFreq = 0;  
	PROX_vRequest();
	while (GPIO_iGetLevel(TCS230_OUTPUT_PIN) == 1)
            {
                ValFreq++;
            }
	return (uint8_t) (ValFreq);
}
