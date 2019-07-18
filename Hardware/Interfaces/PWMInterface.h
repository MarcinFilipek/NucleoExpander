/*
 * PWMInterface.h
 *
 *  Created on: 18.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#ifndef INTERFACES_PWMINTERFACE_H_
#define INTERFACES_PWMINTERFACE_H_

#include "stdint.h"

class PWMInterface
{
public:
	virtual void setDuty(uint8_t channel, float duty) = 0;
};



#endif /* INTERFACES_PWMINTERFACE_H_ */
