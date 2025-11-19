#include <iostream>
#include <vector>

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

        if (N % 4 != 0) {
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";
        const int k = N / 4;
        const int half = N / 2;
        std::vector<int> A(half);
        std::vector<int> B(half);

        int idx = 0;
        for (int i = 0; i < k; ++i) {
            A[idx++] = N - i;
        }
        for (int i = 0; i < k; ++i) {
            A[idx++] = i + 1;
        }
        for (int i = 0; i < half; ++i) {
            B[i] = k + 1 + i;
        }

        for (int i = 0; i < half; ++i) {
            if (i) {
                std::cout << ' ';
            }
            std::cout << A[i];
        }
        std::cout << '\n';

        for (int i = 0; i < half; ++i) {
            if (i) {
                std::cout << ' ';
            }
            std::cout << B[i];
        }
        std::cout << '\n';
    }

    return 0;
}

