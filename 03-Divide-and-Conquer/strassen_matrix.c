// Tanishq patel PRN 26070521506
// Strassen's Matrix Multiplication for 2x2 matrices - 7 multiplications instead of 8
#include <stdio.h>

int main() {
    int a[2][2], b[2][2], c[2][2];
    printf("Enter elements of 2x2 matrix A: ");
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) scanf("%d", &a[i][j]);
    printf("Enter elements of 2x2 matrix B: ");
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) scanf("%d", &b[i][j]);

    int m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    int m2 = (a[1][0] + a[1][1]) * b[0][0];
    int m3 = a[0][0] * (b[0][1] - b[1][1]);
    int m4 = a[1][1] * (b[1][0] - b[0][0]);
    int m5 = (a[0][0] + a[0][1]) * b[1][1];
    int m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    int m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = m1 + m4 - m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;

    printf("Product matrix C:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
