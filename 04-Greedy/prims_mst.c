// Tanishq patel PRN 26070521506
// Prim's Algorithm for Minimum Spanning Tree - O(V^2), 0 means no edge
#include <stdio.h>
#define INF 999999

int main() {
    int n, g[20][20], key[20], parent[20], inMST[20], cost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);

    for (int i = 0; i < n; i++) { key[i] = INF; inMST[i] = 0; parent[i] = -1; }
    key[0] = 0;

    for (int c = 0; c < n; c++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!inMST[v] && (u == -1 || key[v] < key[u])) u = v;
        inMST[u] = 1;
        for (int v = 0; v < n; v++)
            if (g[u][v] && !inMST[v] && g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d   %d\n", parent[i], i, g[i][parent[i]]);
        cost += g[i][parent[i]];
    }
    printf("Minimum cost = %d\n", cost);
    return 0;
}
