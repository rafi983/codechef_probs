#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    string S, T;
    cin >> S >> T;

    if (M > N) {
        cout << -1 << endl;
        return;
    }

    vector<int> prev_dp(N, INF);
    vector<int> curr_dp(N, INF);

    for (int i = 0; i < N; ++i) {
        if (S[i] == T[0]) {
            prev_dp[i] = (i > 0 ? 1 : 0);
        } else {
            prev_dp[i] = INF;
        }
    }

    for (int j = 1; j < M; ++j) {
        int min_prev_up_to_i_minus_2 = INF;

        for (int i = 0; i < N; ++i) {
            curr_dp[i] = INF; // Reset current value

            if (i >= 2) {
                min_prev_up_to_i_minus_2 = min(min_prev_up_to_i_minus_2, prev_dp[i-2]);
            }

            if (S[i] == T[j]) {
                if (i > 0 && prev_dp[i-1] != INF) {
                    curr_dp[i] = min(curr_dp[i], prev_dp[i-1]);
                }

                if (min_prev_up_to_i_minus_2 != INF) {
                    curr_dp[i] = min(curr_dp[i], min_prev_up_to_i_minus_2 + 1);
                }
            }
        }
        // Move curr to prev
        prev_dp = curr_dp;
    }

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        if (prev_dp[i] != INF) {
            int cost = prev_dp[i];
            if (i < N - 1) {
                cost++;
            }
            ans = min(ans, cost);
        }
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
