#pragma once

#include "src/board/STTechBoard.h"
#include "src/MotorControl/encoder/encoder.h"
#include "SpeedyStepper/src/SpeedyStepper.h"
#include "Configuration.h"

SpeedyStepper PanasonicA4mines;

//define variable for Panasonic A4 mines motor control
 float PPR_value = 30.47; // This value set in Panasonic A4 Series Servo drive
 int speed = 100;
 int Encoder_PPR = 400;

/*
 //upcoming version support Accelaretion and Deaccelaretion for more power and accuray
void Accel()
{

}

void Deaccel()
{

}
*/

void PanasonicA4mines_setup()
{
    PanasonicA4mines.connectToPins(SERVO_STEP_PIN,SERVO_STEP_PIN);

    // intrrupt for encoder input 
    attachInterrupt(digitalPinToInterrupt(ENCODER_PHASE_A_PIN), checkPosition, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER_PHASE_B_PIN), checkPosition, CHANGE);

}

//used for only testing purpose
void defaultSetting()
{
    //PanasonicA4mines.setStepsPerMillimeter(4000);
}
/*
void MoveToPosition(float moving_mm)
{
    //PanasonicA4mines.setSpeedInStepsPerSecond(4000);
    //PanasonicA4mines.setAccelerationInRevolutionsPerSecondPerSecond(2500);

    //PanasonicA4mines.moveRelativeInSteps(move);

    // defualt setting for panasonic servo motor drive
    PanasonicA4mines.setStepsPerMillimeter(52.49);
    PanasonicA4mines.setSpeedInMillimetersPerSecond(100);
    PanasonicA4mines.setAccelerationInMillimetersPerSecondPerSecond(200);

    PanasonicA4mines.moveToPositionInMillimeters(moving_mm);
}
*/

void MoveToPosition(float moving_mm)
{
    unsigned long mmToMove = moving_mm * PPR_value;

    for(unsigned long i = 0; i < mmToMove ; i++)
    {
        digitalWrite(SERVO_STEP_PIN,HIGH);
        delayMicroseconds(100);
        digitalWrite(SERVO_STEP_PIN,LOW);
        delayMicroseconds(100);
    }
}