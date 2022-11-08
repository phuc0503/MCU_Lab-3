/*
 * global.h
 *
 *  Created on: Oct 28, 2022
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "led_color.h"
#include "fsm_automatic.h"
#include "fsm_autolight1.h"
#include "led7seg.h"

#define INIT			0
#define NORMAL			1
#define MOD_RED			2
#define MOD_YELLOW		3
#define MOD_GREEN		4

#define INIT1			10
#define RED1			11
#define YELLOW1			12
#define GREEN1			13

#define INIT2			20
#define RED2			21
#define	YELLOW2			22
#define	GREEN2			23

#define RED				30
#define YELLOW			31
#define	GREEN			32
extern int color;
extern int status_0;
extern int status_1;	//status for auto 1
extern int status_2;	//status for auto 2
extern int counter_red;
extern int counter_yellow;
extern int counter_green;
extern int index_led;
extern int led_buffer[4];
#endif /* INC_GLOBAL_H_ */
