################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
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
Core/user_driver/shell/%.o Core/user_driver/shell/%.su Core/user_driver/shell/%.cyclo: ../Core/user_driver/shell/%.c Core/user_driver/shell/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -I../Core/user_driver/sht20 -I../Core/user_driver/charger_status -I../Core/user_driver/volt_detect -I../Core/user_driver/lora_com -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-user_driver-2f-shell

clean-Core-2f-user_driver-2f-shell:
	-$(RM) ./Core/user_driver/shell/app_cli.cyclo ./Core/user_driver/shell/app_cli.d ./Core/user_driver/shell/app_cli.o ./Core/user_driver/shell/app_cli.su ./Core/user_driver/shell/vsm_fifo.cyclo ./Core/user_driver/shell/vsm_fifo.d ./Core/user_driver/shell/vsm_fifo.o ./Core/user_driver/shell/vsm_fifo.su ./Core/user_driver/shell/vsm_retarget.cyclo ./Core/user_driver/shell/vsm_retarget.d ./Core/user_driver/shell/vsm_retarget.o ./Core/user_driver/shell/vsm_retarget.su ./Core/user_driver/shell/vsm_shell.cyclo ./Core/user_driver/shell/vsm_shell.d ./Core/user_driver/shell/vsm_shell.o ./Core/user_driver/shell/vsm_shell.su

.PHONY: clean-Core-2f-user_driver-2f-shell

