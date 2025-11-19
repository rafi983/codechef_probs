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
        long long K;
        if (!(std::cin >> N >> K)) {
            return 0;
        }

        long long mn = 0;
        long long mx = 0;
        for (int i = 0; i < N; ++i) {
            long long x;
            std::cin >> x;
            if (i == 0) {
                mn = mx = x;
            } else {
                if (x < mn) {
                    mn = x;
                }
                if (x > mx) {
                    mx = x;
                }
            }
        }

        if (N == 1 || mn + mx <= K) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}

