/*
this is an example of using /dev/urandom as an entropy source to create random number
*/

#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>


unsigned int using_urandom_4_number(int max, int min){
    unsigned int ran_number;

    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0){
        perror("cannot open /dev/urandom");
        return 0;
    }
    if (read(fd, &ran_number,sizeof(ran_number)) == -1) {
        perror("cannot read from fd");
        return 0;
    }    
    close(fd);
    return (min + (ran_number % (max - min + 1)));
}

int main(int argc, char *argv[]){
    int max_number = 6;
    int min_number = 1;
    for (int i=0; i < 6; i++){
        uint64_t any_number = using_urandom_4_number(max_number, min_number);
        printf("this number %ld is random selection \n", any_number);

    }


    return 0;
}