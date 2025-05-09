/*
this is an example for using time_t type and struct tm for convert time to struct 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define seconds 1000000000
#define BUFFER_SIZE sizeof("YYYY-MM-DD HH-MM-SS")

int main(int argc, char *argv[]){
    time_t toronto = 0;//time(NULL);//fetch the current time
    struct tm *my_time = localtime(&toronto);
   
    my_time->tm_year = 1977-1900;
    my_time->tm_mon = 5;
    my_time->tm_mday = 13;
    my_time->tm_hour = 0;
    my_time->tm_min = 0;
    my_time->tm_sec = 0;
    
    //*my_time = *localtime(&toronto);
    printf(" initialization time is %d-%d-%d %d-%d-%d \n", 
                                                    my_time->tm_year + 1900, 
                                                    my_time->tm_mon +1, 
                                                    my_time->tm_mday,
                                                    my_time->tm_hour,
                                                    my_time->tm_min,
                                                    my_time->tm_sec);
    toronto = mktime(my_time);
    toronto += seconds;
    my_time = localtime(&toronto);
    printf("after %d second local time will be %d-%d-%d %d-%d-%d \n", seconds
                                                                , my_time->tm_year + 1900
                                                                , my_time->tm_mon + 1
                                                                , my_time->tm_mday
                                                                , my_time->tm_hour
                                                                , my_time->tm_min
                                                                , my_time->tm_sec);
    char buffer[BUFFER_SIZE];
    strftime(buffer, BUFFER_SIZE, "%Y-%m-%d %H-%M-%S", my_time);
    printf("%s \n", buffer);

  
    return 0;
}