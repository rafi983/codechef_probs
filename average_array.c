#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    while (t--) {
        int n;
        int x;
        scanf("%d %d", &n, &x);
        int arr[1000];
        int idx = 0;
        if (n % 2 == 1) {
            arr[idx++] = 0;
        }
        int k = 1;
        while (idx < n) {
            arr[idx++] = -k;
            if (idx < n) {
                arr[idx++] = k;
            }
            k++;
        }
        for (int i = 0; i < n; i++) {
            arr[i] += x;
        }
        for (int i = 0; i < n; i++) {
            if (i) {
                printf(" ");
            }
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

