/*
 * Dalay.h
 *
 *  Created on: 18.07.2019
 *      Author: Marcin Filipek (Uzume)
 */

#ifndef MISC_DELAY_H_
#define MISC_DELAY_H_

#include "Hal.h"

void delay(uint32_t t)
{
	HAL_Delay(t);
}



#endif /* MISC_DELAY_H_ */
