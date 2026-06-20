#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int s = 10000;

bool is_prime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int *h = calloc(s+1, sizeof (int));
    for (int n = 2; n < s; n++) {
        bool b = is_prime(n);
        if (b) { h[n] = true; }
        else {
            bool found = false; int p = 2;
            while (!found && p <= n) {
                if (!h[p]) { p++; continue; }
                int m = (int)sqrt((n-p)/2);
                if (m*m == ((n-p)/2)) { found = true; }
                p++;
            }
            if (!found) { printf("n = %d\n", n); return; }
        }
        
    }
}

int main() {
    solve();
}

