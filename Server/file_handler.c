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
    char* tmp = malloc(6 + (strlen(format) * sizeof(char)));
    int i;
    srand(time(NULL));

    for (i = 0; i < 5; i++) {
        int j = 1 + rand() % 9;
        if (j + '0' >= 48 && j + '0' <= 57) {
            tmp[i] = j + '0';
        }
    }
    tmp[i + 1] = '\0';
    strcat(tmp, format);

    return tmp;
}