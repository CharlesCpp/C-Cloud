#include "client.h"

size_t bytes_read;

// Length of the file
long int get_length(char *filename) {
    struct stat st;

    stat(filename, &st);
    return (st.st_size);
}

// Write the file
int write_file(FILE *f_write, long int size) {

    // Temp variables
    FILE *img = fopen("test.jpeg", "wb");
    unsigned char buffer[255];
    
    while ( (bytes_read = fread(buffer, 1, sizeof(buffer), f_write) ) > 0) {
        fwrite(buffer, 1, bytes_read, img);
    }

    fclose(img);
    return 1;
}