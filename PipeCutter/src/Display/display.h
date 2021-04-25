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

NexTouch *nex_listen_list[] =
{
  NULL  // String terminated
};  // End of touch event list

//save setting for esch type of paper
void softSavePopCallback(void *ptr)//for release
{
    String save = Serial.readString();
}

const int SWITCH_ON = 1;
const int SWITCH_OFF = 0;

byte received_data[1];
int  switch_pos;
int spindle_switch_pos;

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
  spindleSpeed.attachPop(spindleSpeedPopCallback);
}

void NextionIDLE()
{
    nexLoop(nex_listen_list);
}