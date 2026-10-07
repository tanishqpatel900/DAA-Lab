// Tanishq patel PRN 26070521506
// Binary Search (iterative and recursive) - O(log n), array must be sorted
#include <stdio.h>

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRec(int a[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key) return binarySearchRec(a, mid + 1, high, key);
    return binarySearchRec(a, low, mid - 1, key);
}

int main() {
    int n, key, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter key to search: ");
    scanf("%d", &key);
    int pos = binarySearch(a, n, key);
    if (pos == -1) printf("Element not found\n");
    else printf("Iterative: element found at index %d\n", pos);
    printf("Recursive: index %d\n", binarySearchRec(a, 0, n - 1, key));
    return 0;
}
