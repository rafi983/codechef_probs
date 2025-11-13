#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        char s[101];
        scanf("%s", s);

        int maxConsecutiveConsonants = 0;
        int currentConsecutiveConsonants = 0;

        for(int i = 0; i < n; i++) {
            if(isVowel(s[i])) {
                currentConsecutiveConsonants = 0;
            } else {
                currentConsecutiveConsonants++;
                if(currentConsecutiveConsonants > maxConsecutiveConsonants) {
                    maxConsecutiveConsonants = currentConsecutiveConsonants;
                }
            }
        }

        if(maxConsecutiveConsonants >= 4) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}

