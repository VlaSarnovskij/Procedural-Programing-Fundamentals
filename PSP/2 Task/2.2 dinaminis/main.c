#include <stdio.h>
#include <stdlib.h>

void input_matrica(int n, int **matrica) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            printf("Iveskite %d eiles %d nari: ", i + 1, j + 1);
            scanf("%d", &matrica[i][j]);
        }
}

void print_matrica(int n, int **matrica) {
    printf("\nMatrica:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d ", matrica[i][j]);
        printf("\n");
    }
    printf("\n");
}

int rasti_min_row(int n, int **matrica, int row) {
    int min = matrica[row][0];
    for (int j = 1; j < n; ++j)
        if (matrica[row][j] < min)
            min = matrica[row][j];
    return min;
}

int rasti_max_row(int n, int **matrica, int row) {
    int max = matrica[row][0];
    for (int j = 1; j < n; ++j)
        if (matrica[row][j] > max)
            max = matrica[row][j];
    return max;
}

int balno_taskas(int n, int **matrica, int i, int j) {
    int min_row = rasti_min_row(n, matrica, i);
    int max_row = rasti_max_row(n, matrica, i);

    if (matrica[i][j] == max_row) {
        int min_col = matrica[i][j];
        for (int k = 0; k < n; ++k)
            if (matrica[k][j] < min_col)
                min_col = matrica[k][j];
        if (matrica[i][j] == min_col)
            return 1;
    }

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
    int n;
    printf("Programa randa matricos balno taskus.\n");
    printf("Iveskite n: ");
    scanf("%d", &n);

    // Dinaminio masyvo kurymas
    int **matrica = malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i)
        matrica[i] = malloc(n * sizeof(int)); // Atminties atskirimas

    // Input output
    input_matrica(n, matrica);
    print_matrica(n, matrica);

    // Balno koordinaciu paieska
    printf("Rezultatai:\n");
    int found = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (balno_taskas(n, matrica, i, j)) {
                printf("Balno taskas: %d (eile %d, stulpelis %d)\n",
                       matrica[i][j], i + 1, j + 1);
                found = 1;
            }

    if (!found)
        printf("Balno tasku nerasta.\n");

    // Atminties islaisvinimas
    for (int i = 0; i < n; ++i)
        free(matrica[i]);
    free(matrica);

    return 0;
}
