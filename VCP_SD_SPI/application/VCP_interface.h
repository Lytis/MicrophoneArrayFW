/*
 * VCP_interface.h
 *
 *  Created on: Feb 4, 2018
 *      Author: User
 */

#ifndef VCP_INTERFACE_H_
#define VCP_INTERFACE_H_


#include "usbd_cdc_if.h"
#include "app.h"
#include "app_storage.h"


void VCP_command(uint8_t);
void VCP_main_menu(void);
void VCP_micboard_nemu(void);
void VCP_record_menu(void);

#endif /* VCP_INTERFACE_H_ */
