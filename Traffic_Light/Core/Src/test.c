/*
 * test.c
 *
 *  Created on: 29 Nov 2022
 *      Author: Ahmed
 */
#include "register.h"
#include "gpio.h"
#include "test.h"
#include "spi.h"
#include "traffic_functions.h"
#include "stdbool.h"

/**
 @brief Test_program, Tests the essentials function needed for traffic light system to work
 @param No parameters
 @return void
 */
void Test_program(void) {

	reset();
	Traffic_reset();
//	test_leds();
	//while(1)
	//test_traffic();

	test_buttons();
	//test_led1();
	//test_toggle();

}



/**
 @brief test_leds, tests all led light in sequence
 @param No parameters
 @return void
 */
void test_leds(void) {

	reset();
	Traffic_set();
	HAL_Delay(500);
	Traffic_reset();
	HAL_Delay(500);
	Traffic1_red();
	HAL_Delay(500);
	Traffic1_orange();
	HAL_Delay(500);
	Traffic1_green();
	HAL_Delay(500);
	Traffic2_red();
	HAL_Delay(500);
	Traffic2_orange();
	HAL_Delay(500);
	Traffic2_green();
	//-----------------------------------------------

	HAL_Delay(500);
	Traffic1_red();
	HAL_Delay(500);
	Traffic1_orange();
	HAL_Delay(500);
	Traffic1_green();
	HAL_Delay(500);
	Traffic2_red();
	HAL_Delay(500);
	Traffic2_orange();
	HAL_Delay(500);
	Traffic2_green();

	HAL_Delay(500);
	pedestrian_red1();
	HAL_Delay(500);
	pedestrian_green1();
	HAL_Delay(500);
	pedestrian_blue1();
	HAL_Delay(500);
	pedestrian_red2();
	HAL_Delay(500);
	pedestrian_green2();
	HAL_Delay(500);
	pedestrian_blue2();

}


/**
 @brief test_led1, tests if the blue light responds to the shift register change
 @param No parameters
 @return void
 */
void test_led1(void) {
	Traffic_reset();
	while (1) {
		pedestrian_blue1();
		HAL_Delay(500);
	}

	return;
}


/**
 @brief test_traffic, test to determine which bit connects to which led
 @param No parameters
 @return void
 */
void test_traffic(void) {
	Traffic_reset();

	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 7; n++) {

			increment(i, n);
			HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);
			HAL_Delay(1000);

		}

	}
}


/**
 @brief test_buttons, test to see if the button responds to input
 @param No parameters
 @return void
 */
void test_buttons(void) {
	while (1) {

		if (street1_hit() == true) {
			pedestrian_blue1();
			HAL_Delay(2000);

		}
		if (street1_hit() != true) {
			Traffic1_green();
			HAL_Delay(2000);
		}
	}
}




/**
 @brief test_toggle, tests the function toggle_street in which the blue led sets on and off
 @param No parameters
 @return void
 */

void test_toggle(void) {

	while (1)
		toggle_street1();
}
