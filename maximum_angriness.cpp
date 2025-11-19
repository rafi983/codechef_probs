#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        long long N;
        long long K;
        std::cin >> N >> K;

        long long m = K;
        const long long half = N / 2;
        if (m > half) {
            m = half;
        }

        const long long ans = m * (2 * N - 2 * m - 1);
        std::cout << ans << '\n';
    }

    return 0;
}

