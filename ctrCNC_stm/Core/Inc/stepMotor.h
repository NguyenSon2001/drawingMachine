#ifndef __STEP_MORTOR_H
#define __STEP_MORTOR_H



/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "gpio.h"

typedef struct stepMotor{
 uint16_t dir;
uint16_t tep;
	uint16_t en;
}stepMotor;

typedef enum direction{
LEFT = 0,
RIGHT	= 1
}direction;

void initMotorStep(stepMotor StepMotor);
void deinitMotorStep(stepMotor StepMotor);
void controlMotorStep(stepMotor StepMotor, int steps, int speed);


#endif /* __STEP_MORTOR_H */