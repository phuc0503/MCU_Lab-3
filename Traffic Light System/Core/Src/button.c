/*
 * button.c
 *
 *  Created on: Oct 26, 2022
 *      Author: DELL
 */

#include "button.h"

int KeyBuffer1[NUMBER_OF_BUTTONS];
int KeyBuffer2[NUMBER_OF_BUTTONS];
int KeyBuffer3[NUMBER_OF_BUTTONS];
int KeyBuffer4[NUMBER_OF_BUTTONS];

int flagForButtons[NUMBER_OF_BUTTONS];
int timerForKeyPress[NUMBER_OF_BUTTONS];

int isButtonPressed(int index){
	if(index > NUMBER_OF_BUTTONS){
		return 0;
	}
	if(flagForButtons[index] == 1){
		flagForButtons[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	for(int i = 0; i < NUMBER_OF_BUTTONS; i++){
		KeyBuffer1[i] = KeyBuffer2[i];
		KeyBuffer2[i] = KeyBuffer3[i];
		switch(i){
		//Button 1
		case 0:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin);
			break;
		//Button 2
		case 1:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin);
			break;
		//Button 3
		case 2:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(BUT3_GPIO_Port, BUT3_Pin);
			break;
		//Button 4
		case 3:
			break;
		//Button 5
		case 4:
			break;
		//Button 6
		case 5:
			break;
		default:
			break;
		}
		if((KeyBuffer1[i] == KeyBuffer2[i]) && (KeyBuffer2[i] == KeyBuffer3[i])){
			if(KeyBuffer3[i] != KeyBuffer4[i]){
				KeyBuffer4[i] = KeyBuffer3[i];

				if(KeyBuffer3[i] == PRESSED_STATE){
					timerForKeyPress[i] = 200;
					flagForButtons[i] = 1;
				}
			}else{
				timerForKeyPress[i]--;
				if(timerForKeyPress[i] == 0){
					KeyBuffer4[i] = NORMAL_STATE;
				}
			}
		}
	}
}
