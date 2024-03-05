#ifndef __SERIAL_H
#define __SERIAL_H



/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"	
#include "usart.h"
#include "myStepMotor.h"



void initSerial();
int analyzeData();


#endif /* __SERIAL_H */