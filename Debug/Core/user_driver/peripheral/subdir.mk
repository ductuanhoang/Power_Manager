################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/user_driver/peripheral/adc_driver.c \
../Core/user_driver/peripheral/i2c_driver.c \
../Core/user_driver/peripheral/timer_driver.c \
../Core/user_driver/peripheral/uart_com.c \
../Core/user_driver/peripheral/uart_lora.c 

OBJS += \
./Core/user_driver/peripheral/adc_driver.o \
./Core/user_driver/peripheral/i2c_driver.o \
./Core/user_driver/peripheral/timer_driver.o \
./Core/user_driver/peripheral/uart_com.o \
./Core/user_driver/peripheral/uart_lora.o 

C_DEPS += \
./Core/user_driver/peripheral/adc_driver.d \
./Core/user_driver/peripheral/i2c_driver.d \
./Core/user_driver/peripheral/timer_driver.d \
./Core/user_driver/peripheral/uart_com.d \
./Core/user_driver/peripheral/uart_lora.d 


# Each subdirectory must supply rules for building sources it contributes
Core/user_driver/peripheral/%.o Core/user_driver/peripheral/%.su Core/user_driver/peripheral/%.cyclo: ../Core/user_driver/peripheral/%.c Core/user_driver/peripheral/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L071xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I../Core/user_driver -I../Core/user_driver/control_output -I../Core/user_driver/peripheral -I../Core/user_driver/rotary -I../Core/user_driver/shell -I../Core/user_driver/sht20 -I../Core/user_driver/charger_status -I../Core/user_driver/volt_detect -I../Core/user_driver/lora_com -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-user_driver-2f-peripheral

clean-Core-2f-user_driver-2f-peripheral:
	-$(RM) ./Core/user_driver/peripheral/adc_driver.cyclo ./Core/user_driver/peripheral/adc_driver.d ./Core/user_driver/peripheral/adc_driver.o ./Core/user_driver/peripheral/adc_driver.su ./Core/user_driver/peripheral/i2c_driver.cyclo ./Core/user_driver/peripheral/i2c_driver.d ./Core/user_driver/peripheral/i2c_driver.o ./Core/user_driver/peripheral/i2c_driver.su ./Core/user_driver/peripheral/timer_driver.cyclo ./Core/user_driver/peripheral/timer_driver.d ./Core/user_driver/peripheral/timer_driver.o ./Core/user_driver/peripheral/timer_driver.su ./Core/user_driver/peripheral/uart_com.cyclo ./Core/user_driver/peripheral/uart_com.d ./Core/user_driver/peripheral/uart_com.o ./Core/user_driver/peripheral/uart_com.su ./Core/user_driver/peripheral/uart_lora.cyclo ./Core/user_driver/peripheral/uart_lora.d ./Core/user_driver/peripheral/uart_lora.o ./Core/user_driver/peripheral/uart_lora.su

.PHONY: clean-Core-2f-user_driver-2f-peripheral

