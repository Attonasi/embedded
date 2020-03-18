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
# Makefile for hte MSP432 build system
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

.RECIPEPREFIX = >
TARGET = c1m2

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = /home/collin/CollinSmith_Coursera/cXmX-Collin_Smith/c1m2-CollinSmith/msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Compiler Flags and Defines

ifeq ($(PLATFORM), MSP432)
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-ld
    CFLAGS = -DMSP432 -mcpu=$(CPU) -march=$(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16
else
    CC = gcc
    LD = ld -N
    CFLAGS = -DHOST
endif

LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CPPFLAGS = -Wall -Werror -g -O0 -std=c99 $(INCLUDES)
CFILES = main.c memory.c startup_msp432p401r_gcc.c system_msp432p401r.c
OBJS = $(SRCS:c=o)


.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY: compile-all
compile-all: $(TARGET).o

$(TARGET).out: $(OBJS)
> $(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(TARGET).out

$(TARGET).o: $(OBJS)
> $(CC) -c $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(TARGET).o

%.o: %.c
> $(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.i: %.c
> $(CC) -E $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

%.s: %.c
> $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -S $< -o $@

%.asm: %.c
> $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -S $< -o $@

.PHONY: clean
clean:
> rm -f $(OBJS) *.out *.o *.i *.map *.s *.asm