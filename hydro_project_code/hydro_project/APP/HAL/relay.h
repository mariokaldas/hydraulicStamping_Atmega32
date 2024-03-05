/*
 * relay.h
 *
 *  Created on: Nov 29, 2023
 *      Author: mario
 */

#ifndef RELAY_H_
#define RELAY_H_

#include"MCAL/std_types.h"

/***************************************************************************
 *                              Relays definition
 *************************************************************************** */

#define RELAYS_PORT PORTC_ID

#define RELAY_CLAMPING 4
#define RELAY_STAMPING 3



/***************************************************************************
 *                            Functions declaration
 *************************************************************************** */

void RELAY_init(uint8 relay_num);
void RELAY_on(uint8 relay_num);
void RELAY_off(uint8 relay_num);

#endif /* RELAY_H_ */
