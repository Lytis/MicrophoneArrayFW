/*
 * app.c
 *
 *  Created on: Feb 26, 2018
 *      Author: User
 */


#include "app.h"

extern SPI_HandleTypeDef hspi2;

#define     P_SIZE     8 * 4800 * sizeof(int16_t) + 2     //10 msec buffer per mic @ 8 mics

#define     HALF_1      0xFFFFFFFF
#define     HALF_2      0xFFFFFFFF
#define     HALF_3      0xFFFFFFFF
#define     HALF_4      0xFFFFFFFF

#define     SPI_1_HT
#define     SPI_1_FT
#define     SPI_2_HT
#define     SPI_2_FT

static char msg_SPI_success[] = "SPI_OK\n\r";
static char msg_SPI_error[] = "SPI_ERROR\n\r";

int16_t *SPI_1_buffer;
int16_t *SPI_2_buffer;
int16_t *SPI_3_buffer;
int16_t *SPI_4_buffer;

void main_app()
{
    // VCP_main_menu();
    // instead of main()
    // memmory allocation
    // debug messages
    VCP_main_menu();
}

void initialize()
{

    /*
    1. send restart command to mic modes and wait for them to restart
    2. initialize storage, open necesery files
    3. Start SPI peripherals


    */

    // test function until final built

    initialize_storage();
    initialize_SPI();

    SPI_1_buffer = (int16_t*)malloc(P_SIZE);
    SPI_2_buffer = (int16_t*)malloc(P_SIZE);
    //SPI_3_buffer = (int16_t*)malloc(P_SIZE);
    //SPI_4_buffer = (int16_t*)malloc(P_SIZE);

    int i;

        for (i=0; i<P_SIZE/2; i++)
    {
        SPI_1_buffer[i] = (int16_t)i;
        SPI_2_buffer[i] = (int16_t)i;
        //SPI_3_buffer[i] = (int16_t)i;
        //SPI_4_buffer[i] = (int16_t)i;
    }

    main_app();

    // start SPI with DMA


}

void initialize_SPI()
{



    int size = 8*4800*sizeof(int16_t)+2;

    if (1)
    {
        CDC_Transmit_HS((uint8_t *)msg_SPI_success, sizeof(msg_SPI_success));
    }else
    {
        CDC_Transmit_HS((uint8_t *)msg_SPI_error, sizeof(msg_SPI_error));
    }

    /*
    1. initialize SPI and DMA recieve buffers

    */

}

void SPI_recieve_app(uint32_t fl_L, uint32_t fl_H)
{
    /*
    1.
    2. are all 4 half buffers ready??? use a byte and a mask to keep track or open 4 seperate files
    3. write buffers to file (or files)
    4. 


    */
    // based on the flag write to the memory buffer
    // store_packet(pointer to buffer, size of buffer)

    // test function using test function of storage


    //static uint8_t buffer[20] = "I am a packet\n\r";

    //store_packet(buffer, sizeof(buffer));

    store_packet((uint8_t *) &SPI_1_buffer[1], P_SIZE - 2, 1);
    
    
}

void start_recording()
{

    // start clock for micMode
    /* 
    1. start output of SAI clock


    */
    static char pack[] = "I am a packet\n\r";

    int k;
    // kathe paketo einai 0.1 sec
    for (k=1; k<=100; k++)
    {

        //store_packet((uint8_t *) pack, sizeof(pack), 3);
        SPI_recieve_app(1,1);
    }
}

void end_recording()
{

    /*
    1. disable DMA interrupts close SPI peripheral

    */
    close_storage();

}

void get_status()
{

}

void reset_device()
{

}

void hardware_check()
{

}
