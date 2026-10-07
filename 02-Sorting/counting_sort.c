// Tanishq patel PRN 26070521506
// Counting Sort - O(n + k), for non-negative integers
#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n) {
    if (n <= 0) return;
    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i];
    int *count = calloc(max + 1, sizeof(int));
    int *out = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) count[a[i]]++;
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) out[--count[a[i]]] = a[i];
    for (int i = 0; i < n; i++) a[i] = out[i];
    free(count); free(out);
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
