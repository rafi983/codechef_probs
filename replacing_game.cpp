#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

struct Operation {
    int index;
    char c;
};

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    string A, B;
    cin >> A >> B;

    int mismatch_count = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] != B[i]) {
            mismatch_count++;
        }
    }

    if (mismatch_count == 0) {
        cout << 0 << endl;
        return;
    }

    queue<int> q;
    vector<bool> is_queued(N - K + 1, false);

    int count = 0;
    for(int i = 0; i < N; ++i) {
        if(i == 0 || B[i] == B[i-1]) {
            count++;
        } else {
            count = 1;
        }
        if(count >= K) {
             int start_idx = i - K + 1;
             if(start_idx >= 0 && start_idx <= N - K) { // Check bounds just in case
                 q.push(start_idx);
                 is_queued[start_idx] = true;
             }
        }
    }

    if (q.empty()) {
        cout << -1 << endl;
        return;
    }

    vector<Operation> ops;
    DSU dsu(N); // To manage visited indices. parent[i] points to next unvisited.


    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int curr = dsu.find(u);

        if (curr < u + K) {


            char color = B[curr];
            ops.push_back({u + 1, color}); // 1-based index

            while (curr < u + K) {
                if (A[curr] != B[curr]) {
                    mismatch_count--;
                }

                dsu.unite(curr, curr + 1); // point curr to curr+1

                curr = dsu.find(curr);
            }

            // Add neighbors to queue if they exist and not queued
            if (u - 1 >= 0 && !is_queued[u - 1]) {
                is_queued[u - 1] = true;
                q.push(u - 1);
            }
            if (u + 1 <= N - K && !is_queued[u + 1]) {
                is_queued[u + 1] = true;
                q.push(u + 1);
            }
        } else {

             if (u - 1 >= 0 && !is_queued[u - 1]) {
                is_queued[u - 1] = true;
                q.push(u - 1);
            }
            if (u + 1 <= N - K && !is_queued[u + 1]) {
                is_queued[u + 1] = true;
                q.push(u + 1);
            }
        }
    }

    if (mismatch_count > 0) {
        cout << -1 << endl;
    } else {
        cout << ops.size() << endl;
        reverse(ops.begin(), ops.end());
        for (const auto& op : ops) {
            cout << op.index << " " << op.c << "\n";
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
