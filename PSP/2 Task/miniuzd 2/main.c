#include <stdio.h>
#include <stdlib.h>

void rasti_didz_sk(int skaicius1, int skaicius2, int *didz){
    if(skaicius1 > skaicius2){
        *didz = skaicius1;
    } else {
        *didz = skaicius2;
    }
}

int main()
{
    int skaicius1, skaicius2;
    int didz;

    printf("Iveskite skaiciu skaicius1: ");
    scanf("%d", &skaicius1);

    printf("Iveskite skaiciu skaicius2: ");
    scanf("%d", &skaicius2);


    rasti_didz_sk (skaicius1, skaicius2, &didz);

    printf("Didziausias skaicius: %d\n", didz);

    return 0;
}
