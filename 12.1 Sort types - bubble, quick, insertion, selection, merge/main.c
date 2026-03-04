#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int comparisons = 0;
int assignments = 0;

void swap(int *a, int *b){
    int temp = *a; ++assignments;
    *a = *b; ++assignments;
    *b = temp; ++assignments;
}

// 1a:
void generateArray(int *data, int size){
    for (int i = 0; i < size; ++i){
        data[i] = rand() % 100;
    }
}

// 1b:
int isSorted(int *data, int size){
    if(size < 2){
        return 1;
    }               // in case there is 1 element

    for(int i = 0; i < size - 1; ++i){
        if(data[i] > data[i + 1]){
                return 0; // return 0 if not sorted
        }
    }
    return 1;   // return 1 if sorted
}


// 1c a) Burbuliuko metodas
void bubbleSort(int *data, int size){
    ++assignments;
    for (int i = 0; i < size - 1; ++i, ++assignments) {

        ++assignments;
        for (int j = 0; j < size - i - 1; ++j, ++assignments) {
            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
            }
            ++comparisons;
        }
    }
}


// 1c b) Greitojo rikiavimo metodas
int partition(int *data,int start, int end) {
    int pivot = data[end];++assignments;
    int i = start;++assignments;


    for(int j = start; j < end; ++j, ++assignments){
        if(data[j] <= pivot){
            swap(&data[i], &data[j]);
            ++i; ++assignments;
        }
        ++comparisons;
    }
    ++assignments;
    swap(&data[i], &data[end]);
    return i;
}

void quickSort(int *data,int start, int end){
    if (start < end){
        ++comparisons;
        int p = partition(data, start, end);++assignments;
        ++assignments;
        quickSort(data, start, p - 1);
        quickSort(data, p + 1, end);
    }
}


// 1c c) Įterpimo metodas
void insertionSort(int *data, int size){
    int i = 1;++assignments;


    while (i < size){
        ++comparisons;
        int j = i;++assignments;

        while(j > 0 && data[j - 1] > data[j]){
            comparisons += 2;
            swap(&data[j], &data[j - 1]);
            --j;++assignments;
        }
        ++i;++assignments;
    }
}


// 1c d) Išrinkimo metodas
void selectionSort(int *data, int size){
    for (int i = 0, j = 0; i < size; ++i, ++comparisons, ++assignments){
        int jMin = i;++assignments;

        for (j = i + 1; j < size; ++j, ++comparisons, ++assignments){
            if (data[j] < data[jMin]){
                jMin = j;++assignments;
            }
            ++comparisons;
        }

        if (jMin != i){
            swap(&data[i], &data[jMin]);
        }
        ++comparisons;
    }
    assignments += 2;
}


// 1c e) Sąlajos metodas
void merge(int *data, int start, int mid, int end) {
    int i, j, k;
    int n1 = mid - start + 1;++assignments; // size of L[]
    int n2 = end - mid;++assignments;        //size of R[]


    // Temporary arrays
    int L[n1], R[n2];

    // Copy data in temporary L[] and R[]
    for (i = 0; i < n1; ++i, ++comparisons, ++assignments){
        L[i] = data[start + i];++assignments;
    }
    for (j = 0; j < n2; ++j, ++comparisons, ++assignments){
        R[j] = data[mid + 1 + j];++assignments;
    }

    i = 0;++assignments; // index L[]
    j = 0;++assignments; // index R[]
    k = start;++assignments; // index merged array

    while (i < n1 && j < n2) {
        comparisons += 2;
        if (L[i] <= R[j]) {
            data[k] = L[i];++assignments;
            ++i;++assignments;
        } else {
            data[k] = R[j];++assignments;
            ++j;++assignments;
        }
        ++comparisons;
        ++k;++assignments;
    }

    // Copy L[] elements, if there is
    while (i < n1) {
        ++comparisons;
        data[k] = L[i];++assignments;
        ++i;++assignments;
        ++k;++assignments;
    }

    // Copy R[] elements, if there is
    while (j < n2) {
        ++comparisons;
        data[k] = R[j];++assignments;
        ++j;++assignments;
        ++k;++assignments;
    }
}

void mergeSort(int *data, int start, int end) {
    if (start < end){
        ++comparisons;
        int mid = start + (end - start) / 2;++assignments;
        // 1. Recursive sorting 1 part
        mergeSort(data, start, mid);

        // 2. Recursive sorting 2 part
        mergeSort(data, mid + 1, end);

        // 3. Merging 2 parts
        merge(data, start, mid, end);
    }
}


int main()
{
    srand(time(NULL));

    int size = 50;
    int data[50];
    int temp[50];

    generateArray(data, size);

    memcpy(temp, data, size * sizeof(int)); // copy array, then to compare different types of sorting

    printf("%-15s %-12s %-12s %-6s\n", "Algorithm", "Comparisons", "Assignments", "Sorted");

    // Print Bubble sort results
    bubbleSort(data, size);
    printf("%-15s %-12d %-12d %-6s\n",
           "Bubble Sort", comparisons, assignments, isSorted(data, size) ? "Yes" : "No");

    memcpy(data, temp, size * sizeof(int));
    comparisons = 0;
    assignments = 0;

    // Print Quick sort results
    quickSort(data, 0, size - 1);
    printf("%-15s %-12d %-12d %-6s\n",
           "Quick sort", comparisons, assignments, isSorted(data, size) ? "Yes" : "No");

    memcpy(data, temp, size * sizeof(int));
    comparisons = 0;
    assignments = 0;

    // Print Insertion sort results
    insertionSort(data, size);
    printf("%-15s %-12d %-12d %-6s\n",
           "Insertion sort", comparisons, assignments, isSorted(data, size) ? "Yes" : "No");

    memcpy(data, temp, size * sizeof(int));
    comparisons = 0;
    assignments = 0;

    // Print Selection sort results
    selectionSort(data, size);
    printf("%-15s %-12d %-12d %-6s\n",
           "Selection sort", comparisons, assignments, isSorted(data, size) ? "Yes" : "No");

    memcpy(data, temp, size * sizeof(int));
    comparisons = 0;
    assignments = 0;

    // Print Merge sort results
    mergeSort(data, 0, size - 1);
    printf("%-15s %-12d %-12d %-6s\n",
           "Merge sort", comparisons, assignments, isSorted(data, size) ? "Yes" : "No");

    return 0;
}
