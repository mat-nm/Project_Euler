#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long *square_table(long *a, int n) {
    for (long i = 0; i < n; i++) {
        a[i] = i * i;
    }
    return a;
}


int main(void) {
    long *c = calloc(1000, sizeof(long));
    square_table(c, 1000);
    for (long i = 0; i < 1000; i++) {
        for (long j = 0; j < i; j++) {
            for (long k = 0; k < j; k++) {
                if (c[i] == (c[j] + c[k])) { 
                    if (i + j + k == 1000) {
                        long res;
                        res = i * j * k;
                        printf("c = %ld\nb = %ld\na = %ld\n", i, j, k);
                        printf("produit = %ld\n", res);
                        free(c);
                        return 0;
                    }
                }
            }
        }
    }
    free(c);
    return 0;
}