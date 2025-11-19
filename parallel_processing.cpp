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

        std::vector<long long> a(n);
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            total += a[i];
        }

        long long best = total;
        long long pref = 0;
        for (int i = 0; i <= n; ++i) {
            long long first = pref;
            long long second = total - pref;
            long long cur = std::max(first, second);
            if (cur < best) {
                best = cur;
            }
            if (i < n) {
                pref += a[i];
            }
        }

        std::cout << best << '\n';
    }

    return 0;
}

