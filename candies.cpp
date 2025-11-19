#include <iostream>
#include <vector>
#include <algorithm>

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
        const int total = 2 * n;
        std::vector<int> a(total);
        for (int &value : a) {
            std::cin >> value;
        }

        std::sort(a.begin(), a.end());
        bool valid = true;

        for (int i = 0; i < total;) {
            int j = i + 1;
            while (j < total && a[j] == a[i]) {
                ++j;
            }
            if (j - i > 2) {
                valid = false;
                break;
            }
            i = j;
        }

        std::cout << (valid ? "Yes" : "No") << '\n';
    }

    return 0;
}

