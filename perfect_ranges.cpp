#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;
    vector<int> lazy;

    SegmentTree(int n) : n(n) {
        tree.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, -1);
    }

    void push(int node) {
        if (lazy[node] != -1) {
            tree[2 * node] = lazy[node];
            lazy[2 * node] = lazy[node];
            tree[2 * node + 1] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
            lazy[node] = -1;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node] = val;
            lazy[node] = val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int find_first(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return -1;
        if (tree[node] >= val) return -1;
        if (start == end) return start;

        push(node);
        int mid = (start + end) / 2;
        int res = find_first(2 * node, start, mid, l, r, val);
        if (res != -1) return res;
        return find_first(2 * node + 1, mid + 1, end, l, r, val);
    }
};

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    SegmentTree st(N);
    long long ans = 0;
    int min_L = 1;

    for (int R = 1; R <= N; ++R) {
        int X = min(A[R-1], B[R-1]);
        int Y = max(A[R-1], B[R-1]);

        int idx_die = -1;
        if (min_L <= R - 1) {
            idx_die = st.find_first(1, 1, N, min_L, R - 1, Y);
        }

        if (idx_die == -1) {
            if (min_L <= R - 1) {
                min_L = R;
            }
        } else {
            min_L = idx_die;
        }

        int idx_split = -1;
        if (min_L <= R - 1) {
            idx_split = st.find_first(1, 1, N, min_L, R - 1, X);
        }

        if (idx_split == -1) {
            idx_split = R;
        }

        if (min_L <= idx_split - 1) {
            st.update(1, 1, N, min_L, idx_split - 1, Y);
        }

        st.update(1, 1, N, idx_split, R, X);

        ans += (long long)(R - min_L + 1);
    }
    cout << ans << endl;
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

