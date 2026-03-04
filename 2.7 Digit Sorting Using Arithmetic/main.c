#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, temp = 0, skc[10] = {0};

    n = 120;

    while (n > 0){
        for(int i = 9; i != 0; i--){
            temp = n % 10;
            if(temp == i){
                printf("%d", i);
            }
            else if(n % 10 == 0){
                n /= 10;
                printf("%d\n", n);
            }
            else {
                n--;
            }
        }
    }

    printf("Hello world!\n");
    return 0;
}
