################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/cr_startup_lpc11xx.c \
../example/src/hid_desc.c \
../example/src/hid_keyboard.c \
../example/src/hid_main.c \
../example/src/ms_timer.c \
../example/src/sysinit.c 

OBJS += \
./example/src/cr_startup_lpc11xx.o \
./example/src/hid_desc.o \
./example/src/hid_keyboard.o \
./example/src/hid_main.o \
./example/src/ms_timer.o \
./example/src/sysinit.o 

C_DEPS += \
./example/src/cr_startup_lpc11xx.d \
./example/src/hid_desc.d \
./example/src/hid_keyboard.d \
./example/src/hid_main.d \
./example/src/ms_timer.d \
./example/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/cr_startup_lpc11xx.o: ../example/src/cr_startup_lpc11xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M0 -I"/Users/bertouttier/development/workspaces/LPCXpresso/Phyx_hid_device/example/inc" -I"/Users/bertouttier/development/workspaces/LPCXpresso/lpc_chip_11uxx_lib/inc" -I"/Users/bertouttier/development/workspaces/LPCXpresso/phyx_11u35_board_lib/inc" -I"/Users/bertouttier/development/workspaces/LPCXpresso/lpc_chip_11uxx_lib/inc/usbd" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"example/src/cr_startup_lpc11xx.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M0 -I"/Users/bertouttier/development/workspaces/LPCXpresso/Phyx_hid_device/example/inc" -I"/Users/bertouttier/development/workspaces/LPCXpresso/lpc_chip_11uxx_lib/inc" -I"/Users/bertouttier/development/workspaces/LPCXpresso/phyx_11u35_board_lib/inc" -I"/Users/bertouttier/development/workspaces/LPCXpresso/lpc_chip_11uxx_lib/inc/usbd" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


