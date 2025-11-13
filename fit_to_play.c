#include <stdio.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 0;
        int x;
        int min_so_far = 0;
        int max_diff = -2147483647 - 1;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &x);
            if (i == 0) {
                min_so_far = x;
            } else {
                int diff = x - min_so_far;
                if (diff > max_diff) max_diff = diff;
                if (x < min_so_far) min_so_far = x;
            }
        }
        if (max_diff > 0) printf("%d\n", max_diff);
        else puts("UNFIT");
    }
    return 0;
}

