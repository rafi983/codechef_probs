#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXA 100000

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N, K;
        if (scanf("%d %d", &N, &K) != 2) return 0;

        int *A = (int *) malloc(sizeof(int) * N);
        int *B = (int *) malloc(sizeof(int) * N);

        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; ++i) {
            scanf("%d", &B[i]);
        }

        static int minB[MAXA + 1];
        for (int i = 0; i <= MAXA; ++i) {
            minB[i] = INT_MAX;
        }

        for (int i = 0; i < N; ++i) {
            int c = A[i];
            int t = B[i];
            if (t < minB[c]) {
                minB[c] = t;
            }
        }

        int *vals = (int *) malloc(sizeof(int) * (MAXA + 1));
        int m = 0;
        for (int c = 1; c <= MAXA; ++c) {
            if (minB[c] != INT_MAX) {
                vals[m++] = minB[c];
            }
        }

        if (m < K) {
            printf("-1\n");
        } else {
            qsort(vals, m, sizeof(int), cmp_int);
            long long sum = 0;
            for (int i = 0; i < K; ++i) {
                sum += vals[i];
            }
            printf("%lld\n", sum);
        }

        free(A);
        free(B);
        free(vals);
    }
    return 0;
}
