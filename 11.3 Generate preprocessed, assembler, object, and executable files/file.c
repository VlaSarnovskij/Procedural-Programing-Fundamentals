#include "file.h"
#include <stdlib.h>

int saveCount = 0;
int loadCount = 0;

void saveToFile(const char *filename, int *arr, int size) {
    FILE *f = fopen(filename, "ab");
    if (!f) return;

    fwrite(&size, sizeof(int), 1, f);       // Writing size
    fwrite(arr, sizeof(int), size, f);      // Writing array

    ++saveCount;

    fclose(f);
}

int* loadFromFile(const char *filename, int *outSize, int offset) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;


    fseek(f, offset, SEEK_SET);

    fread(outSize, sizeof(int), 1, f);      // Reading size

    int *arr = malloc(*outSize * sizeof(int));
    if (!arr) {
        fclose(f);
        return NULL;
    }
    fread(arr, sizeof(int), *outSize, f);   // Reading elements

    ++loadCount;

    fclose(f);
    return arr;
}
