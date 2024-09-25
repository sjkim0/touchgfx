################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp/bsp.c \
../src/bsp/memorymap.c \
../src/bsp/stm32h7xx_hal_msp.c \
../src/bsp/stm32h7xx_it.c \
../src/bsp/syscalls.c \
../src/bsp/sysmem.c \
../src/bsp/system_stm32h7xx.c 

OBJS += \
./src/bsp/bsp.o \
./src/bsp/memorymap.o \
./src/bsp/stm32h7xx_hal_msp.o \
./src/bsp/stm32h7xx_it.o \
./src/bsp/syscalls.o \
./src/bsp/sysmem.o \
./src/bsp/system_stm32h7xx.o 

C_DEPS += \
./src/bsp/bsp.d \
./src/bsp/memorymap.d \
./src/bsp/stm32h7xx_hal_msp.d \
./src/bsp/stm32h7xx_it.d \
./src/bsp/syscalls.d \
./src/bsp/sysmem.d \
./src/bsp/system_stm32h7xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/%.o src/bsp/%.su src/bsp/%.cyclo: ../src/bsp/%.c src/bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/ap" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/ap/user_ap" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/bsp" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/bsp/startup" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/common" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/common/hw/inc" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/hw" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-bsp

clean-src-2f-bsp:
	-$(RM) ./src/bsp/bsp.cyclo ./src/bsp/bsp.d ./src/bsp/bsp.o ./src/bsp/bsp.su ./src/bsp/memorymap.cyclo ./src/bsp/memorymap.d ./src/bsp/memorymap.o ./src/bsp/memorymap.su ./src/bsp/stm32h7xx_hal_msp.cyclo ./src/bsp/stm32h7xx_hal_msp.d ./src/bsp/stm32h7xx_hal_msp.o ./src/bsp/stm32h7xx_hal_msp.su ./src/bsp/stm32h7xx_it.cyclo ./src/bsp/stm32h7xx_it.d ./src/bsp/stm32h7xx_it.o ./src/bsp/stm32h7xx_it.su ./src/bsp/syscalls.cyclo ./src/bsp/syscalls.d ./src/bsp/syscalls.o ./src/bsp/syscalls.su ./src/bsp/sysmem.cyclo ./src/bsp/sysmem.d ./src/bsp/sysmem.o ./src/bsp/sysmem.su ./src/bsp/system_stm32h7xx.cyclo ./src/bsp/system_stm32h7xx.d ./src/bsp/system_stm32h7xx.o ./src/bsp/system_stm32h7xx.su

.PHONY: clean-src-2f-bsp

