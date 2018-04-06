/*
 * app.c
 *
 *  Created on: Mar 4, 2018
 *      Author: User
 */

#include "app.h"


void application()
{

    /* memory allocation for buffers

    prepare UART command reception
    prepare SAI interface
    prepare SPI peripheral

    */
    
}

void SAI_app(uint32_t flag)
{
    /*
    what it does when an interrupt from SAI comes
    1. manipulate data to make them int16_t
    2. simultaneusly write them in the SPI transfer buffer
    3. read the flag to decide which half-buffer to proccess every time

    */

}

void UART_app(uint8_t cmd)
{
    /*
    command recieved
    1. restart device
    2. send status

    */

}
