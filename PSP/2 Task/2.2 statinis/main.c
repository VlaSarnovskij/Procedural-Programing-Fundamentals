#include <stdio.h>

#define MAX 10  // maksimalus leidziamas matricos dydis

// Funkcija duomenu ivedimui i matrica
void input_matrica(int n, int matrica[MAX][MAX]) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            printf("Iveskite %d eiles %d nari: ", i + 1, j + 1);
            scanf("%d", &matrica[i][j]);
        }
}

// Funkcija matricos isvedimui
void print_matrica(int n, int matrica[MAX][MAX]) {
    printf("\nMatrica:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", matrica[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Funkcija rasti maziausia reiksme eiluteje
int rasti_min_row(int n, int matrica[MAX][MAX], int row) {
    int min = matrica[row][0];
    for (int j = 1; j < n; ++j)
        if (matrica[row][j] < min)
            min = matrica[row][j];
    return min;
}

// Funkcija rasti didziausia reiksme eiluteje
int rasti_max_row(int n, int matrica[MAX][MAX], int row) {
    int max = matrica[row][0];
    for (int j = 1; j < n; ++j)
        if (matrica[row][j] > max)
            max = matrica[row][j];
    return max;
}

// Funkcija, kuri patikrino ar tai yra balno taska
int balno_taskas(int n, int matrica[MAX][MAX], int i, int j){
    int min_row = rasti_min_row(n, matrica, i);
    int max_row = rasti_max_row(n, matrica, i);
    // Maksimumas savo eiluteje ir minimumas savo stulpelyje
    if (matrica[i][j] == max_row) {
        int min_col = matrica[i][j];
        for (int k = 0; k < n; ++k)
            if (matrica[k][j] < min_col)
                min_col = matrica[k][j];
        if (matrica[i][j] == min_col)
            return 1;
    }
    // Minimumas savo eiluteje ir maksimumas savo stulpelyje
    if (matrica[i][j] == min_row) {
        int max_col = matrica[i][j];
        for (int k = 0; k < n; ++k)
            if (matrica[k][j] > max_col)
                max_col = matrica[k][j];
        if (matrica[i][j] == max_col)
            return 1;
    }
    return 0;
}

int main() {
    printf("Programa randa matricos balno taskus.\n");
    int n;
    printf("Iveskite n (ne daugiau kaip %d): ", MAX);
    scanf("%d", &n);

    int matrica[MAX][MAX];
    input_matrica(n, matrica);
    print_matrica(n, matrica);

    printf("Rezultatai:\n");
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (balno_taskas(n, matrica, i, j)){
                printf("Balno taskas: %d (eile %d, stulpelis %d)\n", matrica[i][j], i + 1, j + 1);
            }
        }
    }

    return 0;
}
