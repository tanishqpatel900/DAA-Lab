// Tanishq patel PRN 26070521506
// Activity Selection Problem using Greedy method - sort by finish time
#include <stdio.h>

int main() {
    int n, s[50], f[50], id[50];
    printf("Enter number of activities: ");
    scanf("%d", &n);
    printf("Enter start and finish time of each activity:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s[i], &f[i]);
        id[i] = i + 1;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (f[j] > f[j + 1]) {
                int t;
                t = f[j]; f[j] = f[j + 1]; f[j + 1] = t;
                t = s[j]; s[j] = s[j + 1]; s[j + 1] = t;
                t = id[j]; id[j] = id[j + 1]; id[j + 1] = t;
            }

    int count = 1, last = 0;
    printf("Selected activities: A%d ", id[0]);
    for (int i = 1; i < n; i++)
        if (s[i] >= f[last]) {
            printf("A%d ", id[i]);
            last = i;
            count++;
        }
    printf("\nTotal activities selected = %d\n", count);
    return 0;
}
