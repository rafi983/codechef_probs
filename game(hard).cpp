#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long calculate_score(int M, int K, const vector<long long>& P) {
    long long L = K - M;

    long long extra = (long long)(2 * M - L - 1) * L / 2;
    return P[M] + extra;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());

    vector<long long> P(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        P[i + 1] = P[i] + A[i];
    }

    int best_M = 1;
    for (int K = 1; K <= 2 * N; ++K) {
        int L_bound = (K + 1) / 2;
        int R_bound = min(N, K);

        if (best_M < L_bound) best_M = L_bound;

        while (best_M < R_bound) {
            long long curr_val = calculate_score(best_M, K, P);
            long long next_val = calculate_score(best_M + 1, K, P);
            if (next_val >= curr_val) {
                best_M++;
            } else {
                break;
            }
        }

        cout << calculate_score(best_M, K, P) << (K == 2 * N ? "" : " ");
    }
    cout << "\n";
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

