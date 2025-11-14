#include <stdio.h>

static int arr[100000];

static int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
        int g = 0;
        for (int i = 0; i < N; ++i) {
            int diff = arr[i] - (i + 1);
            if (diff < 0) diff = -diff;
            g = gcd(g, diff);
        }
        if (g == 0) g = N;
        if (g > N) g = N;
        printf("%d\n", g);
    }
    return 0;
}

