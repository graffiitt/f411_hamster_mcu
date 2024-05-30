/*
 * cmd_tracer.h
 *
 *  Created on: Nov 26, 2023
 *      Author: vlad
 */

#ifndef INC_CMD_TRACER_CMD_TRACER_H_
#define INC_CMD_TRACER_CMD_TRACER_H_

#include <main.h>
#include "ioCommand.h"
#include "cmd_move.h"

#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define CMD_NUM_COMMANDS 3


typedef struct CMD_trace
{
	uint8_t cmdIndex[2];
	uint8_t command;

	size_t sizeData;
	uint8_t* data;

 	void (*exec)(uint8_t, uint8_t*);
}CMD_trace;

void cmdInit();
void recieveData(uint8_t *buf, CMD_trace* command);

#endif /* INC_CMD_TRACER_CMD_TRACER_H_ */
