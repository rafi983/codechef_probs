#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

void solve() {
    ull X, N;
    if (!(cin >> X >> N)) return;


    for (int L = 1; L <= 62; ++L) {
        ull K = (N < (ull)L) ? N : (ull)L; // min(N, L)

        vector<ull> C(L);



        for (int j = 0; j < L; ++j) {
            if (j < K) {
                // C[j] = 2^(j+1) - 1
                // Since j < K <= L <= 62, j+1 <= 63. Safe for ull.
                C[j] = (1ULL << (j + 1)) - 1;
            } else {
                if (C[j-1] > (X + 1) / 2) {
                     C[j] = X + 2; // Mark as too big
                } else {
                    C[j] = 2 * C[j-1];
                }
            }
        }

        if (C[L-1] > X) continue;

        ull current_X = X;
        ull u = 0;

        current_X -= C[L-1];
        u |= (1ULL << (L - 1));

        for (int j = L - 2; j >= 0; --j) {
            if (current_X >= C[j]) {
                current_X -= C[j];
                u |= (1ULL << j);
            }
        }

        if (current_X == 0) {
            cout << u << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

