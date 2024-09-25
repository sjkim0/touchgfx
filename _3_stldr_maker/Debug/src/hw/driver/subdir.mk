################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/driver/gpio.c \
../src/hw/driver/octospi.c 

OBJS += \
./src/hw/driver/gpio.o \
./src/hw/driver/octospi.o 

C_DEPS += \
./src/hw/driver/gpio.d \
./src/hw/driver/octospi.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/driver/%.o src/hw/driver/%.su src/hw/driver/%.cyclo: ../src/hw/driver/%.c src/hw/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/ap" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/ap/user_ap" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/bsp" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/bsp/startup" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/common" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/common/hw/inc" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/hw" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-hw-2f-driver

clean-src-2f-hw-2f-driver:
	-$(RM) ./src/hw/driver/gpio.cyclo ./src/hw/driver/gpio.d ./src/hw/driver/gpio.o ./src/hw/driver/gpio.su ./src/hw/driver/octospi.cyclo ./src/hw/driver/octospi.d ./src/hw/driver/octospi.o ./src/hw/driver/octospi.su

.PHONY: clean-src-2f-hw-2f-driver

