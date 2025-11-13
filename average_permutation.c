#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 0;
        int *P = (int *)malloc((N + 1) * sizeof(int));
        if (!P) return 0;

        int curr = 1;
        if (N >= 5) {
            for (int i = 3; i <= N - 2; ++i) {
                P[i] = curr++;
            }
        }
        P[2] = curr++;
        if (N - 1 != 2) {
            P[N - 1] = curr++;
        }
        P[1] = curr++;
        P[N] = curr++;

        for (int i = 1; i <= N; ++i) {
            printf("%d%c", P[i], (i == N ? '\n' : ' '));
        }
        free(P);
    }
    return 0;
}

