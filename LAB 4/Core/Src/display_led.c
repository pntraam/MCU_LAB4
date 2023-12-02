/*
 * display_led.c
 *
 *  Created on: Dec 6, 2022
 *      Author: USER
 */
#include "display_led.h"
#include "main.h"
void display_led1(){
	HAL_GPIO_TogglePin(led1_GPIO_Port, led1_Pin);
}
void display_led2(){
	HAL_GPIO_TogglePin(led2_GPIO_Port, led2_Pin);
}
void display_led3(){
	HAL_GPIO_TogglePin(led3_GPIO_Port, led3_Pin);
}
void display_led4(){
	HAL_GPIO_TogglePin(led4_GPIO_Port, led4_Pin);
}
void display_led5(){
	HAL_GPIO_TogglePin(led5_GPIO_Port, led5_Pin);
}
