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

#include "BSW/MCAL/PWM/pwm.h"

#include "driver/ledc.h"

static const char *TAG = "MCAL PWM";

static ledc_channel_config_t ledc_channel[PWM_CHANNELS] = {
	{.channel = SERVO_MOTOR_PWM_CHANNEL,
	 .duty = 0,
	 .gpio_num = SERVO_MOTOR_PWM_PIN,
	 .speed_mode = LEDC_LOW_SPEED_MODE,
	 .hpoint = 0,
	 .timer_sel = LEDC_TIMER_1},
	{.channel = DC_MOTOR_PWM_CHANNEL,
	 .duty = 0,
	 .gpio_num = DC_MOTOR_PWM_PIN,
	 .speed_mode = LEDC_LOW_SPEED_MODE,
	 .hpoint = 0,
	 .timer_sel = LEDC_TIMER_1},
	{.channel = BUZZER_PWM_CHANNEL,
	 .duty = 0,
	 .gpio_num = BUZZER_PWM_PIN,
	 .speed_mode = LEDC_LOW_SPEED_MODE,
	 .hpoint = 0,
	 .timer_sel = LEDC_TIMER_1}};

/*******************************************************************************
 *  Function name    : PWM_vInit
 *
 *  Description      : Initial configuration of MCAL PWM
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 ******************************************************************************/
void PWM_vInit(void)
{
	uint8_t channel = 0;

	ledc_timer_config_t ledc_timer = {
		.duty_resolution = LEDC_TIMER_13_BIT, // resolution of PWM duty
		.freq_hz = PWM_FREQUENCY,			  // frequency of PWM signal
		.speed_mode = LEDC_LOW_SPEED_MODE,	  // timer mode
		.timer_num = LEDC_TIMER_1,			  // timer index
		.clk_cfg = LEDC_AUTO_CLK,			  // Auto select the source clock
	};

	ledc_timer_config(&ledc_timer);

	for (channel = 0; channel < PWM_CHANNELS; channel++)
	{
		ledc_channel_config(&ledc_channel[channel]);
	}

	ledc_fade_func_install(0);
}

/*******************************************************************************
 *  Function name    : PWM_vSetDutyCycle
 *
 *  Description      : Set duty cycle for a specific channel
 *
 *  List of arguments: u8Channel -> Channel where to change duty cycle
 *                     u32DutyCycle -> Period of duty cycle
 *
 *  Return value     : -
 *
 ******************************************************************************/
void PWM_vSetDutyCycle(uint8_t u8Channel, uint32_t u32DutyCycle)
{
	// Limit DutyCycle maximum period to 20ms
	if (u32DutyCycle > 20000)
	{
		u32DutyCycle = 20000;
	}

	// Calculate DutyCycle
	u32DutyCycle = u32DutyCycle * 8192 / 20000;

	// Update DutyCycle
	ledc_set_duty(ledc_channel[u8Channel].speed_mode, ledc_channel[u8Channel].channel, u32DutyCycle);
	ledc_update_duty(ledc_channel[u8Channel].speed_mode, ledc_channel[u8Channel].channel);
}
