// Tanishq patel PRN 26070521506
// Find maximum and minimum using Divide and Conquer - about 3n/2 - 2 comparisons
#include <stdio.h>

int a[100];

void maxMin(int i, int j, int *max, int *min) {
    if (i == j) {
        *max = *min = a[i];
    } else if (i == j - 1) {
        if (a[i] < a[j]) { *max = a[j]; *min = a[i]; }
        else { *max = a[i]; *min = a[j]; }
    } else {
        int mid = (i + j) / 2, max1, min1;
        maxMin(i, mid, max, min);
        maxMin(mid + 1, j, &max1, &min1);
        if (max1 > *max) *max = max1;
        if (min1 < *min) *min = min1;
    }
}

int main() {
    int n, max, min;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    maxMin(0, n - 1, &max, &min);
    printf("Maximum = %d\nMinimum = %d\n", max, min);
    return 0;
}
