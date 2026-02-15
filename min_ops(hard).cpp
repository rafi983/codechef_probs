#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }


    vector<long long> P(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        P[i] = P[i - 1] + abs(A[i] - A[i - 1]);
    }

    for (int i = 0; i < Q; ++i) {
        int L, R;
        long long K;
        cin >> L >> R >> K;

        if (L == R) {
            cout << 0 << "\n";
            continue;
        }

        long long current_tv = P[R] - P[L];

        long long endpoint_diff = abs(A[R] - A[L]);

        if (current_tv <= K) {
            cout << 0 << "\n";
        } else {

            long long max_reduction_rate_2 = current_tv - endpoint_diff;

            // Required reduction
            long long required_reduction = current_tv - K;

            if (required_reduction <= max_reduction_rate_2) {

                long long ops = (required_reduction + 1) / 2;
                cout << ops << "\n";
            } else {
                long long ops_rate_2 = max_reduction_rate_2 / 2;

                long long ops_rate_1 = endpoint_diff - K;

                cout << (ops_rate_2 + ops_rate_1) << "\n";
            }
        }
    }
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

