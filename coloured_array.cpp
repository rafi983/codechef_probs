#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    vector<int> cnt2(N + 1, 0);
    vector<pair<int, int>> blocks;
    blocks.reserve(N);

    for (int i = 0; i < N; ++i) {
        int u = A[2 * i];
        int v = A[2 * i + 1];
        blocks.push_back({u, v});
        if (u == v) {
            cnt2[u]++;
        }
    }

    vector<bool> is_used(N + 1, false);
    long long score = 0;
    for (int i = 1; i <= N; ++i) {
        if (cnt2[i] > 0) {
            is_used[i] = true;
            score += 2;
        }
    }

    vector<int> S(N + 1, 0);
    vector<vector<int>> adj(N + 1);

    for (const auto& block : blocks) {
        int u = block.first;
        int v = block.second;

        if (u == v) continue;

        bool u_used = is_used[u];
        bool v_used = is_used[v];

        if (u_used && v_used) {
            continue;
        } else if (u_used && !v_used) {
            S[v]++;
        } else if (!u_used && v_used) {
            S[u]++;
        } else {
            // Both unused
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!is_used[i] && !visited[i]) {
            // Start traversal
            vector<int> q;
            q.push_back(i);
            visited[i] = true;

            int vertices = 0;
            int edges = 0;
            int s_sum = 0;

            int head = 0;
            while(head < q.size()){
                int u = q[head++];
                vertices++;
                s_sum += S[u];
                edges += adj[u].size();

                for(int v : adj[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push_back(v);
                    }
                }
            }

            edges /= 2;

            score += min((long long)vertices, (long long)edges + s_sum);
        }
    }

    cout << (2 * N - score) << endl;
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
