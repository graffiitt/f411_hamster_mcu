/*
 * cmd_move.c
 *
 *  Created on: Mar 9, 2024
 *      Author: vlad
 */
#include "cmd_move.h"

extern uint8_t CDC_Transmit_FS(uint8_t *Buf, uint16_t Len);

void execMV(uint8_t command, uint8_t *data) {

	size_t range = sizeof(data);
	uint8_t msg[range + 3];

	char cmd[3];
	itoa(command, cmd, 10);

	if (command < 9) {
		msg[0] = '0';
		msg[1] = '0';
		msg[2] = cmd[0];
	}
	if (command > 9 && command < 100) {
		msg[0] = '0';
		msg[1] = cmd[0];
		msg[2] = cmd[1];
	}
	if (command > 99) {
		msg[0] = cmd[0];
		msg[1] = cmd[1];
		msg[2] = cmd[2];
	}

	memcpy(msg + 4, data, range);

	//HAL_UART_Transmit(&huart2, pData, Size, 5);
}

void transmitUART() {

	//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

	static uint8_t i = 2;
	static uint8_t rx_buff[] = "MV000000000000000000";

	if (USART2->SR & USART_SR_RXNE) //Проверяем, прило ли чтонибудь в UART
	{
		rx_buff[i] = (uint8_t) USART2->DR;
		if (rx_buff[i] == ';') {
			CDC_Transmit_FS(rx_buff, (uint16_t) i);
			i = 2;
		} else {
			i++;
		}
	}
}

