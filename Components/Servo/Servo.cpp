/*
 * Servo.cpp
 *
 *  Created on: 18.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#include "Servo/Servo.h"

void Servo::setPWMInterface(PWMInterface* pwm)
{
	this->pwm = pwm;
}

void Servo::setAngle(uint8_t angle)
{
	if(idServo > -1 && pwm)
	{
		this->angle = angle;
		float duty = minDuty + (maxDuty - minDuty) * angle / 180.0f;
		pwm->setDuty(idServo, duty);
	}
}
