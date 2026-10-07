// Tanishq patel PRN 26070521506
// Dijkstra's Single Source Shortest Path - O(V^2), 0 means no edge
#include <stdio.h>
#define INF 999999

int main() {
    int n, src, g[20][20], dist[20], visited[20], prev[20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (int i = 0; i < n; i++) { dist[i] = INF; visited[i] = 0; prev[i] = -1; }
    dist[src] = 0;

    for (int c = 0; c < n; c++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) u = v;
        if (dist[u] == INF) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (g[u][v] && !visited[v] && dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
                prev[v] = u;
            }
    }

    printf("Vertex  Distance  Path\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) { printf("%d       INF\n", i); continue; }
        printf("%d       %d        ", i, dist[i]);
        int path[20], len = 0;
        for (int v = i; v != -1; v = prev[v]) path[len++] = v;
        for (int k = len - 1; k >= 0; k--) printf("%d%s", path[k], k ? " -> " : "\n");
    }
    return 0;
}
