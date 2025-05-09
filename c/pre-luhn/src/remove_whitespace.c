/*
this is a program that receive a string and it will do the cleanup of  whitespace in the string
*/
#include "remove_whitespace.h"
#include <string.h>
#include <ctype.h>
#include <stddef.h>

void remove_whitespace(const char *input_str, char *output_str, size_t size){//size included '\0'
    if (input_str != NULL && output_str != NULL){ 

            strncpy(output_str, input_str, size);
            size_t new_index = 0;
            for (size_t i = 0; i < size; i++){
                if (!isspace(output_str[i])){//copy non-whitespace characters only
                    output_str[new_index] = output_str[i];
                    new_index++;
                }
            }
        }
}