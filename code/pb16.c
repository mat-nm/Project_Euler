#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void solution(int pow) {
    int *number = calloc(302, sizeof(int)); number[0] = 1;
    for (int i = 1; i <= pow; i++) {
        int rem = 0;
        for (int j = 0; j < 302; j++) {
            int num = number[j];
            number[j] = (2*number[j] + rem)%10;
            rem = 2*num + rem >= 10 ? 1 : 0;
        }
    }
    int res = 0;
    for (int i = 0; i < 302; i++) {
        res += number[i];
    }
    printf("It contains %d digits.\n", res);
}

int main() {
    solution(1000);
}