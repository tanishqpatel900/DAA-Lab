// Tanishq patel PRN 26070521506
// Maximum Subarray Sum using Divide and Conquer - O(n log n)
#include <stdio.h>
#include <limits.h>

int max2(int a, int b) { return a > b ? a : b; }
int max3(int a, int b, int c) { return max2(max2(a, b), c); }

int crossSum(int a[], int l, int m, int h) {
    int sum = 0, left = INT_MIN, right = INT_MIN;
    for (int i = m; i >= l; i--) { sum += a[i]; if (sum > left) left = sum; }
    sum = 0;
    for (int i = m + 1; i <= h; i++) { sum += a[i]; if (sum > right) right = sum; }
    return left + right;
}

int maxSubArray(int a[], int l, int h) {
    if (l == h) return a[l];
    int m = (l + h) / 2;
    return max3(maxSubArray(a, l, m), maxSubArray(a, m + 1, h), crossSum(a, l, m, h));
}

int main() {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Maximum subarray sum = %d\n", maxSubArray(a, 0, n - 1));
    return 0;
}
