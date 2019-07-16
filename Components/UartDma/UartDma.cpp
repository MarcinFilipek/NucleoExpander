/*
 * UartDma.cpp
 *
 *  Created on: 16.07.2019
 *      Author: user
 */

#include "UartDma.h"

UartDma* UartDma::getInstance()
{
	static UartDma uartDma;
	return &uartDma;
}

void UartDma::init(uint8_t* ptrBuf, uint8_t sizeBuf)
{
	ptrBuffer = ptrBuf;
	sizeBuffer = sizeBuf;

	huart.Instance = USART3;
	huart.Init.BaudRate = 115200;
	huart.Init.WordLength = UART_WORDLENGTH_8B;
	huart.Init.StopBits = UART_STOPBITS_1;
	huart.Init.Parity = UART_PARITY_NONE;
	huart.Init.Mode = UART_MODE_TX_RX;
	huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart.Init.OverSampling = UART_OVERSAMPLING_16;
	__HAL_RCC_USART3_CLK_ENABLE();
	HAL_UART_Init(&huart);


	pinInit();
	dmaInit();

	/* NVIC configuration for USART TC interrupt */
	HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART3_IRQn);
}


void UartDma::pinInit()
{
	__HAL_RCC_GPIOD_CLK_ENABLE();
	/**USART3 GPIO Configuration
	 PD8     ------> USART3_TX
	 PD9     ------> USART3_RX
	 */
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void UartDma::dmaInit()
{
	__HAL_RCC_DMA1_CLK_ENABLE();
	/* Configure the DMA handler for Transmission process */
	hdma_tx.Instance = DMA1_Stream3;

	hdma_tx.Init.Channel = DMA_CHANNEL_4;
	hdma_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
	hdma_tx.Init.PeriphInc = DMA_PINC_DISABLE;
	hdma_tx.Init.MemInc = DMA_MINC_ENABLE;
	hdma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hdma_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	hdma_tx.Init.Mode = DMA_NORMAL;
	hdma_tx.Init.Priority = DMA_PRIORITY_LOW;
	hdma_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	hdma_tx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
	hdma_tx.Init.MemBurst = DMA_MBURST_INC4;
	hdma_tx.Init.PeriphBurst = DMA_PBURST_INC4;

	HAL_DMA_Init(&hdma_tx);

	/* Associate the initialized DMA handle to the UART handle */
	__HAL_LINKDMA(&huart, hdmatx, hdma_tx);

	/* Configure the DMA handler for reception process */
	hdma_rx.Instance = DMA1_Stream1;

	hdma_rx.Init.Channel = DMA_CHANNEL_4;
	hdma_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
	hdma_rx.Init.PeriphInc = DMA_PINC_DISABLE;
	hdma_rx.Init.MemInc = DMA_MINC_ENABLE;
	hdma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hdma_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	hdma_rx.Init.Mode = DMA_NORMAL;
	hdma_rx.Init.Priority = DMA_PRIORITY_HIGH;
	hdma_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	hdma_rx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
	hdma_rx.Init.MemBurst = DMA_MBURST_INC4;
	hdma_rx.Init.PeriphBurst = DMA_PBURST_INC4;

	HAL_DMA_Init(&hdma_rx);

	/* Associate the initialized DMA handle to the the UART handle */
	__HAL_LINKDMA(&huart, hdmarx, hdma_rx);
	/* NVIC configuration for DMA transfer complete interrupt (USARTx_TX) */
	HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);

	/* NVIC configuration for DMA transfer complete interrupt (USARTx_RX) */
	HAL_NVIC_SetPriority(DMA1_Stream1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream1_IRQn);
}

void UartDma::startRecieveDMA()
{
	if(ptrBuffer && sizeBuffer)
		HAL_UART_Receive_DMA(&huart, ptrBuffer, sizeBuffer);
}

void UartDma::irqTX()
{
	HAL_DMA_IRQHandler(huart.hdmatx);
}

void UartDma::irqRX()
{
	HAL_DMA_IRQHandler(huart.hdmarx);
}

void UartDma::irqUART()
{
	HAL_UART_IRQHandler(&huart);
}
