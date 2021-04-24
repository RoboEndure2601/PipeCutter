#pragma once

#include "Nextion/Nextion.h"

//define variable for communication

//guess page number for skip lag
int pageNumber;
/*
//page number name declaration
boolean startPage = false; //pageNumber = 0;
boolean homePage = false; //pageNumber = 1;
boolean settingPage = false; //pageNumber = 2;
boolean ManualPage = false; //pageNumber = 3;
boolean AutoPage = false; //pageNumber = 4;
boolean ErrorPage = false; //pageNumber = 5;
boolean keybdAPage = false; //pageNumber = 6;
boolean keybdBPage = false; //pageNumber = 7;
boolean keybdCPage = false; //pageNumber = 8;
boolean softPaperPage = false; //pageNumber = 9;
boolean mediumPaperPage = false; //pageNumber = 10;
boolean hardPaperPage = false; //pageNumber = 11;
boolean customPaperPage = false; //pageNumber = 12;
boolean factoryResetPage = false; //pageNumber = 13;
boolean paperProgPage = false; //pageNumber = 14;
boolean noQtyPage = false; //pageNumber = 15;
*/
// Declare objects that we are going to read from the display. This includes buttons, sliders, text boxes, etc:
// Format: <type of object> <object name> = <type of object>(<page id>, <object id>, "<object name>");
/* ***** Types of objects:
   NexButton - Button
   NexDSButton - Dual-state Button
   NexHotspot - Hotspot, that is like an invisible button
   NexCheckbox - Checkbox
   NexRadio - "Radio" checkbox, that it's exactly like the checkbox but with a rounded shape
   NexSlider - Slider
   NexGauge - Gauge
   NexProgressBar - Progress Bar
   NexText - Text box
   NexScrolltext - Scroll text box
   NexNumber - Number box
   NexVariable - Variable inside the nextion display
   NexPage - Page touch event
   NexGpio - To use the Expansion Board add-on for Enhanced Nextion displays
   NexRtc - To use the real time clock for Enhanced Nextion displays
 * *****
*/

//variables of settingPage
NexButton factoryReset = NexButton(2, 8, "reset");

//variables of ManualPage
NexButton waterRelay = NexButton(3, 8, "waterR");
NexButton oilRelay = NexButton(3, 9, "oilR");
NexButton batterRelay = NexButton(3, 10, "batterR");
NexDSButton sprederRelay = NexDSButton(3, 12, "sprederR");
NexButton stepper = NexButton(3, 11, "Stepper");
NexDSButton spindleSpeed = NexDSButton(3, 13, "SSpeed");
NexButton tempareture = NexButton(3, 14, "tempOutput");
NexNumber tempSetPoint = NexNumber(3, 16, "setPoint");
NexNumber manualTemp = NexNumber(3, 6, "temp");

//variable of AutoPage
NexText paperType = NexText(4, 6, "type");
NexNumber paperQty = NexNumber(4, 5, "qty");
NexButton startProgress = NexButton(4, 8, "startAuto");

//variable of ErrorPage

//variable of softPaperPage
NexNumber softTemp = NexNumber(9, 15, "temp");
NexNumber softWater = NexNumber(9, 11, "water");
NexNumber softOil = NexNumber(9, 12, "oil");
NexNumber softSpreder = NexNumber(9, 13, "spreder");
NexNumber softBatter = NexNumber(9, 14, "batter");
NexButton softSave = NexButton(9, 5, "save");
//variable of mediumPaperPage
NexNumber mediumTemp = NexNumber(10, 15, "temp");
NexNumber mediumWater = NexNumber(10, 11, "water");
NexNumber mediumOil = NexNumber(10, 12, "oil");
NexNumber mediumSpreder = NexNumber(10, 13, "spreder");
NexNumber mediumBatter = NexNumber(10, 14, "batter");
NexButton mediumSave = NexButton(10, 5, "save");
//variable of hardPaperPage
NexNumber hardTemp = NexNumber(11, 15, "temp");
NexNumber hardWater = NexNumber(11, 11, "water");
NexNumber hardOil = NexNumber(11, 12, "oil");
NexNumber hardSpreder = NexNumber(11, 13, "spreder");
NexNumber hardBatter = NexNumber(11, 14, "batter");
NexButton hardSave = NexButton(11, 5, "save");
//variable of customPaperPage
NexNumber customTemp = NexNumber(12, 15, "temp");
NexNumber customWater = NexNumber(12, 11, "water");
NexNumber customOil = NexNumber(12, 12, "oil");
NexNumber customSpreder = NexNumber(12, 13, "spreder");
NexNumber customBatter = NexNumber(12, 14, "batter");
NexButton customSave = NexButton(12, 5, "save");

