#include <stdio.h>

int main(void){
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        long long D,d,P,Q;
        if (scanf("%lld %lld %lld %lld", &D, &d, &P, &Q) != 4) return 0;
        long long k = D / d;
        long long r = D % d;
        long long full = d * (k * P + (Q * k * (k - 1)) / 2);
        long long rem = r * (P + k * Q);
        long long ans = full + rem;
        printf("%lld\n", ans);
    }
    return 0;
}

