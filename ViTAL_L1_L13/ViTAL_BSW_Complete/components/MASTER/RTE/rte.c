
#include "RTE/rte.h"

#include "BSW/HAL/Buzzer/buzzer.h"
#include "BSW/HAL/Com/com.h"
#include "BSW/HAL/DC_Motor/dc_motor.h"
#include "BSW/HAL/Proximity_Sensor/proximity_sensor.h"
#include "BSW/HAL/Servo_Motor/servo_motor.h"
#include "BSW/HAL/Shift_Register/shift_register.h"

static const char *TAG = "RTE";

extern COM_GET_struct g_GET_DataStructure;
extern COM_POST_struct g_POST_DataStructure;
