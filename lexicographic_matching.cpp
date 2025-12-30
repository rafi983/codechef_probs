#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 3005;

int dp[MAXN][MAXN];
vector<int> adj[MAXN];
int B[MAXN];
int last_pos[MAXN];

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    for (int i = 1; i <= N; ++i) {
        cin >> B[i];
    }

    // Validation
    if (B[1] != 1) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (B[i] > i) {
            cout << 0 << "\n";
            return;
        }
        if (i > 1 && B[i] > B[i-1] + 1) {
            cout << 0 << "\n";
            return;
        }
    }

    // Build Tree
    for (int i = 0; i <= N; ++i) adj[i].clear();
    for (int i = 0; i <= N; ++i) last_pos[i] = 0;

    for (int i = 1; i <= N; ++i) {
        int parent = 0;
        if (B[i] > 1) {
            parent = last_pos[B[i] - 1];
        }
        adj[parent].push_back(i);
        last_pos[B[i]] = i;
    }



    for (int u = N; u >= 0; --u) {
        vector<int> cur(K + 1, 0);
        cur[0] = 1;

        for (int v : adj[u]) {
            vector<int> next_cur(K + 1, 0);
            long long sum_prev = 0;
            for (int y = 1; y <= K; ++y) {
                sum_prev = (sum_prev + cur[y-1]);
                if (sum_prev >= MOD) sum_prev -= MOD;

                long long ways = (long long)dp[v][y] * sum_prev % MOD;
                next_cur[y] = ways;
            }
            cur = next_cur;
        }

        // Compute dp[u][val] = sum(cur[0...val])
        long long current_sum = 0;
        for (int val = 0; val <= K; ++val) {
            current_sum = (current_sum + cur[val]);
            if (current_sum >= MOD) current_sum -= MOD;
            if (val > 0) dp[u][val] = current_sum;
        }
    }

    cout << dp[0][K] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}

