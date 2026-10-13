#include <stdio.h>

int main() {
    int n, W;
    scanf("%d", &n);

    int v[n], wt[n], dp[1001] = {0};

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    scanf("%d", &W);

    for (int i = 0; i < n; i++)
        for (int j = W; j >= wt[i]; j--)
            if (dp[j] < dp[j - wt[i]] + v[i])
                dp[j] = dp[j - wt[i]] + v[i];

    printf("%d", dp[W]);

    return 0;
}