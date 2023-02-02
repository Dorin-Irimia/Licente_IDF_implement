
#ifndef COMPONENTS_VITAL_BSW_HAL_BUZZER_H
#define COMPONENTS_VITAL_BSW_HAL_BUZZER_H

#include "global.h"

void BUZZER_vChangeDutyCycle(uint32_t u32BuzzerDutyCycle);

/* Buzzer PWMs for sound */
#define BUZZER_PWM_STOP 0
#define BUZZER_PWM_START 1000

#endif
