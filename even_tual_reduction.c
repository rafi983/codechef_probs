#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        char s[1001];
        scanf("%s", s);

        int freq[26] = {0};

        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        int possible = 1;
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 == 1) {
                possible = 0;
                break;
            }
        }

        if(possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
