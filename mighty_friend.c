#include <stdio.h>
#include <stdlib.h>

static int cmp_asc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

static int cmp_desc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (y > x) - (y < x);
}

int main(void) {
    int T;

    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        int N, K;

        if (scanf("%d %d", &N, &K) != 2) {
            return 0;
        }

        int *A = (int *)malloc(N * sizeof(int));

        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }

        long long sM = 0, sT = 0;

        int ne = (N + 1) / 2;
        int no = N / 2;

        int *E = (int *)malloc(ne * sizeof(int));
        int *O = (int *)malloc(no * sizeof(int));

        int ie = 0;
        int io = 0;

        for (int i = 0; i < N; ++i) {
            if ((i & 1) == 0) {
                E[ie++] = A[i];
                sM += A[i];
            } else {
                O[io++] = A[i];
                sT += A[i];
            }
        }

        qsort(E, ne, sizeof(int), cmp_desc);
        qsort(O, no, sizeof(int), cmp_asc);

        int lim = K;

        if (lim > ne) {
            lim = ne;
        }
        if (lim > no) {
            lim = no;
        }

        for (int i = 0; i < lim; ++i) {
            if (E[i] > O[i]) {
                sM -= E[i];
                sM += O[i];

                sT -= O[i];
                sT += E[i];
            } else {
                break;
            }
        }

        printf(sT > sM ? "YES\n" : "NO\n");

        free(A);
        free(E);
        free(O);
    }

    return 0;
}
