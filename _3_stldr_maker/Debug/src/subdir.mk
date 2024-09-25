################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su src/%.cyclo: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/ap" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/ap/user_ap" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/bsp" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/bsp/startup" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/common" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/common/hw/inc" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/hw" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/main.cyclo ./src/main.d ./src/main.o ./src/main.su

.PHONY: clean-src

