/*
 * register.c
 *
 *  Created on: 29 Nov 2022
 *      Author: Ahmed
 */
#include "usart.h"
#include "spi.h"
#include "gpio.h"
#include "register.h"


uint8_t traffic[3] = { 0b0000100, 0b00000100, 0b00000100 };

/**
@brief reset, resets the shift register
@param No parameters
@return void
*/
void reset(void) {
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);
}

/**
@brief Traffic_set, turn on all led
@param No parameters
@return void
*/

void Traffic_set(void) {
	for (int i = 0; i < 3; i++)
		traffic[i] = 0b11111111;
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);
}

/**
@brief Traffic_reset, turn off all led
@param No parameters
@return void
*/

void Traffic_reset(void) {
	for (int i = 0; i < 3; i++)
		traffic[i] = 0b00000000;
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);
}

/**
@brief Traffic1_red, turns on the red leds on the vertical lane ( looking from the direction of the CAN BUS)
@param No parameters
@return void
*/
void Traffic1_red(void) {

	increment(0, 1);
	increment(2, 1);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}

/**
@brief Traffic1_orange, turns on the orange leds on the vertical lane ( looking from the direction of the CAN BUS)
@param No parameters
@return void
*/
void Traffic1_orange(void) {

	increment(0, 2);
	increment(2, 2);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}

/**
@brief Traffic1_green, turns on the green leds on the vertical lane ( looking from the direction of the CAN BUS)
@param No parameters
@return void
*/

void Traffic1_green(void) {

	increment(0, 3);
	increment(2, 3);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}


/**
@brief Traffic2_red, turns on the red leds on the horizontal lane (looking from the direction of the CAN BUS)
@param No parameters
@return void
*/
void Traffic2_red(void) {

	increment(0, 4);
	increment(1, 1);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}

/**
@brief Traffic2_orange, turns on the orange leds on the horizontal lane (looking from the direction of the CAN BUS)
@param No parameters
@return void
*/

void Traffic2_orange(void) {

	increment(0, 5);
	increment(1, 2);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}
/**
@brief Traffic2_green, turns on the green leds on the horizontal lane (looking from the direction of the CAN BUS)
@param No parameters
@return void
*/

void Traffic2_green(void) {

	increment(0, 6);
	increment(1, 3);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}

/**
@brief pedestrian_red1, turns on the red leds for  pedestrian on the vertical lane (looking from the direction of the CAN BUS)
@param No parameters
@return void
*/

void pedestrian_red1(void) {
	increment(2, 4);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}


/**
@brief pedestrian_green1, turns on the green leds for  pedestrian on the vertical lane (looking from the direction of the CAN BUS)
@param No parameters
@return void
*/

void pedestrian_green1(void) {
	increment(2, 5);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}


/**
@brief pedestrian_blue1, turns on the blue leds for  pedestrian on the vertical lane (looking from the direction of the CAN BUS)
@param No parameters
@return void
*/

void pedestrian_blue1(void) {
	increment(2, 6);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}


/**
@brief pedestrian_red2, turns on the red leds for  pedestrian on the horizontal lane (looking from the direction of the CAN BUS)
@param No parameters
@return void
*/
void pedestrian_red2(void) {
	increment(1, 4);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}


/**
@brief pedestrian_green2, turns on the green leds for  pedestrian on the horizontal lane (looking from the direction of the CAN BUS)
@param No parameters
@return void
*/

void pedestrian_green2(void) {
	increment(1, 5);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}


/**
@brief pedestrian_blue2, turns on the blue leds for  pedestrian on the horizontal lane (looking from the direction of the CAN BUS)
@param No parameters
@return void
*/
void pedestrian_blue2(void) {
	increment(1, 6);
	HAL_SPI_Transmit(&hspi3, traffic, 3, 1);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(STCP_GPIO_Port, STCP_Pin, GPIO_PIN_RESET);

}

/**
@brief increment, XOR the shift register array with a binary number to toggle a specific led
@param int element, which element in the array to do the operation with
@param int position, determine which binary number to XOR with
@return void
*/

void increment(int element, int position) {

	uint8_t temp;
	if (position == 1)
		temp = 0b00000001;
	if (position == 2)
		temp = 0b00000010;
	if (position == 3)
		temp = 0b00000100;
	if (position == 4)
		temp = 0b00001000;
	if (position == 5)
		temp = 0b00010000;
	if (position == 6)
		temp = 0b00100000;

	traffic[element] = traffic[element] ^ temp;

}

