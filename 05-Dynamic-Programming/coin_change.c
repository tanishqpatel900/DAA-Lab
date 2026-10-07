// Tanishq patel PRN 26070521506
// Coin Change using Dynamic Programming - number of ways and minimum coins
#include <stdio.h>
#define INF 999999

int main() {
    int n, amt, c[50];
    long long ways[10001];
    int minc[10001];
    printf("Enter number of coin types: ");
    scanf("%d", &n);
    printf("Enter coin values: ");
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    printf("Enter amount: ");
    scanf("%d", &amt);

    for (int i = 0; i <= amt; i++) { ways[i] = 0; minc[i] = INF; }
    ways[0] = 1;
    minc[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = c[i]; j <= amt; j++) {
            ways[j] += ways[j - c[i]];
            if (minc[j - c[i]] + 1 < minc[j]) minc[j] = minc[j - c[i]] + 1;
        }

    printf("Number of ways = %lld\n", ways[amt]);
    if (minc[amt] == INF) printf("Amount cannot be formed\n");
    else printf("Minimum coins needed = %d\n", minc[amt]);
    return 0;
}
