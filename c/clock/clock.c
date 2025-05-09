/*until now 2025-05-08, this source code is under maintenance to replace clock.h and time.h
*/

#define _XOPEN_SOURCE

#include "clock.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>


clock_t clock_create(int hour, int minute){
    struct tm *new_clock = malloc(sizeof(struct tm));
    memset(new_clock, 0, sizeof(struct tm));
    time_t from_epoch = time(NULL);
    new_clock = localtime(&from_epoch);
    if (new_clock == NULL){
        fprintf(stderr, "localtime failed-error %s \n",strerror(errno));
        exit(EXIT_FAILURE);
    }
    new_clock->tm_hour = hour;
    new_clock->tm_min = minute;
    mktime(new_clock);
    clock_t myclock;
    if (strftime(myclock.text, MAX_STR_LEN, "%H:%M", new_clock) == 0){
        fprintf(stderr, "strftime failed-error %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    free(new_clock);
    return myclock;

}
clock_t clock_add(clock_t clock, int minute_add){
    clock_t cpy_clock;
    strcpy(cpy_clock.text, clock.text);
    struct tm *my_clock = malloc(sizeof(struct tm));
    if (my_clock == NULL){
        fprintf(stderr, "malloc failed - error %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    memset(my_clock, 0, sizeof(struct tm));
    if (strptime(cpy_clock.text, "%H:%M", my_clock) == NULL){
        fprintf(stderr, "strptime failed - error %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    my_clock->tm_min += minute_add;
    mktime(my_clock);
    if (strftime(cpy_clock.text, MAX_STR_LEN, "%H:%M", my_clock) == 0){
        fprintf(stderr, "strftime failed - error %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }


    free(my_clock);
    return cpy_clock;

}
clock_t clock_subtract(clock_t clock, int minute_subtract){
    clock_t cpy_clock;
    strcpy(cpy_clock.text, clock.text);
    struct tm *my_clock = malloc(sizeof(struct tm));
    if (my_clock == NULL){
        fprintf(stderr, "malloc failed - error %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    memset(my_clock, 0, sizeof(struct tm));
    if (strptime(cpy_clock.text, "%H:%M", my_clock) == NULL){
        fprintf(stderr, "strptime failed - error %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    my_clock->tm_min -= minute_subtract;
    mktime(my_clock);
    if(strftime(cpy_clock.text, MAX_STR_LEN, "%H:%M", my_clock) == 0){
        fprintf(stderr, "strftime failed - error %s \n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    free(my_clock);
    return cpy_clock;

}
bool clock_is_equal( clock_t a, clock_t b){
    return (strcmp(a.text, b.text) == 0);
}
