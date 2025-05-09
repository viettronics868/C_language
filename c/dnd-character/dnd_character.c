/*
this program is using /dev/urandom for create random numbers. Hence it is suitable
for Linux user only.
there is a problem with this program. with the same source code but 'make test' passed sometime and failed sometime.
*/


#include "dnd_character.h"
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
//#define ROLL_NUMBER 4;


int ability(void){
    /*
    roll the dice (call random_number()) 4 times and record the sum of
     the largest three dices
    */

    int rolling_dice[4] = {0};
    int max_dice = 6;
    int min_dice = 1;
    int buffer_number = 0;
    int sum = 0;
    for (size_t i = 0; i < sizeof(rolling_dice)/sizeof(rolling_dice[0]); i++){
        int roll = random_number(max_dice, min_dice) ;
        if ((roll >= 1) && (roll <= 6)) {rolling_dice[i] = roll;}
        else return EIO;
    }
    for (size_t i = 0; i < sizeof(rolling_dice)/sizeof(rolling_dice[0]); i++){//sorting the array
        for (size_t j = 0; j < (sizeof(rolling_dice)/sizeof(rolling_dice[0])) -i - 1; j++){ 
            if (rolling_dice[i] > rolling_dice[i+1]){                             
                buffer_number = rolling_dice[i];
                rolling_dice[i] = rolling_dice[i-1];
                rolling_dice[i+1] = buffer_number;
            }  
        }
    }
    for (size_t i = 1; i < sizeof(rolling_dice)/sizeof(rolling_dice[0]); i++){
        sum += rolling_dice[i];
    }
    return sum;
}

int modifier(int score){
    float buffer_number = 0;
    int cpy_score = score;
    if (cpy_score >= 3 && cpy_score <= 18){
        buffer_number = (cpy_score - 10) / 2.0;
        if ( buffer_number != (int)buffer_number){
            buffer_number = buffer_number - 0.5;
        }
    } 
    else{
            return EINVAL;
        }
    return (int)buffer_number;
}

dnd_character_t make_dnd_character(void){
    dnd_character_t any_character = {0};
    any_character.strength = ability();
    any_character.dexterity = ability();
    any_character.constitution = ability();
    any_character.intelligence = ability();
    any_character.wisdom = ability();
    any_character.charisma = ability();
    any_character.hitpoints = (10 + modifier(any_character.constitution));

    return any_character;
}

int random_number(int max, int min){

    int rand_num = 0;
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0){
        perror("cannot open /dev/urandom");
        close(fd);
//        return EIO;
        srand(time(NULL));
        return (min + (rand() % (max - min + 1)));
    }
    if (read(fd, &rand_num, sizeof(rand_num)) < 0){
        perror("cannot create random number");
        close(fd);

    }
    close(fd);
    return (min + (rand_num % (max - min +1)));


}
