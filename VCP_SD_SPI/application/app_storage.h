/*
 * app_storage.h
 *
 *  Created on: Feb 7, 2018
 *      Author: User
 */

#ifndef APP_STORAGE_H_
#define APP_STORAGE_H_


#include "usbd_cdc_if.h"
#include "fatfs.h"


void store_packet(uint8_t*, int, int);
void initialize_storage();
void close_storage();


#endif /* APP_STORAGE_H_ */