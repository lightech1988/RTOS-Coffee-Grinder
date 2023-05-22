################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Ass-02-adcTask.c \
../Core/Src/Ass-02-controlTask.c \
../Core/Src/Ass-02-grindTimerTask.c \
../Core/Src/Ass-02-pauseTimer.c \
../Core/Src/Ass-02-touchPanelTask.c \
../Core/Src/adc.c \
../Core/Src/dac.c \
../Core/Src/dma.c \
../Core/Src/freertos.c \
../Core/Src/fsmc.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/spi.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_hal_timebase_tim.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tim.c 

OBJS += \
./Core/Src/Ass-02-adcTask.o \
./Core/Src/Ass-02-controlTask.o \
./Core/Src/Ass-02-grindTimerTask.o \
./Core/Src/Ass-02-pauseTimer.o \
./Core/Src/Ass-02-touchPanelTask.o \
./Core/Src/adc.o \
./Core/Src/dac.o \
./Core/Src/dma.o \
./Core/Src/freertos.o \
./Core/Src/fsmc.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/spi.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_hal_timebase_tim.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tim.o 

C_DEPS += \
./Core/Src/Ass-02-adcTask.d \
./Core/Src/Ass-02-controlTask.d \
./Core/Src/Ass-02-grindTimerTask.d \
./Core/Src/Ass-02-pauseTimer.d \
./Core/Src/Ass-02-touchPanelTask.d \
./Core/Src/adc.d \
./Core/Src/dac.d \
./Core/Src/dma.d \
./Core/Src/freertos.d \
./Core/Src/fsmc.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/spi.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_hal_timebase_tim.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Ass-02-adcTask.cyclo ./Core/Src/Ass-02-adcTask.d ./Core/Src/Ass-02-adcTask.o ./Core/Src/Ass-02-adcTask.su ./Core/Src/Ass-02-controlTask.cyclo ./Core/Src/Ass-02-controlTask.d ./Core/Src/Ass-02-controlTask.o ./Core/Src/Ass-02-controlTask.su ./Core/Src/Ass-02-grindTimerTask.cyclo ./Core/Src/Ass-02-grindTimerTask.d ./Core/Src/Ass-02-grindTimerTask.o ./Core/Src/Ass-02-grindTimerTask.su ./Core/Src/Ass-02-pauseTimer.cyclo ./Core/Src/Ass-02-pauseTimer.d ./Core/Src/Ass-02-pauseTimer.o ./Core/Src/Ass-02-pauseTimer.su ./Core/Src/Ass-02-touchPanelTask.cyclo ./Core/Src/Ass-02-touchPanelTask.d ./Core/Src/Ass-02-touchPanelTask.o ./Core/Src/Ass-02-touchPanelTask.su ./Core/Src/adc.cyclo ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/dac.cyclo ./Core/Src/dac.d ./Core/Src/dac.o ./Core/Src/dac.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/freertos.cyclo ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/fsmc.cyclo ./Core/Src/fsmc.d ./Core/Src/fsmc.o ./Core/Src/fsmc.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/spi.cyclo ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_hal_timebase_tim.cyclo ./Core/Src/stm32f4xx_hal_timebase_tim.d ./Core/Src/stm32f4xx_hal_timebase_tim.o ./Core/Src/stm32f4xx_hal_timebase_tim.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su

.PHONY: clean-Core-2f-Src

