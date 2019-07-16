/*
 * PacketUnpack.h
 *
 *  Created on: 16.07.2019
 *      Author: user
 */

#ifndef PACKET_PACKETUNPACK_H_
#define PACKET_PACKETUNPACK_H_

#include "Packet.h"

class PacketUnpack
{
public:
	PacketUnpack(Packet* ptr):
		ptrPacket(ptr)
	{

	}
	virtual ~PacketUnpack(){}

	uint16_t getCommand()
	{
		return ptrPacket->command;
	}

	void setCommand(uint16_t c)
	{
		ptrPacket->command = c;
	}

	uint16_t getData()
	{
		return ptrPacket->data;
	}

	void setData(uint16_t d)
	{
		ptrPacket->data = d;
	}
private:
	Packet* ptrPacket;
};

#endif /* PACKET_PACKETUNPACK_H_ */
