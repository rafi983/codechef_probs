#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        int N;
        std::cin >> N;
        std::vector<int> arr(N);
        for (int &x : arr) {
            std::cin >> x;
        }

        int g = 0;
        for (int i = 0; i < N; ++i) {
            int diff = arr[i] - (i + 1);
            if (diff < 0) {
                diff = -diff;
            }
            g = std::gcd(g, diff);
        }

        if (g == 0 || g > N) {
            g = N;
        }

        std::cout << g << '\n';
    }

    return 0;
}

