#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353LL;

long long mod_pow2(long long exp) {
    long long base = 2 % MOD;
    long long res = 1 % MOD;
    while (exp > 0) {
        if (exp & 1LL) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1LL;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    const long long NEG = LLONG_MIN / 4;

    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N + 1);
        for (int i = 1; i <= N; ++i) cin >> A[i];
        vector<vector<int>> g(N + 1);
        for (int i = 0; i < N - 1; ++i) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> parent(N + 1, 0);
        vector<int> order; order.reserve(N);
        order.push_back(1);
        parent[1] = -1;
        for (size_t i = 0; i < order.size(); ++i) {
            int u = order[i];
            for (int v : g[u]) if (v != parent[u]) {
                parent[v] = u;
                order.push_back(v);
            }
        }

        vector<long long> dp_even(N + 1, NEG), dp_odd(N + 1, NEG);

        for (int idx = (int)order.size() - 1; idx >= 0; --idx) {
            int u = order[idx];
            long long w = llabs(A[u]);
            int p = (A[u] < 0);
            long long ce = NEG, co = NEG;
            if (p == 0) { ce = w; }
            else { co = w; }

            for (int v : g[u]) if (v != parent[u]) {
                long long nce = ce, nco = co;
                if (dp_even[v] != NEG) {
                    nce = max(nce, ce == NEG ? NEG : ce + dp_even[v]);
                    nco = max(nco, co == NEG ? NEG : co + dp_even[v]);
                }
                if (dp_odd[v] != NEG) {
                    nce = max(nce, co == NEG ? NEG : co + dp_odd[v]);
                    nco = max(nco, ce == NEG ? NEG : ce + dp_odd[v]);
                }
                ce = nce; co = nco;
            }
            dp_even[u] = ce;
            dp_odd[u] = co;
        }

        long long best_even = NEG, best_odd = NEG;
        for (int u = 1; u <= N; ++u) {
            best_even = max(best_even, dp_even[u]);
            best_odd  = max(best_odd,  dp_odd[u]);
        }

        long long ans_mod;
        if (best_even != NEG) {
            ans_mod = mod_pow2(best_even);
        } else {
            long long v = mod_pow2(best_odd);
            ans_mod = (MOD - v) % MOD;
        }

        cout << ans_mod << '\n';
    }
    return 0;
}

