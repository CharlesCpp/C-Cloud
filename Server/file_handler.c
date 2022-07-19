#include "server.h"

size_t bytes_read;

size_t get_file_size(FILE *f) {
    size_t pos = ftell(f); // store the cursor position
    size_t size;

    // go to the end of the file and get the cursor position
    fseek(f, 0L, SEEK_END);
    size = ftell(f);

    // go back to the old position
    fseek(f, pos, SEEK_SET);
    return size;
}

char* Create_File_Name(char* format) {
    long int tmp = 1;
    srand(time(NULL));

    for (int i = 0; i < 9; i++) {
        tmp += tmp * (rand() % 10);
    }

    char* result = malloc(sizeof(tmp));
    sprintf(result, "%d", tmp);
    strcat(result, format);

    return result;
}