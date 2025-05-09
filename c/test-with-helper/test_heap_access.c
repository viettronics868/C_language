/*
this is a test file for testing the reallocation of memory when input message is 
not fix size
Author LK
Date 2024-12-25
*/
#define _XOPEN_SOURCE 700

#include "heap_access.h"
#include <stdio.h>
#include <stdlib.h>
#include "test-framework/unity.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int create_temp_fd(const char *content);

void setUp(void){

}

void tearDown(void){
    system("rm -rf /tmp/file*");
}

int create_temp_fd(const char *content){
    size_t leng_content = 0;
    if (content != NULL){
        leng_content = strlen(content);
    } else return EXIT_FAILURE;

    char file_path[] = "/tmp/fileXXXXXX";
    int fd = mkstemp(file_path);
    if (fd == -1){
        fprintf(stderr, "cannot create temp fileXXXXXX , description %s ", strerror(errno));
        return EXIT_FAILURE;
    }

    write(fd, content, leng_content);
    lseek(fd, 0, SEEK_SET);//set file pointer to the beginning of fd for reading

    return fd;
    
}

static void helper_test(char *user_string, size_t chunk_size){
    int file_number = create_temp_fd(user_string);
    //this checkpoint to ensure passing the proper file descriptor
    //in the case with wrong file descriptor, there will be a infinite loop and 
    //the program will hang infinitely(i.e return EXIT_SUCCESS instead of return fd)
    if (file_number < 3){
        fprintf(stderr, "something happened-wrong file number!!!");
        exit(EXIT_FAILURE);
    }
    
    char *output_text = malloc(1);
    output_text[0] = '\0';
    parse_from_fd(file_number, &output_text, chunk_size);

    TEST_ASSERT_EQUAL_STRING(user_string, output_text);

    free(output_text);
    close(file_number);
}

static void test_short_string(void){
    
    //TEST_IGNORE();

    helper_test("hello welcome ", 16);
}

static void test_long_string(void){
    //TEST_IGNORE();
    helper_test("this is a long greeting. Merry Christmas. Happy New Year. Happy coding!", 16);
}

static void test_empty_fd(void){
    TEST_IGNORE();

}

static void test_allocation_fail(void){
    TEST_IGNORE();
}

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_short_string);
    RUN_TEST(test_long_string);
    RUN_TEST(test_empty_fd);
    RUN_TEST(test_allocation_fail);

    return UNITY_END();
}

