/**
******************************************************************************
@brief register. editing the shift register
@file register.c
@author Ahmed Tareg
@version 1.0
@date 2-December-2022
@brief all functions that has to do with the shift register from editing to transmiting
****************************************************************************
**/

#ifndef INC_REGISTER_H_
#define INC_REGISTER_H_

void Traffic1_red(void);
void Traffic1_orange(void);
void Traffic1_green(void);
void Traffic2_red(void);
void Traffic2_orange(void);
void Traffic2_green(void);
void Traffic_reset(void);
void Traffic_set(void);
void pedestrian_red1(void);
void pedestrian_green1(void);
void pedestrian_blue1(void);
void pedestrian_red2(void);
void pedestrian_green2(void);
void pedestrian_blue2(void);

void orange_delay(void);
void increment(int element,int position);
void reset (void);




#endif /* INC_REGISTER_H_ */
