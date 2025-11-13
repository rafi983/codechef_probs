#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

        int possible = 0;

        if((a + b <= d && c <= e) ||
           (a + c <= d && b <= e) ||
           (b + c <= d && a <= e)) {
            possible = 1;
        }

        if(possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
