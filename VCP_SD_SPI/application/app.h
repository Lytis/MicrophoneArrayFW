/*
 * app.h
 *
 *  Created on: Feb 26, 2018
 *      Author: User
 */

#ifndef APP_H_
#define APP_H_

#include "stm32f7xx_hal.h"

#include "VCP_interface.h"
#include "app_storage.h"




void main_app();
void initialize();
void initialize_SPI();
void SPI_recieve_app(uint32_t, uint32_t);

void start_recording();
void end_recording();
void get_status();
void reset_device();
void hardware_check();

#endif /* APP_H_ */
