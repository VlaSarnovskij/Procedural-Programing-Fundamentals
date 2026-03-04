#include <stdio.h>
#include <stdlib.h>

int splitArray(int arr[], int size, int firstSize, int **firstPart, int **secondPart) {
    // Allocate memory for the first array
    *firstPart = malloc(firstSize * sizeof(int));
    if (*firstPart == NULL) {
        printf("Memory allocation failed for the first array!\n");
        return -1;
    }

    int secondSize = size - firstSize;
    // Allocate memory for the second array
    *secondPart = malloc(secondSize * sizeof(int));
    if (*secondPart == NULL) {
        printf("Memory allocation failed for the second array!\n");
        free(*firstPart);
        return -1;
    }

    // Copy elements to the first array
    for (int i = 0; i < firstSize; ++i) {
        (*firstPart)[i] = arr[i];
    }

    // Copy elements to the second array
    for (int i = firstSize; i < size; ++i) {
        (*secondPart)[i - firstSize] = arr[i];
    }

    return 0;
}

int main() {
    int size = 10;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    int firstSize = 6, secondSize = 4;
    int *firstArray = NULL, *secondArray = NULL;

    if (splitArray(array, size, firstSize, &firstArray, &secondArray) != 0) {
        return -1;
    }

    // Print the first part
    printf("First array: ");
    for (int i = 0; i < firstSize; ++i) {
        printf("%d ", firstArray[i]);
    }
    printf("\n");

    // Print the second part
    printf("Second array: ");
    for (int i = 0; i < secondSize; ++i) {
        printf("%d ", secondArray[i]);
    }
    printf("\n");

    // Free memory
    free(firstArray);
    free(secondArray);

    return 0;
}
