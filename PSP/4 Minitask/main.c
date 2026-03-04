#include <stdio.h>
#include <stdlib.h>

typedef struct StaticArray{
    int arr[1000];
    int n;
}StaticArray;

typedef struct DinamicArray{
    int *arr;
    int n;
}DinamicArray;

void generateStaticArray(StaticArray *a, int n){
    a->n = n;
    for (int i = 0; i < n; ++i){
        a->arr[i] = i + 1;
    }
}

void initDinamicArray(DinamicArray *a, int n){
    a->arr = malloc(n * sizeof(int));
    if(a->arr == NULL){
        printf("Error: cannot allocate memory.");
        return;
    }
    for (int i = 0; i < n; ++i){
        a->arr[i] = i + 1;
    }
    a->n = n;
}

void initDinamicArray2(DinamicArray a, int n){
    for (int i = 0; i < n; ++i){
        a.arr[i] = i + 1;
    }
}

void freeArray(DinamicArray *a){
    free(a->arr);
}

int main()
{
    // Static array
    StaticArray myStaticArray;

    generateStaticArray(&myStaticArray, 15);

    printf("Static array: ");
    for(int i = 0; i < myStaticArray.n; ++i){
        printf("%d ", myStaticArray.arr[i]);
    }
    printf("\n");


    // Dinamic array1
    DinamicArray myDinamicArray1;

    initDinamicArray(&myDinamicArray1, 10);

    printf("Dinamic1 array: ");
    for(int i = 0; i < myDinamicArray1.n; ++i){
        printf("%d ", myDinamicArray1.arr[i]);
    }
    printf("\n");

    // Dinamic array2
    DinamicArray myDinamicArray2;

    int n = 12;
    myDinamicArray2.arr = malloc(n * sizeof(int));
    if(myDinamicArray2.arr == NULL){
        printf("Error: cannot allocate memory.");
        return 1;
    }
    initDinamicArray2(myDinamicArray2, n);
    myDinamicArray2.n = n;

    printf("Dinamic2 array: ");
    for(int i = 0; i < myDinamicArray2.n; ++i){
        printf("%d ", myDinamicArray2.arr[i]);
    }
    printf("\n");

    // Atlaisvinom atminti
    freeArray(&myDinamicArray1);
    freeArray(&myDinamicArray2);
    return 0;
}
