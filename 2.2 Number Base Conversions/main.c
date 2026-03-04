#include <stdio.h>
#include <stdlib.h>

void IDvejetaine(int des){
    int bits[32];   // parasyti dvejetaini skc.
    int i = 0;

    printf("%d (10) = ", des);
    // kol skc. didesnis negu 0
    while (des > 0) {
        bits[i] = des % 2; // 0 arba 1 likutis
        des = des / 2;
        i++;
    }
    // isvedam atvirkstinei tvarkoj
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
    }
    printf(" (2)\n");
}

int main()
{
    // a) Is dvejetaines i desimtaine
    int dv1 = 0b11011, dv2 = 0b10010100, dv3 = 0b11001011010101;
    // scanf("%d", &dvx);

    printf("11011 (2) = %d (10)\n", dv1);
    printf("10010100 (2) = %d (10)\n", dv2);
    printf("11001011010101 (2) = %d (10)\n\n", dv3);

    // b) Is desimtaines i dvejetaine
    int des1 = 37, des2 = 241, des3 = 2487;
    // scanf("%d", &desx);

    IDvejetaine(des1);
    IDvejetaine(des2);
    IDvejetaine(des3);
    printf("\n");

    // c) Is sesioliktaines i desimtaine

    int ses1 = 6E2, ses2 = 0xED33, ses3 = 0x123456;
    // scanf("%x", &sesx);

    printf("6E2 (16) = %d (10)\n", ses1);
    printf("ED33 (16) = %d (10)\n", ses2);
    printf("123456 (16) = %d (10)\n\n", ses3);

    // d) Is desimtaines i sesioliktaine

    int d1 = 243, d2 = 2483, d3 = 4612;
    // scanf("%d", &dx);

    printf("243 (10) = %x (16)\n", d1);
    printf("2483 (10) = %x (16)\n", d2);
    printf("4612 (10) = %x (16)\n\n", d3);

    return 0;
}
