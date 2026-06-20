#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void solution(int max) {
    for (int n = 1; n < max; n++) {
        int *tab = calloc(5000000, sizeof(int)); // J'avais mis ceci hors de la boucle! ça additionnait au résultat précédent à chaque itération!
        int num = n*(n+1) / 2;
        int ind_i = 0; int i = 2;
        while (num > 1 && i < 5000000) {
            if (num % i == 0) {
                tab[ind_i] += 1;
                num /= i;
            }
            else { i++; ind_i++; }
        }
        int res = 1;
        for (int j = 0; j < ind_i+1; j++) {
            res *= (tab[j] + 1);
        }
        if (res >= 500) { 
            printf("number value: %d\n", n*(n+1) / 2);
            break;
        }
    }
}

int main() {
    solution(60000);
}