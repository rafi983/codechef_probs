#include <iostream>
#include <vector>

using namespace std;

long long MOD = 998244353;

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> dp(K + 1, 0);
    vector<long long> S(K + 1, 0);
    long long current_P = 1;

    for (int i = 0; i < N; ++i) {
        // Compute prefix sums of dp from the previous step
        S[0] = 0;
        for (int v = 1; v <= K; ++v) {
            S[v] = (S[v - 1] + dp[v]);
            if (S[v] >= MOD) S[v] -= MOD;
        }

        if (A[i] == -1) {
            for (int v = 1; v <= K; ++v) {
                // dp[v] = dp[v] * K + sum(dp[u] for u < v) + current_P
                long long term = (S[v - 1] + current_P);
                if (term >= MOD) term -= MOD;

                dp[v] = (dp[v] * K) % MOD;
                dp[v] = (dp[v] + term);
                if (dp[v] >= MOD) dp[v] -= MOD;
            }
            current_P = (current_P * K) % MOD;
        } else {
            int val = A[i];
            // Only dp[val] is updated
            // dp[val] += sum(dp[u] for u < val) + current_P
            long long term = (S[val - 1] + current_P);
            if (term >= MOD) term -= MOD;

            dp[val] = (dp[val] + term);
            if (dp[val] >= MOD) dp[val] -= MOD;
            // current_P remains same
        }
    }

    long long ans = 0;
    for (int v = 1; v <= K; ++v) {
        ans = (ans + dp[v]);
        if (ans >= MOD) ans -= MOD;
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

