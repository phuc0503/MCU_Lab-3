/*
 * fsm_autolight1.c
 *
 *  Created on: Nov 8, 2022
 *      Author: DELL
 */

#include "fsm_autolight1.h"
#include "global.h"
void fsm_autolight1_run(){
	switch(status_1){
	case INIT1:
//		if(isButtonPressed(2)){
//			status_1 = RED1;
//		}
		break;
	case RED1:
		if(timer2_flag == 1){
			status_1 = GREEN1;
			setTimer2(counter_green*1000);
		}
		if(isButtonPressed(0)){
			status_0 = MOD_RED;
			status_1 = INIT1;
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
		}
		//TODO
		setLedColor1(RED);

		led_buffer[0] = counter_red/10;
		led_buffer[1] = counter_red%10;

		break;
	case GREEN1:
		if(timer2_flag == 1){
			status_1 = YELLOW1;
			setTimer2(counter_yellow*1000);
		}
		if(isButtonPressed(0)){
			status_0 = MOD_RED;
			status_1 = INIT1;
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
		}
		//TODO
		setLedColor1(GREEN);

		led_buffer[0] = counter_green/10;
		led_buffer[1] = counter_green%10;
		break;
	case YELLOW1:
		if(timer2_flag == 1){
			status_1 = RED1;
			setTimer2(counter_red*1000);
		}
		if(isButtonPressed(0)){
			status_0 = MOD_RED;
			status_1 = INIT1;
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
		}
		//TODO
		setLedColor1(YELLOW);

		led_buffer[0] = counter_yellow/10;
		led_buffer[1] = counter_yellow%10;
		break;
	default:
		break;
	}
}

void fsm_autolight2_run(){
	switch(status_2){
	case INIT2:
//		if(isButtonPressed(2)){
//			status_2 = RED2;
//		}
		break;
	case RED2:
		if(timer3_flag == 1){
			status_2 = GREEN2;
			setTimer3(counter_green*1000);
		}
		if(isButtonPressed(0)){
			status_0 = MOD_RED;
			status_2 = INIT2;
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
		}
		//TODO
		setLedColor2(RED);

		led_buffer[2] = counter_red/10;
		led_buffer[3] = counter_red%10;

		break;
	case GREEN2:
		if(timer3_flag == 1){
			status_2 = YELLOW2;
			setTimer3(counter_yellow*1000);
		}
		if(isButtonPressed(0)){
			status_0 = MOD_RED;
			status_2= INIT2;
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
		}
		//TODO
		setLedColor2(GREEN);

		led_buffer[2] = counter_green/10;
		led_buffer[3] = counter_green%10;
		break;
	case YELLOW2:
		if(timer3_flag == 1){
			status_2 = RED2;
			setTimer3(counter_red*1000);
		}
		if(isButtonPressed(0)){
			status_0 = MOD_RED;
			status_2 = INIT2;
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
		}
		//TODO
		setLedColor2(YELLOW);

		led_buffer[2] = counter_yellow/10;
		led_buffer[3] = counter_yellow%10;
		break;
	default:
		break;
	}
}
