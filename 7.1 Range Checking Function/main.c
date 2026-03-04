#include <stdio.h>
#include <stdlib.h>

// Funkcija tikrina, ar skaicius 'number' priklauso intervalui [low; high]
int isInRange (int number, int low, int high){
    if (low <= number && number <= high){
        return 1; // true
    }
    return 0;     // false
}

int main()
{
    int low, high;
    int number;

    scanf("%d%d%d", &low, &high, &number);

    if(isInRange (number, low, high) == 1){
        printf ("Number %d is in range [%d;%d]", number, low, high);
    } else{
        printf ("Number %d is not in range [%d;%d]", number, low, high);
    }
    return 0;
}
