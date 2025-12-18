#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

vector<vector<int>> adj;
vector<int> sz;

vector<long long> dfs(int u, int p) {
    sz[u] = 1;
    vector<long long> g1(1, 0);
    vector<long long> g2(1, 0);

    int current_size = 0;

    vector<long long> sum_children_total;

    for (int v : adj[u]) {
        if (v == p) continue;

        vector<long long> T = dfs(v, u);

        if (sum_children_total.size() < T.size()) {
            sum_children_total.resize(T.size(), 0);
        }
        for (int i = 0; i < T.size(); ++i) {
            sum_children_total[i] = (sum_children_total[i] + T[i]) % MOD;
        }

        int child_size = T.size() - 1;
        int new_size = current_size + child_size;

        vector<long long> next_g1(new_size + 1, 0);
        vector<long long> next_g2(new_size + 1, 0);

        for (int i = 0; i <= current_size; ++i) {
            next_g1[i] = g1[i];
            next_g2[i] = g2[i];
        }

        for (int j = 1; j <= child_size; ++j) {
            if (T[j] == 0) continue;

            // g0 * T -> contributes to g1
            // g0 is 1 at index 0
            next_g1[j] = (next_g1[j] + T[j]) % MOD;

            for (int i = 0; i <= current_size; ++i) {
                if (g1[i] > 0) {
                    next_g2[i + j] = (next_g2[i + j] + g1[i] * T[j]) % MOD;
                }
                if (g2[i] > 0) {
                    next_g2[i + j] = (next_g2[i + j] + g2[i] * T[j]) % MOD;
                }
            }
        }

        g1 = next_g1;
        g2 = next_g2;
        current_size = new_size;
        sz[u] += sz[v];
    }

    vector<long long> total(sz[u] + 1, 0);

    for (int s = 0; s <= current_size; ++s) {
        long long ways = 0;
        if (s == 0) ways = 1; // g0
        ways = (ways + g1[s]) % MOD;
        ways = (ways + 2 * g2[s]) % MOD;

        if (s + 1 < total.size()) {
            total[s + 1] = ways;
        }
    }

    for (int i = 0; i < sum_children_total.size(); ++i) {
        if (i < total.size()) {
            total[i] = (total[i] + sum_children_total[i]) % MOD;
        }
    }

    return total;
}

void solve() {
    int N;
    cin >> N;
    adj.assign(N + 1, vector<int>());
    sz.assign(N + 1, 0);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> ans = dfs(1, 0);

    for (int k = 1; k <= N; ++k) {
        cout << ans[k] << (k == N ? "" : " ");
    }
    cout << endl;
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
