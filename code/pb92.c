#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define max 10000000

int card(int a[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1)
            res++;
    }
    return res;
}

int square(int a) {
    return a*a;
}

void solution() {
    int *e89 = malloc((max+1)*sizeof(int)); // -1 si idk, 1 si le nombre s'arrête sur 89, 0 s'il s'arrête sur 1
    for (int i = 0; i <= max; i++) {
        e89[i] = -1;
    }
    for (int i = 2; i <= max; i++) {
        int new = i;
        while (true) {
            if (new <= max && e89[new] != -1) { e89[i] = e89[new]; break; }
            if (new == 1) { e89[i] = 0; break; }
            if (new == 89) { e89[i] = 1; break; }
            int tmp = 0;
            while(new) {
                tmp += square(new % 10);
                new /= 10;
            }
            new = tmp;
        }
        
    }

    printf("%d\n", card(e89, max+1));
}


int main() { 
    solution();
}