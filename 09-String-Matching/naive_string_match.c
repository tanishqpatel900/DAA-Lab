// Tanishq patel PRN 26070521506
// Naive (Brute Force) String Matching - O((n - m + 1) * m)
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], pat[100];
    printf("Enter text: ");
    scanf(" %999[^\n]", text);
    printf("Enter pattern: ");
    scanf(" %99[^\n]", pat);
    int n = strlen(text), m = strlen(pat), found = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pat[j]) j++;
        if (j == m) { printf("Pattern found at index %d\n", i); found = 1; }
    }
    if (!found) printf("Pattern not found\n");
    return 0;
}
