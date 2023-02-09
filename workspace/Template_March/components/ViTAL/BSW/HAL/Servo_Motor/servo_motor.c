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

#include "BSW/MCAL/PWM/pwm.h"  


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
void SERVO_vChangeAngle(uint32_t u32ServoAngle)
{

    /******************************
    // For compatibility reasons, rotation will be used as angle
    // Initialize static variable to retain the old value given to the angle
    static uint32_t u32OldAngle = SERVOMOTOR_STOP_DC;

    // Change the current angle only if it is CW or CCW and is different from the old angle given
    if ((u32OldAngle != u32ServoAngle) && (u32ServoAngle != SERVOMOTOR_STOP_DC))
    {
        // Update the PWM in order to change the rotation direction. Defaults to no rotation.
        switch (u32ServoAngle)
        {
        case SERVOMOTOR_CW_DC:
            PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, SERVOMOTOR_CW_DC);
            break;
        case SERVOMOTOR_CCW_DC:
            PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, SERVOMOTOR_CCW_DC);
            break;
        default:
            PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, SERVOMOTOR_STOP_DC);
            break;
        }
    }
    // Stop the servomotor
    else
    {
        PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, SERVOMOTOR_STOP_DC);
    }

    // Store the current rotation given
    u32OldAngle = u32ServoAngle;

    *************************/
   PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, SERVOMOTOR_STOP_DC);
}
