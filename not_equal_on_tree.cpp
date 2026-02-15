#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

struct Result {
    int min_size;
    int ways;
};

Result merge(const Result& a, const Result& b) {
    if (a.min_size < b.min_size) return a;
    if (b.min_size < a.min_size) return b;
    return {a.min_size, (a.ways + b.ways) % MOD};
}

int N;
vector<int> A, B;
vector<vector<int>> adj;
vector<bool> is_bad;
vector<bool> in_hull;
vector<int> parent;
int bad_count;
int root_bad;

void dfs_parent(int u, int p) {
    parent[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_parent(v, u);
        }
    }
}

// Mark nodes on path from u to root as in_hull
void mark_path(int u) {
    int curr = u;
    while (curr != -1 && !in_hull[curr]) {
        in_hull[curr] = true;
        curr = parent[curr];
    }
}

vector<Result> solve_subtree(int u, int p, int violator_val) {


    bool is_good = (A[u] != violator_val && B[u] != violator_val);

    // Base case: just node u
    vector<Result> dp;
    if (is_good) {
        dp = {{INF, 0}, {1, 1}}; // 0 good impossible with non-empty subtree rooted at u?

    } else {
        dp = {{1, 1}}; // 0 good nodes, size 1, ways 1
    }

    for (int v : adj[u]) {
        if (v != p) {
            vector<Result> child_dp = solve_subtree(v, u, violator_val);


            vector<Result> next_dp(dp.size() + child_dp.size(), {INF, 0});

            // Iterate current state
            for (int i = 0; i < dp.size(); ++i) {
                if (dp[i].min_size == INF) continue;

                // Option 1: Don't extend to child v
                next_dp[i] = merge(next_dp[i], dp[i]);

                // Option 2: Extend to child v with j good nodes
                for (int j = 0; j < child_dp.size(); ++j) {
                    if (child_dp[j].min_size == INF) continue;

                    int nk = i + j;
                    int nsize = dp[i].min_size + child_dp[j].min_size;
                    int nways = (1LL * dp[i].ways * child_dp[j].ways) % MOD;

                    Result combined = {nsize, nways};
                    next_dp[nk] = merge(next_dp[nk], combined);
                }
            }
            dp = next_dp;
        }
    }
    return dp;
}

void solve() {
    if (!(cin >> N)) return;

    A.resize(N + 1);
    B.resize(N + 1);
    adj.assign(N + 1, vector<int>());
    is_bad.assign(N + 1, false);
    in_hull.assign(N + 1, false);
    parent.assign(N + 1, 0);
    vector<int> bad_nodes;

    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) cin >> B[i];

    for (int i = 1; i <= N; ++i) {
        if (A[i] == B[i]) {
            is_bad[i] = true;
            bad_nodes.push_back(i);
        }
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (bad_nodes.empty()) {
        cout << "0 1" << endl;
        return;
    }

    root_bad = bad_nodes[0];
    dfs_parent(root_bad, -1); // Parent of root is -1

    for (int u : bad_nodes) {
        mark_path(u);
    }

    // Calculate stats on Hull
    int hull_size = 0;
    map<int, int> freqA, freqB;
    for (int i = 1; i <= N; ++i) {
        if (in_hull[i]) {
            hull_size++;
            freqA[A[i]]++;
            freqB[B[i]]++;
        }
    }

    // Check feasibility
    int violator = -1;
    for (auto const& [val, count] : freqA) {
        if (count + freqB[val] > hull_size) {
            violator = val;
            break;
        }
    }
    // Also check freqB keys that might not be in freqA
    if (violator == -1) {
        for (auto const& [val, count] : freqB) {
             if (count + freqA[val] > hull_size) {
                violator = val;
                break;
            }
        }
    }

    if (violator == -1) {
        cout << hull_size << " " << 1 << endl;
        return;
    }

    int needed = freqA[violator] + freqB[violator] - hull_size;

    vector<Result> global_dp = {{0, 1}}; // cost 0 to get 0 good nodes (base hull)

    for (int i = 1; i <= N; ++i) {
        if (in_hull[i]) {
            for (int v : adj[i]) {
                if (!in_hull[v]) {

                    vector<Result> comp_dp = solve_subtree(v, i, violator); // i acts as parent


                    vector<Result> next_global(global_dp.size() + comp_dp.size(), {INF, 0});

                    for (int g = 0; g < global_dp.size(); ++g) {
                        if (global_dp[g].min_size == INF) continue;

                        // Option 1
                        next_global[g] = merge(next_global[g], global_dp[g]);

                        // Option 2
                        for (int c = 0; c < comp_dp.size(); ++c) {
                            if (comp_dp[c].min_size == INF) continue;

                            int nk = g + c;
                            int nsize = global_dp[g].min_size + comp_dp[c].min_size;
                            int nways = (1LL * global_dp[g].ways * comp_dp[c].ways) % MOD;

                            next_global[nk] = merge(next_global[nk], {nsize, nways});
                        }
                    }
                    global_dp = next_global;
                }
            }
        }
    }

    // Find result for at least needed
    Result answer = {INF, 0};


    for (int k = needed; k < global_dp.size(); ++k) {
        if (global_dp[k].min_size != INF) {
             answer = merge(answer, global_dp[k]);
        }
    }

    size_t k_needed = needed;
    if (k_needed < global_dp.size() && global_dp[k_needed].min_size != INF) {

    }

    if (answer.min_size == INF) {
        cout << "-1 -1" << endl;
    } else {
        cout << (hull_size + answer.min_size) << " " << answer.ways << endl;
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

