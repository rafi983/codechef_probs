#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        long long D, d, P, Q;
        if (!(std::cin >> D >> d >> P >> Q)) {
            return 0;
        }

        const long long k = D / d;
        const long long r = D % d;
        const long long full = d * (k * P + (Q * k * (k - 1)) / 2);
        const long long rem = r * (P + k * Q);
        std::cout << (full + rem) << '\n';
    }

    return 0;
}

