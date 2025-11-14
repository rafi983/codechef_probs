#include <stdio.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        long long N;
        if (scanf("%lld", &N) != 1) return 0;
        if (N % 6 == 0) {
            printf("Misha\n");
        } else {
            printf("Chef\n");
        }
    }
    return 0;
}

