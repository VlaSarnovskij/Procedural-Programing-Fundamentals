#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("Programa atspausdins visus teigiamus sveikus skaicius intervale (a; b],\n");
    printf("kurie dalijasi is skaiciaus c su liekana 1.\n\n");


    // Ivedame a
    printf("Iveskite skaiciu a: ");
    scanf("%d", &a);

    // Ivedame b (b > a)
    while (1) {
        printf("Iveskite skaiciu b: ");
        scanf("%d", &b);
        if (b > a) break;
        printf("Klaida! b turi buti didesnis negu a.\n");
    }

    // Ivedame c (c != 0)
    while (1) {
        printf("Iveskite skaiciu c: ");
        scanf("%d", &c);
        if (c != 0) break;
        printf("Klaida! c negali buti lygus nuliui.\n");
    }


    printf("\nJusu ivesti skaiciai:\n");
    printf("a = %d\nb = %d\nc = %d.\n\n", a, b, c);

    int temp = a;
    printf("Rezultatas: ");
    for (int temp = a+1; temp <= b; ++temp){
        if(temp % c == 1 && temp > 0){
            printf("%d ", temp);
        }
    }
    return 0;
}
