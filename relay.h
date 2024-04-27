/*
 * relay.h
 *
 *  Created on: Apr 15, 2024
 *      Author: DELL
 */

#ifndef RELAY_H_
#define RELAY_H_

#include "std_types.h"

#define RELY_PORT_ID  PORTC_ID
#define RELAY_PIN_ID  PIN4_ID

void relay_init(void);

void relay_ON(void);

void relay_OFF(void);


#endif /* RELAY_H_ */
