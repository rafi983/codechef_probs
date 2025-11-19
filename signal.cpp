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

        std::string buf;
        if (!(std::cin >> buf)) {
            return 0;
        }

        bool seen_zero = false;
        int count = 0;
        for (char c : buf) {
            if (!seen_zero && c == '0') {
                seen_zero = true;
            } else if (seen_zero && c == '1') {
                ++count;
            }
        }

        std::cout << count << '\n';
    }

    return 0;
}

