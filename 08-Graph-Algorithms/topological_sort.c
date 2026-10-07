// Tanishq patel PRN 26070521506
// Topological Sort using Kahn's algorithm (in-degree / source removal)
#include <stdio.h>

int main() {
    int n, g[20][20], indeg[20] = {0}, queue[20], front = 0, rear = 0, count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix of the directed graph:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j]) indeg[j]++;
        }

    for (int i = 0; i < n; i++) if (indeg[i] == 0) queue[rear++] = i;
    printf("Topological order: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;
        for (int v = 0; v < n; v++)
            if (g[u][v] && --indeg[v] == 0) queue[rear++] = v;
    }
    printf("\n");
    if (count != n) printf("Graph has a cycle, topological sort not possible\n");
    return 0;
}
