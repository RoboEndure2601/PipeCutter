#include <Arduino.h>
#include "PipeCutterCore.h"
#include "Display/display.h"
#include "board/pin.h"
#include "encoder/encoder.h"

encoder Encoder(ENCODER_PHASE_A_PIN,ENCODER_PHASE_B_PIN);

void setup() {
  // put your setup code here, to run once:
  pinModes();
  PushCallPopCall();

  // use for serial debug connection or pc based connetion
  Serial.begin(115200);

  // use for Nextion Display connection
  Serial1.begin(9600);
  Serial1.print("baud = 115200");
  Serial1.end();
  Serial1.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //getting new position
  NextionIDLE();
  
  Encoder.updateEncoder();
}