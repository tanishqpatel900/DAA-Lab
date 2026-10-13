#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

	// Write your code here...
	     int parent[V];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edges = 0;
    int totalCost = 0;

    while (edges < V - 1) {
        int min = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (cost[i][j] != 9999 && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u == -1 || v == -1)
            break;

        // Find root of u
        int rootU = u;
}