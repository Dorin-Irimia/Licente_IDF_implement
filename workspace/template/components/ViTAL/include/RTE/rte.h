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

#ifndef COMPONENTS_VITAL_RTE_H
#define COMPONENTS_VITAL_RTE_H

#include "global.h"

extern bool RTE_bGET_TRUNK_STATUS();
extern bool RTE_bGET_DOORLOCK_STATUS();
extern bool RTE_bGET_FAN_STATUS();
extern int RTE_bGETHONK_STATUS();
extern bool RTE_bGET_HEADLIGHTS_STATUS();
extern bool RTE_bGET_AMBIENTAL_LIGHTS_STATUS();
extern int RTE_bGET_FINDMYCAR_STATUS();
extern bool RTE_bGET_SECURITY_STATUS();
extern uint8_t RTE_bGETUserTemp();

#define HIGH 1
#define LOW 0
#define ON 1
#define OFF 0

typedef enum
{
	LOCK_GREEN = (uint8_t)(1 << 1),
	LOCK_RED = (uint8_t)(1 << 0),
	RGB_RED_POS = (uint8_t)(1 << 5),
	RGB_GREEN_POS = (uint8_t)(1 << 6),
	RGB_BLUE_POS = (uint8_t)(1 << 4),
	HEAD_LIGHTS_POS = (uint8_t)((1 << 3) | (1 << 2))
} shift_register_positions_t;

typedef enum
{
	RED = RGB_RED_POS,
	GREEN = RGB_GREEN_POS,
	BLUE = RGB_BLUE_POS,
	RED_GREEN = RGB_RED_POS | RGB_GREEN_POS,
	RED_BLUE = RGB_RED_POS | RGB_BLUE_POS,
	GREEN_BLUE = RGB_GREEN_POS | RGB_BLUE_POS,
	ALL_COLORS = RGB_RED_POS | RGB_GREEN_POS | RGB_BLUE_POS
} rgb_states_masks_t;

typedef enum
{
	STATE_RED ,
	STATE_GREEN,
	STATE_BLUE,
	STATE_RED_GREEN,
	STATE_RED_BLUE,
	STATE_GREEN_BLUE,
	STATE_ALL_COLORS
} rgb_states_t;

void RTE_SERVO_vChangeAngle(uint32_t u32ServoAngle);
void RTE_BUZZER_vChangeDutyCycle(uint32_t u32BuzzerDutyCycle);
void RTE_DCMOT_vChangeSpeed(uint32_t u32DCMotorSpeed);
void RTE_SET_BISOCCUPIED(bool bisOccupied);
void RTE_SET_BISLOCKED(bool bisLocked);
void RTE_SET_PHOTORES(uint16_t PhotoRes);
void RTE_SET_COMFORT(uint8_t Comfort);
void RTE_SET_TEMPERATURE(uint8_t Temp);
void RTE_SET_HUMIDITY(uint8_t Hum);
uint8_t RTE_bGETUserTemp();
bool RTE_GET_bIsOccupied();
bool RTE_GET_bIsLocked();
uint16_t RTE_GET_PhotoRes();
uint8_t RTE_GET_COMFORT();
uint8_t RTE_GET_HUMIDITY();
uint8_t RTE_GET_TEMPERATURE();
void RTE_SET_ButtonFan(bool ButtonFan);
bool RTE_bGETButtonFan();
int RTE_bGETButtonFindMyCar();
void RTE_SET_ButtonFindMyCar(bool ButtonFindMyCar );
bool RTE_bGETButtonHeadlights();
void RTE_SET_bButtonHeadlights(bool bButtonHeadlights);
void RTE_vSETHeadlights_State(bool bState);
void RTE_vSetShiftRegisterOutput(shift_register_positions_t u8ComponentMask,
uint8_t bLevel);
void RTE_vSetAmbientalLightsState(bool bState,uint8_t variabila);
bool RTE_GET_bButtonAmbientalLights();
void RTE_SET_bButtonAmbientalLights(bool bButtonAmbientalLights);
void RTE_SET_bButtonSecurity(bool bButtonSecurity);
bool RTE_GET_bButtonSecurity();

#endif
