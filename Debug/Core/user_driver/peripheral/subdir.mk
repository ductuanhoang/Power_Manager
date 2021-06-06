################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/user_driver/peripheral/adc_driver.c \
../Core/user_driver/peripheral/i2c_driver.c \
../Core/user_driver/peripheral/timer_driver.c \
../Core/user_driver/peripheral/uart_com.c 

OBJS += \
./Core/user_driver/peripheral/adc_driver.o \
./Core/user_driver/peripheral/i2c_driver.o \
./Core/user_driver/peripheral/timer_driver.o \
./Core/user_driver/peripheral/uart_com.o 

C_DEPS += \
./Core/user_driver/peripheral/adc_driver.d \
./Core/user_driver/peripheral/i2c_driver.d \
./Core/user_driver/peripheral/timer_driver.d \
./Core/user_driver/peripheral/uart_com.d 


# Each subdirectory must supply rules for building sources it contributes
Core/user_driver/peripheral/adc_driver.o: ../Core/user_driver/peripheral/adc_driver.c Core/user_driver/peripheral/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/user_driver/peripheral/adc_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/user_driver/peripheral/i2c_driver.o: ../Core/user_driver/peripheral/i2c_driver.c Core/user_driver/peripheral/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/user_driver/peripheral/i2c_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/user_driver/peripheral/timer_driver.o: ../Core/user_driver/peripheral/timer_driver.c Core/user_driver/peripheral/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/user_driver/peripheral/timer_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/user_driver/peripheral/uart_com.o: ../Core/user_driver/peripheral/uart_com.c Core/user_driver/peripheral/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/user_driver/peripheral/uart_com.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

