/*
 * PacketInterpreter.h
 *
 *  Created on: 15.07.2019
 *      Author: user
 */

#ifndef PACKETINTERPRETER_PACKETINTERPRETER_H_
#define PACKETINTERPRETER_PACKETINTERPRETER_H_

#include "Packet/Packet.h"

class PacketInterpreter
{
public:
	PacketInterpreter(){}
	virtual ~PacketInterpreter(){}
	void packetService(Packet packet);
};

#endif /* PACKETINTERPRETER_PACKETINTERPRETER_H_ */
