// Tanishq patel PRN 26070521506
// Shell Sort - gap insertion sort
#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int t = a[i], j;
            for (j = i; j >= gap && a[j - gap] > t; j -= gap) a[j] = a[j - gap];
            a[j] = t;
        }
}

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
