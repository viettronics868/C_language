#ifndef HEAP_ACCESS_H
#define HEAP_ACCESS_H

#include <stddef.h>

int parse_from_fd(int fd, char **parsed_text, size_t word_size);

//int create_temp_fd(const char *content);

#endif