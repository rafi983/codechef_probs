#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int dragon_dsa, dragon_toc, dragon_dm;
        int sloth_dsa, sloth_toc, sloth_dm;

        scanf("%d %d %d", &dragon_dsa, &dragon_toc, &dragon_dm);
        scanf("%d %d %d", &sloth_dsa, &sloth_toc, &sloth_dm);

        int dragon_total = dragon_dsa + dragon_toc + dragon_dm;
        int sloth_total = sloth_dsa + sloth_toc + sloth_dm;

        if(dragon_total > sloth_total) {
            printf("Dragon\n");
        } else if(sloth_total > dragon_total) {
            printf("Sloth\n");
        } else {
            if(dragon_dsa > sloth_dsa) {
                printf("Dragon\n");
            } else if(sloth_dsa > dragon_dsa) {
                printf("Sloth\n");
            } else {
                if(dragon_toc > sloth_toc) {
                    printf("Dragon\n");
                } else if(sloth_toc > dragon_toc) {
                    printf("Sloth\n");
                } else {
                    printf("Tie\n");
                }
            }
        }
    }

    return 0;
}

