#include <stdio.h>

// Tikrina ir grazina teisingai ivesta sk.
int validacija() {
    int num;
    char c;

    while (1) {
        if (scanf("%d", &num) == 1 && (c = getchar()) == '\n') {
            return num; // Ivestas teisingai
        } else {
            printf("Netinkama ivestis! Iveskite sveika skaiciu!\n");
            while (getchar() != '\n');
        }
    }
}

int main()
{
    int num;          // Ivestas skaicius
    int position = 0; // Rodo skaiciaus padeti sekoje
    int count = 0;    // Kiek skaiciu atitinkancios uzduoties salygas

    while (num != 0){
        position++;
        printf("Iveskite %d sekos nari (sekos pabaiga pazymekite '0'): ", position);

        num = validacija();

        if(position % 2 == 0 && num > 0){ // Jei pozicija dalijama is 2 be liekanos - pozicija yra lygi
            count++;
        }
    }

    printf("Lyginiu teigiamu skaiciu sekoje yra: %d\n", count); // Buvo ivestas '0' - sekos pabaiga

    return 0;
}
