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
        if (!(std::cin >> N)) {
            return 0;
        }
        if (N % 6 == 0) {
            std::cout << "Misha\n";
        } else {
            std::cout << "Chef\n";
        }
    }

    return 0;
}

