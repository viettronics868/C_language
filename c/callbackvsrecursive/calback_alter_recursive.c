/*
this is an example of using callback function to alternative recursive implementation in calculation factorial
Date 2024-12-08
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>

//declare a new type of the function pointer
typedef int (*callbackForFactorial)(int factor, int currentValue);

//declare a function to multiply two integers
int calculate_factorial(int factor, int currentValue){
    int factorial = factor * currentValue;
    return factorial;
}

//declare a function that receive the function pointer as its argument
void callbackImplementation(callbackForFactorial callback, int input_factor){
    int factorial_result = 1;
    void *stack_ptr = NULL;
    if (callback != NULL){
        for (int i = 1; i <= input_factor; i++){
            factorial_result = callback(i, factorial_result);
            __asm__("movq %%rsp, %0": "=r"(stack_ptr));//monitor the call stack with inline assembly code
            printf("at time %d stack pointer is at %p and the result is %d \n", i, stack_ptr, factorial_result);
        }
        
    }
}

int main(int argc, char *argv[]){
    int inp_factor = 6;
    callbackForFactorial real_callback = calculate_factorial;
    callbackImplementation(real_callback, inp_factor);
    

    return 0;
}
