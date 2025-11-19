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
        std::cin >> N;

        if (N == 1) {
            std::cout << 1 << '\n';
            continue;
        }
        if (N == 2) {
            std::cout << -1 << '\n';
            continue;
        }

        std::vector<int> perm;
        perm.reserve(N);

        if (N % 2 == 1) {
            for (int i = 1; i <= N; ++i) {
                perm.push_back(i);
            }
        } else {
            for (int i = 1; i <= N - 4; ++i) {
                perm.push_back(i);
            }
            perm.push_back(N - 3);
            perm.push_back(N);
            perm.push_back(N - 2);
            perm.push_back(N - 1);
        }

        for (int i = 0; i < N; ++i) {
            if (i) {
                std::cout << ' ';
            }
            std::cout << perm[i];
        }
        std::cout << '\n';
    }

    return 0;
}

