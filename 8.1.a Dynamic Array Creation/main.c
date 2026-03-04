#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int data[], int size, int low, int high){
    srand(time(NULL));
    for (int i = 0; i < size; ++i){
        data[i] = low + rand() % (high - low + 1);
    }
}

int* createArray(int size, int low, int high) {
    if (size <= 0) return NULL;

    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        // Failed to allocate memory
        return NULL;
    }

    // Fill array with random values
    generateArray(arr, size, low, high);

    // Return pointer on array
    return arr;
}

int main() {
    int size = 10;
    int low = 1, high = 100;

    int* myArray = createArray(size, low, high);
    if (myArray == NULL) {
        printf("Failed to create array.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }

    free(myArray);
    return 0;
}
