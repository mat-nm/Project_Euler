#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {
    long n = 20;
    long k = 3;
    long m[n][n];
    int sx;
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            sx = scanf("%ld", &m[i][j]);
            assert(sx == 1);
        }
    }
    long res = 0;
    // right diag
    for (long i = 0; i < n-k; i++) {
        for (long j = 0; j < n-k; j++) {
            long cand = m[i][j] * m[i+1][j+1] * m[i+2][j+2] * m[i+3][j+3]; 
            if (cand > res) { res = cand; }
        }
    }
    // up
    for (long i = 0; i < n-k; i++) {
        for (long j = 0; j < n; j++) {
            long cand = m[i][j] * m[i+1][j] * m[i+2][j] * m[i+3][j]; 
            if (cand > res) { res = cand; }
        }
    }
    // left diag
    for (long i = 0; i < n-k; i++) {
        for (long j = k+1; j < n; j++) {
            long cand = m[i][j] * m[i+1][j-1] * m[i+2][j-2] * m[i+3][j-3]; 
            if (cand > res) { res = cand; }
        }
    }

    printf("result = %ld\n", res);
}