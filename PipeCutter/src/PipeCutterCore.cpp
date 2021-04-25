#include <Arduino.h>
//#include "PipeCutterCore.h"
//#include "Display/display.h"
#include "board/pin.h"
#include "board/STTechBoard.h"
#include "encoder/encoder.h"

void updateEncoder();

void setup() 
{
  // put your setup code here, to run once:

  
  //PushCallPopCall();

  // use for serial debug connection or pc based connetion
  Serial.begin(115200);

  // use for Nextion Display connection
  
  //Serial1.begin(9600);
  //Serial1.print("baud = 115200");
  //Serial1.end();
  //Serial1.begin(115200);

  pinModes();
  attachInterrupt(digitalPinToInterrupt(ENCODER_PHASE_A_PIN), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PHASE_B_PIN), checkPosition, CHANGE);
}

void loop() 
{

  EncoderPosition();// this function give us position of encoder at time
  delay(1);

  //NextionIDLE();
}