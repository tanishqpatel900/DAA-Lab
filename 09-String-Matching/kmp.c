// Tanishq patel PRN 26070521506
// Knuth-Morris-Pratt String Matching - O(n + m)
#include <stdio.h>
#include <string.h>

void computeLPS(char pat[], int m, int lps[]) {
    int len = 0;
    lps[0] = 0;
    for (int i = 1; i < m;) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
}

int main() {
    char text[1000], pat[100];
    int lps[100], found = 0;
    printf("Enter text: ");
    scanf(" %999[^\n]", text);
    printf("Enter pattern: ");
    scanf(" %99[^\n]", pat);
    int n = strlen(text), m = strlen(pat);
    computeLPS(pat, m, lps);

    for (int i = 0, j = 0; i < n;) {
        if (text[i] == pat[j]) {
            i++; j++;
            if (j == m) {
                printf("Pattern found at index %d\n", i - j);
                found = 1;
                j = lps[j - 1];
            }
        } else if (j) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    if (!found) printf("Pattern not found\n");
    return 0;
}
