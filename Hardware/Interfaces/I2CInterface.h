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
private:
	virtual uint8_t read(uint8_t address, uint8_t reg) = 0;
};



#endif /* INTERFACES_I2CINTERFACE_H_ */
