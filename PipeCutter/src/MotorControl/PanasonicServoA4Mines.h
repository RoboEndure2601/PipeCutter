#pragma once

#include "src/board/STTechBoard.h"
#include "SpeedyStepper/src/SpeedyStepper.h"
#include "Configuration.h"

SpeedyStepper PanasonicA4mines;

//define variable for Panasonic A4 mines motor control
 int PPR_value = 4000; // This value set in Panasonic A4 Series Servo drive
 int speed = 100;

 long runValue_input = 0;
 unsigned long move = 0;

 float feetToMm = 304.8;  // mm
 float inchToMm = 25.4;   // mm
 float mmToMm   = 1;      // mm

 //upcoming version support Accelaretion and Deaccelaretion for more power and accuray
void Accel()
{

}

void Deaccel()
{

}

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
    PanasonicA4mines.setSpeedInStepsPerSecond(4000);
    PanasonicA4mines.setAccelerationInRevolutionsPerSecondPerSecond(2500);

    PanasonicA4mines.moveRelativeInSteps(12000000L);
    
    delay(1000);
}

int checking_type()
{
    if(feet_state == 1)
    {
        inch_state = 0;
        mm_state = 0;
        return feet_state;
    }
    else if(inch_state == 1)
    {
        feet_state = 0;
        mm_state = 0;
        return inch_state;
    }
    else if(mm_state == 1)
    {
        feet_state = 0;
        inch_state = 0;
        return mm_state;
    }
    else
    {
        feet_state = 0;
        inch_state = 0;
        mm_state = 0;
        return 0;
    }
}

long moveCalculator()
{
    checking_type();

    if(feet_state == 1)
    {
        move = runValue_input * feetToMm;
        
        return move;    
    }
    else if(feet_state == 1)
    {
        move = runValue_input * inchToMm;
        
        return move;
    }
    else if(feet_state == 1)
    {
        move = runValue_input * mmToMm;

        return move;
    }
}

void MoveToPosition()
{
    //PanasonicA4mines.setSpeedInStepsPerSecond(4000);
    //PanasonicA4mines.setAccelerationInRevolutionsPerSecondPerSecond(2500);

    //PanasonicA4mines.moveRelativeInSteps(move);

    // defualt setting for panasonic servo motor drive
    PanasonicA4mines.setStepsPerMillimeter(52.49);
    PanasonicA4mines.setSpeedInMillimetersPerSecond(100);
    PanasonicA4mines.setAccelerationInMillimetersPerSecondPerSecond(50);

    PanasonicA4mines.moveToPositionInMillimeters(moveCalculator());
}