#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        char s[101];
        scanf("%s", s);

        for(int i = 0; i < n - 1; i += 2) {
            char temp = s[i];
            s[i] = s[i + 1];
            s[i + 1] = temp;
        }

        for(int i = 0; i < n; i++) {
            s[i] = 'z' - (s[i] - 'a');
        }

        printf("%s\n", s);
    }

    return 0;
}
