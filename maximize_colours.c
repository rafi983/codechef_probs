#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    while (t--) {
        int x;
        int y;
        int z;
        scanf("%d %d %d", &x, &y, &z);
        int best = 0;
        for (int mask = 0; mask < 8; mask++) {
            int rg = (mask & 1) ? 1 : 0;
            int rb = (mask & 2) ? 1 : 0;
            int gb = (mask & 4) ? 1 : 0;
            int need_r = rg + rb;
            int need_g = rg + gb;
            int need_b = rb + gb;
            if (need_r > x || need_g > y || need_b > z) {
                continue;
            }
            int primary = 0;
            if (x - need_r > 0) {
                primary++;
            }
            if (y - need_g > 0) {
                primary++;
            }
            if (z - need_b > 0) {
                primary++;
            }
            int secondary = rg + rb + gb;
            if (primary + secondary > best) {
                best = primary + secondary;
            }
        }
        printf("%d\n", best);
    }
    return 0;
}

