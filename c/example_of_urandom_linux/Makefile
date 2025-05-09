#this Makefile is created for compiling the *.c file within this directory

#variables
CC=gcc
CFLAG=-g -Wall
LDFLAG=-lm
TARGET=random_number
SCR=using_urandom.c
OBJ=$(patsubst %.c, %.o, $(SCR))

#target
all: $(TARGET)

#link objects to create target
$(TARGET): $(OBJ)
	$(CC) $(CFLAG) -o $(TARGET) $(OBJ) $(LDFLAG)

#compile sources into objects
%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $^

#clean up built files
clean:
	rm -rf $(TARGET) $(OBJ)

#phony
.PHONY: all clean

