#include <stdio.h>
#include <stdlib.h>

// Funkcija duomenu ivedimui i matrica
void input_matrica(int n, int matrica[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("Iveskite %d eiles %d nari: ", i + 1, j + 1);
            scanf("%d", &matrica[i][j]);
        }
    }
}

// Funkcija matricos isvedimui
void print_matrica(int n, int matrica[n][n]) {
    printf("\nMatrica:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrica[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Funkcija rasti maziausia reiksme eiluteje
int rasti_min_row(int n, int matrica[n][n], int row) {
    int min = matrica[row][0];
    for (int j = 1; j < n; ++j)
        if (matrica[row][j] < min)
            min = matrica[row][j];
    return min; // grazina reiksme
}

// Funkcija rasti didziausia reiksme eiluteje
int rasti_max_row(int n, int matrica[n][n], int row) {
    int max = matrica[row][0];
    for (int j = 1; j < n; ++j)
        if (matrica[row][j] > max)
            max = matrica[row][j];
    return max; // grazina reiksme
}

// Funkcija, kuri suranda ir isveda visus balno taskus
void find_balno_taskus(int n, int matrica[n][n]) {
    printf("Rezultatai:\n");

    for (int i = 0; i < n; ++i) {
        int min_row = rasti_min_row(n, matrica, i);
        int max_row = rasti_max_row(n, matrica, i);

        for (int j = 0; j < n; ++j) {

            // Jei elementas yra max savo eiluteje
            if (matrica[i][j] == max_row) {
                int min_collumn = matrica[i][j];
                // Tikriname, ar jis yra min savo stulpelyje
                for (int k = 0; k < n; ++k)
                    if (matrica[k][j] < min_collumn)
                        min_collumn = matrica[k][j];

                if (matrica[i][j] == min_collumn) {
                    printf("Balno taskas: %d\n", matrica[i][j]);
                    printf("Eile: %d, stulpelis: %d\n\n", i + 1, j + 1);
                    if (n == 1){
                        break; // Isimtis: jei matrica is 1 el. jis turi spausdinti 1 karta
                    }
                }
            }

            // Jei elementas yra min savo eiluteje
            if (matrica[i][j] == min_row) {
                int max_collumn = matrica[i][j];
                // Tikriname, ar jis yra max savo stulpelyje
                for (int k = 0; k < n; ++k)
                    if (matrica[k][j] > max_collumn)
                        max_collumn = matrica[k][j];

                if (matrica[i][j] == max_collumn) {
                    printf("Balno taskas: %d\n", matrica[i][j]);
                    printf("Eile: %d, stulpelis: %d\n\n", i + 1, j + 1);
                }
            }
        }
    }
}

// Pagrindine funkcija
int main() {
    printf("Programa sukurs matrica pagal ivestus duomenis ir atspausdins visu balno tasku koordinates.\n");

    int n;
    printf("Iveskite n (stulpeliu ir eiluciu sk.): ");
    scanf("%d", &n);

    int matrica[n][n]; // Dvimatis masyvas

    input_matrica(n, matrica);
    print_matrica(n, matrica);
    find_balno_taskus(n, matrica);

    return 0;
}
