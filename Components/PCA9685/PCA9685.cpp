/*
 * PCA9685.cpp
 *
 *  Created on: 17.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#include "PCA9685.h"

void PCA9685::setFreq(uint8_t freq)
{
	float prescaleValue = 25000000.0f;
	prescaleValue /= 4046.0f;
	prescaleValue /= (float)freq;
	prescaleValue -= 1.0f;
}
