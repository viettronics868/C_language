#this is a simple makefile for read_write example
#variable
CC = gcc
CFLAG = -g -Wall
LDFLAG = -lm
INCFLAG = Iinclude
TARGET = r_w
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

#link object to create target
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAG) -o $@ $^

%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(TARGET)
.PHONY: all clean