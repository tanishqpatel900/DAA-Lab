// Tanishq patel PRN 26070521506
// Longest Increasing Subsequence using Dynamic Programming - O(n^2)
#include <stdio.h>

int main() {
    int n, a[100], L[100], prev[100], best = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        L[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && L[j] + 1 > L[i]) { L[i] = L[j] + 1; prev[i] = j; }
        if (L[i] > L[best]) best = i;
    }

    int seq[100], len = 0;
    for (int i = best; i != -1; i = prev[i]) seq[len++] = a[i];
    printf("Length of LIS = %d\nLIS: ", len);
    for (int i = len - 1; i >= 0; i--) printf("%d ", seq[i]);
    printf("\n");
    return 0;
}
