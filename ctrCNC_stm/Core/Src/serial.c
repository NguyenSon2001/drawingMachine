#include "serial.h"
#include <string.h>
#include <stdlib.h>

uint8_t receiveData[20];


void initSerial(){
	HAL_UART_Receive_IT(&huart1,receiveData,sizeof(receiveData));
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == huart1.Instance){
	HAL_UART_Receive_IT(&huart1,receiveData,sizeof(receiveData));
	}
}


void splitString(char *key, char *ch, int *num) {
    *ch = key[0]; // L?y k� t? d?u ti�n c?a chu?i
    *num = atoi(key + 1); // Chuy?n ph?n c�n l?i th�nh s? nguy�n
}

int analyzeData(){
char data[20] ;
memcpy(data, receiveData, sizeof(receiveData));
	
	if(strcmp(data, "resetCoord") == 0){
		setDefaultCoord();
		return 1;
	}
	
	char **keyW;
	int leng = 0;
	char *token; 	
	
	token = strtok(data, " ");
	
	while (token != NULL) {
        // T�ch gi� tri c?a tr?c v� s? bu?c t? chu?i con
        
        keyW[leng] = token; // B?t d?u t? v? tr� th? hai d? b? qua k� t? tr?c
				leng++;
        token = strtok(data, " ");
    }
		char ch;
    int num;
		int coordX = 0;
		int coordY = 0;
		int coordZ = 0;
		
		for(int i = 0 ; i < leng ; i++){
			splitString(keyW[i], &ch, &num);
			if(ch == 'X') coordX = num;
			else if(ch == 'Y') coordY = num;
			else if(ch == 'Z') coordZ = num;
			else if(ch == 'S') {
				setSpeed(num);
				return 2;
			}
				
		}
		
		controlMyMotorStep(coordX,coordY,coordZ);
		return 0;
}