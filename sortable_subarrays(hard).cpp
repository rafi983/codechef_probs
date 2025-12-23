#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF_VAL = 2e18; // Larger than any A_i

struct Node {
    long long val; // Represents the value at the left end of the range (max value in range)
    long long lazy_add;
    long long lazy_set;
};

vector<Node> tree;
int n;

void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;

    // Propagate Set
    if (tree[v].lazy_set != -1) {
        long long set_val = tree[v].lazy_set;

        tree[2*v].lazy_set = set_val;
        tree[2*v].lazy_add = 0;
        tree[2*v].val = set_val;

        tree[2*v+1].lazy_set = set_val;
        tree[2*v+1].lazy_add = 0;
        tree[2*v+1].val = set_val;

        tree[v].lazy_set = -1;
    }

    // Propagate Add
    if (tree[v].lazy_add != 0) {
        long long add_val = tree[v].lazy_add;

        if (tree[2*v].lazy_set != -1) {
            tree[2*v].lazy_set += add_val;
        } else {
            tree[2*v].lazy_add += add_val;
        }
        tree[2*v].val += add_val;

        if (tree[2*v+1].lazy_set != -1) {
            tree[2*v+1].lazy_set += add_val;
        } else {
            tree[2*v+1].lazy_add += add_val;
        }
        tree[2*v+1].val += add_val;

        tree[v].lazy_add = 0;
    }
}

void update_add(int v, int tl, int tr, int l, int r, long long add) {
    if (l > r) return;
    if (l == tl && r == tr) {
        if (tree[v].lazy_set != -1) {
            tree[v].lazy_set += add;
        } else {
            tree[v].lazy_add += add;
        }
        tree[v].val += add;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update_add(2*v, tl, tm, l, min(r, tm), add);
        update_add(2*v+1, tm+1, tr, max(l, tm+1), r, add);
        tree[v].val = max(tree[2*v].val, tree[2*v+1].val);
    }
}

void update_set(int v, int tl, int tr, int l, int r, long long val) {
    if (l > r) return;
    if (l == tl && r == tr) {
        tree[v].lazy_set = val;
        tree[v].lazy_add = 0;
        tree[v].val = val;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update_set(2*v, tl, tm, l, min(r, tm), val);
        update_set(2*v+1, tm+1, tr, max(l, tm+1), r, val);
        tree[v].val = max(tree[2*v].val, tree[2*v+1].val);
    }
}

void update_point(int v, int tl, int tr, int pos, long long val) {
    if (tl == tr) {
        tree[v].val = val;
        tree[v].lazy_add = 0;
        tree[v].lazy_set = -1;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_point(2*v, tl, tm, pos, val);
        else
            update_point(2*v+1, tm+1, tr, pos, val);
        tree[v].val = max(tree[2*v].val, tree[2*v+1].val);
    }
}

// Find largest index k in [l, r] such that val(k) > limit
int find_last_greater(int v, int tl, int tr, int l, int r, long long limit) {
    if (l > r) return -1;
    // Optimization: if max value in this node <= limit, then no element > limit
    if (tree[v].val <= limit) return -1;

    if (tl == tr) {
        return tl;
    }

    push(v, tl, tr);
    int tm = (tl + tr) / 2;

    // Check right child first
    int res = find_last_greater(2*v+1, tm+1, tr, max(l, tm+1), r, limit);
    if (res != -1) return res;

    return find_last_greater(2*v, tl, tm, l, min(r, tm), limit);
}

long long query_val(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return tree[v].val;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm) return query_val(2*v, tl, tm, pos);
    else return query_val(2*v+1, tm+1, tr, pos);
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize tree
    // Size 4*N
    tree.assign(4 * N + 1, {0, 0, -1});

    long long total_ans = 0;
    int L_start = 1; // 1-based index

    for (int i = 1; i <= N; ++i) {
        long long Ai = A[i-1];
        long long Mi = (Ai - 1) / 2;

        if (L_start <= i - 1) {
            // 1. Add 1 to all active
            update_add(1, 1, N, L_start, i - 1, 1);

            // 2. Find range that exceeds Mi
            // We want largest k in [L_start, i-1] such that val(k) > Mi
            int k = find_last_greater(1, 1, N, L_start, i - 1, Mi);

            if (k != -1) {

                int p = find_last_greater(1, 1, N, L_start, k, Ai);

                if (p != -1) {
                    // Range [L_start, p] dies.
                    L_start = p + 1;
                }

                // Range [max(L_start, p+1), k] sets to Ai
                int set_l = (p == -1) ? L_start : p + 1;
                if (set_l <= k) {
                    update_set(1, 1, N, set_l, k, Ai);
                }
            }
        }

        // 3. Add new element at i with value 0
        update_point(1, 1, N, i, 0);

        // 4. Add valid count
        if (L_start <= i) {
            total_ans += (i - L_start + 1);
        }


    }

    cout << total_ans << endl;
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
