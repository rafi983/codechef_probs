#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct PrimorialInfo {
    long long val;
    int diff;
};

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v; // 0-indexed
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> B(N, 2LL * N);

    // Pairs of (Primorial, Difference to add)
    // M_3 = 2, diff = 3-2 = 1
    // M_5 = 6, diff = 5-3 = 2
    // ...
    vector<PrimorialInfo> primorials = {
        {2, 1},
        {6, 2},
        {30, 2},
        {210, 4},
        {2310, 2},
        {30030, 4},
        {510510, 2},
        {9699690, 4},
        {223092870, 6}
    };

    vector<bool> visited(N);
    vector<int> component;
    vector<int> q;
    q.reserve(N);

    for (const auto& info : primorials) {
        long long K = info.val;
        long long D = info.diff;

        fill(visited.begin(), visited.end(), false);

        for (int i = 0; i < N; ++i) {
            if (!visited[i] && A[i] % K == 0) {
                // Start BFS
                component.clear();
                q.clear();

                visited[i] = true;
                q.push_back(i);
                component.push_back(i);

                int head = 0;
                while(head < q.size()){
                    int u = q[head++];
                    for(int v : adj[u]){
                        if(!visited[v] && A[v] % K == 0){
                            visited[v] = true;
                            q.push_back(v);
                            component.push_back(v);
                        }
                    }
                }

                long long comp_size = component.size();
                long long add_val = D * comp_size;
                for (int u : component) {
                    B[u] += add_val;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << B[i] << (i == N - 1 ? "" : " ");
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

