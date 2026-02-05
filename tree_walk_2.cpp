#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long MOD = 998244353;
vector<vector<int>> adj;
vector<int> parent_node;
vector<bool> on_path;
vector<long long> memo_D;

bool find_path(int u, int target, int p, vector<int>& path) {
    path.push_back(u);
    if (u == target) return true;
    for (int v : adj[u]) {
        if (v != p) {
            if (find_path(v, target, u, path)) return true;
        }
    }
    path.pop_back();
    return false;
}

long long get_D(int u, int p) {
    long long sum_children = 0;
    for (int v : adj[u]) {
        if (v != p && !on_path[v]) {
            sum_children = (sum_children + get_D(v, u)) % MOD;
        }
    }
    return (1 + sum_children) % MOD;
}

void solve() {
    int N;
    if (!(cin >> N)) return;

    adj.assign(N + 1, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (N == 1) {
        cout << 1 << endl;
        return;
    }

    vector<int> path;
    find_path(1, N, 0, path);

    on_path.assign(N + 1, false);
    for (int u : path) on_path[u] = true;

    int m = path.size();
    vector<long long> H(m);


    for (int i = 0; i < m; ++i) {
        int u = path[i];
        long long sum_subtrees = 0;
        for (int v : adj[u]) {
            if (!on_path[v]) {
                sum_subtrees = (sum_subtrees + get_D(v, u)) % MOD;
            }
        }
        H[i] = (1 + sum_subtrees) % MOD;
    }

    long long dp1 = 1;
    long long dp2 = 0;

    for (int i = 0; i < m - 1; ++i) {
        long long next_dp1 = 0;
        long long next_dp2 = 0;



        long long ways_to_next_1 = (dp1 * H[i]) % MOD;
        long long ways_to_next_2 = (dp1) % MOD; // No detour -> Type 2 relation

        next_dp1 = (next_dp1 + ways_to_next_1) % MOD;
        next_dp2 = (next_dp2 + ways_to_next_2) % MOD;

        long long from_2_to_1 = dp2;

        next_dp1 = (next_dp1 + from_2_to_1) % MOD;

        dp1 = next_dp1;
        dp2 = next_dp2;


    }


    dp1 = 1; dp2 = 0;

    for (int i = 0; i < m - 1; ++i) {
        long long next_dp1 = 0;
        long long next_dp2 = 0;

        long long term1 = (dp1 * H[i]) % MOD;
        long long term2 = dp2;

        next_dp1 = (term1 + term2) % MOD;

        if (i < m - 2) {
             next_dp2 = dp1;
        } else {
            next_dp2 = 0;
        }

        dp1 = next_dp1;
        dp2 = next_dp2;
    }


    cout << dp1 << endl;
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
