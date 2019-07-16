/*
 * PacketReceiver.cpp
 *
 *  Created on: 16.07.2019
 *      Author: user
 */

#include "PacketReceiver.h"
#include "string.h"

void PacketReceiver::clearPacketArray()
{
	memset(packetArray, 0, MAX_SIZE * sizeof(Packet));
	packetPtr = packetArray;
}

Packet PacketReceiver::getPacket()
{
	Packet packet = *packetPtr;
	if(packetPtr == getLastPacket())
	{
		clearPacketArray();
	}
	else
	{
		packetPtr++;
	}
	return packet;
}

Packet* PacketReceiver::getLastPacket()
{
	return &packetArray[MAX_SIZE - 1];
}
