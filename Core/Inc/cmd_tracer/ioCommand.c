/*
 * ioCommand.c
 *
 *  Created on: Nov 28, 2023
 *      Author: vlad
 */

#include "ioCommand.h"

extern uint8_t CDC_Transmit_FS(uint8_t *Buf, uint16_t Len);

IO_Pin DOpin[8];
IO_Pin DIpin[8];

void initIO() {
	DOpin[0].port = GPIOB;
	DOpin[0].pin = GPIO_PIN_0;
	DOpin[0].state = 0;

	DOpin[1].port = GPIOB;
	DOpin[1].pin = GPIO_PIN_1;
	DOpin[1].state = 0;

	DOpin[2].port = GPIOB;
	DOpin[2].pin = GPIO_PIN_2;
	DOpin[2].state = 0;

	DOpin[3].port = GPIOB;
	DOpin[3].pin = GPIO_PIN_10;
	DOpin[3].state = 0;

	DOpin[4].port = GPIOA;
	DOpin[4].pin = GPIO_PIN_4;
	DOpin[4].state = 0;

	DOpin[5].port = GPIOA;
	DOpin[5].pin = GPIO_PIN_5;
	DOpin[5].state = 0;

	DOpin[6].port = GPIOA;
	DOpin[6].pin = GPIO_PIN_6;
	DOpin[6].state = 0;

	DOpin[7].port = GPIOA;
	DOpin[7].pin = GPIO_PIN_7;
	DOpin[7].state = 0;

	DIpin[0].port = GPIOA;
	DIpin[0].pin = GPIO_PIN_10;
	DIpin[0].state = 0;

	DIpin[1].port = GPIOA;
	DIpin[1].pin = GPIO_PIN_9;
	DIpin[1].state = 0;

	DIpin[2].port = GPIOA;
	DIpin[2].pin = GPIO_PIN_8;
	DIpin[2].state = 0;

	DIpin[3].port = GPIOB;
	DIpin[3].pin = GPIO_PIN_15;
	DIpin[3].state = 0;

	DIpin[4].port = GPIOB;
	DIpin[4].pin = GPIO_PIN_14;
	DIpin[4].state = 0;

	DIpin[5].port = GPIOB;
	DIpin[5].pin = GPIO_PIN_13;
	DIpin[5].state = 0;

	DIpin[6].port = GPIOB;
	DIpin[6].pin = GPIO_PIN_12;
	DIpin[6].state = 0;

	DIpin[7].port = GPIOA;
	DIpin[7].pin = GPIO_PIN_1;
	DIpin[7].state = 0;

}

void execIO(uint8_t command, uint8_t *data) {

	uint8_t pin[] = { data[0], data[1] };
	uint8_t numPin = atoi((char*) pin);

	switch (command) {
	case 10: // set out pin state  io010050101   010 number state
	{
		//set number pin
		DOpin[numPin].state = data[2] - '0';

		setPin(&DOpin[numPin]);
		uint8_t m[] = {numPin + '0', DOpin[numPin].state + '0'};
		uint8_t msg[] = {'I', 'O', '0', '2', '0', '0', m[0], '0', m[1]} ;
		CDC_Transmit_FS(msg, sizeof(msg));
		break;
	}

	case 11: // read pin state   io011050101 011 number state
	{ 		//set number pin
		readPin(&DIpin[numPin]);

		uint8_t m[] = {numPin + '0', DIpin[numPin].state + '0'};
		uint8_t msg[] = {'I', 'O', '0', '2', '1', '0', m[0], '0', m[1]} ;

		CDC_Transmit_FS(msg, sizeof(msg));
		break;
	}

	case 01: // reset all pins
	{
		for (size_t i = 0; i < 8; i++) {
			DOpin[i].state = 0;
			setPin(&DOpin[i]);
		}
		break;
	}
	default:
		break;
	}
}

void setPin(IO_Pin *pin) {
	if (pin->state == 1) {
		pin->port->BSRR = pin->pin;
	} else
		pin->port->BSRR = (uint32_t) pin->pin << 16U;
}

void readPin(IO_Pin *pin) {
	if ((pin->port->IDR & pin->pin) != (uint32_t) 0) {
		pin->state = 1;
	} else {
		pin->state = 0;
	}
}
