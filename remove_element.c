#include <stdio.h>

int main(void){
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N; long long K;
        if (scanf("%d %lld", &N, &K) != 2) return 0;
        long long mn = 0, mx = 0;
        for (int i = 0; i < N; ++i) {
            long long x; scanf("%lld", &x);
            if (i == 0) { mn = mx = x; }
            else {
                if (x < mn) mn = x;
                if (x > mx) mx = x;
            }
        }
        if (N == 1 || mn + mx <= K) puts("YES"); else puts("NO");
    }
    return 0;
}

