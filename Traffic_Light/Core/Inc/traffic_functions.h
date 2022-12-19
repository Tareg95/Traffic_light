/**
******************************************************************************
@brief traffic functions. making traffic light functions
@file traffic_functions.c
@author Ahmed Tareg
@version 1.0
@date 2-December-2022
@brief grouping register functions to make a sequence of function relevent to traffic light operation
****************************************************************************
**/

#ifndef INC_TRAFFIC_FUNCTIONS_H_
#define INC_TRAFFIC_FUNCTIONS_H_
#include "usart.h"
#include "spi.h"
#include "gpio.h"
#include "register.h"
#include "stdbool.h"

void traffic1_on(void);
void Traffic2_on(void);
void traffic1_off(void);
void Traffic2_off(void);
void orange1_delay(void);
void orange2_delay(void);
void Walking_delay(void);
void toggle_delay(void);
bool street1_hit(void);
bool street2_hit(void);
void toggle_street1(void);
void toggle_street2(void);
void Pedestrian1_on(void);
void Pedestrian1_off(void);
void Pedestrian2_on(void);
void Pedestrian2_off(void);
void task1_start(void);
void orange2_delay_no_toggle(void);


#endif /* INC_TRAFFIC_FUNCTIONS_H_ */
