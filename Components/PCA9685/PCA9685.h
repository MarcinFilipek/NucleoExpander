/*
 * PCA9685.h
 *
 *  Created on: 17.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#ifndef PCA9685_PCA9685_H_
#define PCA9685_PCA9685_H_

#include "Interfaces/I2CInterface.h"
#include "Interfaces/PWMInterface.h"

class PCA9685: public PWMInterface
{
public:
	static const uint8_t MODE_ADR = 0x00;
	static const uint8_t PRESCALE_ADR = 0xFE;
	static const uint8_t BASE_ADR_LOW = 0x08;
	static const uint8_t BASE_ADR_HIGH = 0x09;

	PCA9685():
		address(0x80)
	{

	}
	virtual ~PCA9685(){}
	void init(I2CInterface* i2c);
	void setFreq(uint8_t freq);
	void setDuty(uint8_t channel, float duty);
private:
	uint8_t address;

	I2CInterface* i2c;
};

#endif /* PCA9685_PCA9685_H_ */
