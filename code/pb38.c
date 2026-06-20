#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int d = 9122;
int e = 9999;

bool is_pan(int n) {
    int h[10];
    for (int i = 0; i < 10; i++) {
        h[i] = 0;
    }
    int s = 0;
    int i = 0;
    while (s < 9) {
        ++i;
        int num = n*i;
        while (num > 0) {
            int c = num % 10;
            if (h[c] == 1 || c == 0) { return false; }
            h[c] = 1;
            num = num / 10;
            s++;
            // printf("c=%d  s=%d\n", c, s);
        }
                
    }
    // printf("n = %d  i = %d\n", n, i);
    return true;
}

void solve() {
    for (int i = e; i >= d; i--) {
        if (is_pan(i)) {
            printf("%d%d\n", i, 2*i); return;
        }
    }
}

int main() {
    solve();
}