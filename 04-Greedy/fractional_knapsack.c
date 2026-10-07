// Tanishq patel PRN 26070521506
// Fractional Knapsack using Greedy method - sort by profit/weight ratio
#include <stdio.h>

int main() {
    int n;
    float w[50], p[50], r[50], cap, total = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &w[i], &p[i]);
        r[i] = p[i] / w[i];
    }
    printf("Enter knapsack capacity: ");
    scanf("%f", &cap);

    // sort items by ratio in descending order
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (r[j] < r[j + 1]) {
                float t;
                t = r[j]; r[j] = r[j + 1]; r[j + 1] = t;
                t = w[j]; w[j] = w[j + 1]; w[j + 1] = t;
                t = p[j]; p[j] = p[j + 1]; p[j + 1] = t;
            }

    for (int i = 0; i < n && cap > 0; i++) {
        if (w[i] <= cap) {
            total += p[i];
            cap -= w[i];
            printf("Item (w=%.1f, p=%.1f) taken fully\n", w[i], p[i]);
        } else {
            total += r[i] * cap;
            printf("Item (w=%.1f, p=%.1f) taken fraction %.2f\n", w[i], p[i], cap / w[i]);
            cap = 0;
        }
    }
    printf("Maximum profit = %.2f\n", total);
    return 0;
}
