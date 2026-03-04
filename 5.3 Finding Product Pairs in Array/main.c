#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Programa atspausdins visas skaiciu poras is masyvo x kuriu sandauga ligu s.\n");

    int s, n;

    while(1){
        printf("Iveskite s: ");
        scanf("%d", &s);
        if (s > 0) {
            break;
        } else {
            printf("Neteisingas ivestis. Iveskite sveika, teigiama sk. \n");
        }
    }

    while(1){
        printf("Iveskite n (masyvo el. skaiciu): ");
        scanf("%d", &n);
        if (n > 0) {
            break;
        } else {
            printf("Neteisingas ivestis. Iveskite sveika, teigiama sk. \n");
        }
    }

    int x[n];
    int i = 0;

    // Nuskaitom skaicius kurie yra teigiami
    do{
        printf("Iveskite teigiama %d sk.: ", i+1);
        scanf("%d", &x[i]);
        if (x[i] > 0){
            ++i;
        } else{
            printf("Neteisingas ivestis. Iveskite sveika, teigiama sk.\n");
        }
    } while (i < n);
    printf("\nDuomenys ivesti sekmingai!\n\n");

    printf("Rezultatai:\n");
    for (i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            if (x[i] * x[j] == s){      // Randam skaiciu pora ir isvedam
                printf("sk. %d = %d; sk. %d = %d\n", i+1, x[i], j+1, x[j]);
            }
        }
    }

    return 0;
}
