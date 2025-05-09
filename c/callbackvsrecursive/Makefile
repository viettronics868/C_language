#this is a Makefile for the example of using callback-based implementation

#variables
CC=gcc
CFLAG=-g -Wall
LDFLAG= -lm
TARGET=callbacked
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,$(SRC))

#target
all: $(TARGET)

#link objects to create target
$(TARGET): $(OBJ)
	$(CC) $(CFLAG) -o $@ $< $(LDFLAG)

#compile source files to create object
%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $(SRC)

#clean up
clean:
	rm -rf $(OBJ) $(TARGET)

#phony
.PHONY: all clean
