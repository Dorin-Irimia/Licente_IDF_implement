
#include "global.h"

#include "SRVL/SCHEDULER/scheduler.h"

void app_main(void)
{
	SYSTEM_vInit();

	SYSTEM_vTaskScheduler();
}
