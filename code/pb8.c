#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int n = 20; int m = 50; int k = 13;
    char num[n*m];
    for (int i = 0; i < n; i++) {
        char buff[m];
        scanf("%s", buff);
        for (int j = 0; j < m; j++) {
            num[m*i+j] = buff[j] - '0';
        }
    }
    uint64_t res = 0;
    for (int i = 0; i < n*m-k+1; i++) {
        uint64_t candidate = num[i];
        for (int j = i+1; candidate != 0 && j < i+k; j++) {
            candidate *= num[j];
        }
        if (candidate > res) { res = candidate; }
    }
    printf("%lu\n", res);    
}