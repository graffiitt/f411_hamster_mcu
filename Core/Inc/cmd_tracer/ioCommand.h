/*
 * ioCommand.h
 *
 *  Created on: Nov 28, 2023
 *      Author: vlad
 */

#ifndef INC_CMD_TRACER_IOCOMMAND_H_
#define INC_CMD_TRACER_IOCOMMAND_H_

#include "main.h"
#include <stdlib.h>
#include "usb_device.h"


typedef struct IO_Pin {
	GPIO_TypeDef *port;
	uint32_t pin;

	uint8_t state;

} IO_Pin;

void initIO();
void execIO(uint8_t command, uint8_t* data);
void setPin(IO_Pin *pin);
void readPin(IO_Pin *pin);

#endif /* INC_CMD_TRACER_IOCOMMAND_H_ */
