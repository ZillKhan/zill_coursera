#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       compile-all : all the source files are compiled in the project but doesn't build
#		build : compile all the files and link them, also a final execution file.
#		clean : clean all the files
#		<File>.o : generate object file
#		<File>.i : generate preprocessed file
#		<File>.asm : generate assembly file
# Platform Overrides:
#       HOST
#		MSP432
#
#------------------------------------------------------------------------------
include sources.mk

# General Flags for both platforms
GFLAGS = -Wall \
	-Werror \
       -g \
       -O0 \
       -std=c99 

# Architectures Specific Flags
LINKER_FILE =  -T msp432p401r.lds
PLATFORM_FILE = -DHOST
CPU = cortex-m4
ARCH = armv7e-m 
FLOAT = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs

TARGET = c1m2

# Compiler Flags and Defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc 
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map \
		 -L ../ $(LINKER_FILE) 
	CFLAGS = $(GFLAGS)\
		 -mcpu=$(CPU)\
		 -mthumb \
		 -march=$(ARCH)\
		 -mfloat-abi=hard \
		 -mfpu=$(FPU) \
		 --specs=$(SPECS)

	CPPFLAGS = -DMSP432 $(INCLUDES)
	OBJDUMP = arm-none-eabi-objdump 
	SIZE = arm-none-eabi-size
else
	CC = gcc
	LD = ld
	CFLAGS = $(GFLAGS)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CPPFLAGS = $(PLATFORM_FILE) $(INCLUDES)
	OBJDUMP = objdump 
	SIZE = size
endif

#building preprocessed files
PRE = $(SOURCES:.c=.i)

#building assembly files
ASM = $(SOURCES:.c=.asm)

#building object files
OBJ = $(SOURCES:.c=.o)

#building dependency files
DEP = $(SOURCES:.c=.d)

%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@


$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

.PHONY: compile-all
compile-all: $(OBJ)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJ) $(DEP)
	$(CC) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f *.i *.o *.asm *.d *.out $(TARGET).map
 	
