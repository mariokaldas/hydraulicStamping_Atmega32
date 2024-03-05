/*
 * main.c
 *
 *  Created on: Nov 29, 2023
 *      Author: mario
 */
#include"HAL/IR.h"
#include"HAL/relay.h"
#include"HAL/pushbutton.h"
#include<util/delay.h>

/****************************************************************************
 *                          User defined variables
 * *************************************************************************/

enum states{

	WAITING_OBJECT,WAITING_CLAMPING

}g_currentState;

/****************************************************************************
 *                                MAIN CODE
 * *************************************************************************/

int main(){

	IR_init(IR_OBJECT);
	IR_init(IR_CLAMPING_CHECK);

	RELAY_init(RELAY_CLAMPING);
	RELAY_init(RELAY_STAMPING);

	RELAY_off(RELAY_CLAMPING);
	RELAY_off(RELAY_STAMPING);

	g_currentState = WAITING_OBJECT;

	while(1){

		switch(g_currentState){

		case WAITING_OBJECT:

			if(IR_getReading(IR_OBJECT) == OBJECT_DETECTED)
			{
				_delay_ms(1500);
				if(IR_getReading(IR_OBJECT) == OBJECT_DETECTED)
				{
					RELAY_on(RELAY_CLAMPING);
					g_currentState = WAITING_CLAMPING;
				}
			}
			else
			{
				RELAY_off(RELAY_CLAMPING);
			}

			break;

		case WAITING_CLAMPING:

			if(IR_getReading(IR_OBJECT) == OBJECT_DETECTED)
			{
				if(IR_getReading(IR_CLAMPING_CHECK) == OBJECT_DETECTED)
				{
					_delay_ms(250);
					RELAY_on(RELAY_STAMPING);
	  				_delay_ms(3000);
					RELAY_off(RELAY_STAMPING);
					_delay_ms(1000);
					RELAY_off(RELAY_CLAMPING);
					while(IR_getReading(IR_OBJECT) == OBJECT_DETECTED);
					g_currentState = WAITING_OBJECT;
				}
			}
			else
			{
				g_currentState = WAITING_OBJECT;
			}

			break;

		}
	}
}
