#include <stdio.h>
#include <stdlib.h>

int main()
{
    int skc;

    printf("Iveskite sveika skaiciu: \n");
    skc = 5;
    //scanf("%d",&skc);

    // triviecias operatorius tikrina lyginis ar ne skc.
    printf("%s\n", (skc % 2 == 0) ? "Lyginis" : "Nelyginis");

    return 0;
}
