// Tanishq patel PRN 26070521506
// Job Sequencing with Deadlines using Greedy method - sort by profit
#include <stdio.h>

int main() {
    int n, d[50], p[50], id[50], slot[50], maxD = 0, total = 0;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    printf("Enter deadline and profit of each job:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &d[i], &p[i]);
        id[i] = i + 1;
        if (d[i] > maxD) maxD = d[i];
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j] < p[j + 1]) {
                int t;
                t = p[j]; p[j] = p[j + 1]; p[j + 1] = t;
                t = d[j]; d[j] = d[j + 1]; d[j + 1] = t;
                t = id[j]; id[j] = id[j + 1]; id[j + 1] = t;
            }

    for (int i = 1; i <= maxD; i++) slot[i] = 0;
    for (int i = 0; i < n; i++)
        for (int k = d[i]; k >= 1; k--)
            if (slot[k] == 0) {
                slot[k] = id[i];
                total += p[i];
                break;
            }

    printf("Job sequence: ");
    for (int i = 1; i <= maxD; i++)
        if (slot[i]) printf("J%d ", slot[i]);
    printf("\nMaximum profit = %d\n", total);
    return 0;
}
