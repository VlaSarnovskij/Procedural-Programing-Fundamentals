#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int data[], int size, int low, int high){
    srand(time(NULL));
    for (int i = 0; i < size; ++i){
        data[i] = low + rand() % (high - low + 1);
    }
}

int main()
{
    int low, high;
    int size;

    printf("low, high, size:");
    scanf("%d%d%d", &low, &high, &size);

    int data[size];

    generateArray (data, size, low, high);

    // spausdiname rezultata
    printf("Sugeneruoti skaiciai:\n");
    for (int i = 0; i < size; ++i){
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
