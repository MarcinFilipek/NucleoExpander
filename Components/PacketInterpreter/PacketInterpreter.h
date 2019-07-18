/*
 * PacketInterpreter.h
 *
 *  Created on: 15.07.2019
 *      Author: user
 */

#ifndef PACKETINTERPRETER_PACKETINTERPRETER_H_
#define PACKETINTERPRETER_PACKETINTERPRETER_H_

#include "Packet/Packet.h"
#include "PacketReceiver/PacketReceiver.h"
#include "MainDriver.h"

class PacketInterpreter
{
public:
	PacketInterpreter(PacketReceiver* packRec, MainDriver* mainDriver):
		packetReceiver(packRec),
		mainDriver(mainDriver)
	{

	}
	virtual ~PacketInterpreter(){}
	void update();
	void packetService(Packet packet);
private:
	PacketReceiver* packetReceiver;
	MainDriver* mainDriver;
};

#endif /* PACKETINTERPRETER_PACKETINTERPRETER_H_ */
