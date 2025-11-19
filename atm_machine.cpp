#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> withdrawals(n);
        for (int &value : withdrawals) {
            std::cin >> value;
        }

        std::string result(n, '0');
        int currentMoney = k;

        for (int i = 0; i < n; ++i) {
            if (currentMoney >= withdrawals[i]) {
                result[i] = '1';
                currentMoney -= withdrawals[i];
            }
        }

        std::cout << result << '\n';
    }

    return 0;
}

