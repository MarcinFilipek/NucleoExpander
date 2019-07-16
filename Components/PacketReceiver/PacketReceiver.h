/*
 * PacketReceiver.h
 *
 *  Created on: 16.07.2019
 *      Author: user
 */

#ifndef PACKETRECEIVER_PACKETRECEIVER_H_
#define PACKETRECEIVER_PACKETRECEIVER_H_

#include "Packet/Packet.h"

class PacketReceiver
{
public:
	static const uint8_t MAX_SIZE = 8;

	PacketReceiver()
	{
		clearPacketArray();
	}

	virtual ~PacketReceiver(){}
	inline Packet* getPacketArray(){ return packetArray; }
	Packet getPacket();
private:
	Packet packetArray[MAX_SIZE];
	Packet* packetPtr;

	void clearPacketArray();
	Packet* getLastPacket();
};

#endif /* PACKETRECEIVER_PACKETRECEIVER_H_ */
