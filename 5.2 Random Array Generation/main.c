#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[1000];
    int a, b, c;

    printf("Programa sugeneruos 'c' atsitiktinai sugeneruotu reiksmiu, intervale [a; b], ir atspausdins ju i ekrana.\n");

    printf("Iveskite a: ");
    scanf("%d", &a);

    printf("Iveskite b: ");
    scanf("%d", &b);

    while (1){
        printf("Iveskite c: ");
        scanf("%d", &c);
        if (c <= 1000){
            break;
        } else {
            printf("Klaida, negalima generuoti daugiau nei 1000 elementu!\n");
        }
    }

    // inicializuojame generatoriu su kintanciu skaiciumi
    srand(time(NULL));

    // generuojame c atsitiktiniu skaiciu intervale [a; b]
    for (int i = 0; i < c; ++i){
        arr[i] = a + rand() % (b - a + 1);
    }

    // spausdiname rezultata
    printf("Sugeneruoti skaiciai:\n");
    for (int i = 0; i < c; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
