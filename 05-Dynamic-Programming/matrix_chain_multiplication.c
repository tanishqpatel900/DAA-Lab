// Tanishq patel PRN 26070521506
// Matrix Chain Multiplication using Dynamic Programming - O(n^3)
#include <stdio.h>
#include <limits.h>

int m[20][20], s[20][20];

void printOrder(int i, int j) {
    if (i == j) { printf("A%d", i); return; }
    printf("(");
    printOrder(i, s[i][j]);
    printOrder(s[i][j] + 1, j);
    printf(")");
}

int main() {
    int n, p[21];
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter %d dimensions: ", n + 1);
    for (int i = 0; i <= n; i++) scanf("%d", &p[i]);

    for (int i = 1; i <= n; i++) m[i][i] = 0;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) { m[i][j] = cost; s[i][j] = k; }
            }
        }

    printf("Minimum number of multiplications = %d\n", m[1][n]);
    printf("Optimal parenthesization: ");
    printOrder(1, n);
    printf("\n");
    return 0;
}
