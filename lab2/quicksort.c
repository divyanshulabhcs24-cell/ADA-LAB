#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low, j = high;

    while (i < j) {
        while (a[i] <= pivot && i <= high - 1) i++;
        while (a[j] > pivot && j >= low + 1) j--;
        if (i < j) swap(&a[i], &a[j]);
    }
    swap(&a[low], &a[j]);
    return j;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pIndex = partition(a, low, high);
        quickSort(a, low, pIndex - 1);
        quickSort(a, pIndex + 1, high);
    }
}

int main() {
    int n, i;
    clock_t start, end;

    printf("Enter number of elements (N): ");
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));

    // Generating random numbers for sorting
    for (i = 0; i < n; i++) a[i] = rand() % 10000;

    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();

    int clocktaken = (int) end - start;

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted first 5 elements: ");
    for (i = 0; i < 5 && i < n; i++) printf("%d ", a[i]);

    printf("\n\nTime taken for N=%d: %f seconds\n", n, time_taken);
    printf("CLock taken for N=%d: %d clock\n", n, clocktaken);

    free(a);
    return 0;
}

