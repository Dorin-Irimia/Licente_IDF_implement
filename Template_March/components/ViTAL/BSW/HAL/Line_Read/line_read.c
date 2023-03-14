
#include "BSW/HAL/Line_Read/line_read.h"
#include "BSW/MCAL/GPIO/gpio.h"
#include "ASW/Run_Movement/run_movements.h"

static const char *TAG = "HAL LINE READ";

/*******************************************************************************
 *  Function name    : LS_vLineRead
 *
 *  Description      : Change line status
 *
 *  List of arguments: bLineSensor -> Read road line
 *
 *  Return value     : - 
 *
 ******************************************************************************/

 void LS_vLineRead(void)
 {
    Run_struct.bSensorLineLeft = GPIO_iGetLevel(LINE_LEFT_SENSOR_PIN);
     Run_struct.bSensorLineRight  = GPIO_iGetLevel(LINE_RIGHT_SENSOR_PIN);
     if(GPIO_iGetLevel(LINE_CENTER_SENSOR_PIN);)
     {
         Run_struct.bLineStatus = true;
     }
     else
      {
         Run_struct.bLineStatus = false;
     }

 }
 
