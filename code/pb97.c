#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define Z 10000000000
#define P 7830457
#define M 28433

int a[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void solution() {
    for (int i = 1; i <= P; i++) {
        //int rest = 0;
        for (int j = 9; j >= 0; j--) {
            int tmp = a[j] * 2;
            a[j] = tmp % 10;
            if (j != 0) {
                if (tmp > 10) {
                    a[j-1] += tmp / 10;
                }
            }
        }
    }
    uint64_t res = a[0];
    for (int i = 1; i < 10; i++) {
        res = res * 10 + a[i];
        //printf("%d\n", a[i]);
    }
    //printf("\n%lu\n", res);
    printf("%lu\n", (M * res + 1)%Z);
}

void solution2(){
    uint64_t res = 1;
    uint64_t s = Z;
    for (int i = 1; i <= P; i++) {
        res *= 2;
        res %= s;
    }
    printf("%lu\n", (M * res + 1)%s);
}

int main() {
    solution2();
}