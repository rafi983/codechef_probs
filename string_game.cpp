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
        if (!(std::cin >> N)) {
            return 0;
        }

        std::string s;
        s.reserve(N);
        std::cin >> s;

        int c0 = 0;
        int c1 = 0;
        for (char ch : s) {
            if (ch == '0') {
                ++c0;
            } else {
                ++c1;
            }
        }

        const int moves = std::min(c0, c1);
        std::cout << ((moves & 1) ? "Zlatan" : "Ramos") << '\n';
    }

    return 0;
}

