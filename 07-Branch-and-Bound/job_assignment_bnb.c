// Tanishq patel PRN 26070521506
// Job Assignment Problem using Branch and Bound
// assigns n workers to n jobs minimising total cost
#include <stdio.h>
#define INF 999999

int n, cost[15][15], assigned[15], best[15], cur[15], minCost = INF;

// lower bound: current cost + cheapest free job for each remaining worker
int lowerBound(int worker, int cc) {
    int lb = cc;
    for (int i = worker; i < n; i++) {
        int m = INF;
        for (int j = 0; j < n; j++)
            if (!assigned[j] && cost[i][j] < m) m = cost[i][j];
        lb += m;
    }
    return lb;
}

void solve(int worker, int cc) {
    if (worker == n) {
        if (cc < minCost) {
            minCost = cc;
            for (int i = 0; i < n; i++) best[i] = cur[i];
        }
        return;
    }
    for (int j = 0; j < n; j++)
        if (!assigned[j]) {
            assigned[j] = 1;
            cur[worker] = j;
            if (lowerBound(worker + 1, cc + cost[worker][j]) < minCost)
                solve(worker + 1, cc + cost[worker][j]);
            assigned[j] = 0;
        }
}

int main() {
    printf("Enter number of workers/jobs: ");
    scanf("%d", &n);
    printf("Enter cost matrix (rows = workers, columns = jobs):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &cost[i][j]);
    solve(0, 0);
    for (int i = 0; i < n; i++) printf("Worker %d -> Job %d\n", i + 1, best[i] + 1);
    printf("Minimum cost = %d\n", minCost);
    return 0;
}
