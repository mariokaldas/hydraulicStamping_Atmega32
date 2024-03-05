/*
 * IR.h
 *
 *  Created on: Nov 29, 2023
 *      Author: mario
 */

#ifndef IR_H_
#define IR_H_

#include"MCAL/std_types.h"

/***************************************************************************
 *                                Definitions
 *************************************************************************** */

#define OBJECT_DETECTED    0
#define NO_OBJECT_DETECTED 1

#define IR_PORT PORTD_ID


/***************************************************************************
 *                              IR's definition
 *************************************************************************** */

#define IR_OBJECT 2
#define IR_CLAMPING_CHECK 3


/***************************************************************************
 *                           Functions declaration
 *************************************************************************** */

void IR_init(uint8 IR_num);
uint8 IR_getReading(uint8 IR_num);

#endif /* IR_H_ */
