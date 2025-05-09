/*
this is an example that use read and write to replace printf and scannf to show and fetch messages in stdin/stdout
*/
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#define buffer 64

int main(int argc, char * argv[]){
    char input[buffer] = {0};
    
    char hello[] = "hello world please enter a string of number \n";
    size_t leng_hello = sizeof(hello);
    write(1, hello, leng_hello);

    read(0, input, buffer);
    input[buffer] = '\0';
    char *str_input = (char *)calloc(buffer,sizeof(char));
    sscanf(input,"%[^\n]", str_input);//using %[^\n] to make sscanf include whitespace

    write(1, str_input, buffer);
    write(1, "\n", 1);

    free(str_input);
    
    return 0;
}