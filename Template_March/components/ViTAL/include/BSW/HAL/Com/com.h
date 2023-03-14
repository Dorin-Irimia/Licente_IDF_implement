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

#ifndef COMPONENTS_VITAL_BSW_HAL_COM_H
#define COMPONENTS_VITAL_BSW_HAL_COM_H

#include "global.h"
  char *POI_slide ;
  uint8_t index_red;
  uint8_t index_blue;
 //uint16_t var_Slide ;

typedef struct
{
	uint8_t u8Temperature;
	uint8_t u8Humidity;
	uint8_t u8Comfort;
	uint16_t u16PhotoRes;
	bool bIsLocked;
	bool bIsOccupied;
	uint8_t u8SlideServo;
} COM_GET_struct;

typedef struct
{
	bool bButtonFan;
	bool bButtonRun;
	bool bButtonLights;
	bool bButtonLightsState;
	bool bButtonFindMyCar;
	bool bButtonHonk;
	bool bButtonSecurity;
	bool bButtonDoorLock;
	bool bButtonBlueExe;
	bool bButtonRedExe;
	
	uint8_t u8UserTemperature;
	uint16_t u16S1Val;
	uint16_t u16S2Val;
	uint16_t u16S3Val;
	uint16_t u16S4Val;
	uint16_t u16S5Val;
	uint16_t u16S6Val;
	uint16_t u16StoragePozRed[100];
	uint16_t u16StoragePozBlue[100];
	
} COM_POST_struct;

void COM_vProcessGetRequest(void);

void COM_vProcessPostRequest(void);

void COM_vTaskProcessServer(void);

#endif
