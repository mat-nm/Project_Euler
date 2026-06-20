#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// On commence à partir de 7 car aucun 8pan et 9pan n'est premier


long hi = 7654321; 
long lo = 1234567;

bool is_prime(long n) {
    for (long i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

bool is_pan(long p, int n) {
    int h[n+1];
    for (int i = 0; i < n+1; i++) {
        h[i] = 0;
    }
    int s = 0;
    while (p > 0) {
        long c = p % 10;
        h[c] += 1;
        p = p / 10;
        s++;
        // printf("c=%d  s=%d\n", c, s);
    }
    if (h[0] != 0 || s != n) { return false; }
    for (int i = 1; i < n+1; i++) {
        if (h[i] != 1) { return false; }
    }
    // printf("n = %d  i = %d\n", n, i);
    return true;
}

void solve() {
    for (long i = hi; i >= lo; i -= 2) {
        if (is_prime(i) && is_pan(i, 7)) {
            printf("res = %ld\n", i); return;
        }
    }
    printf("Not found\n");
}

int main() {
    solve();
    //printf("%d %d %d\n", is_pan(324517869, 9), is_pan(lo, 9), is_pan(12346, 5));
}