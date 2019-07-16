/*
 * Packet.h
 *
 *  Created on: 15.07.2019
 *      Author: user
 */

#ifndef PACKET_PACKET_H_
#define PACKET_PACKET_H_
#include "stdint.h"

struct Packet
{
	uint16_t command;
	uint16_t data;
};

#endif /* PACKET_PACKET_H_ */
