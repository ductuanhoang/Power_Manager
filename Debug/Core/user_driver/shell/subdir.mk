################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/user_driver/shell/app_cli.c \
../Core/user_driver/shell/vsm_fifo.c \
../Core/user_driver/shell/vsm_retarget.c \
../Core/user_driver/shell/vsm_shell.c 

OBJS += \
./Core/user_driver/shell/app_cli.o \
./Core/user_driver/shell/vsm_fifo.o \
./Core/user_driver/shell/vsm_retarget.o \
./Core/user_driver/shell/vsm_shell.o 

C_DEPS += \
./Core/user_driver/shell/app_cli.d \
./Core/user_driver/shell/vsm_fifo.d \
./Core/user_driver/shell/vsm_retarget.d \
./Core/user_driver/shell/vsm_shell.d 


# Each subdirectory must supply rules for building sources it contributes
Core/user_driver/shell/app_cli.o: ../Core/user_driver/shell/app_cli.c Core/user_driver/shell/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/user_driver/shell/app_cli.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/user_driver/shell/vsm_fifo.o: ../Core/user_driver/shell/vsm_fifo.c Core/user_driver/shell/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/user_driver/shell/vsm_fifo.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/user_driver/shell/vsm_retarget.o: ../Core/user_driver/shell/vsm_retarget.c Core/user_driver/shell/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/user_driver/shell/vsm_retarget.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/user_driver/shell/vsm_shell.o: ../Core/user_driver/shell/vsm_shell.c Core/user_driver/shell/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/user_driver/shell/vsm_shell.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

