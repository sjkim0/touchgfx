################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ap/user_ap/Dev_Inf.c \
../src/ap/user_ap/Loader_Src.c \
../src/ap/user_ap/ap_custom_loader.c \
../src/ap/user_ap/ap_qspi.c \
../src/ap/user_ap/ap_switch.c \
../src/ap/user_ap/ap_uart.c 

OBJS += \
./src/ap/user_ap/Dev_Inf.o \
./src/ap/user_ap/Loader_Src.o \
./src/ap/user_ap/ap_custom_loader.o \
./src/ap/user_ap/ap_qspi.o \
./src/ap/user_ap/ap_switch.o \
./src/ap/user_ap/ap_uart.o 

C_DEPS += \
./src/ap/user_ap/Dev_Inf.d \
./src/ap/user_ap/Loader_Src.d \
./src/ap/user_ap/ap_custom_loader.d \
./src/ap/user_ap/ap_qspi.d \
./src/ap/user_ap/ap_switch.d \
./src/ap/user_ap/ap_uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/ap/user_ap/%.o src/ap/user_ap/%.su src/ap/user_ap/%.cyclo: ../src/ap/user_ap/%.c src/ap/user_ap/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H730xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/ap" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/ap/user_ap" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/bsp" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/bsp/startup" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/common" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/common/hw/inc" -I"C:/Users/ksj10/Desktop/_0_programs/_3_GIT_REPO/__PRIVATE/_2_TOUCHGFX/_3_stldr_maker/src/hw" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-ap-2f-user_ap

clean-src-2f-ap-2f-user_ap:
	-$(RM) ./src/ap/user_ap/Dev_Inf.cyclo ./src/ap/user_ap/Dev_Inf.d ./src/ap/user_ap/Dev_Inf.o ./src/ap/user_ap/Dev_Inf.su ./src/ap/user_ap/Loader_Src.cyclo ./src/ap/user_ap/Loader_Src.d ./src/ap/user_ap/Loader_Src.o ./src/ap/user_ap/Loader_Src.su ./src/ap/user_ap/ap_custom_loader.cyclo ./src/ap/user_ap/ap_custom_loader.d ./src/ap/user_ap/ap_custom_loader.o ./src/ap/user_ap/ap_custom_loader.su ./src/ap/user_ap/ap_qspi.cyclo ./src/ap/user_ap/ap_qspi.d ./src/ap/user_ap/ap_qspi.o ./src/ap/user_ap/ap_qspi.su ./src/ap/user_ap/ap_switch.cyclo ./src/ap/user_ap/ap_switch.d ./src/ap/user_ap/ap_switch.o ./src/ap/user_ap/ap_switch.su ./src/ap/user_ap/ap_uart.cyclo ./src/ap/user_ap/ap_uart.d ./src/ap/user_ap/ap_uart.o ./src/ap/user_ap/ap_uart.su

.PHONY: clean-src-2f-ap-2f-user_ap

