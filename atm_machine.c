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

        char result[101];
        int currentMoney = k;

        for(int i = 0; i < n; i++) {
            if(currentMoney >= a[i]) {
                result[i] = '1';
                currentMoney -= a[i];
            } else {
                result[i] = '0';
            }
        }
        result[n] = '\0';

        printf("%s\n", result);
    }

    return 0;
}

