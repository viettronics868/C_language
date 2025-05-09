#include "resistor_color_trio.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <errno.h>

resistor_value_t color_code(const resistor_band_t *color_band){
 
    resistor_value_t result = {
        .unit = OHMS,
        .value = 0
    };
    resistor_band_t cpy_color_bands[3];

    memcpy(cpy_color_bands, color_band, (3*sizeof(int))) ;
    size_t leng_color_band = (sizeof(cpy_color_bands))/(sizeof(cpy_color_bands[0]));
    const resistor_band_t list_colors[] = {BLACK,BROWN,RED,ORANGE,YELLOW,GREEN,BLUE,VIOLET,GREY,WHITE};
    size_t leng_list_color = (sizeof(list_colors))/ (sizeof(list_colors[0]));
    uint16_t value_of_color[3];
   

    for (size_t i = 0; i < leng_color_band; i++){
        for (size_t j = 0; j < leng_list_color; j++){
            if (cpy_color_bands[i] == list_colors[j]){
                value_of_color[i] = (uint16_t)j;
                break;
            }
        }
    }
    long value = (double)((value_of_color[0] * pow(10,1))  + (value_of_color[1] * pow(10,0))) * pow(10,value_of_color[2]);
    
    resistor_unit unit = 0;
    
    if (((value % 1000000000) == 0) && (value != 0)){
        unit = GIGAOHMS;
        value = (value)/1000000000;
    } else if (((value % 1000000) == 0) && (value != 0)){
        unit = MEGAOHMS;
        value = (value)/1000000;
    } else if (((value % 1000) == 0) && (value != 0)){
        unit = KILOOHMS;
        value = (value)/1000;
    } else unit = OHMS;

    result.unit = unit;
    result.value = value;
    return result;

}
