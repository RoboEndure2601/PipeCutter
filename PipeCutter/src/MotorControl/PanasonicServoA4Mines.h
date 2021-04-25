#pragma once

#include "src/board/STTechBoard.h"
#include "SpeedyStepper/src/SpeedyStepper.h"

SpeedyStepper PanasonicA4mines;

//define variable for Panasonic A4 mines motor control
 int PPR_value = 4000; // This value set in Panasonic A4 Series Servo drive

 int speed = 100;

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
}

//used for only testing purpose
void defaultSetting()
{
    PanasonicA4mines.setSpeedInStepsPerSecond(4000);
    PanasonicA4mines.setAccelerationInRevolutionsPerSecondPerSecond(2500);

    PanasonicA4mines.moveRelativeInSteps(12000000L);
    
    delay(1000);
}

void Move_mm()
{
    
}