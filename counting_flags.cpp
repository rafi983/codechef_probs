#include <iostream>

int main() {
    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        long long n;
        if (!(std::cin >> n)) {
            n = 0;
        }
        long long term = 2 * n * n - 5 * n + 4;
        long long answer = n * (n - 1) * term;
        std::cout << answer << '\n';
    }

    return 0;
}
