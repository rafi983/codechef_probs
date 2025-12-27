#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<string> M(N);
    for (int i = 0; i < N; ++i) {
        cin >> M[i];
    }

    long long total_valid = 1;
    for (int i = 0; i < N; ++i) {
        int count = 0;
        for (char c : M[i]) {
            if (c == '1') count++;
        }
        total_valid = (total_valid * count) % MOD;
    }

    int K = N / 2;


    int offset = K * N;
    vector<long long> dp(offset + 1, 0);

    // Base case: sum 0 has 1 way.
    dp[offset] = 1;

    // Optimization: track reachable range
    int min_reachable = 0;
    int max_reachable = 0;

    for (int i = 0; i < K; ++i) {
        vector<int> valid_u;
        vector<int> valid_v;
        for(int val=1; val<=N; ++val) {
            if(M[i][val-1] == '1') valid_u.push_back(val);
            if(M[i+K][val-1] == '1') valid_v.push_back(val);
        }

        // Compute difference counts
        // diff range: -(N-1) to (N-1)
        vector<long long> diff_counts(2 * N, 0); // offset N
        int diff_offset = N;

        for(int u : valid_u) {
            for(int v : valid_v) {
                int d = v - u;
                diff_counts[d + diff_offset]++;
            }
        }

        vector<long long> next_dp(offset + 1, 0);

        int start_idx = max(0, min_reachable + offset);
        int end_idx = min(offset, max_reachable + offset);

        int new_min = offset + 1;
        int new_max = -1;

        for(int s_idx = start_idx; s_idx <= end_idx; ++s_idx) {
            if(dp[s_idx] == 0) continue;

            long long current_ways = dp[s_idx];
            int current_sum = s_idx - offset;

            for(int d = -(N-1); d <= (N-1); ++d) {
                if(diff_counts[d + diff_offset] == 0) continue;

                int next_sum = current_sum + d;
                if(next_sum <= 0) {
                    int next_idx = next_sum + offset;
                    if(next_idx >= 0 && next_idx <= offset) {
                        next_dp[next_idx] = (next_dp[next_idx] + current_ways * diff_counts[d + diff_offset]) % MOD;
                        if(next_idx < new_min) new_min = next_idx;
                        if(next_idx > new_max) new_max = next_idx;
                    }
                }
            }
        }

        if (new_max == -1) {
            min_reachable = 0;
            max_reachable = -1;
        } else {
            min_reachable = new_min - offset;
            max_reachable = new_max - offset;
        }

        dp = next_dp;
    }

    long long bad_arrays = dp[offset]; // Count of paths ending at sum 0
    long long ans = (total_valid - bad_arrays + MOD) % MOD;
    cout << ans << "\n";
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

