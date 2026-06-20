#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define max 10000

void solution() {
    int *d = calloc(max+1, sizeof(int));
    for (int i = 0; i < max+1; i++) {
        for (int j = 1; j < i; j++) {
            if (i%j == 0) {
                d[i] += j;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < max+1; i++) {
        for (int j = 0; j < i; j++) {
            if (d[i] == j && d[j] == i) {
                res += i + j;
            }
        }
    }
    free(d);
    printf("%d\n", res);
}

int main() {
    solution();
}