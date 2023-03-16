
#ifndef COMPONENTS_VITAL_BSW_HAL_DC_MOTOR_H
#define COMPONENTS_VITAL_BSW_HAL_DC_MOTOR_H

#include "global.h"

void DCMOT_vChangeSpeed(uint32_t u32DCMotorSpeed);

/* Motor PWMs for speeds */
#define DC_MOTOR_STOP 0
#define DC_MOTOR_LOW_SPEED 15000
#define DC_MOTOR_FULL_SPEED 20000

#endif
