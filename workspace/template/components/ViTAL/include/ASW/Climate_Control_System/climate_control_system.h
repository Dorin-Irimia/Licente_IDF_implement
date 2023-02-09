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

#ifndef COMPONENTS_VITAL_ASW_CLIMATE_CONTROL_SYSTEM_H
#define COMPONENTS_VITAL_ASW_CLIMATE_CONTROL_SYSTEM_H

#include "global.h"

void vASW_FAN();

double vASW_Comfort_Level( uint8_t u8Temp , uint8_t u8Hum);

void vASW_Set_Fan();

#define FAN_MAX 20000
#define FAN_ON 15000
#define FAN_OFF 0
#define C1 -8.78469475556
#define C2 1.61139411
#define C3 2.33854883889
#define C4 -0.14611605
#define C5 -0.012308094
#define C6 -0.0164248277778
#define C7 0.002211732
#define C8 0.00072546
#define C9 -0.000003582

#endif
