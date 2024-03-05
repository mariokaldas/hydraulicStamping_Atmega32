/*
 * IR.c
 *
 *  Created on: Nov 29, 2023
 *      Author: mario
 */

#include"IR.h"
#include"MCAL/GPIO.h"

/***************************************************************************
 *                          Functions definition
 *************************************************************************** */
void IR_init(uint8 IR_num){

	GPIO_setupPinDirection(IR_PORT,IR_num,PIN_INPUT);
}

uint8 IR_getReading(uint8 IR_num){

	return GPIO_readPin(IR_PORT,IR_num);
}
