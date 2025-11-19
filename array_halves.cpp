#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        int N;
        if (!(std::cin >> N)) {
            return 0;
        }

        long long ans = 0;
        int big = 0;
        const int total = 2 * N;

        for (int i = 0; i < total; ++i) {
            int x;
            std::cin >> x;
            if (x <= N) {
                ans += big; // each smaller element pairs with all prior large elements
            } else {
                ++big;
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}

