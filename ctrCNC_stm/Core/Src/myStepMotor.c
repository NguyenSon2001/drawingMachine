#include "myStepMotor.h"

int coordNowX = 0;
int coordNowY = 0;
int coordNowZ = 0;

int speed = 500;

void initMyMotorStep(){
	initMotorStep(motorX);
	initMotorStep(motorY);
	initMotorStep(motorZ);
}
	
void deinitMyMotorStep(){
	deinitMotorStep(motorX);
	deinitMotorStep(motorY);
	deinitMotorStep(motorZ);
}

void setDefaultCoord(){
	coordNowX = 0;
	coordNowY = 0;
	coordNowZ = 0;
}

void setSpeed(int newSpeed){
	speed = newSpeed ;
}

void controlMyMotorStep(int coordX, int coordY, int coordZ){
	int offsetX = coordX - coordNowX;
	int offsetY= coordY - coordNowY;
	int offsetZ = coordZ - coordNowZ;
	
	controlMotorStep(motorX,offsetX,speed);
	controlMotorStep(motorY,offsetY,speed);
	controlMotorStep(motorZ,offsetZ,speed);
}