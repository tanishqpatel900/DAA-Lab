// Tanishq patel PRN 26070521506
// Generate all subsets (power set) using Backtracking
#include <stdio.h>

int a[20], x[20], n;

void subsets(int k) {
    if (k == n) {
        printf("{ ");
        for (int i = 0; i < n; i++) if (x[i]) printf("%d ", a[i]);
        printf("}\n");
        return;
    }
    x[k] = 1;
    subsets(k + 1);
    x[k] = 0;
    subsets(k + 1);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    subsets(0);
    return 0;
}
