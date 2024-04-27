/*
 * relay.c
 *
 *  Created on: Apr 15, 2024
 *      Author: DELL
 */

#include "relay.h"
#include "gpio.h"

void relay_init(void){
	GPIO_setupPinDirection(RELY_PORT_ID,RELAY_PIN_ID,PIN_OUTPUT);
}

void relay_ON(void){
	GPIO_writePin(RELY_PORT_ID,RELAY_PIN_ID,LOGIC_HIGH);
}

void relay_OFF(void){
	GPIO_writePin(RELY_PORT_ID,RELAY_PIN_ID,LOGIC_LOW);
}
