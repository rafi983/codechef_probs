#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int x;
        int y;
        int z;
        std::cin >> x >> y >> z;

        int best = 0;
        for (int mask = 0; mask < 8; ++mask) {
            const int rg = (mask & 1) ? 1 : 0;
            const int rb = (mask & 2) ? 1 : 0;
            const int gb = (mask & 4) ? 1 : 0;

            const int need_r = rg + rb;
            const int need_g = rg + gb;
            const int need_b = rb + gb;
            if (need_r > x || need_g > y || need_b > z) {
                continue;
            }

            int primary = 0;
            if (x - need_r > 0) {
                ++primary;
            }
            if (y - need_g > 0) {
                ++primary;
            }
            if (z - need_b > 0) {
                ++primary;
            }

            const int secondary = rg + rb + gb;
            if (primary + secondary > best) {
                best = primary + secondary;
            }
        }

        std::cout << best << '\n';
    }

    return 0;
}

