// Tanishq patel PRN 26070521506
// Bellman-Ford Single Source Shortest Path (handles negative edges) - O(V * E)
#include <stdio.h>
#define INF 999999

int main() {
    int n, e, src, u[200], v[200], w[200], dist[100];
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    printf("Enter edges (u v weight), vertices numbered from 0:\n");
    for (int i = 0; i < e; i++) scanf("%d %d %d", &u[i], &v[i], &w[i]);
    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    for (int k = 1; k < n; k++)
        for (int i = 0; i < e; i++)
            if (dist[u[i]] != INF && dist[u[i]] + w[i] < dist[v[i]])
                dist[v[i]] = dist[u[i]] + w[i];

    for (int i = 0; i < e; i++)
        if (dist[u[i]] != INF && dist[u[i]] + w[i] < dist[v[i]]) {
            printf("Graph contains a negative weight cycle\n");
            return 0;
        }

    printf("Vertex  Distance\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("%d       INF\n", i);
        else printf("%d       %d\n", i, dist[i]);
    }
    return 0;
}
