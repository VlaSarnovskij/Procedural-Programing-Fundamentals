#include <stdio.h>
#include <stdlib.h>

int DBD(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int MBK(int a, int b){
    return (a * b) / DBD(a, b);
}

int main()
{
    int a, b, c;
    printf("Programa atspausdins a, b ir c skaiciu didziausia bendraji dalikli (DBD)\n");
    printf("bei maziausiaji bendra kartotini (MBK).\n\n");

    printf("Iveskite tris naturaliuosius skaicius (a, b, c):");
    scanf("%d %d %d", &a, &b, &c);

    printf("\nJusu ivesti skaiciai:\n");
    printf("a = %d\nb = %d\nc = %d.\n\n", a, b, c);

    int DBDab = DBD(a, b);
    int DBDabc = DBD(DBDab, c);

    int MBKab = MBK(a, b);
    int MBKabc = MBK(MBKab, c);

    printf("Didziausias bendrasis daliklis (DBD): %d\n", DBDabc,);
    printf("Maziausias bendras kartotinis (MBK): %d\n"MBKabc);

    return 0;
}
