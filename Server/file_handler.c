#include "server.h"


size_t get_file_size(FILE *f)
{
    size_t pos = ftell(f); // store the cursor position
    size_t size;

    // go to the end of the file and get the cursor position
    fseek(f, 0L, SEEK_END);
    size = ftell(f);

    // go back to the old position
    fseek(f, pos, SEEK_SET);
    return size;
}