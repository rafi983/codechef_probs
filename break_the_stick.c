#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        long long n, x;
        scanf("%lld %lld", &n, &x);

        if(n % 2 == x % 2) {
            printf("YES\n");
        } else if(n % 2 == 0 && x % 2 == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
