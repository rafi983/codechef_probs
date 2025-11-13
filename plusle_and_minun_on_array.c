#include <stdio.h>

int main(void){
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 0;
        long long sum = 0;
        long long minOdd = 0x7fffffffffffffffLL;
        long long maxEven = 0;
        for (int i = 1; i <= N; ++i) {
            long long a;
            scanf("%lld", &a);
            long long b = a < 0 ? -a : a;
            if (i & 1) {
                sum += b;
                if (b < minOdd) minOdd = b;
            } else {
                sum -= b;
                if (b > maxEven) maxEven = b;
            }
        }
        long long gain = maxEven > minOdd ? 2 * (maxEven - minOdd) : 0;
        printf("%lld\n", sum + gain);
    }
    return 0;
}

