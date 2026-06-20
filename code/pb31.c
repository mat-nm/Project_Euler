#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int p = 200;
const int n = 8;

void dp_2coin() {
    int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    int *m = calloc(p+1, sizeof(int));
    m[0] = 1; m[1] = 1;
    for (int i = 0; i < 8; i++) {
        for (int s = 2; s <= p; s++) {
            if (coins[i] <= s) {
                m[s] += m[s-coins[i]];
            }
        }
    }
    printf("%d\n", m[p]);
}

int main() {
    dp_2coin();
}