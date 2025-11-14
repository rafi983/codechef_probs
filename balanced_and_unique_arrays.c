#include <stdio.h>

#define MAX_HALF 50005

int main(void) {
    static int A[MAX_HALF];
    static int B[MAX_HALF];
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) {
            return 0;
        }
        if (N % 4 != 0) {
            puts("NO");
            continue;
        }
        puts("YES");
        int k = N / 4;
        int half = N / 2;
        int idx = 0;
        for (int i = 0; i < k; ++i) {
            A[idx++] = N - i;
        }
        for (int i = 0; i < k; ++i) {
            A[idx++] = i + 1;
        }
        for (int i = 0; i < half; ++i) {
            B[i] = k + 1 + i;
        }
        for (int i = 0; i < half; ++i) {
            if (i) putchar(' ');
            printf("%d", A[i]);
        }
        putchar('\n');
        for (int i = 0; i < half; ++i) {
            if (i) putchar(' ');
            printf("%d", B[i]);
        }
        putchar('\n');
    }
    return 0;
}

