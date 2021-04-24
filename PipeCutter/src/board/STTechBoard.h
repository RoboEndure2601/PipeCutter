#pragma once

//#ifndef STTechBoard_h_
//#define STTechBoard_h_

#include "Configuration.h"

//#if NOT_TARGET(__AVR_ATmega1280__, __AVR_ATmega2560__)
//    #error "Oops! Select 'Arduino/Genuino Mega or Mega 2560' in 'Tools > Board.'"
//#endif

#define BOARD_INFO_NAME "STTECH_1"

#define SERVO_STEP_PIN                           36
#define SERVO_DIR_PIN                            34

#define ENCODER_PHASE_A_PIN                      2
#define ENCODER_PHASE_B_PIN                      3

#define NEXTION_DISPLAY_RX_PIN                   19
#define NEXTION_DISPLAY_TX_PIN                   18

//#endif

#pragma endregion