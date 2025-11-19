#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t)) {
        return 0;
    }

    while (t--) {
        int n, x;
        std::cin >> n >> x;

        std::vector<int> arr;
        arr.reserve(n);

        if (n % 2 == 1) {
            arr.push_back(0);
        }

        int k = 1;
        while (static_cast<int>(arr.size()) < n) {
            arr.push_back(-k);
            if (static_cast<int>(arr.size()) < n) {
                arr.push_back(k);
            }
            ++k;
        }

        for (int &value : arr) {
            value += x; // shifting keeps mean at x
        }

        for (int i = 0; i < n; ++i) {
            if (i) {
                std::cout << ' ';
            }
            std::cout << arr[i];
        }
        std::cout << '\n';
    }

    return 0;
}

