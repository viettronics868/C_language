/*in reality, depending on diffirent kinds of input, there is a requirement to dynamically allocate
memory in heap, this is an example that using recalloc() for expansion memory in heap and
monitoring this expansion
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "heap_expansion.h"
#include "process_long_input.h"
#include "greet.h"


#define WORD_SIZE 16

int main (int argc, char *argv[]){
    // char buffer[WORD_SIZE];
    // size_t data_read = 0;

    char *memory_alloc = malloc(1);
    memory_alloc[0] = '\0';
    
//    size_t memory_len = 0;

    greet();

    printf("starting memory allocation \n");

    parse_input(WORD_SIZE, memory_alloc);


    // while (data_read = read(STDIN_FILENO, buffer, WORD_SIZE) > 0){
        
    //     //allocate memory
    //     char *buffer_alloc = realloc(memory_alloc, memory_len + data_read + 1);
    //     //check and veriy the memory allocation. *Note: mandatory step!!!
    //     if (buffer_alloc == NULL){
    //         perror("error from reallocation the memory");
    //         free(memory_alloc);//prevent memory leak
    //         return EXIT_FAILURE;
    //     }
    //     //update the memory allocation
    //     memory_alloc = buffer_alloc;

    //     //append the new word of data to the existing string and overwrite the previous null terminator
    //     memcpy(memory_alloc + memory_len, buffer, data_read);

    //     //update the memory length
    //     memory_len += data_read;

    //     //add the null terminator
    //     memory_alloc[memory_len] = '\0';        

    //     check_allocate_memory(memory_alloc);
    // }
    // //check and verify the data read. *Note: important step!!!
    // if (data_read == -1){
    //     perror("error reading from stdin");
    //     free(memory_alloc);//prevent memory leak
    //     return EXIT_FAILURE;
    // }
    
    
    free(memory_alloc);
    
    return EXIT_SUCCESS;
}