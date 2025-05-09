/*
this is a program that convert a string of number to the number in decimal base
*/
#include <stdint.h>
#include <stddef.h>
#include "convert_str_number.h"


void convert(const char *str_number, double *number_from_string, size_t size){
    double result = 0;
    if (str_number != NULL && str_number[0] != '\0'){

        for (size_t i = 0; str_number[i] != '\0'; i++){
            result = (result * 10 + str_number[i] - '0');// substract '0' for convert char to interger
        }
        *number_from_string = result;
    }
    


}