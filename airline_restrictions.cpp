#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b, c, d, e;
        std::cin >> a >> b >> c >> d >> e;

        bool possible = (a + b <= d && c <= e) ||
                        (a + c <= d && b <= e) ||
                        (b + c <= d && a <= e);

        std::cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}