#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Programa apskaiciuos ir parodys ivesto skaiciaus faktoriala.\n");

    int skaicius;
    char c; // Patikrinti, ar ivestas sveikasis skaicius

    while (1){
        printf("Iveskite teigiama skaiciu: ");

        // Tikrinam ar ivesta skaicius
        if (scanf("%d%c", &skaicius, &c) != 2 || c != '\n') {
            printf("Klaida: ivestis turi buti tik vienas sveikas skaicius be papildomu simboliu.\n");
            while (getchar() != '\n'); // isvalom neteisinga ivesti
            continue;
        }
        if (skaicius > 0){
            break;
        }
        printf("Neteisingas ivestis. Skaicius turi buti teigiamas.\n");
    }

    int faktorialas = 1;
    for (int i = 1; i <= skaicius; ++i){
        faktorialas *= i;
    }

    printf("Skaiciaus %d faktorialas: %d\n", skaicius, faktorialas);

    FILE *file = fopen("out.txt", "w"); // Atidarom (arba kuriam) output faila

    fprintf(file, "Skaiciaus %d faktorialas: %d\n", skaicius, faktorialas); // Parodom rezultata

    fclose(file); // Uzdarom faila

    return 0;
}
