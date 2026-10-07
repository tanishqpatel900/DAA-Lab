// Tanishq patel PRN 26070521506
// Graph Coloring (m-coloring) Problem using Backtracking
#include <stdio.h>

int g[20][20], x[20], n, m, count = 0;

int isSafe(int k, int c) {
    for (int i = 0; i < n; i++)
        if (g[k][i] && x[i] == c) return 0;
    return 1;
}

void colour(int k) {
    for (int c = 1; c <= m; c++)
        if (isSafe(k, c)) {
            x[k] = c;
            if (k == n - 1) {
                printf("Solution %d: ", ++count);
                for (int i = 0; i < n; i++) printf("%d ", x[i]);
                printf("\n");
            } else {
                colour(k + 1);
            }
            x[k] = 0;
        }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
    printf("Enter number of colours: ");
    scanf("%d", &m);
    colour(0);
    if (!count) printf("Graph cannot be coloured with %d colours\n", m);
    else printf("Total solutions = %d\n", count);
    return 0;
}
