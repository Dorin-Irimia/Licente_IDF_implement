#include "ASW/Run_Movement/run_movements.h"

static const char *TAG = "ASW RUN MOVEMENT";

Run_struct Start_Structure =
{   .bLineStatus = false,
    .bObjectStatus = false, 
    .bColorStatus = false,
    .bSTEPMotorLeft = false,
    .bSTEPMotorRight = false,
    .u16RED_COLOR,
    .u16BLUE_COLOR,
    .u16GREEN_COLOR,
    .bSensorLineLeft,
    .bSensorLineRight};


void Run_Movement(void)
{
    if(g_POST_DataStructure.bButtonRun)
    {
        if(Run_struct.bLineStatus)
        {
             if(Run_struct.bObjectStatus)
             {
                Run_struct.bSTEPMotorLeft = false;
                Run_struct.bSTEPMotorRight = false;

                // verificam culoarea obiectului 

                    if(Run_struct.u16RED_COLOR < Run_struct.u16BLUE_COLOR) && (Run_struct.u16RED_COLOR < Run_struct.u16GREEN_COLOR))
                        g_POST_DataStructure.bButtonRedExe = true;
                    else if(Run_struct.u16BLUE_COLOR < Run_struct.u16RED_COLOR) && (Run_struct.u16BLUE_COLOR < Run_struct.u16GREEN_COLOR))
                        g_POST_DataStructure.bButtonBlueExe = true;
                    else
                        // asteapta comanda
             }
             else
             {
                Run_struct.bSTEPMotorLeft = Run_struct.bSensorLineLeft;
                Run_struct.bSTEPMotorRight = Run_struct.bSensorLineRight;
             }
             
        }
        else
    }

} 