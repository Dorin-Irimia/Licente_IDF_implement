
#ifndef COMPONENTS_VITAL_SRVL_SCHEDULER_H
#define COMPONENTS_VITAL_SRVL_SCHEDULER_H

#include "global.h"

void SYSTEM_vInit(void);

void vTask100ms(void);

void vTask200ms(void);

void vTask500ms(void);

void vTask800ms(void);

void vTask1000ms(void);

void vTask2000ms(void);

void vTask5000ms(void);

void SYSTEM_vTaskScheduler(void);

#define TASK_LOOP_FREQ 100

#define TASK_100MS (100 / TASK_LOOP_FREQ)
#define TASK_200MS (200 / TASK_LOOP_FREQ)
#define TASK_500MS (500 / TASK_LOOP_FREQ)
#define TASK_800MS (800 / TASK_LOOP_FREQ)
#define TASK_1000MS (1000 / TASK_LOOP_FREQ)
#define TASK_2000MS (2000 / TASK_LOOP_FREQ)
#define TASK_5000MS (5000 / TASK_LOOP_FREQ)

#endif
