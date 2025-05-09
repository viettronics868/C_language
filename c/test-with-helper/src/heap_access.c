/*
this is the program for practicing my first test cases
Author LK
Date 2024-12-25
*/
#include "heap_access.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int parse_from_fd(int fd, char **parsed_text, size_t word_size){
    char temp_mem[word_size];
    int byte_read = 0;
    size_t len_text = 0;

    while ((byte_read = read(fd, temp_mem, word_size)) > 0){
        char *buffer_text = realloc(*parsed_text, len_text + byte_read + 1);
        if (buffer_text == NULL){
            perror("error reallocating memory!");
            free(*parsed_text);
            *parsed_text = NULL;
            return EXIT_FAILURE;            
        }
        *parsed_text = buffer_text;
        memcpy(*parsed_text + len_text, temp_mem, byte_read);
        len_text += byte_read;
        (*parsed_text)[len_text] = '\0';
    }
    if (byte_read == -1){
        perror("cannot read from fd");
        free(*parsed_text);
        *parsed_text = NULL;
        return EXIT_FAILURE;
    } 
    return EXIT_SUCCESS;
    

}