#this is the Makefile for testing my program
#Author LK
#Date 2024-12-25

#variables for setting compiler
CC = gcc
CFLAGS = -std=c99 -g -Wall -Wextra -pedantic -Werror -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR
LDFLAG = -lm
INCFLAG = -Iinclude
SRCDIR = ./src
TESTSRC = ./test_heap_access.c
INCDIR = ./include
OBJDIR = ./build
UNISRC = ./test-framework/unity.c
UNILIB = ./test-framework/unity.h
TARBIN = ./bin/test_alloc.out
TARMEM = ./bin/test_memcheck.out
SRC = $(wildcard $(SRCDIR)/*.c)
SRC += $(UNISRC)
SRC += $(TESTSRC)
INC = $(wildcard $(INCDIR)/*.h)
INC += $(UNILIB)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

#variables for AddressSanitizer
ASRFLAGS = -fsanitize=address -fno-common -fno-omit-frame-pointer

#default
.PHONY: all
all: test

#test setting
.PHONY: test
test: $(TARBIN)
	@echo test in progress...
	@$(TARBIN)

#compile the binary target from source files and libraries
$(TARBIN): $(SRC) $(INC)
	@echo Compile the binary target from source files and libraries...
	@$(CC) $(CFLAGS) $(INCFLAG) $(SRC) $(LDFLAG) -o $@


#memory check using AddressSanitizer
.PHONY: memcheck
memcheck: $(SRC) $(INC)
	@echo memory check using AddressSanitizer...
	@$(CC) $(CFLAGS) $(INCFLAG) $(SRC) $(ASANFLAGS) -o $(TARMEM) $(LDFLAG)
	@$(TARMEM)
	@echo "pass memory check"

#clean up
.PHONY: clean
clean:
	@echo cleaning up...
	@rm -rf *.out.dSYM
	@rm -f *.o $(TARBIN) $(TARMEM)

