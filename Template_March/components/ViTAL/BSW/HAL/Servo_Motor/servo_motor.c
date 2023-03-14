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

#include "BSW/HAL/Servo_Motor/servo_motor.h"
#include "BSW/HAL/Com/com.h"


#include "BSW/MCAL/PWM/pwm.h"  

extern COM_POST_struct g_POST_DataStructure;

static const char *TAG = "HAL SERVO MOTOR";

/*******************************************************************************
 *  Function name    : SERVO_vChangeAngle
 *
 *  Description      : Change the Servo Motor angle
 *
 *  List of arguments: u32ServoAngle -> PWM duty cycle for this angle
 *
 *  Return value     : -
 *
 *******************************************************************************/
void SERVO_vChangeAngle(void)

{
 uint16_t potVal;   
double InputStart = 0;      // 0 is first value at the first range
double InputStop = 180;      // 10 is last value at the first range

double OutputStart = 550;     // 0 is first value at the second range
double OutputStop = 2000;    // 100 is a last value at the second range





  potVal = ( g_POST_DataStructure.u16S1Val  - InputStart ) / ( InputStop - InputStart ) * ( OutputStop - OutputStart ) + OutputStart;  
     PWM_vSetDutyCycle(SERVO_MOTOR_1_PWM_CHANNEL, potVal);

   potVal = ( g_POST_DataStructure.u16S2Val  - InputStart ) / ( InputStop - InputStart ) * ( OutputStop - OutputStart ) + OutputStart;  
     PWM_vSetDutyCycle(SERVO_MOTOR_2_PWM_CHANNEL, potVal);
   
   potVal = ( g_POST_DataStructure.u16S3Val  - InputStart ) / ( InputStop - InputStart ) * ( OutputStop - OutputStart ) + OutputStart;  
     PWM_vSetDutyCycle(SERVO_MOTOR_3_PWM_CHANNEL, potVal);
 
   potVal = ( g_POST_DataStructure.u16S4Val  - InputStart ) / ( InputStop - InputStart ) * ( OutputStop - OutputStart ) + OutputStart;  
     PWM_vSetDutyCycle(SERVO_MOTOR_4_PWM_CHANNEL, potVal);
 
   potVal = ( g_POST_DataStructure.u16S5Val  - InputStart ) / ( InputStop - InputStart ) * ( OutputStop - OutputStart ) + OutputStart;  
     PWM_vSetDutyCycle(SERVO_MOTOR_5_PWM_CHANNEL, potVal);
 
   potVal = ( g_POST_DataStructure.u16S6Val  - InputStart ) / ( InputStop - InputStart ) * ( OutputStop - OutputStart ) + OutputStart;  
     PWM_vSetDutyCycle(SERVO_MOTOR_6_PWM_CHANNEL, potVal);
 
 


    /*
    //                this is a old code for control and return to 0 pozition

    // For compatibility reasons, rotation will be used as angle
    // Initialize static variable to retain the old value given to the angle
    static uint32_t u32OldAngle = SERVOMOTOR_STOP_DC_1;

    // Change the current angle only if it is CW or CCW and is different from the old angle given
    if ((u32OldAngle != u32ServoAngle) && (u32ServoAngle != SERVOMOTOR_STOP_DC_1))
    {
        
        // Update the PWM in order to change the rotation direction. Defaults to no rotation.
        switch (u32ServoAngle)
        {
        case SERVOMOTOR_CW_DC_1:
            PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, SERVOMOTOR_CW_DC_1);
            break;
        case SERVOMOTOR_CCW_DC_1:
            PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, SERVOMOTOR_CCW_DC_1);
            break;
        default:
            PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, SERVOMOTOR_STOP_DC_1);
            break;
        }
    }
    // Stop the servomotor
    else
    {
        PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, SERVOMOTOR_STOP_DC_1);
    }

    // Store the current rotation given
    u32OldAngle = u32ServoAngle;
    *******************************************/

       // PWM_vSetDutyCycle(SERVO_MOTOR_1_PWM_CHANNEL, u32ServoAngle1);  //for has a single movements is this code
      //   PWM_vSetDutyCycle(SERVO_MOTOR_2_PWM_CHANNEL, u32ServoAngle2); 

       


}

