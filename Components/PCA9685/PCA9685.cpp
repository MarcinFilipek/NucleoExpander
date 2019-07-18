/*
 * PCA9685.cpp
 *
 *  Created on: 17.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#include "PCA9685.h"
#include "Misc/Delay.h"

void PCA9685::init(I2CInterface* i2c)
{
	this->i2c = i2c;
	uint8_t data = 0x00;
	i2c->write(address, MODE_ADR, &data);
}

void PCA9685::setFreq(uint8_t freq)
{
	float prescaleValue = 25000000.0f;
	prescaleValue /= 4046.0f;
	prescaleValue /= (float)freq;
	prescaleValue -= 1.0f;
	uint8_t prescale = (uint8_t)prescaleValue;
	uint8_t oldmode = 0x00;
	i2c->read(address, MODE_ADR, &oldmode);
	uint8_t newmode = (oldmode & 0x7F) | 0x10;
	i2c->write(address, MODE_ADR, &newmode);
	i2c->write(address, PRESCALE_ADR, &prescale);
	i2c->write(address, MODE_ADR, &oldmode);
	delay(5);
	oldmode = oldmode | 0x80;
	i2c->write(address, MODE_ADR, &oldmode);
}

void PCA9685::setDuty(uint8_t channel, float duty)
{
	float data = duty * 4996 / 100;
	uint8_t dataSend = (uint16_t)data & 0xFF;
	i2c->write(address, BASE_ADR_LOW + 4 * channel, &dataSend);
	dataSend = (uint16_t)data >> 8;
	i2c->write(address, BASE_ADR_HIGH + 4 * channel, &dataSend);
}
