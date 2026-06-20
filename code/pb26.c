#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define m 1000

int cycle_length(int d) {
    int seen[m];
    for (int i = 0; i < m; i++) {
        seen[i] = -1;
    }
    int n = 1;
    int cmp = 0;
    while (n > 0) {
        int q = n / d;
        int r = n - q*d;
        if (r == 0) { return -1; }
        if (seen[r] != -1) {
            return cmp - seen[r];
        }
        seen[r] = cmp++;
        n = r * 10;
        // printf("q = %d  r = %d  n = %d\n", q, r, n);
    }
    return -1;
}

void solve() { 
    int s = 7; int ls = 6;
    for (int d = 8; d < m; d++) {
        int ld = cycle_length(d);
        if (ld > ls) {
            s = d; ls = ld;
        }
    }
    printf("d = %d pour un cycle de longeur %d\n", s, ls);
}


int main() {
    // printf("%d\n%d\n", cycle_length(9), cycle_length(10));
    solve();
}