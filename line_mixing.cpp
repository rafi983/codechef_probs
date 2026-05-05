#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

static long long mod_pow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

static long long fall_perm_mod(long long n, int m) {
    if (n < m) return 0;
    long long r = 1;
    for (int i = 0; i < m; ++i) {
        r = (r * ((n - i) % MOD)) % MOD;
    }
    return r;
}

static long long count_assignments_for_weights(
    const vector<int>& weights,
    const vector<long long>& cnt_q
) {
    int r = (int)weights.size();
    vector<int> block_sum;
    long long total = 0;

    function<void(int)> dfs = [&](int idx) {
        if (idx == r) {
            unordered_map<int, int> need;
            for (int s : block_sum) ++need[s];

            long long ways = 1;
            for (auto &it : need) {
                int v = it.first;
                int c = it.second;
                if (v < 0 || v >= (int)cnt_q.size()) {
                    ways = 0;
                    break;
                }
                ways = (ways * fall_perm_mod(cnt_q[v], c)) % MOD;
                if (ways == 0) break;
            }
            total += ways;
            if (total >= MOD) total -= MOD;
            return;
        }

        for (int b = 0; b < (int)block_sum.size(); ++b) {
            block_sum[b] += weights[idx];
            dfs(idx + 1);
            block_sum[b] -= weights[idx];
        }

        block_sum.push_back(weights[idx]);
        dfs(idx + 1);
        block_sum.pop_back();
    };

    dfs(0);
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m, x, k;
        cin >> n >> m >> x >> k;

        vector<int> s(k);
        for (int i = 0; i < k; ++i) cin >> s[i];

        vector<pair<int, int>> edges;
        edges.reserve(m);
        vector<vector<char>> adj(n + 1, vector<char>(n + 1, 0));
        vector<int> deg(n + 1, 0);

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            adj[u][v] = adj[v][u] = 1;
            ++deg[u];
            ++deg[v];
        }

        int W = 1 << x;
        vector<long long> cnt_q(W + 1, 0);
        bool ok = true;
        for (int i = 0; i < k; ++i) {
            long long num = 1LL * s[i] * W;
            if (num % 1024 != 0) {
                ok = false;
                break;
            }
            long long qv = num / 1024;
            if (qv < 0 || qv > W) {
                ok = false;
                break;
            }
            ++cnt_q[(int)qv];
        }

        if (!ok) {
            cout << 0 << '\n';
            continue;
        }

        long long inv_k = mod_pow(k, MOD - 2);

        auto prob_for_weights = [&](const vector<int>& w) {
            long long cnt = count_assignments_for_weights(w, cnt_q);
            long long denom_inv = mod_pow(inv_k, (int)w.size());
            return (cnt * denom_inv) % MOD;
        };

        long long ans = 0;

        if (x == 1) {
            long long p = prob_for_weights({1, 1});
            ans = (1LL * m % MOD) * p % MOD;
        } else if (x == 2) {
            long long wedges = 0;
            for (int v = 1; v <= n; ++v) {
                wedges += 1LL * deg[v] * (deg[v] - 1) / 2;
            }
            long long p = prob_for_weights({1, 2, 1});
            ans = (wedges % MOD) * p % MOD;
        } else {
            long long p_same_side = prob_for_weights({4, 2, 1, 1});
            long long p_cross_diff = prob_for_weights({3, 3, 1, 1});
            long long p_cross_same_outer = prob_for_weights({3, 3, 2});

            for (auto &e : edges) {
                int u = e.first, v = e.second;

                long long du = deg[u], dv = deg[v];
                long long cnt1 = du >= 2 ? (du - 1) * (du - 2) / 2 : 0;
                cnt1 += dv >= 2 ? (dv - 1) * (dv - 2) / 2 : 0;

                long long common = 0;
                for (int w = 1; w <= n; ++w) {
                    if (w == u || w == v) continue;
                    if (adj[u][w] && adj[v][w]) ++common;
                }

                long long cnt3 = common;
                long long cnt2 = (du - 1) * (dv - 1) - common;

                ans = (ans + (cnt1 % MOD) * p_same_side) % MOD;
                ans = (ans + (cnt2 % MOD) * p_cross_diff) % MOD;
                ans = (ans + (cnt3 % MOD) * p_cross_same_outer) % MOD;
            }
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}
