#include <stdio.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        long long N, K;
        if (scanf("%lld %lld", &N, &K) != 2) return 0;
        long long m = K;
        long long half = N / 2;
        if (m > half) m = half;
        long long ans = m * (2 * N - 2 * m - 1);
        printf("%lld\n", ans);
    }
    return 0;
}

