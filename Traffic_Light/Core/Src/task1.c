/*
 * task1.c
 *
 *  Created on: 16 Dec 2022
 *      Author: Ahmed
 */
#include "task1.h"
typedef enum {
	Start, TrafficOne

} states;
static states State, NextState;

/**
@brief task1, follows the specification of task 1 in the project
@param No parameters
@return void
*/
void task1(void) {
	State = Start;
	NextState = Start;
	reset();
	Traffic_reset();
	task1_start();
	while (1) {
		State = NextState;
		switch (State)
		{
		case Start:

			if (street2_hit() == true) {
				NextState = TrafficOne;
			} else {
				NextState = Start;
			}
			break;

		case TrafficOne:
			toggle_street2();
			Traffic2_off();
			Pedestrian2_on();
			Walking_delay();
			Pedestrian2_off();
			Traffic2_on();
			NextState = Start;
			break;
		}
	}

}
