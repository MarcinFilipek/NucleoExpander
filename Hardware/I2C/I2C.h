/*
 * I2C.h
 *
 *  Created on: 17.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#ifndef I2C_I2C_H_
#define I2C_I2C_H_

#include "Hal.h"
#include "Interfaces/I2CInterface.h"

class I2C: public I2CInterface
{
public:
	void init();
	void test();
	uint8_t read(uint8_t address, uint8_t reg);
private:
	I2C_HandleTypeDef I2CHandle;

	void initPins();
};

#endif /* I2C_I2C_H_ */
