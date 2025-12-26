#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N + 1);
    vector<int> fixed_pos(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        if (A[i] != 0) {
            fixed_pos[A[i]] = i;
        }
    }

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> max_fixed_neighbor(N + 1, 0);
    vector<int> zeros_in_neighbors(N + 1, 0);

    for (int u = 1; u <= N; ++u) {
        for (int v : adj[u]) {
            if (A[v] != 0) {
                max_fixed_neighbor[u] = max(max_fixed_neighbor[u], A[v]);
            } else {
                zeros_in_neighbors[u]++;
            }
        }
    }

    vector<vector<int>> buckets(N + 1);
    for (int u = 1; u <= N; ++u) {
        if (A[u] == 0) {
            buckets[max_fixed_neighbor[u]].push_back(u);
        }
    }

    int current_min_req = 1e9;
    int C_fixed_small = 0;

    for (int K = 1; K <= N; ++K) {
        // Add candidates from bucket[K-1]
        // These are u with A[u]==0 and max_fixed_neighbor[u] == K-1 < K
        for (int u : buckets[K - 1]) {
            current_min_req = min(current_min_req, zeros_in_neighbors[u]);
        }

        int budget = (K - 1) - C_fixed_small;

        if (fixed_pos[K] != 0) {
            int u = fixed_pos[K];
            if (max_fixed_neighbor[u] < K) {
                if (zeros_in_neighbors[u] <= budget) {
                    cout << K << endl;
                    return;
                }
            }
        } else {
            if (current_min_req <= budget) {
                cout << K << endl;
                return;
            }
        }

        if (fixed_pos[K] != 0) {
            C_fixed_small++;
        }
    }
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

