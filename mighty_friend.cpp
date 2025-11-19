#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) {
        return 0;
    }

    while (T--) {
        int N;
        int K;
        std::cin >> N >> K;

        std::vector<int> A(N);
        for (int &value : A) {
            std::cin >> value;
        }

        long long sM = 0;
        long long sT = 0;

        const int ne = (N + 1) / 2;
        const int no = N / 2;

        std::vector<int> E;
        std::vector<int> O;
        E.reserve(ne);
        O.reserve(no);

        for (int i = 0; i < N; ++i) {
            if ((i & 1) == 0) {
                E.push_back(A[i]);
                sM += A[i];
            } else {
                O.push_back(A[i]);
                sT += A[i];
            }
        }

        std::sort(E.begin(), E.end(), std::greater<int>());
        std::sort(O.begin(), O.end());

        int lim = std::min({K, ne, no});
        for (int i = 0; i < lim; ++i) {
            if (E[i] > O[i]) {
                sM -= E[i];
                sM += O[i];
                sT -= O[i];
                sT += E[i];
            } else {
                break;
            }
        }

        std::cout << (sT > sM ? "YES\n" : "NO\n");
    }

    return 0;
}

