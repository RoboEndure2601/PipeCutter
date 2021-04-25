#pragma once

//#include "Configuration.h"

// update for upcoming version 
// new update gone suppourt multiple arduino board and other boards
/*
#if defined(__AVR_ATmega2560__)
   #error "Oops! Select 'Arduino/Genuino Mega or Mega 2560' in 'Tools > Board.'"
#endif
*/

#define BOARD_INFO_NAME "ST_TECH 1"

#define SERVO_STEP_PIN                           5
#define SERVO_DIR_PIN                            6

#define ENCODER_PHASE_A_PIN                      2
#define ENCODER_PHASE_B_PIN                      3

#define NEXTION_DISPLAY_RX_PIN                   19
#define NEXTION_DISPLAY_TX_PIN                   18
