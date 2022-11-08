/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2022
 *      Author: DELL
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status_0){
		case INIT:
			status_0 = NORMAL;
			//TODO
			break;
		case NORMAL:
			if(isButtonPressed(0)){
				status_0 = MOD_RED;
			}
			//TODO
			status_1 = RED1;
			status_2 = GREEN2;
			break;
		case MOD_RED:
			if(isButtonPressed(0)){
				status_0 = MOD_YELLOW;
			}
			if(isButtonPressed(2)){
				status_0 = NORMAL;
				counter_green = counter_red - counter_yellow;
			}
			//TODO
			if(timer5_flag == 1){
				HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin | LED_RED2_Pin);
				setTimer5(500);
			}
			if(isButtonPressed(1)){
				if(counter_red < 99){
					counter_red++;
				}else{
					counter_red = 0;
				}
			}
			led_buffer[0] = counter_red/10;
			led_buffer[1] = counter_red%10;
			break;
		case MOD_YELLOW:
			if(isButtonPressed(0)){
				status_0 = MOD_GREEN;
			}
			if(isButtonPressed(2)){
				status_0 = NORMAL;
				counter_green = counter_red - counter_yellow;
			}
			//TODO
			if(timer5_flag == 1){
				HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin | LED_YELLOW2_Pin);
				setTimer5(500);
			}
			if(isButtonPressed(1)){
				if(counter_yellow < 99){
					counter_yellow++;
				}else{
					counter_yellow = 0;
				}
			}
			led_buffer[0] = counter_yellow/10;
			led_buffer[1] = counter_yellow%10;
			break;
		case MOD_GREEN:
			if(isButtonPressed(0) || isButtonPressed(2)){
				status_0 = NORMAL;
				counter_red = counter_green - counter_yellow;
			}
			//TODO
			if(timer5_flag == 1){
				HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin | LED_GREEN2_Pin);
				setTimer5(500);
			}
			if(isButtonPressed(1)){
				if(counter_green < 99){
					counter_green++;
				}else{
					counter_green = 0;
				}
			}
			led_buffer[0] = counter_green/10;
			led_buffer[1] = counter_green%10;
			break;
		default:
			break;
	}
}

