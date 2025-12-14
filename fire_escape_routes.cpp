#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, int& size) {
    visited[u] = true;
    size++;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, size);
        }
    }
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);
    long long routes = 0;
    long long ways = 1;

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            routes++;
            int size = 0;
            dfs(i, adj, visited, size);
            ways = (ways * size) % MOD;
        }
    }

    cout << routes << " " << ways << endl;
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

