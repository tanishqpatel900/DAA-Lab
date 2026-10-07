#include <stdio.h>
#define INF 999999
// Tanishq patel PRN 26070521506
int n, a[15][15], dp[1<<15][15];

int tsp(int mask, int pos) {
    if (mask == (1<<n)-1)
        return a[pos][0] == -1 ? INF : a[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for (int i = 0; i < n; i++)
        if (!(mask & (1<<i)) && a[pos][i] != -1) {
            int x = a[pos][i] + tsp(mask|(1<<i), i);
            if (x < ans) ans = x;
        }

    return dp[mask][pos] = ans;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < (1<<n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    printf("%d", tsp(1, 0));
    return 0;
}
