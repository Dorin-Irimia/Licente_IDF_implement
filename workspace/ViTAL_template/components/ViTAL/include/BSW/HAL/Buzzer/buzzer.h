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

#ifndef COMPONENTS_VITAL_BSW_HAL_BUZZER_H
#define COMPONENTS_VITAL_BSW_HAL_BUZZER_H

#include "global.h"

void BUZZER_vChangeDutyCycle(uint32_t u32BuzzerDutyCycle);

/* Buzzer PWMs for sound */
#define BUZZER_PWM_STOP 0
#define BUZZER_PWM_START 1000

#endif
