################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L0xx_HAL_Driver/Src/subdir.mk
-include Core/user_driver/volt_detect/subdir.mk
-include Core/user_driver/sht20/subdir.mk
-include Core/user_driver/shell/subdir.mk
-include Core/user_driver/rotary/subdir.mk
-include Core/user_driver/peripheral/subdir.mk
-include Core/user_driver/lora_com/subdir.mk
-include Core/user_driver/control_output/subdir.mk
-include Core/user_driver/charger_status/subdir.mk
-include Core/user_driver/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Power_Manager
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Power_Manager.elf \

MAP_FILES += \
Power_Manager.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Power_Manager.list \

OBJCOPY_HEX += \
Power_Manager.hex \

OBJCOPY_BIN += \
Power_Manager.bin \


# All Target
all: main-build

# Main-build Target
main-build: Power_Manager.elf secondary-outputs

# Tool invocations
Power_Manager.elf Power_Manager.map: $(OBJS) $(USER_OBJS) D:\OneDrive\upwork_2\2.upwork\37.PowerManager\Power_Manager\STM32L071CBTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Power_Manager.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"D:\OneDrive\upwork_2\2.upwork\37.PowerManager\Power_Manager\STM32L071CBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Power_Manager.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Power_Manager.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Power_Manager.list"
	@echo 'Finished building: $@'
	@echo ' '

Power_Manager.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Power_Manager.hex"
	@echo 'Finished building: $@'
	@echo ' '

Power_Manager.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Power_Manager.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Power_Manager.bin Power_Manager.elf Power_Manager.hex Power_Manager.list Power_Manager.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
