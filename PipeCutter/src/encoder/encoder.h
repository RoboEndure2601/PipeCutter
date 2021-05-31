#pragma once

//#include "src/board/STTechBoard.h"
#include "RotaryEncoder/src/RotaryEncoder.h"

// upcoming Version with private library for encoder
/*
class encoder
{
private:

protected:
    
public:
};
*/

//RotaryEncoder Library Depened
RotaryEncoder Encoder(ENCODER_PHASE_A_PIN, ENCODER_PHASE_B_PIN, RotaryEncoder::LatchMode::TWO03);

static int pos = 0;

void checkPosition()
{
    Encoder.tick();
}

void EncoderPosition()
{
    int newPos = Encoder.getPosition();
    if (pos != newPos) {
        Serial.print("pos:");
        Serial.print(newPos);
        Serial.print(" dir:");
        Serial.println((int)(Encoder.getDirection()));
        pos = newPos;
    } // if
}

/* 
    In this Function we gone count encoder position 
    current position = Zero
    last position    = Given 
*/
void CountPosition()
{

}