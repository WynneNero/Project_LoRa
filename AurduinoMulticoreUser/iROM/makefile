################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include aurix/variants/tc275/subdir.mk
-include aurix/system/libaurix/source/subdir.mk
-include aurix/libraries/Servo/src/aurix/subdir.mk
-include aurix/libraries/Ethernet/src/utility/subdir.mk
-include aurix/libraries/Ethernet/src/subdir.mk
-include aurix/cores/aurduino/avr/subdir.mk
-include aurix/cores/aurduino/subdir.mk
-include Sketches/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

#rebuild target
rebuild: clean all

# All Target
all: AurduinoMulticoreUser.elf

# Tool invocations
AurduinoMulticoreUser.elf: $(OBJS) $(USER_OBJS) $(ASM)
	@echo 'Building target: $@'
	@echo 'Invoking: TriCore C++ Linker'
	"$(TRICORE_TOOLS)/bin/tricore-g++" -o  "AurduinoMulticoreUser.elf" -nocrt0 -T"..\aurix\variants\tc275\linker_scripts\gcc\iROM.ld" "Sketches\projet_LoRa_V3.o" "aurix\cores\aurduino\IPAddress.o" "aurix\cores\aurduino\Print.o" "aurix\cores\aurduino\Stream.o" "aurix\cores\aurduino\TinyGPS++.o" "aurix\cores\aurduino\avr\dtostrf.o" "aurix\cores\aurduino\hooks.o" "aurix\cores\aurduino\main.o" "aurix\cores\aurduino\main_Cpu1.o" "aurix\cores\aurduino\main_Cpu2.o" "aurix\libraries\Ethernet\src\Dhcp.o" "aurix\libraries\Ethernet\src\Dns.o" "aurix\libraries\Ethernet\src\Ethernet.o" "aurix\libraries\Ethernet\src\EthernetClient.o" "aurix\libraries\Ethernet\src\EthernetServer.o" "aurix\libraries\Ethernet\src\EthernetUdp.o" "aurix\libraries\Ethernet\src\utility\socket.o" "aurix\libraries\Ethernet\src\utility\w5100.o" "aurix\libraries\Servo\src\aurix\Servo.o" "aurix\system\libaurix\source\interrupts.o" "aurix\system\libaurix\source\system_tc2x.o" "aurix\variants\tc275\cint_tc2x.o" "aurix\variants\tc275\cinttab.o" "aurix\variants\tc275\crt0-tc2x.o" "aurix\variants\tc275\net.o" -Wl,--gc-sections -mcpu=tc27xx -Wl,--mem-holes -L"C:\Hitex\AURduinoIDE\Eclipse\AurduinoMulticoreUser\aurix\variants\tc275" -lAurduino -lTriLib -liLLD_Lib_Make -Wl,-Map="$(basename $(notdir $@)).map" -Wl,--cref -fshort-double -Wl,--extmap="a"
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(PCP_S)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS)$(CPCP_DEPS) AurduinoMulticoreUser.elf
	-@echo ' '

post-build:
	-@echo 'Make hexfile'
	-tricore-objcopy -O ihex "AurduinoMulticoreUser.elf" "AurduinoMulticoreUser.hex"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
