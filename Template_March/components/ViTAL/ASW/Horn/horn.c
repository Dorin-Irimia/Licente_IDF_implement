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

#include "ASW/Horn/horn.h"
#include "BSW/HAL/Buzzer/buzzer.h"
#include "RTE/rte.h"

static const char *TAG = "ASW HORN";

//RTE_bGET_Honk_Status
void vASW_Honk()
{   
    if(RTE_bGET_Honk_Status())
    {
        BUZZER_vChangeDutyCycle(BUZZER_PWM_START);
    }
    else
    {
        BUZZER_vChangeDutyCycle(BUZZER_PWM_STOP);
    }
}