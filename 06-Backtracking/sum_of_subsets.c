// Tanishq patel PRN 26070521506
// Sum of Subsets Problem using Backtracking
#include <stdio.h>

int w[50], x[50], n, target, found = 0;

// s = sum of chosen weights, k = current index, r = sum of remaining weights
void sumOfSubsets(int s, int k, int r) {
    if (k == n) return;
    x[k] = 1;
    if (s + w[k] == target) {
        found = 1;
        printf("{ ");
        for (int i = 0; i <= k; i++) if (x[i]) printf("%d ", w[i]);
        printf("}\n");
    } else if (k + 1 < n && s + w[k] + w[k + 1] <= target) {
        sumOfSubsets(s + w[k], k + 1, r - w[k]);
    }
    if (k + 1 < n && s + r - w[k] >= target && s + w[k + 1] <= target) {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k]);
    }
    x[k] = 0;
}

int main() {
    int total = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in increasing order: ", n);
    for (int i = 0; i < n; i++) { scanf("%d", &w[i]); total += w[i]; }
    printf("Enter required sum: ");
    scanf("%d", &target);
    printf("Subsets with sum %d:\n", target);
    if (n > 0 && w[0] <= target && total >= target) sumOfSubsets(0, 0, total);
    if (!found) printf("No subset found\n");
    return 0;
}
