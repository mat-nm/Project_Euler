#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int m = 99*99;
const double ep = 0.00000000001;

void swap(double a[], int i, int j) {
    double tmp = a[i];
    a[i] = a[j]; a[j] = tmp;
}

void knuth_shuffle(double a[], int n) {
    for (int k = 1; k < n; k++) {
        swap(a, k, rand() % (k+1));
    }
}

void quickrec(double a[], int l, int r) {
    if (r - l <= 1) return;
    int lo = l, hi = r;
    double p = a[l];
    for (int i = l+1; i < hi; ) {
        if (a[i] == p) { i++; }
        else if (a[i] < p) { swap(a, lo++, i++); }
        else { swap(a, --hi, i); }
    }
    quickrec(a, l, lo);
    quickrec(a, hi, r);
}

void quicksort(double a[], int n) {
    knuth_shuffle(a, n);
    quickrec(a, 0, n);
}

void solve() {
    double ar[m]; 
    int i = 0;
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            ar[i++] = b * log(a);
        }
    }
    quicksort(ar, m);    
    int res = 1;
    for (int i = 1; i < m; i++) {
        if (fabs(ar[i] - ar[i-1]) > ep) {
            res++;
        }
    }
    printf("res = %d\n", res);
}

int main() {
    solve();
}