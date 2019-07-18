/*
 * MainDriver.cpp
 *
 *  Created on: 18.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#include "MainDriver.h"

MainDriver::MainDriver():
	horizontalServo(0),
	verticalServo(1)
{
	i2c.init();

	pca9685.init(&i2c);
	pca9685.setFreq(50);

	horizontalServo.setPWMInterface(&pca9685);
	verticalServo.setPWMInterface(&pca9685);
}
void MainDriver::init()
{
	horizontalServo.setAngle(horizontalServo.getAngle());
	verticalServo.setAngle(verticalServo.getAngle());
}

void MainDriver::update()
{

}

Servo* MainDriver::getServo(uint8_t id)
{
	switch(id)
	{
	case 0:
		return &horizontalServo;
	case 1:
		return &verticalServo;
	default:
		return 0;
	}
}
