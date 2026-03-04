#include <stdio.h>

int main()
{
    printf("Iveskite sveikaji skaiciu:");
    int n;
    if(!scanf("%d", &n)){ // Tikrinam ar ivestas skaicius
        printf("Klaida, iveskite sveikaji skaiciu");
        return -1;
    }
    int i = 0, temp = 0;
    while(i != n){
        i++;
        temp += i*i; // Skaicius keliamas i 2 laipsni
    }

    printf("%d", temp);
    return 0;
}
