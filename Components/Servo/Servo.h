/*
 * Servo.h
 *
 *  Created on: 18.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#ifndef SERVO_SERVO_H_
#define SERVO_SERVO_H_

#include "Interfaces/PWMInterface.h"

class Servo
{
public:
	Servo(int8_t id = -1, uint8_t angle = 90):
		minDuty(2.0f),
		maxDuty(10.0f),
		angle(angle),
		idServo(id),
		pwm(0)
	{
	}
	virtual ~Servo(){}
	void setPWMInterface(PWMInterface* pwm);
	void setAngle(uint8_t angle);
	uint8_t getAngle(){ return angle; }
private:
	float minDuty;
	float maxDuty;
	uint8_t angle;
	int8_t idServo;
	PWMInterface* pwm;
};

#endif /* SERVO_SERVO_H_ */
