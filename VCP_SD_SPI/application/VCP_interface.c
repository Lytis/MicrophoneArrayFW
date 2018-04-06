/*
 * VCP_interface.c
 *
 *  Created on: Feb 4, 2018
 *      Author: User
 */

#include "VCP_interface.h"


void VCP_command(uint8_t cmd)
{

	char command_response[50] = {0};

	switch (cmd)
	{
	case '1':
	{
		//print command 1
		sprintf (command_response, "Start recording function...\n\r");
		start_recording();
		break;
	}
	case '2':
	{
		//print command 2
		end_recording();
		sprintf(command_response, "End recording session...\n\r");
		break;
	}
	case '3':
	{
		sprintf(command_response, "Geting device status...\n\r");
		get_status();
		break;
	}
	case '4':
	{
		sprintf(command_response, "Reset device...\n\r\n\r");
		NVIC_SystemReset();
		break;
	}
	case '5':
	{
		sprintf(command_response, "Hardware checking...\n\r");
		hardware_check();
		break;
	}
	default:
	{
		//print invalid command
		sprintf (command_response, "Invalid command\n\r");
		break;
	}
	}

	CDC_Transmit_HS((uint8_t*)command_response, sizeof(command_response));


}

void VCP_main_menu(void)
{
	char menu[] =
	"Available commands:\n\r"
	"1.Start recording\n\r"
	"2.End recording\n\r"
	"3.Device status\n\r"
	"4.Device reset\n\r"
	"5.Hardware check\n\r"
	"Press command number..."
	"\n\r";

	CDC_Transmit_HS ((uint8_t*)menu, sizeof(menu));

}