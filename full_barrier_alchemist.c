#include <stdio.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N, H, Y1, Y2, L;
        if (scanf("%d %d %d %d %d", &N, &H, &Y1, &Y2, &L) != 5) return 0;
        int passed = 0;
        int exhausted = 0;

        for (int i = 0; i < N; ++i) {
            int t, X;
            if (scanf("%d %d", &t, &X) != 2) return 0;

            if (exhausted) {
                continue;
            }

            int can_pass = 0;
            if (t == 1) {
                if (X >= H - Y1) can_pass = 1;
            } else {
                if (X <= Y2) can_pass = 1;
            }

            if (can_pass) {
                passed++;
            } else {
                if (L >= 2) {
                    L--;
                    passed++;
                } else {
                    exhausted = 1;
                }
            }
        }

        printf("%d\n", passed);
    }
    return 0;
}

