#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int b[100000];
        int sum = 0;

        for(int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            sum += b[i];
        }

        if(sum % 2 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

