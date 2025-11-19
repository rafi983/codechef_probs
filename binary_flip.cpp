#include <iostream>
#include <string>

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
        std::string s;
        s.reserve(N);
        std::cin >> s;

        int D = 0;
        for (int i = 0; i + 1 < N; ++i) {
            if (s[i] == s[i + 1]) {
                if (s[i] == '1') {
                    ++D;
                } else {
                    --D;
                }
            }
        }

        if (D >= 0) {
            std::cout << 0 << '\n';
        } else {
            int need = -D;
            int ans = (need + 1) / 2;
            std::cout << ans << '\n';
        }
    }

    return 0;
}