//variable of paperProgPage
NexNumber AutoTempareture = NexNumber(14, 6, "temp");
NexNumber AutoQtyMade = NexNumber(14, 11, "qtyMade");
NexNumber AutoQty = NexNumber(14, 12, "qty");
NexButton AutoStop = NexButton(14, 7, "stop");

NexTouch *nex_listen_list[] =
{
  //variables of settingPage
  &factoryReset,


  //variables of ManualPage
  &waterRelay,
  &oilRelay,
  &batterRelay ,
  &sprederRelay ,
  &stepper ,
  &spindleSpeed ,
  &tempareture ,
  &tempSetPoint,
  &manualTemp ,

  //variable of AutoPage
  &paperType,
  &paperQty,
  &startProgress,

  //variable of ErrorPage

  //variable of softPaperPage
  &softTemp,
  &softWater,
  &softOil ,
  &softSpreder,
  &softBatter ,
  &softSave ,
  //variable of mediumPaperPage
  &mediumTemp ,
  &mediumWater ,
  &mediumOil ,
  &mediumSpreder ,
  &mediumBatter ,
  &mediumSave ,
  //variable of hardPaperPage
  &hardTemp ,
  &hardWater ,
  &hardOil ,
  &hardSpreder ,
  &hardBatter ,
  &hardSave ,
  //variable of customPaperPage
  &customTemp ,
  &customWater ,
  &customOil,
  &customSpreder ,
  &customBatter,
  &customSave ,

  //variable of paperProgPage
  &AutoTempareture,
  &AutoQtyMade,
  &AutoQty,
  &AutoStop,
  NULL  // String terminated
};  // End of touch event list

//save setting for esch type of paper
void softSavePopCallback(void *ptr)//for release
{
    String save = Serial.readString();
}
void mediumSavePopCallback(void *ptr)//for release
{
    String save = Serial.readString();
}
void hardSavePopCallback(void *ptr)//for release
{
    String save = Serial.readString();
}
void customSavePopCallback(void *ptr)//for release
{
    String save = Serial.readString();
}

const int SWITCH_ON = 1;
const int SWITCH_OFF = 0;

byte received_data[1];
int  switch_pos;
int spindle_switch_pos;

// for water relay button
void waterRelayPushCallback(void *ptr)//for press
{
}
void waterRelayPopCallback(void *ptr)//for release
{
}

// for oil relay button
void oilRelayPushCallback(void *ptr)//for press
{
}
void oilRelayPopCallback(void *ptr)//for release
{
}

// for batter relay button
void batterRelayPushCallback(void *ptr)//for press
{
}
void batterRelayPopCallback(void *ptr)//for release
{
}

// for spreder relay duoble state button
void sprederRelayPopCallback(void *ptr)//for release
{
    
    int size = Serial.readBytesUntil('\n', received_data, 1);
  // First Byte has the switch position data
  switch_pos = received_data[0];
  if (switch_pos == SWITCH_ON) 
  {
  } else if (switch_pos == SWITCH_OFF) 
  {
  }
}

// for remove paper relay button
void stepperPushCallback(void *ptr)//for press
{
    //digitalWrite(RemovePaperRelay,HIGH);
}
void stepperPopCallback(void *ptr)//for release
{
    //digitalWrite(RemovePaperRelay,LOW);
}

// for spinlde speed relay dual state button
void spindleSpeedPopCallback(void *ptr)//for release
{
    int size = Serial.readBytesUntil('\n', received_data, 1);
  // First Byte has the switch position data
  spindle_switch_pos = received_data[0];
  if (spindle_switch_pos == SWITCH_ON)
   {
    //digitalWrite(SpindleSpeedRelay,HIGH);
  } else if (spindle_switch_pos == SWITCH_OFF)
   {
    //digitalWrite(SpindleSpeedRelay,LOW);
  }
}

void PushCallPopCall()
{

    waterRelay.attachPush(waterRelayPushCallback);
  waterRelay.attachPop(waterRelayPopCallback);

    oilRelay.attachPush(oilRelayPushCallback);
  oilRelay.attachPop(oilRelayPopCallback);

    batterRelay.attachPush(batterRelayPushCallback);
  batterRelay.attachPop(batterRelayPopCallback);

    sprederRelay.attachPop(sprederRelayPopCallback);

    stepper.attachPush(stepperPushCallback);
  stepper.attachPop(stepperPopCallback);

  spindleSpeed.attachPop(spindleSpeedPopCallback);

}

void NextionIDLE()
{
    nexLoop(nex_listen_list);
}