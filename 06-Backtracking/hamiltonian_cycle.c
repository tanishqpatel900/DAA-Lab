// Tanishq patel PRN 26070521506
// Hamiltonian Cycle Problem using Backtracking
#include <stdio.h>

int g[20][20], path[20], visited[20], n, count = 0;

void hamiltonian(int k) {
    for (int v = 1; v < n; v++)
        if (!visited[v] && g[path[k - 1]][v]) {
            path[k] = v;
            visited[v] = 1;
            if (k == n - 1) {
                if (g[v][path[0]]) {
                    printf("Cycle %d: ", ++count);
                    for (int i = 0; i < n; i++) printf("%d ", path[i]);
                    printf("%d\n", path[0]);
                }
            } else {
                hamiltonian(k + 1);
            }
            visited[v] = 0;
        }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
    path[0] = 0;
    visited[0] = 1;
    if (n == 1) { printf("Single vertex, trivial cycle\n"); return 0; }
    hamiltonian(1);
    if (!count) printf("No Hamiltonian cycle exists\n");
    return 0;
}
