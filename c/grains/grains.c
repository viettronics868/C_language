#include "grains.h"
#include <stdint.h>
#include <math.h>
uint64_t square(uint8_t index){
    return(pow(2,(index -1)));
    
}

uint64_t total(void){
    uint8_t i;
    uint64_t total_number = 0;
    for(i = 1; i <= 64; i++){
        total_number += square(i);
    }

    return total_number;
}