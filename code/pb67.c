#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define N 100

int a[N][N];

int max(int a, int b) {
    return a > b ? a : b;
}

void solution() {
    int sx;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <=i; j++) {
            sx = scanf("%d ", &a[i][j]);
            assert (sx == 1);
            // printf("%d ", a[i][j]);
        }
        // printf("\n");
    }
    int *s = calloc(N+1, sizeof(int));
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            s[j] = a[i][j] + max(s[j], s[j+1]);
        } 
    }
    printf("%d\n", s[0]);
}


int main() {
    solution();
}