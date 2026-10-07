// Tanishq patel PRN 26070521506
// Linear Search - O(n)
#include <stdio.h>

int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

int main() {
    int n, key, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter key to search: ");
    scanf("%d", &key);
    int pos = linearSearch(a, n, key);
    if (pos == -1) printf("Element not found\n");
    else printf("Element found at index %d\n", pos);
    return 0;
}
