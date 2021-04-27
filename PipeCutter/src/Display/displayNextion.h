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
NexNumber runValue = NexNumber(1, 7, "runValue");

NexButton forward = NexButton(1, 1, "forward");
NexButton backward = NexButton(1, 2, "backward");

NexDSButton feet = NexDSButton(1, 6, "feet");
NexDSButton inch = NexDSButton(1, 5, "inch");
NexDSButton mm = NexDSButton(1, 4, "mm");

NexTouch *nex_listen_list[] =
{
  &runValue,
  &feet,
  &inch,
  &mm,
  &forward,
  &backward,
  NULL  // String terminated
};  // End of touch event list


void NextionIDLE()
{
    nexLoop(nex_listen_list);
}

void runValuePopCallback(void *ptr)//for release
{
  nexSerial.println("runValuePopCallback");
  runValue.setValue(150);
}

void forwardPopCallback(void *ptr)//for release
{
  uint32_t number;
    
  nexSerial.println("runValuePopCallback");

  runValue.getValue(&number);
    
  number += 1;
    
  runValue.setValue(number);
}

void backwardPopCallback(void *ptr)//for release
{
}


// dual state button custom code because
// I not able to use directly from Nextion Diaply Library

const boolean SWITCH_ON = 1;
const boolean SWITCH_OFF = 0;

byte received_data[1];
int  switch_pos;
boolean feet_state = 0;
boolean inch_state = 0;
boolean mm_state = 0;

void feetPopCallback(void *ptr)//for release
{
  int size = Serial.readBytesUntil('\n', received_data, 1);
  // First Byte has the switch position data
  feet_state = received_data[0];
  if (feet_state == SWITCH_ON)
  {
  } 
  else if (feet_state == SWITCH_OFF)
  {
  }
}
// void feetPushCallback(void *ptr)//for release
// {
//   int size = Serial.readBytesUntil('\n', received_data, 1);
//   // First Byte has the switch position data
//   feet_state = received_data[0];
//   if (feet_state == SWITCH_ON)
//    {
//     //digitalWrite(SpindleSpeedRelay,HIGH);
//   } else if (feet_state == SWITCH_OFF)
//    {
//     //digitalWrite(SpindleSpeedRelay,LOW);
//   }
// }

void inchPopCallback(void *ptr)//for release
{
  int size = Serial.readBytesUntil('\n', received_data, 1);
  // First Byte has the switch position data
  inch_state = received_data[0];
  if (inch_state == SWITCH_ON)
  {
  }
  else if (inch_state == SWITCH_OFF)
  {
  }
}
// void inchPushCallback(void *ptr)//for release
// {
//   int size = Serial.readBytesUntil('\n', received_data, 1);
//   // First Byte has the switch position data
//   feet_state = received_data[0];
//   if (feet_state == SWITCH_ON)
//    {
//     //digitalWrite(SpindleSpeedRelay,HIGH);
//   } else if (feet_state == SWITCH_OFF)
//    {
//     //digitalWrite(SpindleSpeedRelay,LOW);
//   }
// }

void mmPopCallback(void *ptr)//for release
{
  int size = Serial.readBytesUntil('\n', received_data, 1);
  // First Byte has the switch position data
  mm_state = received_data[0];
  if (mm_state == SWITCH_ON)
  {
  }
  else if (mm_state == SWITCH_OFF)
  {
  }
}
// void mmPushCallback(void *ptr)//for release
// {
//   int size = Serial.readBytesUntil('\n', received_data, 1);
//   // First Byte has the switch position data
//   feet_state = received_data[0];
//   if (feet_state == SWITCH_ON)
//    {
//     //digitalWrite(SpindleSpeedRelay,HIGH);
//   } else if (feet_state == SWITCH_OFF)
//    {
//     //digitalWrite(SpindleSpeedRelay,LOW);
//   }
// }



void PushCallPopCall()
{
  runValue.attachPop(runValuePopCallback);

  forward.attachPop(forwardPopCallback);
  backward.attachPop(backwardPopCallback);

  feet.attachPop(feetPopCallback);
  //feet.attachPush(feetPushCallback);
  
  inch.attachPop(inchPopCallback);
  //inch.attachPush(inchPushCallback);
  
  mm.attachPop(mmPopCallback);
  //mm.attachPush(mmPushCallback);
}
