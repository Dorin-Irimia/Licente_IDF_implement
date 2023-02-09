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

#include "ASW/Headlights/headlights.h"

#include "RTE/rte.h"

static const char *TAG = "ASW HL";

void vASW_Headlights()
{       
    if( RTE_bGETButtonHeadlights()== HEADLIGHTS_ON && RTE_GET_bIsLocked()== UNLOCKED)
    {   
        if( RTE_GET_PhotoRes() < X_LEVEL )  
        { 
            RTE_vSETHeadlights_State(HEADLIGHTS_ON);
        }
        else if( RTE_GET_PhotoRes() >= X_LEVEL )
        {   
            RTE_vSETHeadlights_State(HEADLIGHTS_OFF;
        }
    }
    else
    {   
        RTE_vSETHeadlights_State(HEADLIGHTS_OFF); 
    }
}