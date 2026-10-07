// Tanishq patel PRN 26070521506
// Quick Sort (Divide and Conquer) - O(n log n) average, O(n^2) worst
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }

// Lomuto partition with last element as pivot
int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (a[j] < pivot) swap(&a[++i], &a[j]);
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void sort(int a[], int n) { quickSort(a, 0, n - 1); }

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
