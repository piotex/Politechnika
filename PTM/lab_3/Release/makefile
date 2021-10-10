################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
lab_3.lss \

FLASH_IMAGE += \
lab_3.hex \

EEPROM_IMAGE += \
lab_3.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: lab_3.elf secondary-outputs

# Tool invocations
lab_3.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lab_3.map -mmcu=atmega32 -o "lab_3.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lab_3.lss: lab_3.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lab_3.elf  >"lab_3.lss"
	@echo 'Finished building: $@'
	@echo ' '

lab_3.hex: lab_3.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex lab_3.elf  "lab_3.hex"
	@echo 'Finished building: $@'
	@echo ' '

lab_3.eep: lab_3.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex lab_3.elf  "lab_3.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lab_3.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 lab_3.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) lab_3.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
