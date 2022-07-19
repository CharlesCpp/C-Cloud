#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <sys/stat.h>
#include <string.h>

typedef uint8_t BYTE;

size_t get_length(FILE *f);
int write_file(FILE *f_write, char* filename);
char* check_type(char* filename);
char* Second_server();