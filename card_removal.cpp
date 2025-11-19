#include <iostream>
#include <array>

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
        std::array<int, 100> cards{};
        for (int i = 0; i < n; ++i) {
            std::cin >> cards[i];
        }

        std::array<int, 11> freq{};
        for (int i = 0; i < n; ++i) {
            ++freq[cards[i]];
        }

        int maxFreq = 0;
        for (int i = 1; i <= 10; ++i) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }

        std::cout << (n - maxFreq) << '\n';
    }

    return 0;
}

