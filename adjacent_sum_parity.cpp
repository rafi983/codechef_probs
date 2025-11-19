#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> b(n);
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
            sum += b[i];
        }

        if (sum % 2 == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}