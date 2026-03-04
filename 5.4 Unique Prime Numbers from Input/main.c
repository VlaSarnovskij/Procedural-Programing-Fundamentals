#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Programa atspausdins visus ivestus pirminius skaicius.\n\n");

    int* arr = malloc(16 * sizeof(int));
    int capacity = 16;
    int used = 0;
    int i = 0;

    printf("Veskite teigiamus skaicius (neteigiamas stabdo):\n");
    while (1){
        int temp;

        scanf("%d", &temp);
        if (temp <= 0){
            break;
        }
        // tikrinam ar pakanko atminties, jei nei tai didinam i 2
        if (used == capacity){
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(int));
        }
        arr[i] = temp;
        ++i;
        ++used;
    }
    printf("Duomenys sekmingai ivesti!\n\n");


    printf("Pirminiai skaiciai:\n");
    // Isvedam pirminius skaicius
    for (i = 0; i < used; ++i){
        int n = arr[i];

        // tikrinam ar jau buvo toks pats skaicius anksciau
        int jau_buvo = 0;
        for (int k = 0; k < i; k++) {
            if (arr[k] == n) {
                jau_buvo = 1;
                break;
            }
        }
        if (jau_buvo) continue;

        // tikrinam ar pirminis
        if (n < 2) continue;
        int pirminis = 1;
        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) {
                pirminis = 0;
                break;
            }
        }
        if (pirminis) {
            printf("%d ", n);
        }
    }
    printf("\n");

    free(arr);  // Valome atminti

    return 0;
}
