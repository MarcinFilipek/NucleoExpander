/*
 * PacketReceiver.cpp
 *
 *  Created on: 16.07.2019
 *      Author: user
 */

#include "PacketReceiver.h"
#include "string.h"

PacketReceiver* PacketReceiver::getInstance()
{
	static PacketReceiver packetReceiver;
	return &packetReceiver;
}

void PacketReceiver::clearPacketArray()
{
	memset(packetArray, 0, MAX_SIZE * sizeof(Packet));
	packetPtr = packetArray;
}

void PacketReceiver::setNewPacket()
{
	if(isNewPacket)
		lostPacket++;
	isNewPacket = true;
	packetPtr = packetArray;
}

Packet PacketReceiver::getPacket()
{
	Packet packet = {0, 0};
	if(isNewPacket)
	{
		packet = *packetPtr;
		if(packetPtr == getLastPacket())
		{
			isNewPacket = false;
		}
		packetPtr++;
	}
	return packet;
}

Packet* PacketReceiver::getLastPacket()
{
	return &packetArray[MAX_SIZE - 1];
}
