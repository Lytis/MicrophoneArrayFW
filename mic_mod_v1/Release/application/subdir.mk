################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application/app.c 

OBJS += \
./application/app.o 

C_DEPS += \
./application/app.d 


# Each subdirectory must supply rules for building sources it contributes
application/%.o: ../application/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F446xx -I"C:/Users/User/Documents/diplomatiki_AC/mic_mode_v1/mic_mod_v1/Inc" -I"C:/Users/User/Documents/diplomatiki_AC/mic_mode_v1/mic_mod_v1/application" -I"C:/Users/User/Documents/diplomatiki_AC/mic_mode_v1/mic_mod_v1/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/User/Documents/diplomatiki_AC/mic_mode_v1/mic_mod_v1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/User/Documents/diplomatiki_AC/mic_mode_v1/mic_mod_v1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/User/Documents/diplomatiki_AC/mic_mode_v1/mic_mod_v1/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


