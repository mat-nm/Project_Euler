#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


bool is_prime(long a) {
    for (int i = 2; i*i <= a; i++) {
        if (a%i == 0) return false;
    }
    return true;
}

int main() {
    long a = 3;
    long long sum = 2;
    while (a < 2000000) {
        if (is_prime(a)) {
            sum += a;
        }
        a+=2;
    }
    printf("%lld\n", sum);
    return 0;
}
