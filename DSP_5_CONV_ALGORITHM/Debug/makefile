################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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


BUILD_ARTIFACT_NAME := DSP_5_CONV_ALGORITHM
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
DSP_5_CONV_ALGORITHM.elf \

MAP_FILES += \
DSP_5_CONV_ALGORITHM.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
DSP_5_CONV_ALGORITHM.list \


# All Target
all: main-build

# Main-build Target
main-build: DSP_5_CONV_ALGORITHM.elf secondary-outputs

# Tool invocations
DSP_5_CONV_ALGORITHM.elf DSP_5_CONV_ALGORITHM.map: $(OBJS) $(USER_OBJS) C:\Users\baris\OneDrive\Masaüstü\DSP\DSP_5_CONV_ALGORITHM\STM32F303VCTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -gdwarf-4 -o "DSP_5_CONV_ALGORITHM.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\baris\OneDrive\Masaüstü\DSP\DSP_5_CONV_ALGORITHM\STM32F303VCTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="DSP_5_CONV_ALGORITHM.map" -Wl,--gc-sections -static -L"C:\Users\baris\OneDrive\Masaüstü\DSP\DSP_5_CONV_ALGORITHM\CMSIS\Lib\GCC" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

DSP_5_CONV_ALGORITHM.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "DSP_5_CONV_ALGORITHM.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) DSP_5_CONV_ALGORITHM.elf DSP_5_CONV_ALGORITHM.list DSP_5_CONV_ALGORITHM.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
