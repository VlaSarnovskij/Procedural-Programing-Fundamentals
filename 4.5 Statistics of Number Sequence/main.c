#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Programa suskaicios 'n' realiuju skaiciu suma, vidurki, maziausia ir didziausia reiksmes.\n\n");

    do{
        printf("Iveskite n: ");
        scanf("%d", &n);
        if(n <= 0){
            printf("Skaiciu negali buti nuli arba maziau.\n");
        }
    } while(n <= 0);

    double num[n];

    for (int i = 0; i < n; ++i){
        printf("Iveskite %d sk.: ", i+1);
        scanf("%lf", &num[i]);
    }

    double sum = 0;
    double numMax = num[0], numMin = num[0];
    // Ciklas nustatyti suma ir rasti maz. ir didz. sk.
    for (int i = 0; i < n; ++i){
        sum += num[i];

        if (num[i] > numMax){
            numMax = num[i];
        }
        if (num[i] < numMin){
            numMin = num[i];
        }
    }

    printf("\nSkaiciu suma: %.2f\n", sum);
    printf("Skaiciu vidurkis: %.2f\n", sum/n);
    printf("Maziausia reiksme: %.2f\n", numMin);
    printf("Didziausia reiksme: %.2f\n", numMax);

    return 0;
}
