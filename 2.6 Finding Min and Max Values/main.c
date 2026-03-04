#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rasti_min_max(int x, int y, int z, int *min, int *max){
    int x_y_min = fmin(x, y); // 1 palyginimas
    int x_y_max = fmax(x, y);

    *min = fmin(x_y_min, z); // 2 palyginimas
    *max = fmax(x_y_max, z);
}

int main()
{
    int x, y, z, min, max;
    x=5, y=8, z=10;
    // scanf("%d %d %d", &x, &y, &z);

    rasti_min_max(x, y, z, &min, &max);

    printf("Minimumas - %d, maksimumas - %d\n", min, max);

    // Testai
    x = 1; y = 2; z = 3; rasti_min_max(x, y, z, &min, &max);
    printf("1Testas {1,2,3} (min-1, max-3). Gauta: min-%d, max-%d\n", min, max);

    x = 4; y = 9; z = 5; rasti_min_max(x, y, z, &min, &max);
    printf("2Testas {4,9,5} (min-4, max-9). Gauta: min-%d, max-%d\n", min, max);

    x = 10; y = 0; z = 8; rasti_min_max(x, y, z, &min, &max);
    printf("3Testas {10,0,8} (min-0, max-10). Gauta: min-%d, max-%d\n", min, max);

    x = 8; y = 1; z = 8; rasti_min_max(x, y, z, &min, &max);
    printf("4Testas {8,1,8} (min-1, max-8). Gauta: min-%d, max-%d\n", min, max);

    x = 4; y = 4; z = 0; rasti_min_max(x, y, z, &min, &max);
    printf("5Testas {4,4,0} (min-0, max-4). Gauta: min-%d, max-%d\n", min, max);

    x = -1; y = 40; z = 40; rasti_min_max(x, y, z, &min, &max);
    printf("6Testas {-1,40,40} (min-(-1), max-40). Gauta: min-%d, max-%d\n", min, max);

    x = 10; y = 10; z = 10; rasti_min_max(x, y, z, &min, &max);
    printf("7Testas {10,10,10} (min-10, max-10). Gauta: min-%d, max-%d\n", min, max);

    x = 20; y = 1; z = 73; rasti_min_max(x, y, z, &min, &max);
    printf("8Testas {20,1,73} (min-1, max-73). Gauta: min-%d, max-%d\n", min, max);

    x = 9; y = 13; z = 5; rasti_min_max(x, y, z, &min, &max);
    printf("9Testas {9,13,5} (min-5, max-13). Gauta: min-%d, max-%d\n", min, max);

    x = 83; y = 20; z = -5; rasti_min_max(x, y, z, &min, &max);
    printf("10Testas {83,20,-5} (min-(-5), max-83)). Gauta: min-%d, max-%d\n", min, max);

    x = 7; y = 0; z = 0; rasti_min_max(x, y, z, &min, &max);
    printf("11Testas {7,0,0} (min-0, max-7). Gauta: min-%d, max-%d\n", min, max);

    x = 2; y = 8; z = 2; rasti_min_max(x, y, z, &min, &max);
    printf("12Testas {2,8,2} (min-2, max-8). Gauta: min-%d, max-%d\n", min, max);

    x = -12; y = -12; z = 80; rasti_min_max(x, y, z, &min, &max);
    printf("13Testas {-12,-12,80} (min-(-12), max-80). Gauta: min-%d, max-%d\n", min, max);

    return 0;
}
