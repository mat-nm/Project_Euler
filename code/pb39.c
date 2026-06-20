#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int m = 1000;

int prt(int p) {
    int r = 0;
    for (int a = 1; a < m; a++) {
        for (int b = 1; b < m; b++) {
            int c = p - a - b;
            if (c > 0 && (a*a == c*c + b*b)) {
                r++;
            }
        }
    }
    return r;
}

void solve() {
    int re = 3, res = 120;
    for (int p = 1; p <= m; p++) {
        int r = prt(p);
        if (r > re) { re = r; res = p; }
    }
    printf("%d\n", res);
}

int main() {
    solve();
}