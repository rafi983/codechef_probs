#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    while (t--) {
        long long l;
        long long r;
        scanf("%lld %lld", &l, &r);
        if (r >= 2 * l) {
            printf("-1\n");
        } else {
            printf("%lld\n", r);
        }
    }
    return 0;
}

