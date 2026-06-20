#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int m = 28123;

bool is_abundant(int n) {
    int s = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            s += i;
        }
    }
    return s > n ? true : false;
}

void solve() {
    bool ab[m+1];
    for (int i = 0; i < m+1; i++) {
        ab[i] = is_abundant(i);
    }
    // printf("done\n");
    bool found[m+1];
    for (int i = 0; i < m+1; i++) {
        found[i] = false;
    }
    for (int i = 0; i < m+1; i++) {
        for (int j = i; j < m+1; j++) {
            if ((i+j < m+1) && ab[i] && ab[j]) {
                found[i+j] = true;
            }
        }
    }
    // printf("found[0] = %d\n", found[0]);
    // C'était ça, l'erreur: j'avais initialisé s à 1, (l. 12), donc 0 était abondant, et donc les petits nombres qui étaient abondants mais pas somme de deux abondants étaient marqués dans found.
    int res = 0;
    for (int i = 1; i < m+1; i++) {
        if (!found[i]) {
            res += i;
        }
    }
    printf("res = %d\n", res);
}

int main() {
    solve();
}