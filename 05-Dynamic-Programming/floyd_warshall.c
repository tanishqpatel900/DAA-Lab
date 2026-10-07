// Tanishq patel PRN 26070521506
// Floyd-Warshall All Pairs Shortest Path - O(V^3), use 999 for infinity
#include <stdio.h>
#define INF 999

int main() {
    int n, d[20][20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (%d for no edge):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &d[i][j]);

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("All pairs shortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == INF) printf("INF ");
            else printf("%3d ", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
