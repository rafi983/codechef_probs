#include <stdio.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        long long n;
        if (scanf("%lld", &n) != 1) {
            n = 0;
        }
        long long term = 2 * n * n - 5 * n + 4;
        long long answer = n * (n - 1) * term;
        printf("%lld\n", answer);
    }

    return 0;
}

