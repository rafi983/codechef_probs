#include <stdio.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 0;
        long long ans = 0;
        int big = 0;
        for (int i = 0; i < 2 * N; ++i) {
            int x;
            scanf("%d", &x);
            if (x <= N) ans += big;
            else big++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

