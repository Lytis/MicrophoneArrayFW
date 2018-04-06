/*
 * app.h
 *
 *  Created on: Mar 4, 2018
 *      Author: User
 */

#ifndef APP_H_
#define APP_H_

#include "main.h"
#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

void application();
void SAI_app(uint32_t);
void UART_app(uint8_t);



#endif /* APP_H_ */
