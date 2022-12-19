/*
 * Traffic_functions.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Ahmed
 *
 */

#include "usart.h"
#include "spi.h"
#include "gpio.h"
#include "register.h"
#include<stdbool.h>
#include "traffic_functions.h"


/**
@brief Traffic1_on, turns the vertical traffic lights from red to green
@param No parameters
@return void
*/

void Traffic1_on(void) {
	Traffic1_red();
	Traffic1_orange();
	orange_delay();
	Traffic1_orange();
	Traffic1_green();

}


/**
@brief Traffic2_on, turns the horizontal traffic lights from red to green
@param No parameters
@return void
*/
void Traffic2_on(void) {
	HAL_Delay(1000);
	Traffic2_red();

	Traffic2_orange();
	orange2_delay_no_toggle();
	Traffic2_orange();
	Traffic2_green();

}


/**
@brief Traffic1_off, turns the vertical traffic lights from green to red
@param No parameters
@return void
*/
void Traffic1_off(void) {

	Traffic1_green();
	Traffic1_orange();
	orange_delay();
	Traffic1_orange();
	Traffic1_red();

}

/**
@brief Traffic2_off, turns the horizontal traffic lights from green to red
@param No parameters
@return void
*/
void Traffic2_off(void) {
	Traffic2_green();

	Traffic2_orange();
	toggle_street2();
	orange2_delay();
	Traffic2_orange();
	Traffic2_red();
	HAL_Delay(1000);

}

/**
@brief Pedestrian2_on, turns the horizontal pedestrian lights from red to green
@param No parameters
@return void
*/
void Pedestrian2_on(void){

	pedestrian_red2();
	pedestrian_green2();

}

/**
@brief Pedestrian2_off, turns the horizontal pedestrian lights from green to red
@param No parameters
@return void
*/
void Pedestrian2_off(void){
	pedestrian_green2();
	pedestrian_red2();

}

/**
@brief Pedestrian1_on, turns the vertical pedestrian lights from red to green
@param No parameters
@return void
*/
void Pedestrian1_on(void){

	pedestrian_red1();
	pedestrian_green1();

}

/**
@brief Pedestrian2_on, turns the vertical pedestrian lights from green to red
@param No parameters
@return void
*/
void Pedestrian1_off(void){
	pedestrian_green1();
	pedestrian_red1();

}

/**
@brief task1_start, initiate the start state for task 1
@param No parameters
@return void
*/
void task1_start(void){
	pedestrian_red2();
	Traffic2_green();

}

/**
@brief street1_hit, checks if PL1_switch has been triggered
@param No parameters
@return TRUE	Button has been pressed
@return	False	Button not been pressed
*/
bool street1_hit(void) {

	if (HAL_GPIO_ReadPin(PL1_Switch_GPIO_Port, PL1_Switch_Pin)
			== GPIO_PIN_RESET)
		return true;
	else
		return false;

}

/**
@brief street1_hit, checks if PL2_switch has been triggered
@param No parameters
@return TRUE	Button has been pressed
@return	False	Button not been pressed
*/
bool street2_hit(void) {

	if (HAL_GPIO_ReadPin(PL2_Switch_GPIO_Port, PL2_Switch_Pin)
			== GPIO_PIN_RESET)
		return true;
	else
		return false;

}

/**
@brief orange1_delay, Waiting period between orange led and red led in the vertical lane
@param No parameters
@return void
*/
void orange1_delay(void) {

	for (int i = 0; i < 2; i++) {
		toggle_street1();
	}
}

/**
@brief orange2_delay, Waiting period between orange led and red led in the horizontal lane.
@param No parameters
@return void
*/
void orange2_delay(void) {

	for (int i = 0; i < 2; i++) {
		toggle_street2();
	}
}

/**
@brief orange2_delay_no_toggle, Waiting period between orange led and green led in the horizontal lane.
@param No parameters
@return void
*/
void orange2_delay_no_toggle(void) {

	HAL_Delay(7000);
}


/**
@brief toggle_street2, toggles the blue pedestrian led for the horizontal lane  for certian amount of time.
@param No parameters
@return void
*/
void toggle_street2(void) {
	int i = 0;
	while (i < 10) {
		i++;
		pedestrian_blue2();
		HAL_Delay(250);
	}

}

/**
@brief toggle_street1, toggles the blue pedestrian led for the vertical lane  for certian amount of time.
@param No parameters
@return void
*/

void toggle_street1(void) {
	int i = 0;
	while (i < 10) {
		i++;
		pedestrian_blue1();
		HAL_Delay(250);
	}

}


/**
@brief Walking_delay, A simple delay
@param No parameters
@return void
*/
void Walking_delay(void){

	for (int i = 0;i < 5; i++){
		HAL_Delay(1500);
	}

}

