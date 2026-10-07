// Tanishq patel PRN 26070521506
// 0/1 Knapsack using Branch and Bound (best-first with fractional upper bound)
#include <stdio.h>

int n, W;
float w[50], p[50], maxProfit = 0;
int best[50], cur[50];

// upper bound: greedy fractional fill from item k onwards
float bound(int k, float cw, float cp) {
    float b = cp;
    for (int i = k; i < n; i++) {
        if (cw + w[i] <= W) { cw += w[i]; b += p[i]; }
        else return b + (W - cw) * p[i] / w[i];
    }
    return b;
}

void branch(int k, float cw, float cp) {
    if (k == n) {
        if (cp > maxProfit) {
            maxProfit = cp;
            for (int i = 0; i < n; i++) best[i] = cur[i];
        }
        return;
    }
    if (cw + w[k] <= W) {
        cur[k] = 1;
        branch(k + 1, cw + w[k], cp + p[k]);
    }
    cur[k] = 0;
    if (bound(k + 1, cw, cp) > maxProfit) branch(k + 1, cw, cp);
}

int main() {
    int id[50];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item:\n");
    for (int i = 0; i < n; i++) { scanf("%f %f", &w[i], &p[i]); id[i] = i + 1; }
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // sort by profit/weight ratio for a tight bound
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j] / w[j] < p[j + 1] / w[j + 1]) {
                float t; int ti;
                t = p[j]; p[j] = p[j + 1]; p[j + 1] = t;
                t = w[j]; w[j] = w[j + 1]; w[j + 1] = t;
                ti = id[j]; id[j] = id[j + 1]; id[j + 1] = ti;
            }

    branch(0, 0, 0);
    printf("Maximum profit = %.0f\nItems selected: ", maxProfit);
    for (int i = 0; i < n; i++) if (best[i]) printf("%d ", id[i]);
    printf("\n");
    return 0;
}
