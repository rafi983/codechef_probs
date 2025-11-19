#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        long long n, x;
        std::cin >> n >> x;

        const bool sameParity = (n % 2) == (x % 2);
        const bool evenOdd = (n % 2 == 0) && (x % 2 == 1);
        if (sameParity || evenOdd) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}

