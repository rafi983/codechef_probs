#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long dp[200005];
const int MOD = 998244353;

void precompute() {
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 3;
    for (int i = 3; i <= 200000; ++i) {
        dp[i] = (dp[i-1] + dp[i-3]) % MOD;
    }
}

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    long long ans = 1;
    int current_len = 1;

    for (int i = 1; i < N; ++i) {
        if (S[i] != S[i-1]) {
            current_len++;
        } else {
            if (current_len >= 3) {
                ans = (ans * dp[current_len - 3]) % MOD;
            }
            current_len = 1;
        }
    }
    // Process the last segment
    if (current_len >= 3) {
        ans = (ans * dp[current_len - 3]) % MOD;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

