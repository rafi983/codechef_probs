#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        char s[100001];
        scanf("%s", s);

        int zeros = 0, ones = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                zeros++;
            } else {
                ones++;
            }
        }

        if(ones == 0) {
            printf("0\n");
        } else {
            int option1 = ones;
            int option2 = 1 + zeros;
            printf("%d\n", (option1 < option2) ? option1 : option2);
        }
    }

    return 0;
}
