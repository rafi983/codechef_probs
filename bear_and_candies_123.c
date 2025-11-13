#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int a, b;
        scanf("%d %d", &a, &b);

        int limak_total = 0;
        int bob_total = 0;
        int turn = 1;

        while(1) {
            if(turn % 2 == 1) {
                if(limak_total + turn > a) {
                    printf("Bob\n");
                    break;
                }
                limak_total += turn;
            } else {
                if(bob_total + turn > b) {
                    printf("Limak\n");
                    break;
                }
                bob_total += turn;
            }
            turn++;
        }
    }

    return 0;
}
