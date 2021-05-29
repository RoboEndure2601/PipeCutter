#include <Arduino.h>
#include "PipeCutterCore.h"
#include "Display/displayCustom.h"
#include "board/pin.h"
//#include "board/STTechBoard.h"
#include "src/MotorControl/encoder/encoder.h"
#include "MotorControl/PanasonicServoA4Mines.h"
#include "src/MotorControl/ClosedLoopStepper/ClosedLoopStepper.h"
#include "src/MotorControl/ClosedLoopStepper/StepperSpeedControler.h"


ClosedLoopStepper cls;

void setup() 
{
  // put your setup code here, to run once:

  // Nextion Display intrrupt call setting defined in this function
  // If you dont want to use Nextion Display then just comment this line
  //nexInit();
  //PushCallPopCall();

  // use for serial debug connection or pc based connetion
  // If don't need serial data output on your device just 
  //comment this line
  //Serial.begin(115200);

  // use for Nextion Display connection
  // If you dont want to use Nextion Display then just comment this line
  Serial.begin(115200);
  //Serial.print("baud = 115200");
  //Serial.end();
  Serial1.begin(9600);

  pinModes();

  // If you use custom motor setting then just change in funtion 
  // define that motor function here
  // and comment this line 
  PanasonicA4mines_setup();

  // intrrupt for encoder input 
  // this line included in PanasonicA4mines_setup() check there for changes
  //attachInterrupt(digitalPinToInterrupt(ENCODER_PHASE_A_PIN), checkPosition, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(ENCODER_PHASE_B_PIN), checkPosition, CHANGE);

  //motor test
  //defaultSetting();
}

void loop() 
{
  // we going to use intrrupt in next version 
  // wait until or modify by your self
  //EncoderPosition();// this function give us position of encoder at time

  // taking action based on Nextion Display Input for Arduino or MCU
  //NextionIDLE();

  // when any command given then it's one work
  Serial_loop();
}