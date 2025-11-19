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
        std::string s1, s2;
        std::cin >> s1 >> s2;

        const int len = static_cast<int>(s1.size());
        int minDiff = 0;
        int maxDiff = 0;

        for (int i = 0; i < len; ++i) {
            if (s1[i] != '?' && s2[i] != '?') {
                if (s1[i] != s2[i]) {
                    ++minDiff;
                    ++maxDiff;
                }
            } else {
                ++maxDiff;
            }
        }

        std::cout << minDiff << ' ' << maxDiff << '\n';
    }

    return 0;
}

