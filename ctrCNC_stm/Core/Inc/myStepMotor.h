#ifndef __MY_STEP_MORTOR_H
#define __MY_STEP_MORTOR_H



/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "stepMotor.h"

stepMotor motorX = {dirX_Pin, tepX_Pin, enX_Pin}; // dir,tep,en
stepMotor motorY = {dirY_Pin, tepY_Pin, enY_Pin};
stepMotor motorZ = {dirZ_Pin, tepZ_Pin, enZ_Pin};



void initMyMotorStep();
void deinitMyMotorStep();
void setDefaultCoord();
void setSpeed(int newSpeed);
void controlMyMotorStep(int coordX, int coordY, int coordZ);
#endif /* __MY_STEP_MORTOR_H */