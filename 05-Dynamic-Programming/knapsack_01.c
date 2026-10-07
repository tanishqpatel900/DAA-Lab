// Tanishq patel PRN 26070521506
// 0/1 Knapsack using Dynamic Programming - O(n * W)
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, W, w[50], p[50], dp[51][1001];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item:\n");
    for (int i = 1; i <= n; i++) scanf("%d %d", &w[i], &p[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (w[i] <= j) dp[i][j] = max(dp[i - 1][j], p[i] + dp[i - 1][j - w[i]]);
            else dp[i][j] = dp[i - 1][j];
        }

    printf("Maximum profit = %d\n", dp[n][W]);
    printf("Items selected: ");
    for (int i = n, j = W; i > 0; i--)
        if (dp[i][j] != dp[i - 1][j]) {
            printf("%d ", i);
            j -= w[i];
        }
    printf("\n");
    return 0;
}
