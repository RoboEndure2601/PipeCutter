#pragma once

#include "src/MotorControl/PanasonicServoA4Mines.h"
#include "src/MotorControl/ClosedLoopStepper/ClosedLoopStepper.h"
#include "src/MotorControl/ClosedLoopStepper/StepperSpeedControler.h"

// doing close loop between Motor and Encoder
// count encoder pulse and compare to position and make pid connection 

