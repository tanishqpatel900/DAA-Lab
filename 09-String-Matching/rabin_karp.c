// Tanishq patel PRN 26070521506
// Rabin-Karp String Matching using rolling hash - O(n + m) average
#include <stdio.h>
#include <string.h>
#define D 256
#define Q 101

int main() {
    char text[1000], pat[100];
    int found = 0;
    printf("Enter text: ");
    scanf(" %999[^\n]", text);
    printf("Enter pattern: ");
    scanf(" %99[^\n]", pat);
    int n = strlen(text), m = strlen(pat), p = 0, t = 0, h = 1;
    if (m > n) { printf("Pattern not found\n"); return 0; }

    for (int i = 0; i < m - 1; i++) h = (h * D) % Q;
    for (int i = 0; i < m; i++) {
        p = (D * p + pat[i]) % Q;
        t = (D * t + text[i]) % Q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t && strncmp(text + i, pat, m) == 0) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
        if (i < n - m) {
            t = (D * (t - text[i] * h) + text[i + m]) % Q;
            if (t < 0) t += Q;
        }
    }
    if (!found) printf("Pattern not found\n");
    return 0;
}
