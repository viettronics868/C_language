/*
this program is for greeting user and requesting an input as a decimal number
I will use the combination of write() and snprintf() to alternate scanf()
Date: 2024-12-23
Author LK
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void greet(char *welcome, size_t size){
    if (welcome != NULL){
        write(1, welcome, size);
    } else return EXIT_FAILURE;

}