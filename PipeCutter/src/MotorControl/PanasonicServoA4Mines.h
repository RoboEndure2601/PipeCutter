#pragma once

//#include "src/board/STTechBoard.h"
#include "src/encoder/encoder.h"
#include "SpeedyStepper/src/SpeedyStepper.h"
//#include "Configuration.h"

SpeedyStepper PanasonicA4mines;

//define variable for Panasonic A4 mines motor control
 float PPR_value = 30.62; // This value set in Panasonic A4 Series Servo drive
 int max_velocity = 600;
 int max_accel = 120;
 float Minimum_ramp_distance = 1001;
 float default_accel = 10;
 
float moving_to_ramp;
float accel = 00.00;
float velocity = 00.00;



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

    PanasonicA4mines.setStepsPerMillimeter(PPR_value);
    PanasonicA4mines.setSpeedInMillimetersPerSecond(velocity);
    PanasonicA4mines.setAccelerationInMillimetersPerSecondPerSecond(accel);

}

//used for only testing purpose
void defaultSetting()
{
    //PanasonicA4mines.setStepsPerMillimeter(4000);
}

void MoveToPosition(float moving_mm)
{
    //PanasonicA4mines.setSpeedInStepsPerSecond(4000);
    //PanasonicA4mines.setAccelerationInRevolutionsPerSecondPerSecond(2500);

    //PanasonicA4mines.moveRelativeInSteps(move);

    moving_mm<Minimum_ramp_distance?moving_to_ramp=moving_mm/2:moving_to_ramp=Minimum_ramp_distance/2;
    moving_to_ramp>(Minimum_ramp_distance/2)-1?accel=max_accel:accel=default_accel;
    moving_to_ramp>(Minimum_ramp_distance/2)-1?velocity=max_velocity:velocity=20;

    // defualt setting for panasonic servo motor drive
    PanasonicA4mines.setStepsPerMillimeter(PPR_value);
    PanasonicA4mines.setSpeedInMillimetersPerSecond(velocity);
    PanasonicA4mines.setAccelerationInMillimetersPerSecondPerSecond(accel);



    PanasonicA4mines.moveToPositionInMillimeters(moving_mm);
}

void MoveToPosition2(float moving_mm)
{
    unsigned long mmToMove = moving_mm * PPR_value;

    for(unsigned long i = 0; i < 
     ; i++)
    {
        digitalWrite(SERVO_STEP_PIN,HIGH);
        delayMicroseconds(100);
        digitalWrite(SERVO_STEP_PIN,LOW);
        delayMicroseconds(100);
    }
}
