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

        std::vector<int> P(N + 1);
        int curr = 1;

        if (N >= 5) {
            for (int i = 3; i <= N - 2; ++i) {
                P[i] = curr++;
            }
        }

        if (N >= 2) {
            P[2] = curr++;
        }

        if (N - 1 != 2 && N >= 2) {
            P[N - 1] = curr++;
        }

        if (N >= 1) {
            P[1] = curr++;
        }

        P[N] = curr++;

        for (int i = 1; i <= N; ++i) {
            if (i > 1) {
                std::cout << ' ';
            }
            std::cout << P[i];
        }
        std::cout << '\n';
    }

    return 0;
}

