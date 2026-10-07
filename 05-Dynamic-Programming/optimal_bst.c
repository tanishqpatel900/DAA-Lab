// Tanishq patel PRN 26070521506
// Optimal Binary Search Tree using Dynamic Programming - O(n^3)
#include <stdio.h>
#include <limits.h>

int main() {
    int n, keys[20], freq[20], cost[21][21], sum[21][21];
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter %d sorted keys: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &keys[i]);
    printf("Enter frequencies: ");
    for (int i = 0; i < n; i++) scanf("%d", &freq[i]);

    for (int i = 0; i < n; i++) {
        sum[i][i] = freq[i];
        for (int j = i + 1; j < n; j++) sum[i][j] = sum[i][j - 1] + freq[j];
    }

    for (int i = 0; i < n; i++) cost[i][i] = freq[i];
    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + sum[i][j];
                if (c < cost[i][j]) cost[i][j] = c;
            }
        }

    printf("Cost of optimal BST = %d\n", cost[0][n - 1]);
    return 0;
}
