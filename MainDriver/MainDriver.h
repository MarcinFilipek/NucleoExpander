/*
 * MainDriver.h
 *
 *  Created on: 18.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#ifndef MAINDRIVER_H_
#define MAINDRIVER_H_

#include "I2C/I2C.h"
#include "PCA9685/PCA9685.h"
#include "Servo/Servo.h"

class MainDriver
{
public:
	MainDriver();
	virtual ~MainDriver(){}
	void init();
	void update();
	Servo* getServo(uint8_t id);
private:
	I2C i2c;
	PCA9685 pca9685;
	Servo horizontalServo;
	Servo verticalServo;
};

#endif /* MAINDRIVER_H_ */
