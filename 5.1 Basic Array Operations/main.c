#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

int main()
{
    // a:
    int arr[CAPACITY] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int size = CAPACITY;


    // b:
    for (int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");


    // c:
    arr[0] = 1;
    arr[3] = 2;
    arr[9] = 3;


    // d:
    int x = 2; // istrinti 2 el.
    for (int i = x; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;


    // e:
    x = 6; // septintas el.
    for (int i = size; i > x; i--) {
        arr[i] = arr[i-1];
    }
    arr[x] = 4; // arba y
    size++;


    // f:
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");


    // g:
    int y;
    printf("\nNustatyti nauja reiksme masyvo elementui.\n");
    while(1){
        printf("Iveskite el. indeksa: ");
        scanf("%d", &x);
        if (x >= 0 && x < size) {
            break;
        }
        printf("Neteisinga ivestis, skaiciai nuo 0 iki %d\n", size-1);
    }
    printf("Iveskite reiksme: ");
    scanf("%d", &y);

    arr[x] = y;



    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");


    // h:
    printf("\nIstrinti is masyvo elementa.\n");
    printf("Iveskite el. indeksa: ");
    while(1){
        scanf("%d", &x);
        if (x >= 0 && x < size) {
            break;
        }
        printf("Neteisinga ivestis, skaiciai nuo 0 iki %d\n", size-1);
    }

    for (int i = x; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;




    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // į:
    printf("\nIterpti nauja elementa i masyva.\n");

    printf("Iveskite el. indeksa: ");
    while(1){
        scanf("%d", &x);
        if (x >= 0 && x < size) {
            break;
        }
        printf("Neteisinga ivestis, skaiciai nuo 0 iki %d\n", size-1);
    }

    printf("Iveskite reiksme: ");
    scanf("%d", &y);

    for (int i = size; i > x; i--) {
    arr[i] = arr[i-1];
    }
    arr[x] = y;
    size++;


    // j:
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
