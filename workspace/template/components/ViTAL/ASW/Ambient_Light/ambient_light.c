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

#include "ASW/Ambient_Light/ambient_light.h"

#include "RTE/rte.h"

static const char *TAG = "ASW AL";

void vASW_AMBIENT_LIGHTS(uint8_t variabila)
{
    if( RTE_GET_bIsLocked() == UNLOCKED)
    {  
        if( RTE_GET_bButtonAmbientalLights() == LIGHTS_ON)
        { 
            RTE_vSetAmbientalLightsState( LIGHTS_ON , variabila);
        }
        else if( RTE_GET_bButtonAmbientalLights() == LIGHTS_OFF)
        {     
            RTE_vSetAmbientalLightsState( LIGHTS_OFF , variabila);
        }
    }
    else if(RTE_GET_bIsLocked() == LOCKED )
    {   
       RTE_vSetShiftRegisterOutput( LOCKED, LIGHTS_OFF);
    }
}