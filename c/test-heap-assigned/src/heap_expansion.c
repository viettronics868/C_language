/*
this is a program for monitoring the expansion of heap and using inline assembly
Author LK
DAte 2024-12-23
*/

#include <stdio.h>
#include <malloc.h>

void check_allocate_memory(char *mem){
    size_t size;
    size = malloc_usable_size(mem);
    printf("current allocated memory size : %zu \n", size);
}