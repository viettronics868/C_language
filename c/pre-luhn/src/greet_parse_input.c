/*
this program is used to greet users and ask users for inputting a string of numbers (like mocking bank account).
this function will receive an argument as a pointer and modify the content of the pointer
*/
#include "greet_parse_input.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

void hello_world(void){
    char HELLO[] = "hello world and enter a mocking bank account \n";
    size_t buffer_size = sizeof(HELLO);

    write(1, HELLO, buffer_size);//fd of stdout is 1
}

void read_input(char *str_input, size_t size){//size included '\0'

    if (str_input != NULL){

        if (read(0, str_input, size) == -1){
            perror("cannot read from stdin \n");
            exit(-1);//terminate the program
        }
        str_input[size] = '\0';//NOte: always add '\0' when using read()
    }
}

void greeting_and_parse(char *input_parse, size_t size){ //size included '\0'

    if (input_parse != NULL){
        hello_world();

        char cpy_input[size];
        read_input(cpy_input, size);
        sscanf(cpy_input,"%[^\n]", input_parse);//format %[^\n] for reading  everything until newline
    }
    
}