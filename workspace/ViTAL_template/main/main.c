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

#include "global.h"

#include "SRVL/SCHEDULER/scheduler.h"

void app_main(void)
{
	SYSTEM_vInit();

	SYSTEM_vTaskScheduler();
}
