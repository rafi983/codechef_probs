#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int rev_idx;
};

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<vector<Edge>> adj(N + 1);
    for (int i = 2; i <= N; ++i) {
        int p;
        cin >> p;
        int u = i;
        int v = p;
        // u connects to v. v's current size is the index where u will be stored in v.
        adj[u].push_back({v, (int)adj[v].size()});
        // v connects to u. u's current size - 1 is the index where v is stored in u.
        adj[v].push_back({u, (int)adj[u].size() - 1});
    }

    for (int i = 1; i <= N; ++i) {
        if (adj[i].size() % 2 == 0) {
            cout << -1 << "\n";
            return;
        }
    }

    vector<vector<int>> mate(N + 1);
    for (int i = 1; i <= N; ++i) {
        int d = adj[i].size();
        mate[i].resize(d);
        // Pair 0 with 1, 2 with 3, ..., leaving the last one unpaired
        for (int j = 0; j < d - 1; j += 2) {
            mate[i][j] = j + 1;
            mate[i][j + 1] = j;
        }
        mate[i][d - 1] = -1; // The last one is unpaired (terminal)
    }

    vector<int> color(N + 1, 0);
    int current_c = 1;

    for (int i = 1; i <= N; ++i) {
        if (color[i] != 0) continue;

        int u = i;
        int edge_idx = adj[u].size() - 1; // The unpaired one

        while (edge_idx != -1) {
            int v = adj[u][edge_idx].to;
            int rev = adj[u][edge_idx].rev_idx;

            // Move to v
            u = v;
            // Find mate at v
            edge_idx = mate[u][rev];
        }

        // u is the other endpoint
        color[i] = current_c;
        color[u] = current_c;
        current_c++;
    }

    for (int i = 1; i <= N; ++i) {
        cout << color[i] << (i == N ? "" : " ");
    }
    cout << "\n";
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

