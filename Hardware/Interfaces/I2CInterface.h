/*
 * I2CInterface.h
 *
 *  Created on: 17.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#ifndef INTERFACES_I2CINTERFACE_H_
#define INTERFACES_I2CINTERFACE_H_

#include "stdint.h"

class I2CInterface
{
public:
	virtual void read(uint8_t address, uint8_t reg, uint8_t* buf, uint8_t sizeBuf = 1) = 0;
	virtual void write(uint8_t address, uint8_t reg, uint8_t* buf, uint8_t sizeBuf = 1) = 0;
};



#endif /* INTERFACES_I2CINTERFACE_H_ */
