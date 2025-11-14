#include <stdio.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        unsigned int X;
        if (scanf("%d %u", &N, &X) != 2) return 0;
        int evens = 0;
        for (int i = 0; i < N; i++) {
            unsigned int a;
            scanf("%u", &a);
            if ((a & 1u) == 0u) evens++;
        }
        if ((X & 1u) == 1u) {
            int ops = (evens + 1) / 2;
            printf("%d\n", ops);
        } else {
            if (evens == N) {
                printf("-1\n");
            } else {
                printf("%d\n", evens);
            }
        }
    }
    return 0;
}
