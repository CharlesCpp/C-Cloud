#include "client.h"

int length_file(FILE *file) {
    int byte;
    for (byte = 0; getc(file) != EOF; byte++);
    return byte;
}