#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v;
    int w;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

struct DSU {
    vector<int> parent;
    vector<long long> S;
    vector<long long> R;

    DSU(int n, const vector<long long>& B) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        S = vector<long long>(n + 1);
        R = vector<long long>(n + 1);
        for (int i = 1; i <= n; ++i) {
            S[i] = B[i-1];
            R[i] = B[i-1];
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j, int w) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            long long S1 = S[root_i];
            long long R1 = R[root_i];
            long long S2 = S[root_j];
            long long R2 = R[root_j];

            // Option 1: C1 -> C2
            // We clear C1 first, then cross to C2.
            // Requirement: max(R1, w + S1, R2 + S1)
            long long opt1 = max({R1, (long long)w + S1, R2 + S1});

            // Option 2: C2 -> C1
            // We clear C2 first, then cross to C1.
            // Requirement: max(R2, w + S2, R1 + S2)
            long long opt2 = max({R2, (long long)w + S2, R1 + S2});

            long long R_new = min(opt1, opt2);
            long long S_new = S1 + S2;

            parent[root_j] = root_i;
            S[root_i] = S_new;
            R[root_i] = R_new;
        }
    }
};

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<long long> B(N);
    for (int i = 0; i < N; ++i) cin >> B[i];

    vector<Edge> edges;
    edges.reserve(M);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        // The weight of an edge is the max of the pass values of its endpoints
        int w = max((int)A[u-1], (int)A[v-1]);
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(N, B);

    for (const auto& edge : edges) {
        dsu.unite(edge.u, edge.v, edge.w);
    }

    // Since the graph is connected, all nodes will be in the same component eventually.
    // We can check the root of any node, e.g., node 1.
    int root = dsu.find(1);
    cout << dsu.R[root] << endl;
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

