#include <stdio.h>
#include <stdlib.h>

int main(void){
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 0;
        char *s = (char*)malloc((N + 5) * sizeof(char));
        scanf("%s", s);
        int c0 = 0, c1 = 0;
        for (int i = 0; i < N; ++i) {
            if (s[i] == '0') ++c0; else ++c1;
        }
        int moves = c0 < c1 ? c0 : c1;
        puts((moves & 1) ? "Zlatan" : "Ramos");
        free(s);
    }
    return 0;
}

