#include <stdio.h>
#include <stdlib.h>

void swap(int *skaicius1_ptr, int *skaicius2_ptr){
    int tmp;

    tmp = *skaicius1_ptr;
    *skaicius1_ptr = *skaicius2_ptr;
    *skaicius2_ptr = tmp;
}

int main()
{
    int sk1 = 5;
    int sk2 = 8;

    printf("Before swap: %d, %d \n", sk1, sk2);

    swap(&sk1, &sk2);

    printf("After swap: %d, %d \n", sk1, sk2);
    return 0;
}
