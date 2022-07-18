#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <sys/stat.h>

typedef uint8_t BYTE;

long int get_length(char *filename);
int write_file(FILE *f_write, long int size);