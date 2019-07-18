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
	static const uint8_t MAX_SIZE = 10;

	PacketReceiver():
		isNewPacket(false),
		lostPacket(0),
		packetPtr(packetArray)
	{
		clearPacketArray();
	}
	virtual ~PacketReceiver(){}
	static PacketReceiver* getInstance();
	inline Packet* getPacketArray(){ return packetArray; }
	Packet getPacket();
	void setNewPacket();
private:
	bool isNewPacket;
	uint8_t lostPacket;
	Packet packetArray[MAX_SIZE];
	Packet* packetPtr;

	void clearPacketArray();
	Packet* getLastPacket();
};

#endif /* PACKETRECEIVER_PACKETRECEIVER_H_ */
