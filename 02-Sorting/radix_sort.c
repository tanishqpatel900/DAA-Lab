// Tanishq patel PRN 26070521506
// Radix Sort (LSD) - O(d * (n + 10)), for non-negative integers
#include <stdio.h>
#include <stdlib.h>

void countSortByDigit(int a[], int n, int exp) {
    int *out = malloc(n * sizeof(int)), count[10] = {0};
    for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) out[--count[(a[i] / exp) % 10]] = a[i];
    for (int i = 0; i < n; i++) a[i] = out[i];
    free(out);
}

void sort(int a[], int n) {
    if (n <= 0) return;
    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i];
    for (int exp = 1; max / exp > 0; exp *= 10) countSortByDigit(a, n, exp);
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
