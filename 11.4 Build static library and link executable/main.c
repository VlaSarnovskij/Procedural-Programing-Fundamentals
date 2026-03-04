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
    // 1)
    int size = 10;
    int *m1 = malloc(size * sizeof(int));
    int *m2 = malloc(size * sizeof(int));
    int *m3 = malloc(size * sizeof(int));

    fillArray(m1, size);
    fillArray(m2, size);
    fillArray(m3, size);
    // 2)
    saveToFile("data.bin", m1, size);
    // 3)
    saveToFile("data.bin", m3, size);
    // 4)
    free(m1);
    int loadedSizem1 = 0;
    m1 = loadFromFile("data.bin", &loadedSizem1, 0);

    // 5)
    saveToFile("data2.bin", m2, size);
    // 6)
    free(m3);
    int offsetBytes = sizeof(int) + loadedSizem1 * sizeof(int);
    int loadedSizem3 = 0;
    m3 = loadFromFile("data.bin", &loadedSizem3, offsetBytes);
    // 7)
    free(m2);
    int loadedSizem2 = 0;
    m2 = loadFromFile("data2.bin", &loadedSizem2, 0);

    // Check is everything correct
    if (saveCount == 3 && loadCount == 3) printf("all good\n");
    else printf("something's wrong\n");

    free(m1);
    free(m2);
    free(m3);

    return 0;
}
