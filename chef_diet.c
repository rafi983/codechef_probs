#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int a[100];
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int stored = 0;
        int possible = 1;
        int first_fail_day = -1;

        for(int i = 0; i < n; i++) {
            stored += a[i];

            if(stored < k) {
                possible = 0;
                first_fail_day = i + 1;
                break;
            }

            stored -= k;
        }

        if(possible) {
            printf("YES\n");
        } else {
            printf("NO %d\n", first_fail_day);
        }
    }

    return 0;
}
