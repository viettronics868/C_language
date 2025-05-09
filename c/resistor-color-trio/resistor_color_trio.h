#include <stdint.h>
#include <errno.h>


#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

typedef enum{
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
}resistor_band_t;
typedef enum{
    OHMS = 0,
    KILOOHMS = 1,
    MEGAOHMS = 2,
    GIGAOHMS = 3
}resistor_unit;

typedef struct 
{
    uint16_t value;
    resistor_unit unit;
}resistor_value_t;


resistor_value_t color_code(const resistor_band_t *color_band);


#endif
