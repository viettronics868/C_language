/*
this is an include file for the source covert_num_2_base.c
*/
#ifndef CONVERT_2_RESULT_H
#define CONVERT_2_RESULT_H
#include <stdlib.h>
#include <stdbool.h>

typedef enum{
    EGG = 0,
    PEANUTs,
    SHELLFISH,
    STRAWBERRIES,
    TOMATOES,
    CHOCOLATE,
    POLLEN,
    CATS,
    ALLERGEN_MAX
} allergen_t;

typedef struct user_result{
    bool result;
    allergen_t *list_current_allergens;
}user_result;

void decimal2binary(int decimal_number, int *array_binary, size_t *size_array);

void return_result(int *array_binary, size_t *size_array, user_result *user_record);

#endif