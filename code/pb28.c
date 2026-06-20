#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void solution(int n) {
    int jump = 2;
    int count = 0;
    int sum = 1;
    int max = n * n;
    int d = 1;
    while (d < max) {
        while (count < 4) {
            d = d + jump;
            // printf("%d ", d);
            sum += d;
            count++;
        }
        jump += 2;
        count = 0;
        // printf("\n");
    }
    printf("%d\n", sum);
}

int main() {
    // solution(5);
    solution(1001);
}