#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int X, Y;
    if (!(std::cin >> X >> Y)) {
        return 0;
    }

    const int total = 3 * X + 2 * Y;
    std::cout << total << '\n';
    return 0;
}

