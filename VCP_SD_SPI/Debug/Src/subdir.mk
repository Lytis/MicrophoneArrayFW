################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/bsp_driver_sd.c \
../Src/fatfs.c \
../Src/main.c \
../Src/sd_diskio.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_it.c \
../Src/system_stm32f7xx.c \
../Src/usb_device.c \
../Src/usbd_cdc_if.c \
../Src/usbd_conf.c \
../Src/usbd_desc.c 

OBJS += \
./Src/bsp_driver_sd.o \
./Src/fatfs.o \
./Src/main.o \
./Src/sd_diskio.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_it.o \
./Src/system_stm32f7xx.o \
./Src/usb_device.o \
./Src/usbd_cdc_if.o \
./Src/usbd_conf.o \
./Src/usbd_desc.o 

C_DEPS += \
./Src/bsp_driver_sd.d \
./Src/fatfs.d \
./Src/main.d \
./Src/sd_diskio.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_it.d \
./Src/system_stm32f7xx.d \
./Src/usb_device.d \
./Src/usbd_cdc_if.d \
./Src/usbd_conf.d \
./Src/usbd_desc.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F769xx -I"C:/Users/User/Documents/diplomatiki_AC/VCP_SD_SPI/Inc" -I"C:/Users/User/Documents/diplomatiki_AC/VCP_SD_SPI/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/User/Documents/diplomatiki_AC/VCP_SD_SPI/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/User/Documents/diplomatiki_AC/VCP_SD_SPI/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/User/Documents/diplomatiki_AC/VCP_SD_SPI/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Users/User/Documents/diplomatiki_AC/VCP_SD_SPI/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/User/Documents/diplomatiki_AC/VCP_SD_SPI/Middlewares/Third_Party/FatFs/src" -I"C:/Users/User/Documents/diplomatiki_AC/VCP_SD_SPI/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


