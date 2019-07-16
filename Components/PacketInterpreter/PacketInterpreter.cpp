/*
 * PacketInterpreter.cpp
 *
 *  Created on: 15.07.2019
 *      Author: user
 */

#include "PacketInterpreter.h"
#include "Command/Command.h"
#include "Packet/PacketUnpack.h"


void PacketInterpreter::packetService(Packet packet)
{
	PacketUnpack packetUnpack = PacketUnpack(&packet);

	uint16_t command = packetUnpack.getCommand();

	switch(command)
	{
	case Command::SET_ANGLE_SERVO_1:
		break;
	case Command::SET_ANGLE_SERVO_2:
		break;
	default:
		break;
	}
}
