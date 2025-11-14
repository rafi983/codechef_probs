#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    while (t--) {
        int n;
        scanf("%d", &n);
        long long total = 0;
        static long long a[200000];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            total += a[i];
        }
        long long best = total;
        long long pref = 0;
        for (int i = 0; i <= n; i++) {
            long long first = pref;
            long long second = total - pref;
            long long cur = first > second ? first : second;
            if (cur < best) {
                best = cur;
            }
            if (i < n) {
                pref += a[i];
            }
        }
        printf("%lld\n", best);
    }
    return 0;
}

