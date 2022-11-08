/*
 * led7seg.c
 *
 *  Created on: Nov 8, 2022
 *      Author: DELL
 */
#include "led7seg.h"
#include "global.h"
void display7SEG_1(int num){
	  HAL_GPIO_WritePin(GPIOB, A1_Pin|B1_Pin|C1_Pin|D1_Pin|E1_Pin|F1_Pin|G1_Pin, SET);

	  switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, A1_Pin|B1_Pin|C1_Pin|D1_Pin|E1_Pin|F1_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, B1_Pin|C1_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, A1_Pin|B1_Pin|D1_Pin|E1_Pin|G1_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, A1_Pin|B1_Pin|C1_Pin|D1_Pin|G1_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, B1_Pin|C1_Pin|F1_Pin|G1_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, A1_Pin|C1_Pin|D1_Pin|F1_Pin|G1_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, A1_Pin|C1_Pin|D1_Pin|E1_Pin|F1_Pin|G1_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, A1_Pin|B1_Pin|C1_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, A1_Pin|B1_Pin|C1_Pin|D1_Pin|E1_Pin|F1_Pin|G1_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, A1_Pin|B1_Pin|C1_Pin|D1_Pin|F1_Pin|G1_Pin, RESET);
			break;
	 }
 }

void display7SEG_2(int num){
	  HAL_GPIO_WritePin(GPIOB, A2_Pin|B2_Pin|C2_Pin|D2_Pin|E2_Pin|F2_Pin|G2_Pin, SET);

	  switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOB, A2_Pin|B2_Pin|C2_Pin|D2_Pin|E2_Pin|F2_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, B2_Pin|C2_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, A2_Pin|B2_Pin|D2_Pin|E2_Pin|G2_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, A2_Pin|B2_Pin|C2_Pin|D2_Pin|G2_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, B2_Pin|C2_Pin|F2_Pin|G2_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, A2_Pin|C2_Pin|D2_Pin|F2_Pin|G2_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, A2_Pin|C2_Pin|D2_Pin|E2_Pin|F2_Pin|G2_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, A2_Pin|B2_Pin|C2_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, A2_Pin|B2_Pin|C2_Pin|D2_Pin|E2_Pin|F2_Pin|G2_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, A2_Pin|B2_Pin|C2_Pin|D2_Pin|F2_Pin|G2_Pin, RESET);
			break;
	 }
 }

void update7SEG(int index){
	switch(index){
	case 0:
		//Display the first 7SEG with led_buffer[0] and led_buffer[2]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG_1(led_buffer[0]);
		display7SEG_2(led_buffer[2]);
		break;
	case 1:
		//Display the second 7SEG with led_buffer[1]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG_1(led_buffer[1]);
		display7SEG_2(led_buffer[3]);
		break;
	default:
		break;
	}
}
