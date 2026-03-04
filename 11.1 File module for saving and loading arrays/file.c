#include "file.h"
#include <stdlib.h>

void saveToFile(const char *filename, int *arr, int size) {
    FILE *f = fopen(filename, "wb");
    if (!f) return;

    fwrite(&size, sizeof(int), 1, f);       // Writing size
    fwrite(arr, sizeof(int), size, f);      // Writing array

    fclose(f);
}

int* loadFromFile(const char *filename, int *outSize) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    fread(outSize, sizeof(int), 1, f);      // Reading size

    int *arr = malloc(*outSize * sizeof(int));
    if (!arr) {
        fclose(f);
        return NULL;
    }

    fread(arr, sizeof(int), *outSize, f);   // Reading elements

    fclose(f);
    return arr;
}
