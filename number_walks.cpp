#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const long long INF = 1e18;

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    vector<int> A(N + 1);
    vector<vector<int>> pos(K + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        pos[A[i]].push_back(i);
    }

    vector<long long> dp(N + 1, INF);

    // Base case: last step (value K) has cost 0 to "finish"
    for (int idx : pos[K]) {
        dp[idx] = 0;
    }

    // Iterate backwards from K-1 to 1
    for (int val = K - 1; val >= 1; --val) {

        vector<int> combined;
        // Since both are sorted, we can merge them
        int i = 0, j = 0;
        while (i < pos[val].size() && j < pos[val+1].size()) {
            if (pos[val][i] < pos[val+1][j]) {
                combined.push_back(pos[val][i]);
                i++;
            } else {
                combined.push_back(pos[val+1][j]);
                j++;
            }
        }
        while (i < pos[val].size()) combined.push_back(pos[val][i++]);
        while (j < pos[val+1].size()) combined.push_back(pos[val+1][j++]);

        // Pass 1: Left to Right
        // min_prev tracks min(dp[v] - v) for v < current_idx
        long long min_prev = INF;
        for (int idx : combined) {
            if (A[idx] == val + 1) {
                if (dp[idx] != INF)
                    min_prev = min(min_prev, dp[idx] - idx);
            } else { // A[idx] == val
                if (min_prev != INF)
                    dp[idx] = min(dp[idx], min_prev + idx);
            }
        }

        // Pass 2: Right to Left
        // min_next tracks min(dp[v] + v) for v > current_idx
        long long min_next = INF;
        for (int k = combined.size() - 1; k >= 0; --k) {
            int idx = combined[k];
            if (A[idx] == val + 1) {
                if (dp[idx] != INF)
                    min_next = min(min_next, dp[idx] + idx);
            } else { // A[idx] == val
                if (min_next != INF)
                    dp[idx] = min(dp[idx], min_next - idx);
            }
        }
    }

    // Now we have dp[u] for u in pos[1].
    // We need to find min(|S - u| + dp[u]) for all S in 1..N

    vector<long long> ans(N + 1, INF);

    // Pass 1: Left to Right
    long long min_prev = INF;
    for (int s = 1; s <= N; ++s) {
        if (A[s] == 1) {
             if (dp[s] != INF)
                min_prev = min(min_prev, dp[s] - s);
        }
        if (min_prev != INF)
            ans[s] = min(ans[s], min_prev + s);
    }

    // Pass 2: Right to Left
    long long min_next = INF;
    for (int s = N; s >= 1; --s) {
        if (A[s] == 1) {
            if (dp[s] != INF)
                min_next = min(min_next, dp[s] + s);
        }
        if (min_next != INF)
            ans[s] = min(ans[s], min_next - s);
    }

    for (int s = 1; s <= N; ++s) {
        cout << ans[s] << (s == N ? "" : " ");
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

