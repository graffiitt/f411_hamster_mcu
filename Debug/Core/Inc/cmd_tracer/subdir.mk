################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/cmd_tracer/cmd_move.c \
../Core/Inc/cmd_tracer/cmd_tracer.c \
../Core/Inc/cmd_tracer/ioCommand.c 

OBJS += \
./Core/Inc/cmd_tracer/cmd_move.o \
./Core/Inc/cmd_tracer/cmd_tracer.o \
./Core/Inc/cmd_tracer/ioCommand.o 

C_DEPS += \
./Core/Inc/cmd_tracer/cmd_move.d \
./Core/Inc/cmd_tracer/cmd_tracer.d \
./Core/Inc/cmd_tracer/ioCommand.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/cmd_tracer/%.o Core/Inc/cmd_tracer/%.su Core/Inc/cmd_tracer/%.cyclo: ../Core/Inc/cmd_tracer/%.c Core/Inc/cmd_tracer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-cmd_tracer

clean-Core-2f-Inc-2f-cmd_tracer:
	-$(RM) ./Core/Inc/cmd_tracer/cmd_move.cyclo ./Core/Inc/cmd_tracer/cmd_move.d ./Core/Inc/cmd_tracer/cmd_move.o ./Core/Inc/cmd_tracer/cmd_move.su ./Core/Inc/cmd_tracer/cmd_tracer.cyclo ./Core/Inc/cmd_tracer/cmd_tracer.d ./Core/Inc/cmd_tracer/cmd_tracer.o ./Core/Inc/cmd_tracer/cmd_tracer.su ./Core/Inc/cmd_tracer/ioCommand.cyclo ./Core/Inc/cmd_tracer/ioCommand.d ./Core/Inc/cmd_tracer/ioCommand.o ./Core/Inc/cmd_tracer/ioCommand.su

.PHONY: clean-Core-2f-Inc-2f-cmd_tracer

