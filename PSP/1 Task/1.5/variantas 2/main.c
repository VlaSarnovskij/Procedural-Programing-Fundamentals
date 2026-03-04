#include <stdio.h>

int main()
{
    int num;          // Ivestas skaicius
    int position = 1; // Skaiciaus pozicija sekoje
    int count = 0;    // Salygas atitinkanciu skaiciu kiekis
    char c;

    while (1) {

        // Validacijos ciklas
        while (1) {
            printf("Įveskite %d sekos narį (sekos pabaiga žymima '0'): ", position);

            if (scanf("%d", &num) == 1) {
                while ((c = getchar()) != '\n' && c != EOF); // Išvalomas buferis
                break; // Įvesta teisingai → išeiname į pagrindinį ciklą
            } else {
                printf("Neteisinga ivestis! Iveskite sveikaji skaiciu!\n");
                while ((c = getchar()) != '\n' && c != EOF); // Išvalomas buferis
            }
        }

        // Jei ivestas 0 - pabaiga
        if (num == 0) {
            printf("Lyginiu teigiamu skaiciu kiekis yra: %d\n", count);
            break;
        }
        // Skaiciojam kiek skaiciu atitinka salygoms
        if (position % 2 == 0 && num > 0) {
            count++;
        }

        position++;
    }

    return 0;
}
