#pragma once

#include <Arduino.h>
#include "src/MotorControl/PanasonicServoA4Mines.h"

boolean feet_state = 0;
boolean inch_state = 0;
boolean mm_state = 0;

String incoming;
String oneSubString;
String toint_conv;

int value;
float values;
float mm = 0.00;
int mode = 0;

 float feetToMm = 304.8;  // mm
 float inchToMm = 25.4;   // mm
 float mmToMm   = 1;      // mm
 int itof_cov   = 10;

void Serial_loop() 
{
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 0)
  {
    incoming = Serial1.readString();

    Serial.print("incoming = ");
    Serial.println(incoming);

    oneSubString = incoming;

    Serial.print("oneSubString = ");
    Serial.println(oneSubString);

    if (oneSubString.length() < 3)
    {

      Serial1.print("feet.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("inch.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("mm.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      if (oneSubString.substring(0, 2) == "ft")
      {
        mode = 1;//mode = feet

        Serial1.print("feet.val=1");
      }
      if (oneSubString.substring(0, 2) == "in")
      {
        mode = 2;//mode = inch

        Serial1.print("inch.val=1");
      }
      if (oneSubString.substring(0, 2) == "mm")
      {
        mode = 3;//mode = mm

        Serial1.print("mm.val=1");
      }

      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      Serial.print("mode = ");
      Serial.println(mode);

      //clear = true;
    }
    else
    {
      if (oneSubString.substring(0, 4) == "for1")
      {
        if (mode == 1)Serial.println("mode = feet");
        if (mode == 2)Serial.println("mode = inch");
        if (mode == 3)Serial.println("mode = mm");

        Serial.println("forward work");

        Serial1.print("forward.txt=\"Running\"");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.print("forward.val=1");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);

        toint_conv = oneSubString.substring(4);
        value = toint_conv.toInt();
        values = value;

        digitalWrite(SERVO_DIR_PIN,HIGH);
      }
      else if (oneSubString.substring(0, 5) == "back1")
      {
        if (mode == 1)Serial.println("mode = feet");
        if (mode == 2)Serial.println("mode = inch");
        if (mode == 3)Serial.println("mode = mm");

        Serial.println("backward work");

        Serial1.print("backward.txt=\"Running\"");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.print("backward.val=1");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);

        toint_conv = oneSubString.substring(5);
        value = toint_conv.toInt();
        values = value;

        digitalWrite(SERVO_DIR_PIN,LOW);
      }

      if (mode == 1) 
      {
        mm = values * feetToMm / itof_cov;
      }
      else if (mode == 2) 
      {
        mm = values * inchToMm / itof_cov;
      }
      else if (mode == 3) 
      {
        mm = values * mmToMm   / itof_cov;
      }

      Serial.print("move in mm = ");
      Serial.println(mm);

      // moving motor acording to input data
      MoveToPosition(mm);

      Serial1.print("forward.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("forward.txt=\"Forward\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("backward.val=0");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.print("backward.txt=\"Backward\"");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      //clear = true;
    }
  }
}
