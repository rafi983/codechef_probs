#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 2005;
const int LOGN = 12;

vector<int> adj[MAXN];
int up[MAXN][LOGN];
int depth[MAXN];
int sub[MAXN];
int tin[MAXN], tout[MAXN];
int timer;
long long memo[MAXN][MAXN];
int N;

void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p;
    tin[u] = ++timer;
    sub[u] = 1;
    for (int i = 1; i < LOGN; ++i) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            sub[u] += sub[v];
        }
    }
    tout[u] = timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_neighbor_towards(int u, int target) {
    if (u == target) return -1;
    if (is_ancestor(u, target)) {
        int v = target;
        for (int i = LOGN - 1; i >= 0; --i) {
            if (depth[v] - (1 << i) > depth[u]) {
                v = up[v][i];
            }
        }

        if (depth[v] > depth[u] + 1) v = up[v][0]; // Should be covered by loop logic if correct
        // Actually standard binary lifting to find K-th ancestor:
        // We want ancestor at depth[u] + 1.
        int k = depth[target] - (depth[u] + 1);
        v = target;
        for(int i=0; i<LOGN; ++i){
            if((k >> i) & 1) v = up[v][i];
        }
        return v;
    } else {
        return up[u][0];
    }
}

int get_W(int u, int v) {
    // Size of component at u when edge (u, v) is removed
    if (v == up[u][0]) {
        // v is parent of u
        return sub[u];
    } else {
        // v is child of u
        return N - sub[v];
    }
}

long long solve(int u, int v) {
    if (u > v) swap(u, v);
    if (memo[u][v] != -1) return memo[u][v];

    long long res = 0;

    if (u == v) {

        for (int w : adj[u]) {

            long long current_term = (long long)get_W(w, u) * get_W(u, w);
            res = max(res, current_term + solve(w, u));
        }
    } else {
        int nu = get_neighbor_towards(u, v);
        int nv = get_neighbor_towards(v, u);

        long long L = get_W(u, nu);
        long long R = get_W(v, nv);

        // Try extending u
        for (int w : adj[u]) {
            if (w != nu) {
                long long current_term = (long long)get_W(w, u) * R;
                res = max(res, current_term + solve(w, v));
            }
        }

        // Try extending v
        for (int w : adj[v]) {
            if (w != nv) {
                long long current_term = L * (long long)get_W(w, v);
                res = max(res, current_term + solve(u, w));
            }
        }
    }

    return memo[u][v] = res;
}

void solve_test_case() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    timer = 0;
    dfs(1, 1, 0);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            memo[i][j] = -1;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        // Calculate Cost(i, i)
        long long paths_passing_i = (long long)N * (N + 1) / 2;
        for (int w : adj[i]) {
            long long sw = get_W(w, i);
            paths_passing_i -= sw * (sw + 1) / 2;
        }
        ans = max(ans, paths_passing_i + solve(i, i));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve_test_case();
    }
    return 0;
}

