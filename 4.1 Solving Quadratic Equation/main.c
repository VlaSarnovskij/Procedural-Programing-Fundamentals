#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("Programa apskaiciuos kvadratines lygties sprendimu skaiciu ir (jei ju yra) juos parodys.\n\n");
    while(1){
        printf("Iveskite skaiciu a:");
        scanf("%d", &a);
        if(a == 0){
            printf("Klaida: a negali buti 0, nes tai ne kvadratine lygtis.\n");
        } else {
            printf("Iveskite skaiciu b:");
            scanf("%d", &b);

            printf("Iveskite skaiciu c:");
            scanf("%d", &c);
            break;
        }
    }



    printf("\nJusu ivesti skaiciai:\n");
    printf("a = %d\nb = %d\nc = %d.\n\n", a, b, c);

    double D;
    D = b*b - 4 * a * c;

    if (D > 0){
        double x1, x2;
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
        printf("Dvi sprendiniai: x1 = %.2f, x2 = %.2f\n", x1, x2);
    } else if(D == 0){
        double x;
        x = (-b + sqrt(D)) / (2*a);
        printf("Vienas sprendinis: x = %.2f\n", x);
    } else{
        printf("Sprendiniu nera.\n");
    }
    return 0;
}
