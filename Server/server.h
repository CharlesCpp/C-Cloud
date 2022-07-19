#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

typedef uint8_t BYTE;
extern char* type;

char* Create_File_Name(char* format);
size_t get_file_size(FILE *f);
int write_file(FILE *f_write);
void    link_back(char* link);