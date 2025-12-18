#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<long long> B(N);
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long suffix_sum = 0;
    long long K = -2e18; // Initialize with a very small number


    for (int i = N - 1; i >= 0; --i) {
        long long current_val = A[i] + suffix_sum;
        if (i == N - 1) {
            K = current_val;
        } else {
            K = max(K, current_val);
        }
        suffix_sum += B[i];
    }

    long long S = suffix_sum;
    long long T = K - S;

    long long ans = 0;

    if (T >= M) {
        ans = M * K;
    } else if (T < 1) {

        ans = M * (M + 1) / 2 + M * S;
    } else {
        ans += T * K;

        long long count = M - T;
        long long sum_X = (M * (M + 1) / 2) - (T * (T + 1) / 2);
        ans += sum_X + count * S;
    }

    cout << ans << endl;
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
