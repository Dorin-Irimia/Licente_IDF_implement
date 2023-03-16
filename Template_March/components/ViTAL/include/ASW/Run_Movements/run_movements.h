#ifndef COMPONENTS_VITAL_RUN_MOVEMENTS_SYSTEM_H
#define COMPONENTS_VITAL_RUN_MOVEMENTS_SYSTEM_H

#include "global.h"

extern void Run_Movement();

#endif



typedef struct
{
	bool bLineStatus;
	bool bObjectStatus;
    bool bColorStatus; 
    bool bSTEPMotorLeft;
	bool bSTEPMotorRight;
    bool bSensorLineLeft;
    bool bSensorLineRight;
    uint16_t u16RED_color;
    uint16_t u16BLUE_color;
	uint16_t u16GREEN_color;

}Run_struct;
