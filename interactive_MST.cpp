#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

int N, M;
vector<Edge> edges;
int cost[1 << 13];
int dp[1 << 13];
int adj[13][13]; // Adjacency matrix for cycle check, stores index of edge or -1
// Actually we need to handle multi-edges? Problem says simple graph.
// We just need to know if there is an edge.

bool has_cycle(int mask) {

    int visited = 0;

    for (int i = 0; i < N; ++i) {
        if (!((mask >> i) & 1)) continue;
        if ((visited >> i) & 1) continue;

        // Start DFS from i
        vector<pair<int, int>> stack; // node, parent
        stack.push_back({i, -1});
        visited |= (1 << i);

        while (!stack.empty()) {
            pair<int, int> curr = stack.back();
            stack.pop_back();
            int u = curr.first;
            int p = curr.second;

            for (int v = 0; v < N; ++v) {
                if (!((mask >> v) & 1)) continue;
                if (u == v) continue;
                if (adj[u][v] == -1) continue; // No edge

                if (v == p) continue;

                if ((visited >> v) & 1) return true; // Cycle detected

                visited |= (1 << v);
                stack.push_back({v, u});
            }
        }
    }
    return false;
}

void solve() {
    cin >> N >> M;
    edges.clear();
    int total_w = 0;

    // Reset adj
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            adj[i][j] = -1;

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.push_back({u, v, w});
        adj[u][v] = i;
        adj[v][u] = i;
        total_w += w;
    }

    // Precompute costs
    int num_masks = 1 << N;
    for (int mask = 0; mask < num_masks; ++mask) {
        // Check if forest
        // We can do this by checking edges vs vertices in components, or just cycle check
        // Cycle check is safer
        if (has_cycle(mask)) {
            cost[mask] = INF;
        } else {
            int current_w_sum = 0;
            int current_edges = 0;
            for (int i = 0; i < N; ++i) {
                if ((mask >> i) & 1) {
                    for (int j = i + 1; j < N; ++j) {
                        if ((mask >> j) & 1) {
                            if (adj[i][j] != -1) {
                                current_edges++;
                                current_w_sum += edges[adj[i][j]].w;
                            }
                        }
                    }
                }
            }
            cost[mask] = 2 * current_w_sum - current_edges;
        }
    }

    // DP
    for (int i = 0; i < num_masks; ++i) dp[i] = INF;
    dp[0] = 0;

    for (int mask = 1; mask < num_masks; ++mask) {
        int v = __builtin_ctz(mask); // Index of first set bit
        // Iterate submasks containing v
        for (int s = mask; s > 0; s = (s - 1) & mask) {
            if ((s >> v) & 1) {
                int prev = mask ^ s;
                if (dp[prev] != INF && cost[s] != INF) {
                    dp[mask] = min(dp[mask], dp[prev] + cost[s]);
                }
            }
        }
    }

    int ans = dp[num_masks - 1] + M - total_w;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

