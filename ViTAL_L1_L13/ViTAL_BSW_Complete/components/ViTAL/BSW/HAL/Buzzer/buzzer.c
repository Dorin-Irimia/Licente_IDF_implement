
#include "BSW/HAL/Buzzer/buzzer.h"

#include "BSW/MCAL/PWM/pwm.h"

static const char *TAG = "HAL BUZZER";

/*******************************************************************************
 *  Function name    : BUZZER_vChangeDutyCycle
 *
 *  Description      : Change the Buzzer sound
 *
 *  List of arguments: u32BuzzerDutyCycle -> PWM duty cycle for sound
 *
 *  Return value     : -
 *
 *******************************************************************************/
void BUZZER_vChangeDutyCycle(uint32_t u32BuzzerDutyCycle)
{
	if (u32BuzzerDutyCycle == BUZZER_PWM_STOP)
	{
		PWM_vSetDutyCycle(BUZZER_PWM_CHANNEL, BUZZER_PWM_STOP);
	}

	else if (u32BuzzerDutyCycle == BUZZER_PWM_START)
	{
		PWM_vSetDutyCycle(BUZZER_PWM_CHANNEL, BUZZER_PWM_START);
	}

	else
	{
		ESP_LOGI(TAG, "Invalid value");
	}
}
