/*
this is an example of using a pair of snprintf and write and a pair of read and sscanf to 
ask for input and parse the input.
In addition, we will remove whitespace if applicable in input string.
it is also using the rule 'shift the Base and add the current digit' to convert string to 
number. 
 
*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "convert_str_number.h"
#include "greet_parse_input.h"
#include "remove_whitespace.h"
#include "string_2_number.h"

#define str_size 64

int main(int argc, char *argv[]){
    char input_string[str_size] = {0};
    char output_string[str_size] = {0};
    double number_after = 0;
    greeting_and_parse(input_string, str_size);

   

    remove_whitespace(input_string, output_string, str_size);

   

    convert(output_string, &number_after, str_size);

    

    return 0;
}