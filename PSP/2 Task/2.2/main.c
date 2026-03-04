#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Programa sukurs matrica pagal ivestus duomenis ir atspausdins visu balno tasku koordinates.\n");

    int n;
    printf("Iveskite n (stulpeliu ir eiluciu sk.): ");
    scanf("%d", &n);

    int arr[n][n]; // two-dimensional array

    // Ivedam duomenius
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf ("Iveskite %d eiles %d nari: ", i+1, j+1);
            scanf ("%d", &arr[i][j]);
        }
    }

    // Parodom Matrica
    printf("\nMatrix:\n");
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf ("%d ", arr[i][j]);
        }
        printf ("\n");
    }
    printf("\n\n");


    printf("Rezultatai:\n");
    // Balno koordinates paieska
    for (int i = 0; i < n; ++i){
        int minRow = arr[i][0];
        int maxRow = arr[i][0];

        // Rasti max ir min elementa eiluteje
        for (int j = 0; j < n; ++j){
            if (arr[i][j] < minRow) minRow = arr[i][j];
            if (arr[i][j] > maxRow) maxRow = arr[i][j];
        }

        for (int j = 0; j < n; ++j){
            // Jei savo eiluteje elementas buvo max
            if (arr[i][j] == maxRow){
                int minColumn = arr[i][j];
                // Tikriname ar jis yra min savo stulpelyje
                for(int k = 0; k < n; ++k){
                    if(arr[k][j] < minColumn) minColumn = arr[k][j];
                }
                // Isvedam taska ir koordinates
                if (arr[i][j] == minColumn){
                    printf("Balno taska: %d\n", arr[i][j]);
                    printf("Eile: %d, stulpelis: %d\n\n", i+1, j+1);
                    if(n == 1){
                        break; // Isimtis: jei matrica yra 1x1, bus 1 rezultatas
                    }
                }
            }

            // Jei elementas buvo min savo eiluteje
            if (arr[i][j] == minRow){
                int maxColumn = arr[i][j];
                // Tikriname ar jis yra max savo stulpelyje
                for(int k = 0; k < n; ++k){
                    if(arr[k][j] > maxColumn) maxColumn = arr[k][j];
                }
                if (arr[i][j] == maxColumn){
                    printf("Balno koordinate: %d\n", arr[i][j]);
                    printf("Eile: %d, stulpelis: %d\n\n", i+1, j+1);
                }
            }
        }
    }
    return 0;
}
