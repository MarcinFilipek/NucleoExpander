/*
 * HardwareInterrupt.cpp
 *
 *  Created on: 16.07.2019
 *      Author: user
 */

#include "HardwareInterrupt.h"
#include "UartDma/UartDma.h"

/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

/**
 * @brief This function handles Memory management fault.
 */
void MemManage_Handler(void)
{
	while (1)
	{
	}
}

/**
 * @brief This function handles Pre-fetch fault, memory access fault.
 */
void BusFault_Handler(void)
{
	while (1)
	{
	}
}

/**
 * @brief This function handles Undefined instruction or illegal state.
 */
void UsageFault_Handler(void)
{
	while (1)
	{
	}
}

/**
 * @brief This function handles System service call via SWI instruction.
 */
void SVC_Handler(void)
{
}

/**
 * @brief This function handles Debug monitor.
 */
void DebugMon_Handler(void)
{
}

/**
 * @brief This function handles Pendable request for system service.
 */
void PendSV_Handler(void)
{
}

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void)
{
	HAL_IncTick();
}

/**
  * @brief  This function handles DMA RX interrupt request.
  * @param  None
  * @retval None
  */
void DMA1_Stream1_IRQHandler(void)
{
	UartDma::getInstance()->irqRX();
}

/**
  * @brief  This function handles DMA TX interrupt request.
  * @param  None
  * @retval None
  */
void DMA1_Stream3_IRQHandler(void)
{
	UartDma::getInstance()->irqTX();
}

/**
  * @brief  This function handles USARTx interrupt request.
  * @param  None
  * @retval None
  */
void USART3_IRQHandler(void)
{
	UartDma::getInstance()->irqUART();
}
