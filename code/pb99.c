#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Attention!!! Pour le numéro de la ligne, ne pas oublier de faire +1 à argmax!

int a[1000], b[1000];

int argmax(double a[1000]) {
    double max = a[0];
    int argm = 0;
    for (int i = 1; i < 1000; i++) {
        if (a[i] > max) { max = a[i]; argm = i; }
    }
    return argm;
}

void solution() {
    int sx;
    for (int i = 0; i < 1000; i++) {
        sx = scanf("%d, %d", &a[i], &b[i]);
        assert(sx == 2);
    }
    double *s = calloc(1000, sizeof(double));
    for (int i = 0; i < 1000; i++) {
        s[i] = (double)b[i] * log(a[i]);
        // printf("%f ", s[i]);
    }
    printf("%d\n", argmax(s)+1); // numéro de la ligne
}


int main() {
    solution();
}