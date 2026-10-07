// Tanishq patel PRN 26070521506
// Breadth First Search traversal - O(V^2) with adjacency matrix
#include <stdio.h>

int main() {
    int n, g[20][20], visited[20] = {0}, queue[20], front = 0, rear = 0, src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &src);

    printf("BFS traversal: ");
    queue[rear++] = src;
    visited[src] = 1;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++)
            if (g[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
    }
    printf("\n");
    return 0;
}
