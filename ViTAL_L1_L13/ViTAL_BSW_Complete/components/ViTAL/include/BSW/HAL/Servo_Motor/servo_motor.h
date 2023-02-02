
#ifndef COMPONENTS_VITAL_BSW_HAL_SERVO_MOTOR_H
#define COMPONENTS_VITAL_BSW_HAL_SERVO_MOTOR_H

#include "global.h"

void SERVO_vChangeAngle(uint32_t u32ServoAngle);

#define SERVOMOTOR_CW_DC 1400
#define SERVOMOTOR_STOP_DC 1500
#define SERVOMOTOR_CCW_DC 1600

#endif
