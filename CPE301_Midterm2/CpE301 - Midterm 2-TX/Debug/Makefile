################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../CpE301\ -\ Midterm\ 2\ TX.c \
../nrf24l01.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
CpE301\ -\ Midterm\ 2\ TX.o \
nrf24l01.o

OBJS_AS_ARGS +=  \
"CpE301 - Midterm 2 TX.o" \
nrf24l01.o

C_DEPS +=  \
CpE301\ -\ Midterm\ 2\ TX.d \
nrf24l01.d

C_DEPS_AS_ARGS +=  \
"CpE301 - Midterm 2 TX.d" \
nrf24l01.d

OUTPUT_FILE_PATH +=CpE301\ -\ Midterm\ 2-TX.elf

OUTPUT_FILE_PATH_AS_ARGS +="CpE301 - Midterm 2-TX.elf"

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./CpE301\ -\ Midterm\ 2\ TX.o: .././CpE301\ -\ Midterm\ 2\ TX.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)E:\Atmel\Studio7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"E:\Atmel\Studio7\7.0\Packs\Atmel\ATmega_DFP\1.2.209\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "E:\Atmel\Studio7\7.0\Packs\Atmel\ATmega_DFP\1.2.209\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./nrf24l01.o: .././nrf24l01.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)E:\Atmel\Studio7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"E:\Atmel\Studio7\7.0\Packs\Atmel\ATmega_DFP\1.2.209\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "E:\Atmel\Studio7\7.0\Packs\Atmel\ATmega_DFP\1.2.209\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	


./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)E:\Atmel\Studio7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"E:\Atmel\Studio7\7.0\Packs\Atmel\ATmega_DFP\1.2.209\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "E:\Atmel\Studio7\7.0\Packs\Atmel\ATmega_DFP\1.2.209\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)E:\Atmel\Studio7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="CpE301 - Midterm 2-TX.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega328p -B "E:\Atmel\Studio7\7.0\Packs\Atmel\ATmega_DFP\1.2.209\gcc\dev\atmega328p"  
	@echo Finished building target: $@
	"E:\Atmel\Studio7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "CpE301 - Midterm 2-TX.elf" "CpE301 - Midterm 2-TX.hex"
	"E:\Atmel\Studio7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "CpE301 - Midterm 2-TX.elf" "CpE301 - Midterm 2-TX.eep" || exit 0
	"E:\Atmel\Studio7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "CpE301 - Midterm 2-TX.elf" > "CpE301 - Midterm 2-TX.lss"
	"E:\Atmel\Studio7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "CpE301 - Midterm 2-TX.elf" "CpE301 - Midterm 2-TX.srec"
	"E:\Atmel\Studio7\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "CpE301 - Midterm 2-TX.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "CpE301 - Midterm 2-TX.elf" "CpE301 - Midterm 2-TX.a" "CpE301 - Midterm 2-TX.hex" "CpE301 - Midterm 2-TX.lss" "CpE301 - Midterm 2-TX.eep" "CpE301 - Midterm 2-TX.map" "CpE301 - Midterm 2-TX.srec" "CpE301 - Midterm 2-TX.usersignatures"
	