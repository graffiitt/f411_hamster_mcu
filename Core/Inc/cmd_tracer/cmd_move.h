/*
 * cmd_move.h
 *
 *  Created on: Mar 9, 2024
 *      Author: vlad
 */

#ifndef INC_CMD_TRACER_CMD_MOVE_H_
#define INC_CMD_TRACER_CMD_MOVE_H_

#include <stdlib.h>
#include "usb_device.h"


void execMV(uint8_t command, uint8_t* data);
void transmitUART();

#endif /* INC_CMD_TRACER_CMD_MOVE_H_ */
