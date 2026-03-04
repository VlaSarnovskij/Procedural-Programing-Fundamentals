#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y, z, rez_a, rez_b;
    printf("Iveskite realu skaiciu x:\n");
    x = 1.1;
    //scanf("%lf", &x);

    printf("Iveskite realu skaiciu y:\n");
    y = 2.8;
    //scanf("%lf", &y);

    printf("Iveskite realu skaiciu z:\n");
    z = 3.14;
    //scanf("%lf", &z);

    // a) x + 4y + z^3
    rez_a = x + 4*y + pow(z, 3);
    printf("\nPirmojo reiskinio reiksme: %lf\n", rez_a);

    // b) (x + √𝑦)(z^4-|z|+46.3)
    rez_b = (x + sqrt(y)) * (pow(z, 4) - fabs(z) + 46.3);
    printf("\nAntrojo reiskinio reiksme: %lf\n", rez_b);

    return 0;
}
