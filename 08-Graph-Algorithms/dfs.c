// Tanishq patel PRN 26070521506
// Depth First Search traversal (recursive) - O(V^2) with adjacency matrix
#include <stdio.h>

int n, g[20][20], visited[20];

void dfs(int u) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; v++)
        if (g[u][v] && !visited[v]) dfs(v);
}

int main() {
    int src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &src);
    printf("DFS traversal: ");
    dfs(src);
    printf("\n");
    return 0;
}
