/*
 * cmd_tracer.c
 *
 *  Created on: Nov 26, 2023
 *      Author: vlad
 */
#include "cmd_tracer.h"

extern CMD_trace cmd[];

uint8_t cmdIO[] = { 'I', 'O' };
uint8_t cmdMV[] = { 'M', 'V'};

void cmdInit() {

	// IO commands
	initIO();
	memcpy(cmd[0].cmdIndex, cmdIO, sizeof(cmdIO));
	cmd[0].exec = execIO;


	memcpy(cmd[1].cmdIndex, cmdMV, sizeof(cmdMV));
	cmd[1].exec = execMV;

}

void recieveData(uint8_t *buf, CMD_trace *command) {

	uint8_t commandBuf[] = { buf[2], buf[3], buf[4] };
	command->command = atoi((char*) commandBuf);

	uint8_t lenghtBuf[] = { buf[5], buf[6] };
	command->sizeData = atoi((char*) lenghtBuf);
	uint8_t *dt = (uint8_t*) malloc(command->sizeData);


	for (uint8_t i = 0; command->sizeData > i; i++) {
		dt[i] = buf[7 + i];
	}

	cmd->data = dt;
}
