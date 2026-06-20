#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define m 1000000

int pow_b(int a, int n) {
    int r = 1;
    while (n > 0) {
        if (n%2 == 1) {
            r *= a;
        }
        a *= a;
        n /= 2;
    }
    return r;
}

int n_digit(int n) {
    int ind = 1;
    // stocke les indices des débuts de chaque nombre entre 1 et m
    int d[m+1];
    for (int i = 1; i < m+1; i++) {
        d[i] = ind;
        ind += (int)log10(i)+1;
        
    }
    int i = 1;
    while (d[i] <= n) { if (i >= m) { break; } i++; } 
    
    int j = i - 1; //j est l'entier qui 'contient' le chiffre d'indice n
    int l = (int)log10(j) + 1;
    return (j / (pow_b(10, l-(n-d[j]+1))))%10;
}

void solve() {
    printf("%d\n", n_digit(1)*n_digit(10)*n_digit(100)*n_digit(1000)*n_digit(10000)*n_digit(100000)*n_digit(1000000));
}

int main() {
    solve();
}