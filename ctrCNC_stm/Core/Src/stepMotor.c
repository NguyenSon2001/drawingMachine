#include "stepMotor.h"

#define STEPS(x) ((x) > 0 ? (x) : 1)


void setupMotorStep(stepMotor StepMotor) {
    HAL_GPIO_WritePin(GPIOA, StepMotor.en, GPIO_PIN_SET);
}

void deinitMotorStep(stepMotor StepMotor) {
    HAL_GPIO_WritePin(GPIOA, StepMotor.en, GPIO_PIN_RESET);
}

void controlMotorStep(stepMotor StepMotor, int steps, int speed) {
		GPIO_PinState direction = ((steps) > 0 ? 0 : 1);
		steps = ((steps) > 0 ? steps : -steps) ;
    // dat huong quay
    HAL_GPIO_WritePin(GPIOA, StepMotor.dir, direction);

    for (uint16_t i = 0; i < steps; ++i) {
        // Tao xung xuong cho chân STEP
        HAL_GPIO_WritePin(GPIOA, StepMotor.tep, GPIO_PIN_SET);
        HAL_Delay(speed);
        HAL_GPIO_WritePin(GPIOA, StepMotor.tep, GPIO_PIN_RESET);
        HAL_Delay(speed);
    }
}
