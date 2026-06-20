#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ep = 0.0001;

int gcd(int u, int v) {
    while (v > 0) {
        int t = v;
        v = u%v;
        u = t;
    }
    return u;
}

void solve() {
    int num = 1, denom = 1;
    for (int a = 1; a < 10; a++) {
        for (int b = a; b < 10; b++) {
            for (int c = 1; c < 10; c++) {
                if (abs( (10*a+b)*c - a*(10*b +c)) < ep) {
                    num *= a; denom *= c;
                }
            }
        }
    }
    printf("%d\n", (int)(denom/gcd(num, denom)));
    return;
}

int main() {
    solve();
}

