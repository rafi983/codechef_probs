#include <stdio.h>
#include <string.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 0;
        static char s[200005];
        if (scanf("%s", s) != 1) return 0;
        int D = 0;
        for (int i = 0; i < N - 1; i++) {
            if (s[i] == s[i + 1]) {
                if (s[i] == '1') D++;
                else D--;
            }
        }
        if (D >= 0) printf("0\n");
        else {
            int need = -D;
            int ans = (need + 1) / 2;
            printf("%d\n", ans);
        }
    }
    return 0;
}

