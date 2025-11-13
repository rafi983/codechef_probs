#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int xa, xb, xc;
        scanf("%d %d %d", &xa, &xb, &xc);

        if(xa > 50) {
            printf("A\n");
        } else if(xb > 50) {
            printf("B\n");
        } else if(xc > 50) {
            printf("C\n");
        } else {
            printf("NOTA\n");
        }
    }

    return 0;
}
