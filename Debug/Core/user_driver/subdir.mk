################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/user_driver/user_process.c 

OBJS += \
./Core/user_driver/user_process.o 

C_DEPS += \
./Core/user_driver/user_process.d 


# Each subdirectory must supply rules for building sources it contributes
Core/user_driver/%.o Core/user_driver/%.su Core/user_driver/%.cyclo: ../Core/user_driver/%.c Core/user_driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -I../Core/user_driver/sht20 -I../Core/user_driver/charger_status -I../Core/user_driver/volt_detect -I../Core/user_driver/lora_com -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-user_driver

clean-Core-2f-user_driver:
	-$(RM) ./Core/user_driver/user_process.cyclo ./Core/user_driver/user_process.d ./Core/user_driver/user_process.o ./Core/user_driver/user_process.su

.PHONY: clean-Core-2f-user_driver

