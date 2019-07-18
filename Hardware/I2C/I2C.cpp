/*
 * I2C.cpp
 *
 *  Created on: 17.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#include "I2C.h"


void I2C::init()
{
	I2CHandle.Instance = I2C1;
	I2CHandle.Init.ClockSpeed = 100000;
	I2CHandle.Init.DutyCycle = I2C_DUTYCYCLE_2;
	I2CHandle.Init.OwnAddress1 = 0;
	I2CHandle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	I2CHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	I2CHandle.Init.OwnAddress2 = 0;
	I2CHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	I2CHandle.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

	initPins();
	__HAL_RCC_I2C1_CLK_ENABLE();
	__HAL_RCC_I2C1_FORCE_RESET();
	__HAL_RCC_I2C1_RELEASE_RESET();
	HAL_I2C_Init(&I2CHandle);
}

void I2C::initPins()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef gpioInitStruct;

	gpioInitStruct.Pin = GPIO_PIN_8;
	gpioInitStruct.Mode = GPIO_MODE_AF_OD;
	gpioInitStruct.Pull = GPIO_PULLUP;
	gpioInitStruct.Speed = GPIO_SPEED_FAST;
	gpioInitStruct.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &gpioInitStruct);

	gpioInitStruct.Pin = GPIO_PIN_9;
	HAL_GPIO_Init(GPIOB, &gpioInitStruct);
}

void I2C::test()
{
	uint8_t addres = 0x80;
//	HAL_I2C_Mem_Write(&I2CHandle, addres, 0, I2C_MEMADD_SIZE_8BIT, &val, 1, 1000);
	uint8_t readVal = 0;
	HAL_I2C_Mem_Read(&I2CHandle, addres, 2, I2C_MEMADD_SIZE_8BIT, &readVal, 1, 100);
}

void I2C::read(uint8_t address, uint8_t reg, uint8_t* buf, uint8_t sizeBuf)
{
	HAL_I2C_Mem_Read(&I2CHandle, address, reg, I2C_MEMADD_SIZE_8BIT, buf, sizeBuf, 100);
}

void I2C::write(uint8_t address, uint8_t reg, uint8_t* buf, uint8_t sizeBuf)
{
	HAL_I2C_Mem_Write(&I2CHandle, address, reg, I2C_MEMADD_SIZE_8BIT, buf, sizeBuf, 100);
}
