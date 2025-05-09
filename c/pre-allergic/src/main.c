/*
this is the main function for practicing convert a decimal number to an array of binary base
Author LK
Date: 2024-12-22
*/

#include "greet.h"
#include "parse_input.h"
#include "convert_num_2.base.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    //these lines of code ask for user to enter a special welcome message
    char *hello_world = "hello world what is your welcome message? \n";
    size_t leng_hello = strlen(hello_world);
    greet(hello_world, leng_hello);


    return EXIT_SUCCESS;
}