#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        char s1[101], s2[101];
        scanf("%s", s1);
        scanf("%s", s2);

        int len = strlen(s1);
        int min_diff = 0;
        int max_diff = 0;

        for(int i = 0; i < len; i++) {
            if(s1[i] != '?' && s2[i] != '?') {
                if(s1[i] != s2[i]) {
                    min_diff++;
                    max_diff++;
                }
            } else {
                max_diff++;
            }
        }

        printf("%d %d\n", min_diff, max_diff);
    }

    return 0;
}
