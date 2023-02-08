
#ifndef COMPONENTS_VITAL_BSW_HAL_SERVO_MOTOR_H
#define COMPONENTS_VITAL_BSW_HAL_SERVO_MOTOR_H

#include "global.h"

void SERVO_vChangeAngle(uint32_t u32ServoAngle);

#define SERVOMOTOR_CW_DC 1343 //standard value is 1400
#define SERVOMOTOR_STOP_DC 3662 //standard value is 1500
#define SERVOMOTOR_CCW_DC 5371 //standard value is 1600

#endif
