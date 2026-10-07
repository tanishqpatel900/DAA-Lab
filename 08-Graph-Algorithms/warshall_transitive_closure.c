// Tanishq patel PRN 26070521506
// Warshall's Algorithm for Transitive Closure - O(V^3)
#include <stdio.h>

int main() {
    int n, r[20][20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &r[i][j]);

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                r[i][j] = r[i][j] || (r[i][k] && r[k][j]);

    printf("Transitive closure:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
