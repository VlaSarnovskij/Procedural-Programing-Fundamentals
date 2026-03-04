#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"

void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand();    
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int size = 10;
    int *m1 = malloc(size * sizeof(int));

    fillArray(m1, size);
    printf("m1: ");
    printArray(m1, size);

    saveToFile("data.bin", m1, size);

    int loadedSize = 0;
    int *m2 = loadFromFile("data.bin", &loadedSize);

    printf("m2: ");
    printArray(m2, loadedSize);

    // Check is everything correct
    int same = 1;
    if (size != loadedSize) same = 0;
    else {
        for (int i = 0; i < size; i++) {
            if (m1[i] != m2[i]) {
                same = 0;
                break;
            }
        }
    }

    if (same) printf("all good\n");
    else printf("something's wrong\n");

    free(m1);
    free(m2);

    return 0;
}
