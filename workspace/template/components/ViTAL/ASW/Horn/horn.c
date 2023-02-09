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

#include "ASW/Horn/horn.h"
#include "BSW/HAL/Buzzer/buzzer.h"
#include "RTE/rte.h"
#include "BSW\HAL\Com\com.h"
extern COM_POST_struct g_POST_DataStructure;
static const char *TAG = "ASW HORN";

void vASW_HORN()
{
     
    if( RTE_bGETHONK_STATUS()==1 && RTE_bGETButtonFindMyCar()==0 && RTE_GET_bIsOccupied() == 1)
    {
        RTE_BUZZER_vChangeDutyCycle(HORN_ON);
      
    }
    else 
    {
        RTE_BUZZER_vChangeDutyCycle(HORN_OFF);
        g_POST_DataStructure.bButtonHonk = 0;
    }
}
