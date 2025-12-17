#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N, K;
vector<vector<int>> adj;
vector<int> sub_sz;

struct NodeDP {
    vector<int> d[2];

    void init(int size) {
        d[0].assign(size + 1, INF);
        d[1].assign(size + 1, INF);
    }
};

struct Choice {
    int k_child;
    int c_child;
};

// choices[u][child_idx][c_u][k_after]
vector<vector<vector<vector<Choice>>>> choices;
bool record_choices = false;

NodeDP dfs(int u, int p, int H) {
    NodeDP res;
    res.init(1);
    res.d[0][0] = 0;
    res.d[1][1] = 0;
    sub_sz[u] = 1;

    if (record_choices) {
        choices[u].clear();
    }

    for (int v : adj[u]) {
        if (v == p) continue;

        NodeDP child_res = dfs(v, u, H);

        NodeDP next_res;
        next_res.init(sub_sz[u] + sub_sz[v]);

        if (record_choices) {
            choices[u].push_back(vector<vector<Choice>>(2, vector<Choice>(sub_sz[u] + sub_sz[v] + 1, {-1, -1})));
        }

        for (int c_u = 0; c_u < 2; ++c_u) {
            for (int k_u = 0; k_u <= sub_sz[u]; ++k_u) {
                if (res.d[c_u][k_u] > H) continue;

                for (int c_v = 0; c_v < 2; ++c_v) {
                    for (int k_v = 0; k_v <= sub_sz[v]; ++k_v) {
                        if (child_res.d[c_v][k_v] > H) continue;

                        int w = (c_u != c_v);
                        int depth_via_v = child_res.d[c_v][k_v] + w;

                        if (res.d[c_u][k_u] + depth_via_v <= H) {
                            int new_max = max(res.d[c_u][k_u], depth_via_v);
                            int new_k = k_u + k_v;

                            if (new_max < next_res.d[c_u][new_k]) {
                                next_res.d[c_u][new_k] = new_max;
                                if (record_choices) {
                                    choices[u].back()[c_u][new_k] = {k_v, c_v};
                                }
                            }
                        }
                    }
                }
            }
        }

        sub_sz[u] += sub_sz[v];
        res = next_res;
    }
    return res;
}

vector<int> final_labels;

void reconstruct(int u, int p, int k, int c) {
    final_labels[u-1] = c;

    vector<int> children;
    for (int v : adj[u]) {
        if (v != p) children.push_back(v);
    }

    int current_k = k;

    for (int i = children.size() - 1; i >= 0; --i) {
        int v = children[i];
        Choice ch = choices[u][i][c][current_k];
        reconstruct(v, u, ch.k_child, ch.c_child);
        current_k -= ch.k_child;
    }
}

bool check(int H) {
    record_choices = false;
    NodeDP res = dfs(1, -1, H);
    return (res.d[0][K] <= H || res.d[1][K] <= H);
}

void solve() {
    if (!(cin >> N >> K)) return;
    adj.assign(N + 1, vector<int>());
    sub_sz.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int low = 0, high = N, ans_H = N;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans_H = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans_H + 1 << endl;

    record_choices = true;
    choices.assign(N + 1, {});
    NodeDP res = dfs(1, -1, ans_H);

    final_labels.assign(N, 0);
    int start_c = -1;
    if (res.d[0][K] <= ans_H) start_c = 0;
    else if (res.d[1][K] <= ans_H) start_c = 1;

    reconstruct(1, -1, K, start_c);

    for (int i = 0; i < N; ++i) {
        cout << final_labels[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;
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

