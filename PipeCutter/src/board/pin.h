//#pragma once


#ifndef pin_h_
#define pin_h_

#include "src/Display/board.h"

void pinModes()
{
    pinMode(SERVO_DIR_PIN,OUTPUT);
    pinMode(SERVO_STEP_PIN,OUTPUT);

    pinMode(ENCODER_PHASE_A_PIN,INPUT);
    pinMode(ENCODER_PHASE_B_PIN,INPUT);

    digitalWrite(ENCODER_PHASE_A_PIN,HIGH);
    digitalWrite(ENCODER_PHASE_B_PIN,HIGH);

    
    digitalWrite(SERVO_DIR_PIN,HIGH);
}

#endif