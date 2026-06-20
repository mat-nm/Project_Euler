#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


const uint64_t max = 1000000;

uint64_t next(uint64_t previous) {
    if (previous % 2 == 0) return previous / 2;
    return 3*previous+1;
}


void solution() {
    uint64_t n = 1; uint64_t res = 13; uint64_t max_count = 10;
    while (n <= max) {
        uint64_t count = 1;
        uint64_t m = n;
        while (m < UINT64_MAX) {
            uint64_t new = next(m);
            //printf("%lu\n", new);
            if (new == 1) { count++; break; }
            count++; m = new;
        }
        //printf("count of %lu: %lu\n", n, count);
        if (count > max_count) { res = n; max_count = count; }
        n++;
    }
    printf("max count: %lu\n", max_count);
    printf("%lu\n", res);
}

int main() {
    solution();
}