#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// tanishq patel PRN-26070521506
struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    const long long INF = LLONG_MAX / 4;

    long long* dist = (long long*)malloc((V + 1) * sizeof(long long));
    int* parent = (int*)malloc((V + 1) * sizeof(int));

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    // Bellman-Ford Relaxation (Full V-1 passes)
    for (int i = 1; i <= V - 1; i++) {
}