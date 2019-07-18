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
	void read(uint8_t address, uint8_t reg, uint8_t* buf, uint8_t sizeBuf = 1);
	void write(uint8_t address, uint8_t reg, uint8_t* buf, uint8_t sizeBuf = 1);
private:
	I2C_HandleTypeDef I2CHandle;

	void initPins();
};

#endif /* I2C_I2C_H_ */
