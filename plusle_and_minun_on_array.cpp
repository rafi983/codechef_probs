#include <iostream>
#include <limits>
#include <cstdlib>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        int N;
        if (!(std::cin >> N)) {
            return 0;
        }

        long long sum = 0;
        long long minOdd = std::numeric_limits<long long>::max();
        long long maxEven = 0;

        for (int i = 1; i <= N; ++i) {
            long long a;
            std::cin >> a;
            long long b = std::llabs(a);
            if (i & 1) {
                sum += b;
                if (b < minOdd) {
                    minOdd = b;
                }
            } else {
                sum -= b;
                if (b > maxEven) {
                    maxEven = b;
                }
            }
        }

        long long gain = maxEven > minOdd ? 2 * (maxEven - minOdd) : 0;
        std::cout << (sum + gain) << '\n';
    }

    return 0;
}

