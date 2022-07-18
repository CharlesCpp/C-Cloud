#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <string.h>

typedef uint8_t BYTE;

size_t get_file_size(FILE *f);
int write_file(FILE *f_write);