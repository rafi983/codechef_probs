#include <stdio.h>

int main(void){
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 0;
        long long sum = 0;
        static long long a[50005];
        for (int i = 0; i < N; ++i) { scanf("%lld", &a[i]); sum += a[i]; }
        long long S = sum / (N - 1);
        for (int i = 0; i < N; ++i) {
            long long xi = S - a[i];
            if (i) putchar(' ');
            printf("%lld", xi);
        }
        putchar('\n');
    }
    return 0;
}

