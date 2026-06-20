#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void solve(int n) {
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (i%3 == 0 || i%5 == 0)
            res += i;
    }
    printf("The sum is %d\n", res);
}


int main() {
    solve(1000);
}