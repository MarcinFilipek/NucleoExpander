/*
 * PacketInterpreter.cpp
 *
 *  Created on: 15.07.2019
 *      Author: user
 */

#include "PacketInterpreter.h"
#include "Command/Command.h"
#include "Packet/PacketUnpack.h"

void PacketInterpreter::update()
{
	packetService(packetReceiver->getPacket());
}

void PacketInterpreter::packetService(Packet packet)
{
	PacketUnpack packetUnpack = PacketUnpack(&packet);

	uint16_t command = packetUnpack.getCommand();
	uint16_t data = packetUnpack.getData();

	if(command == 0)
		return;

	switch(command)
	{
	case Command::SET_ANGLE_SERVO_1:
		mainDriver->getServo(0)->setAngle(data);
		break;
	case Command::SET_ANGLE_SERVO_2:
		mainDriver->getServo(1)->setAngle(data);
		break;
	default:
		break;
	}
}
