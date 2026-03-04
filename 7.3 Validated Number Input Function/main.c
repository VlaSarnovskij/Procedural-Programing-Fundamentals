#include <stdio.h>
#include <stdlib.h>

int getPositiveNumber(char *msg){
    char buffer[256];
    int number;
    int extra;

    while(1){
        printf("%s", msg);

        fgets(buffer, sizeof(buffer), stdin);

        if (sscanf(buffer, "%d %c", &number, &extra) == 1 && number > 0) {
            return number; // Korektiskas ivestis
        }
        printf("Klaida! Bandykite dar karta.\n");
    }
    return 0;
}

int main()
{
    int n = getPositiveNumber("Iveskite teigiama skaiciu: ");

    printf("Jus ivedete: %d\n", n);

    return 0;
}
