#include  "resistor_color.h" 
#include <errno.h>

int color_code(resistor_band_t color_band){
    const resistor_band_t color_list[] = { BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE,
                                             VIOLET , GREY , WHITE };

    for(int i = 0; i < 10; i++){
        if (color_band == color_list[i]){
            return i;
        }
    }
    return EINVAL;
}

const resistor_band_t  *colors(){
    //Using __thread for thread-local storage since Exercism's test environment uses GCC/Clang.
    static __thread const resistor_band_t  list_color[] = { BLACK , BROWN , RED , ORANGE , YELLOW , GREEN , BLUE ,
                                             VIOLET , GREY , WHITE };
    return list_color;
}

