#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

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

    vector<long long> ans(2 * N + 1, 0);

    for (int M = 1; M <= N; ++M) {
        for (int L = 0; L <= M; ++L) {
            int K = M + L;
            long long current_sum = P[M];

            long long extra = (long long)(2 * M - L - 1) * L / 2;
            current_sum += extra;
            if (current_sum > ans[K]) {
                ans[K] = current_sum;
            }
        }
    }

    for (int k = 1; k <= 2 * N; ++k) {
        cout << ans[k] << (k == 2 * N ? "" : " ");
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

