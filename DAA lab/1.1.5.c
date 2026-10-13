#include <stdio.h>

int a[20], s[20], ans[100][20], size[100];
int n, target, count = 0;

void find(int i, int sum, int k) {
    if (i == n) {
        if (sum == target) {
            for (int j = 0; j < k; j++)
                ans[count][j] = s[j];
            size[count++] = k;
        }
        return;
    }

    s[k] = a[i];
    find(i + 1, sum + a[i], k + 1);
    find(i + 1, sum, k);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &target);

    find(0, 0, 0);

    if (count == 0) {
        printf("-1");
    } else {
        for (int i = count - 1; i >= 0; i--) {
            for (int j = 0; j < size[i]; j++)
                printf("%d ", ans[i][j]);
}