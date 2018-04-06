/*
 * app_storage.c
 *
 *  Created on: Feb 7, 2018
 *      Author: User
 */


#include "app_storage.h"


FATFS mynewdiskFatFs;
FIL MyFile, FM1, FM2, FM3, FM4;
const char mynewdiskPath[4];
static  UINT *wbytes;

static char msg_start[] = "Start SD\n\r";

static char msg_error_mount[] = "mount error\n\r";
static char msg_error_open[] = "open error\n\r";
static char msg_error_write[] = "write error\n\r";
static char msg_error_linking[] = "linking error\n\r";

static char msg_link_success[] = "linking success\n\r";
static char msg_mount_success[] = "mount success\n\r";
static char msg_open_success[] = "open file success\n\r";
static char msg_write_success[] = "write buffer success\n\r";



void store_packet (uint8_t * p_packet, int size, int f)
{
    switch (f){     
        case 1:
            if (f_write(&FM1, p_packet, (UINT)size, wbytes) == FR_OK)
            {
                //CDC_Transmit_HS((uint8_t *)msg_write_success, sizeof(msg_write_success));
            }else
            {
                //CDC_Transmit_HS((uint8_t *)msg_error_write, sizeof(msg_error_write));
            }
            break;
        case 2:
            if (f_write(&FM2, p_packet, (UINT)size, wbytes) == FR_OK)
            {
                //CDC_Transmit_HS((uint8_t *)msg_write_success, sizeof(msg_write_success));
            }else
            {
                //CDC_Transmit_HS((uint8_t *)msg_error_write, sizeof(msg_error_write));
            }
            break;
        case 3:
            if (f_write(&FM3, p_packet, (UINT)size, wbytes) == FR_OK)
            {
                //CDC_Transmit_HS((uint8_t *)msg_write_success, sizeof(msg_write_success));
            }else
            {
                //CDC_Transmit_HS((uint8_t *)msg_error_write, sizeof(msg_error_write));
            }
            break;
        case 4:
            if (f_write(&FM4, p_packet, (UINT)size, wbytes) == FR_OK)
            {
                //CDC_Transmit_HS((uint8_t *)msg_write_success, sizeof(msg_write_success));
            }else
            {
                //CDC_Transmit_HS((uint8_t *)msg_error_write, sizeof(msg_error_write));
            }
            break;
    }

}

void initialize_storage()
{
    // debug message
    //CDC_Transmit_HS((uint8_t *)msg_start, sizeof(msg_start));


    if (FATFS_LinkDriver(&SD_Driver, mynewdiskPath) == FR_OK)
    {
        CDC_Transmit_HS((uint8_t *)msg_link_success, sizeof(msg_link_success));
        if (f_mount(&mynewdiskFatFs, (TCHAR const*)mynewdiskPath, 0) == FR_OK)
        {
            CDC_Transmit_HS((uint8_t *)msg_mount_success, sizeof(msg_mount_success));
                if ((f_open(&FM1, "FM1.HEX", FA_CREATE_ALWAYS|FA_WRITE) == FR_OK)&\
                        (f_open(&FM2, "FM2.HEX", FA_CREATE_ALWAYS|FA_WRITE) == FR_OK)&\
                        (f_open(&FM3, "FM3.HEX", FA_CREATE_ALWAYS|FA_WRITE) == FR_OK)&\
                        (f_open(&FM4, "FM4.HEX", FA_CREATE_ALWAYS|FA_WRITE) == FR_OK))
                    {
                        CDC_Transmit_HS((uint8_t *)msg_open_success, sizeof(msg_open_success));
                    }
                    else
                    {
                        CDC_Transmit_HS((uint8_t *)msg_error_open, sizeof(msg_error_open));
                    }
        }else
        {
            CDC_Transmit_HS((uint8_t *)msg_error_mount, sizeof(msg_error_mount));
        }
    }else
    {
        CDC_Transmit_HS((uint8_t *)msg_error_linking, sizeof(msg_error_linking));        
    }





    
}


void close_storage()
{
    f_close(&FM1);
    f_close(&FM2);
    f_close(&FM3);
    f_close(&FM4);
    static char msg[] = "Storage closed\n\r";
    CDC_Transmit_HS((uint8_t *)msg, sizeof(msg));

}

