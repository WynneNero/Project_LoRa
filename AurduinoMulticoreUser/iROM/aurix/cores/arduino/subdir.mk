################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../aurix/cores/arduino/HardwareSerial.cpp \
../aurix/cores/arduino/HardwareSerial0.cpp \
../aurix/cores/arduino/HardwareSerial1.cpp \
../aurix/cores/arduino/HardwareSerialRxTx.cpp \
../aurix/cores/arduino/IPAddress.cpp \
../aurix/cores/arduino/Print.cpp \
../aurix/cores/arduino/Stream.cpp \
../aurix/cores/arduino/WMath.cpp \
../aurix/cores/arduino/main.cpp 

C_SRCS += \
../aurix/cores/arduino/cint_tc27x.c \
../aurix/cores/arduino/hooks.c \
../aurix/cores/arduino/interrupts.c \
../aurix/cores/arduino/wiring.c \
../aurix/cores/arduino/wiring_analog.c \
../aurix/cores/arduino/wiring_digital.c \
../aurix/cores/arduino/wiring_shift.c 

OBJS += \
./aurix/cores/arduino/HardwareSerial.o \
./aurix/cores/arduino/HardwareSerial0.o \
./aurix/cores/arduino/HardwareSerial1.o \
./aurix/cores/arduino/HardwareSerialRxTx.o \
./aurix/cores/arduino/IPAddress.o \
./aurix/cores/arduino/Print.o \
./aurix/cores/arduino/Stream.o \
./aurix/cores/arduino/WMath.o \
./aurix/cores/arduino/cint_tc27x.o \
./aurix/cores/arduino/hooks.o \
./aurix/cores/arduino/interrupts.o \
./aurix/cores/arduino/main.o \
./aurix/cores/arduino/wiring.o \
./aurix/cores/arduino/wiring_analog.o \
./aurix/cores/arduino/wiring_digital.o \
./aurix/cores/arduino/wiring_shift.o 

C_DEPS += \
./aurix/cores/arduino/cint_tc27x.d \
./aurix/cores/arduino/hooks.d \
./aurix/cores/arduino/interrupts.d \
./aurix/cores/arduino/wiring.d \
./aurix/cores/arduino/wiring_analog.d \
./aurix/cores/arduino/wiring_digital.d \
./aurix/cores/arduino/wiring_shift.d 

CPP_DEPS += \
./aurix/cores/arduino/HardwareSerial.d \
./aurix/cores/arduino/HardwareSerial0.d \
./aurix/cores/arduino/HardwareSerial1.d \
./aurix/cores/arduino/HardwareSerialRxTx.d \
./aurix/cores/arduino/IPAddress.d \
./aurix/cores/arduino/Print.d \
./aurix/cores/arduino/Stream.d \
./aurix/cores/arduino/WMath.d \
./aurix/cores/arduino/main.d 


# Each subdirectory must supply rules for building sources it contributes
aurix/cores/arduino/%.o: ../aurix/cores/arduino/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C++ Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\cores\arduino" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Scu\Std" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Stm\Std" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Cpu\Irq" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Lib\DataHandling" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Cpu\Std" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\cores\arduino\avr" -I"../h" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\Ethernet\src" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\Ethernet\src\utility" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\LiquidCrystal" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\SD\src" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\SD\src\utility" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\SPI" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\TFTV2" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\Wire" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Build" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\system\libaurix\include" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Impl" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Lib" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_PinMap" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Reg" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Asclin" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Ccu6" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Cif" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Cpu" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Dma" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Dsadc" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Dts" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Emem" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Eray" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Eth" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Fce" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Flash" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Gtm" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Hssl" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\I2c" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Iom" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Msc" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Mtu" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Multican" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Port" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Psi5" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Psi5s" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Qspi" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Scu" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Sent" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Src" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\SrvSw" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Stm" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Vadc" -fno-common -O0 -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -DUSE_IRQ -DTRIBOARD_TC275C -include Variant.h -fshort-double -mcpu=tc27xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

aurix/cores/arduino/%.o: ../aurix/cores/arduino/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\cores\arduino" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Scu\Std" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Stm\Std" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Cpu\Irq" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Lib\DataHandling" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Cpu\Std" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\cores\arduino\avr" -I"../h" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\Ethernet\src" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\Ethernet\src\utility" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\LiquidCrystal" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\SD\src" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\SD\src\utility" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\SPI" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\TFTV2" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\libraries\Wire" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Build" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\system\libaurix\include" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Impl" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Lib" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_PinMap" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\_Reg" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Asclin" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Ccu6" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Cif" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Cpu" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Dma" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Dsadc" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Dts" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Emem" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Eray" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Eth" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Fce" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Flash" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Gtm" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Hssl" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\I2c" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Iom" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Msc" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Mtu" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Multican" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Port" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Psi5" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Psi5s" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Qspi" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Scu" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Sent" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Src" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\SrvSw" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Stm" -I"C:\Projects\4269.Auxduino\V03_02_Software\V06_Implementation\Eclipse\Aurduino\aurix\variants\tc275\iLLD\Include\Vadc" -fno-common -O0 -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -DTRIBOARD_TC275C -DUSE_IRQ -include Variant.h -fshort-double -mcpu=tc27xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


