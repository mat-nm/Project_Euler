#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


bool is_prime(long a) {
    for (int i = 2; i*i <= a; i++) {
        if (a%i == 0) return false;
    }
    return true;
}

long max_long_array(long a[], int n) {
    long m = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > m) m = a[i];
    }
    return m;
}

int main() {
    long *primes = calloc(10001, sizeof(long));
    int i = 1;
    long a = 3;
    while (i < 10002 && a < __LONG_MAX__) {
        if (is_prime(a)) {
            primes[i++] = a;
        }
        a+=2;
    }
    printf("%ld\n", primes[6]);
    printf("%ld\n", primes[10000]);
    free(primes);
}
