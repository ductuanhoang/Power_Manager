################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/user_driver/control_output/button_driver.c \
../Core/user_driver/control_output/user_control.c \
../Core/user_driver/control_output/user_lec.c 

OBJS += \
./Core/user_driver/control_output/button_driver.o \
./Core/user_driver/control_output/user_control.o \
./Core/user_driver/control_output/user_lec.o 

C_DEPS += \
./Core/user_driver/control_output/button_driver.d \
./Core/user_driver/control_output/user_control.d \
./Core/user_driver/control_output/user_lec.d 


# Each subdirectory must supply rules for building sources it contributes
Core/user_driver/control_output/%.o Core/user_driver/control_output/%.su Core/user_driver/control_output/%.cyclo: ../Core/user_driver/control_output/%.c Core/user_driver/control_output/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -I../Core/user_driver/sht20 -I../Core/user_driver/charger_status -I../Core/user_driver/volt_detect -I../Core/user_driver/lora_com -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-user_driver-2f-control_output

clean-Core-2f-user_driver-2f-control_output:
	-$(RM) ./Core/user_driver/control_output/button_driver.cyclo ./Core/user_driver/control_output/button_driver.d ./Core/user_driver/control_output/button_driver.o ./Core/user_driver/control_output/button_driver.su ./Core/user_driver/control_output/user_control.cyclo ./Core/user_driver/control_output/user_control.d ./Core/user_driver/control_output/user_control.o ./Core/user_driver/control_output/user_control.su ./Core/user_driver/control_output/user_lec.cyclo ./Core/user_driver/control_output/user_lec.d ./Core/user_driver/control_output/user_lec.o ./Core/user_driver/control_output/user_lec.su

.PHONY: clean-Core-2f-user_driver-2f-control_output

