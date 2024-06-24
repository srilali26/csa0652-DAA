#include <stdio.h>
#include <stdlib.h>

void add(int n, int a[n][n], int b[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtract(int n, int a[n][n], int b[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void strassen(int n, int a[n][n], int b[n][n], int c[n][n]) {
    if (n == 1) {
        c[0][0] = a[0][0] * b[0][0];
        return;
    }

    int new_size = n / 2;
    int a11[new_size][new_size], a12[new_size][new_size], a21[new_size][new_size], a22[new_size][new_size];
    int b11[new_size][new_size], b12[new_size][new_size], b21[new_size][new_size], b22[new_size][new_size];
    int c11[new_size][new_size], c12[new_size][new_size], c21[new_size][new_size], c22[new_size][new_size];
    int m1[new_size][new_size], m2[new_size][new_size], m3[new_size][new_size], m4[new_size][new_size];
    int m5[new_size][new_size], m6[new_size][new_size], m7[new_size][new_size];
    int temp1[new_size][new_size], temp2[new_size][new_size];

    for (int i = 0; i < new_size; i++) {
        for (int j = 0; j < new_size; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + new_size];
            a21[i][j] = a[i + new_size][j];
            a22[i][j] = a[i + new_size][j + new_size];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + new_size];
            b21[i][j] = b[i + new_size][j];
            b22[i][j] = b[i + new_size][j + new_size];
        }
    }

    add(new_size, a11, a22, temp1);
    add(new_size, b11, b22, temp2);
    strassen(new_size, temp1, temp2, m1);

    add(new_size, a21, a22, temp1);
    strassen(new_size, temp1, b11, m2);

    subtract(new_size, b12, b22, temp2);
    strassen(new_size, a11, temp2, m3);

    subtract(new_size, b21, b11, temp2);
    strassen(new_size, a22, temp2, m4);

    add(new_size, a11, a12, temp1);
    strassen(new_size, temp1, b22, m5);

    subtract(new_size, a21, a11, temp1);
    add(new_size, b11, b12, temp2);
    strassen(new_size, temp1, temp2, m6);

    subtract(new_size, a12, a22, temp1);
    add(new_size, b21, b22, temp2);
    strassen(new_size, temp1, temp2, m7);

    add(new_size, m1, m4, temp1);
    subtract(new_size, temp1, m5, temp2);
    add(new_size, temp2, m7, c11);

    add(new_size, m3, m5, c12);

    add(new_size, m2, m4, c21);

    add(new_size, m1, m3, temp1);
    subtract(new_size, temp1, m2, temp2);
    add(new_size, temp2, m6, c22);

    for (int i = 0; i < new_size; i++) {
        for (int j = 0; j < new_size; j++) {
            c[i][j] = c11[i][j];
            c[i][j + new_size] = c12[i][j];
            c[i + new_size][j] = c21[i][j];
            c[i + new_size][j + new_size] = c22[i][j];
        }
    }
}

int main() {
    int n = 2; // Matrix size (must be a power of 2 for simplicity)
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2];

    strassen(n, a, b, c);

    printf("Resultant matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

