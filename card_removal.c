#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int a[100];
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int freq[11] = {0};
        for(int i = 0; i < n; i++) {
            freq[a[i]]++;
        }

        int max_freq = 0;
        for(int i = 1; i <= 10; i++) {
            if(freq[i] > max_freq) {
                max_freq = freq[i];
            }
        }

        printf("%d\n", n - max_freq);
    }

    return 0;
}
