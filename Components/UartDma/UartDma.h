/*
 * UartDma.h
 *
 *  Created on: 16.07.2019
 *      Author: user
 */

#ifndef UARTDMA_UARTDMA_H_
#define UARTDMA_UARTDMA_H_

#include "Hal.h"

class UartDma
{
public:
	UartDma():
		ptrBuffer(0),
		sizeBuffer(0)
	{};
	virtual ~UartDma(){}
	void init(uint8_t* ptrBuf, uint8_t sizeBuf);
	static UartDma* getInstance();

	void startRecieveDMA();
	void irqTX();
	void irqRX();
	void irqUART();
	UART_HandleTypeDef huart;
private:
	uint8_t* ptrBuffer;
	uint8_t sizeBuffer;
	DMA_HandleTypeDef hdma_tx;
	DMA_HandleTypeDef hdma_rx;

	void pinInit();
	void dmaInit();
};

#endif /* UARTDMA_UARTDMA_H_ */
