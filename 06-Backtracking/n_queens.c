// Tanishq patel PRN 26070521506
// N-Queens Problem using Backtracking
#include <stdio.h>
#include <stdlib.h>

int x[20], n, count = 0;

int place(int k, int i) {
    for (int j = 1; j < k; j++)
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) return 0;
    return 1;
}

void printBoard() {
    printf("Solution %d:\n", ++count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%c ", x[i] == j ? 'Q' : '.');
        printf("\n");
    }
    printf("\n");
}

void nQueens(int k) {
    for (int i = 1; i <= n; i++)
        if (place(k, i)) {
            x[k] = i;
            if (k == n) printBoard();
            else nQueens(k + 1);
        }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);
    nQueens(1);
    printf("Total solutions = %d\n", count);
    return 0;
}
