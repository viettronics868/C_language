#this is a Makefile to create a target for pre-luhn example

#variables
CC = gcc
CFLAG = -g -Wall
LDFLAG = -lm
INCFLAG = -Iinclude
OBJDIR = ./build
SRCDIR = ./src
INCDIR = ./include
EXEDIR = ./bin
TARGET = $(EXEDIR)/pre_luhn
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

#all target
all: $(TARGET)

#link objects to create target
$(TARGET): $(OBJ)
	$(CC) $(CFLAG) -o $@ $^ $(LDFLAG)

#compile source to create object
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAG) $(INCFLAG) -o $@ -c $< 

#clean up
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

#phony
.PHONY: all clean