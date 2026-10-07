// Tanishq patel PRN 26070521506
// Kruskal's Algorithm for Minimum Spanning Tree using Union-Find - O(E log E)
#include <stdio.h>

typedef struct { int u, v, w; } Edge;

int parent[100];

int find(int x) {
    while (parent[x] != x) x = parent[x] = parent[parent[x]];
    return x;
}

int main() {
    int n, e, cost = 0, count = 0;
    Edge edges[200];
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    printf("Enter edges (u v weight), vertices numbered from 0:\n");
    for (int i = 0; i < e; i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (int i = 0; i < e - 1; i++)
        for (int j = 0; j < e - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                Edge t = edges[j]; edges[j] = edges[j + 1]; edges[j + 1] = t;
            }

    for (int i = 0; i < n; i++) parent[i] = i;

    printf("Edges in MST:\n");
    for (int i = 0; i < e && count < n - 1; i++) {
        int a = find(edges[i].u), b = find(edges[i].v);
        if (a != b) {
            parent[a] = b;
            printf("%d - %d   %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            count++;
        }
    }
    printf("Minimum cost = %d\n", cost);
    return 0;
}
