#this is a Makefile for the example of using struct tm to convert time_t to human readable presentation

#variables
CC=gcc
CFLAG=-g -Wall
LDFLAG=-lm
TARGET=pre_giga
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(SRC))

#all target
all:$(TARGET)

#link objects to create target
$(TARGET): $(OBJ)
	$(CC) $(CFLAG) -o $@ $^ $(LDFLAG)

#compile sources to create object
%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $<

#clean up built files
clean:
	rm -rf $(OBJ) $(TARGET)

#phony
.PHONY: all clean