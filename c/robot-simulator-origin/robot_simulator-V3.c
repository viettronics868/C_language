/*
this is an exercise from Exercism framework. I applied BIG-O notation on my data structure.
I tried to apply O(1) for this algorithm.
Author L.K
Date 2024-12-03
*/


#include "robot_simulator.h"
#include <stdio.h>
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t robot_init ={
        .direction = direction,
        .position = {
            .x = x,
            .y = y
        }
    };
    return robot_init;
}
//this function will update state robot when facing north
robot_status_t deploy_from_north(robot_status_t *robot, const char input){
    if (input == 'L'){
        robot->direction = DIRECTION_WEST;
    } else if (input == 'R') {
        robot->direction = DIRECTION_EAST;
    } else {
        robot->position.y += 1;
    }
    return *robot;    
}
//this function will update state robot when facing east
robot_status_t deploy_from_east(robot_status_t *robot, const char input){
    if (input == 'L'){
        robot->direction = DIRECTION_NORTH;
    } else if (input == 'R'){
        robot->direction = DIRECTION_SOUTH;
    } else{
        robot->position.x += 1;
    }
    return *robot;
}
//this function will update state robot when facing south
robot_status_t deploy_from_south(robot_status_t *robot, const char input){
    if (input == 'L'){
        robot->direction = DIRECTION_EAST;
    } else if (input == 'R') {
        robot->direction = DIRECTION_WEST;
    } else {
        robot->position.y -= 1;
    }
    return *robot;
}
//this function will update state robot when facing west
robot_status_t deploy_from_west(robot_status_t *robot, const char input){
    if (input == 'L'){
        robot->direction = DIRECTION_SOUTH;
    } else if (input == 'R'){
        robot->direction = DIRECTION_NORTH;
    } else{
        robot->position.x -= 1;
    }
    return *robot;
    
}

void robot_move(robot_status_t *robot, const char *commands){

    //declare an array of function pointers that point to the coresponding function that implement properly logic
    robot_status_t (*state_robot[])(robot_status_t *robot, const char command_letter) = 
                                        {&deploy_from_north, 
                                        &deploy_from_east, 
                                        &deploy_from_south,
                                        &deploy_from_west};     

    if ((commands != NULL) && (robot != NULL)){

        size_t leng_command = strlen(commands);
        const char cpy_command[leng_command];

        const char *instruction_letter[] = {"L", "R", "A"};

        memcpy((char *)cpy_command,commands,leng_command*sizeof(char));
        for (size_t i = 0; i < leng_command; i++){ //the 'for' loop of i for traversing each letter of the command
            for (size_t j = 0; j < 3; j++){  //traverse the list of letters of command
                if (cpy_command[i] == *instruction_letter[j]){ //get the letter of command from the list
                    //check the current direction of robot
                    for (robot_direction_t k = DIRECTION_NORTH; k < DIRECTION_MAX; k++){
                        if (robot->direction == k){
                            state_robot[k](robot,cpy_command[i]); 
                            break; // exit this 'for' loop of k
                        }
                    }   
                    break; // exit this 'for' loop of j
                }
            }
            
        }

    } 
}
