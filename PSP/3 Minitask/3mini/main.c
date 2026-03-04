#include <stdio.h>
#include <stdlib.h>

void createArray(int n, int **ptr){
    *ptr = malloc(n * sizeof(int));
    if (*ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < n; ++i){
        (*ptr)[i] = i + 1;
    }
}

int *createArrayReturn(int n){
    int *ptr = malloc(n * sizeof(int));
    if (*ptr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < n; ++i){
        ptr[i] = i + 1;
    }

    return ptr;
}

int main()
{
    // parasykit funkcija kuri savi sukurs dinamini masyva ir irasis sk 1,2,3,4,5 grazinti ne per return
    int size = 10;
    int *arr = NULL;

    createArray(size, &arr);
    if (arr == NULL){
        return 1;
    }

    printf("Array by argument: ");
    for (int i = 0; i < size; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");


    int *arr2 = createArrayReturn(size);
    if (arr2 == NULL){
        return 1;
    }

    printf("Array by return: ");
    for (int i = 0; i < size; ++i){
        printf("%d ", arr2[i]);
    }
    printf("\n");

    free(arr);
    free(arr2);
    return 0;
}
