#include <stdio.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) {
            return 0;
        }
        char buf[20050];
        if (scanf("%s", buf) != 1) {
            return 0;
        }
        int seen_zero = 0;
        int count = 0;
        for (int i = 0; buf[i] != '\0'; ++i) {
            if (!seen_zero && buf[i] == '0') {
                seen_zero = 1;
            } else if (seen_zero && buf[i] == '1') {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}

