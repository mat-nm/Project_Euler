#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


bool is_prime(int n) {
    if (n <= 1) { return false; }
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0)
            return false;
    }
    return true;
}

int test(int a, int b) {
    int n = 0;
    while (is_prime(n*n + a*n + b)) {
        n++;
    }
    return n;
}

void solve() {
    int max = 41, maxa = 1, maxb = 41;
    for (int b = 2; b <= 1000; b++) {
        for (int a = -999; a < 1000; a++) {
            int m = test(a, b);
            if (m > max) {
                max = m; maxa = a; maxb = b;
            }
        }
    }
    // printf("maxa: %d maxb: %d\n", maxa, maxb);
    printf("%d\n", maxa*maxb);
}


int main() {
    solve();
}