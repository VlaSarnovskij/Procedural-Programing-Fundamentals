#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("Programa parodys c-aji skaiciu fc, kur fc=fc-1+fc-2, o f0 = a ir f1 = b.\n\n");

    // Ivedame a
    while (1) {
        printf("Iveskite skaiciu a: ");
        scanf("%d", &a);
        if (a >= 0) break;
        printf("Netinkamas ivestis! Iveskite neneigiama sveika skaiciu.\n");
    }

    // Ivedame b
    while (1) {
        printf("Iveskite skaiciu b: ");
        scanf("%d", &b);
        if (b >= 0) break;
        printf("Netinkamas ivestis! Iveskite neneigiama sveika skaiciu.\n");
    }

    // Ivedame c
    while (1) {
        printf("Iveskite skaiciu c: ");
        scanf("%d", &c);
        if (c >= 0) break;
        printf("Netinkamas ivestis! Iveskite neneigiama sveika skaiciu.\n");
    }

    printf("\nJusu ivesti skaiciai:\n");
    printf("a = %d\nb = %d\nc = %d.\n\n", a, b, c);

   int fc;
    if (c == 0) {
        fc = a;
    } else if (c == 1) {
        fc = b;
    } else {
        int f0 = a, f1 = b;
        for (int i = 2; i <= c; i++) {
            fc = f0 + f1;
            f0 = f1;
            f1 = fc;
        }
    }
        printf("Rezultatas: f%d = %d\n", c, fc);

    return 0;
}
