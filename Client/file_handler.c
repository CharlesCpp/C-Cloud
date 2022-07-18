#include "client.h"

size_t bytes_read;

// Length of the file
size_t get_length(FILE *f) {
    size_t pos = ftell(f); // store the cursor position
    size_t size;

    // go to the end of the file and get the cursor position
    fseek(f, 0L, SEEK_END);
    size = ftell(f);

    // go back to the old position
    fseek(f, pos, SEEK_SET);
    return size;
}

// This function will return the type of the file
char* check_type(char* filename) {
    char *result = malloc(5);
    int j = 0;
    int point = 0;
    for (int i = 0; i < strlen(filename); i++) {
        if (!filename[i] == '.') continue;
        if (filename[i] == '.') {
            for (int f = 0; f < strlen(filename) - i; f++) {
                result[j] = filename[i + f];
                j++;
            }
            break;
        }
    }
    result[j + 1] = '\0';
    return(result);
}

// Write the file
int write_file(FILE *f_write, char* filename) {

    // Temp variables
    FILE *img = fopen("test.pdf", "wb");
    unsigned char buffer[255];
    BYTE test;
    
    while ( (bytes_read = fread(buffer, 1, sizeof(buffer), f_write) ) > 0) {
        fwrite(buffer, 1, bytes_read, img);
    }

    fclose(img);
    return 1;
}