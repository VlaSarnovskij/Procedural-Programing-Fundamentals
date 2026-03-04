#include <stdio.h>
#include <stdlib.h>

int getFactorial(int number) {
    if (number < 0) {
        return 0;  // Neigiamu skaiciu faktorialas nera apibreztas
    }
    if (number == 0 || number == 1) {
        return 1;  // Bazinis atvejis
    }
    return number * getFactorial(number - 1);  // Rekursinis iskvietimas
}

// Tokia pat funkicija kaip ir getFactorial, bet be rekursijos metoda
int getFactorialTwo(int number){
    if (number < 0) return 0;

    int factorial = 1;
    for (int i = 1; i <= number; i++){
        factorial *= i;
    }
    return factorial;
}

int main()
{
    int number;

    scanf("%d", &number);


    printf ("Factorial(with recursion): %d! = %d\n", number, getFactorial(number));

    printf ("Factorial: %d! = %d\n", number, getFactorialTwo(number));

    return 0;
}
