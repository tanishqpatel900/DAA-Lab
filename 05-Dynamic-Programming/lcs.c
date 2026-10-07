// Tanishq patel PRN 26070521506
// Longest Common Subsequence using Dynamic Programming - O(m * n)
#include <stdio.h>
#include <string.h>

int main() {
    char x[100], y[100], lcs[100];
    int L[101][101];
    printf("Enter first string: ");
    scanf("%99s", x);
    printf("Enter second string: ");
    scanf("%99s", y);
    int m = strlen(x), n = strlen(y);

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) L[i][j] = 0;
            else if (x[i - 1] == y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
            else L[i][j] = L[i - 1][j] > L[i][j - 1] ? L[i - 1][j] : L[i][j - 1];
        }

    int idx = L[m][n];
    lcs[idx] = '\0';
    for (int i = m, j = n; i > 0 && j > 0;) {
        if (x[i - 1] == y[j - 1]) { lcs[--idx] = x[i - 1]; i--; j--; }
        else if (L[i - 1][j] > L[i][j - 1]) i--;
        else j--;
    }
    printf("Length of LCS = %d\nLCS = %s\n", L[m][n], lcs);
    return 0;
}
