#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        int zeros = 0;
        int ones = 0;
        for (char c : s) {
            if (c == '0') {
                ++zeros;
            } else {
                ++ones;
            }
        }

        if (ones == 0) {
            std::cout << 0 << '\n';
        } else {
            const int option1 = ones;
            const int option2 = 1 + zeros;
            std::cout << (option1 < option2 ? option1 : option2) << '\n';
        }
    }

    return 0;
}

