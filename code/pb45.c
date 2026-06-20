#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long ullong;
int lo = 143;

bool is_triangular(ullong n) {
    ullong m = (ullong) sqrt(n*2);
    return n == m*(m+1)/2;
}

bool is_pentagonal(ullong n) {
    ullong m = (ullong) (1+sqrt(1+24*n)/6);
    return n == m*(3*m-1) / 2;
}

void solve() {
    for (ullong n = lo+1; n < (ullong)sqrt(UINT64_MAX); n++) {
        ullong h = n*(2*n-1);
        if (is_pentagonal(h) && is_triangular(h)) {
            printf("%llu\n", h);
            return;
        }
    } 
}

int main() {
    solve();
}

