################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include example/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Phyx_hid_device.axf

# Tool invocations
Phyx_hid_device.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/Users/bertouttier/development/workspaces/LPCXpresso/phyx_11u35_board_lib/Debug" -L"/Users/bertouttier/development/workspaces/LPCXpresso/lpc_chip_11uxx_lib/Debug" -Xlinker -Map="Phyx_hid_device.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "Phyx_hid_device_Debug.ld" -o "Phyx_hid_device.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Phyx_hid_device.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Phyx_hid_device.axf"; # arm-none-eabi-objcopy -O binary "Phyx_hid_device.axf" "Phyx_hid_device.bin" ; checksum -p LPC11U35_501 -d "Phyx_hid_device.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
