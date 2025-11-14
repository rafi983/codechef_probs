#include <stdio.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        scanf("%d", &N);
        if (N == 1) {
            printf("1\n");
        } else if (N == 2) {
            printf("-1\n");
        } else if (N % 2 == 1) {
            int first = 1;
            for (int i = 1; i <= N; i++) {
                if (!first) printf(" ");
                printf("%d", i);
                first = 0;
            }
            printf("\n");
        } else {
            int first = 1;
            for (int i = 1; i <= N - 4; i++) {
                if (!first) printf(" ");
                printf("%d", i);
                first = 0;
            }
            if (!first) printf(" ");
            printf("%d", N - 3); first = 0;
            printf(" %d %d %d\n", N, N - 2, N - 1);
        }
    }
    return 0;
}
