#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <map>

using namespace std;

typedef long long ll;

vector<unsigned long long> pos_hash;
unsigned long long get_pos_hash(int r, int c, int M) {
    return pos_hash[(r - 1) * M + (c - 1)];
}

struct Corner {
    int r, c;
};

int corner_parent[4];
int find_set(int v) {
    if (v == corner_parent[v]) return v;
    return corner_parent[v] = find_set(corner_parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) corner_parent[b] = a;
}

bool check(int X, int N, int M, const vector<vector<int>>& grid, const vector<pair<int, int>>& targets) {
    int corners_connected_mask[4] = {0}; // Stores mask of corner connections for each corner itself? No need.

    for(int i=0; i<4; ++i) corner_parent[i] = i;

    auto dist = [&](int r1, int c1, int r2, int c2) {
        return 1LL * (abs(r1 - r2) + 1) * (abs(c1 - c2) + 1);
    };

    int rs[4] = {1, 1, N, N};
    int cs[4] = {1, M, 1, M};

    for(int i=0; i<4; ++i) {
        for(int j=i+1; j<4; ++j) {
            if (dist(rs[i], cs[i], rs[j], cs[j]) >= X) {
                union_sets(i, j);
            }
        }
    }

    bool use_corner_logic = (X > max(N, M));

    unsigned long long comp_xor[4] = {0, 0, 0, 0};

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int mask = 0;
            if (1LL * i * j >= X) mask |= 1;
            if (1LL * i * (M - j + 1) >= X) mask |= 2;
            if (1LL * (N - i + 1) * j >= X) mask |= 4;
            if (1LL * (N - i + 1) * (M - j + 1) >= X) mask |= 8;

            if (mask == 0) {
                // Isolated
                int val = grid[i-1][j-1];
                // Target pos
                int tr = targets[val].first;
                int tc = targets[val].second;
                if (tr != i || tc != j) return false;
            } else if (use_corner_logic) {
                // Determine root component
                int root = -1;
                for(int k=0; k<4; ++k) {
                    if ((mask >> k) & 1) {
                        if (root == -1) root = find_set(k);
                        else union_sets(root, k);
                    }
                }

            }
        }
    }

    if (!use_corner_logic) return true; // Heuristic: Single component unless isolated

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int mask = 0;
            if (1LL * i * j >= X) mask |= 1;
            if (1LL * i * (M - j + 1) >= X) mask |= 2;
            if (1LL * (N - i + 1) * j >= X) mask |= 4;
            if (1LL * (N - i + 1) * (M - j + 1) >= X) mask |= 8;

            if (mask != 0) {
                // Find ANY corner in mask
                int k = 0;
                while(!((mask >> k) & 1)) k++;
                int root = find_set(k);

                unsigned long long h_curr = get_pos_hash(i, j, M); // Hash of current position

                int val = grid[i-1][j-1];
                int tr = targets[val].first;
                int tc = targets[val].second;
                unsigned long long h_target = get_pos_hash(tr, tc, M); // Hash of target position (which is unique to value)


                int root_target_pos = -1;
                // Target pos connectivity
                int t_mask = 0;
                if (1LL * tr * tc >= X) t_mask |= 1;
                if (1LL * tr * (M - tc + 1) >= X) t_mask |= 2;
                if (1LL * (N - tr + 1) * tc >= X) t_mask |= 4;
                if (1LL * (N - tr + 1) * (M - tc + 1) >= X) t_mask |= 8;

                if (t_mask == 0) return false; // Target is isolated? If current is not isolated, but target is, impossible.

                // Find root of target
                int tk = 0;
                while(!((t_mask >> tk) & 1)) tk++;
                int t_root = find_set(tk);

                if (root != t_root) return false;
            }
        }
    }
    return true;
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    vector<vector<int>> grid(N, vector<int>(M));
    vector<pair<int, int>> targets(N * M + 1);
    for (int i = 1; i <= N * M; ++i) {
        targets[i] = { (i - 1) / M + 1, (i - 1) % M + 1 };
    }


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    int low = 1, high = N * M + 1;
    int ans = 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, N, M, grid, targets)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Init Hash
    mt19937_64 rng(1337);
    int MAX_NM = 200005; // Sum constraint
    pos_hash.resize(MAX_NM);
    for(int i=0; i<MAX_NM; ++i) pos_hash[i] = rng();

    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}
