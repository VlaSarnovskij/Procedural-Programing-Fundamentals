#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Programa ras skaicius tarp ivestuju kuri turi daugiausiai skaitmenu.\n");
    printf("Pabaiga zymekite ivesdami neigama sk.\n\n");

    double num = 1; // Kintamasis ivestam sk.
    double maxLengthNum; // Kintamasis ilgiausiam sk.
    int i = 0; // Numeroti sk.
    int maxLength = 0; // Rasti ilgiausia sk.

    while(num > 0){
        ++i;
        printf("Iveskite %d teigiama sk.: ", i);
        scanf("%lf", &num);

        int length = 0;
        double temp = num;

        // Ciklas suzinoti koks yra skaiciaus ilgis
        while(temp >= 1){
            temp /= 10;
            ++length;
        }
        // Issaugojam ilgiausia sk.
        if (length > maxLength){
            maxLength = length;
            maxLengthNum = num;
        }
    }
    if(maxLength == 0){
        printf("Nebuvo ivesta teigiamu skaiciu.");
    } else{
        printf("Daugiausiai skaitmenu turi sk.: %f", maxLengthNum);
    }
    return 0;
}
