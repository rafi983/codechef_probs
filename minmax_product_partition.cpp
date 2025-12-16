#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

const int MAX_SIZE = 400005;
long long pow2[MAX_SIZE];

void precompute() {
    pow2[0] = 1;
    for (int i = 1; i < MAX_SIZE; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
}

struct Node {
    int cnt;
    long long X, Y, ans, S2;
    long long min_v, max_v;

    Node() : cnt(0), X(0), Y(0), ans(0), S2(0), min_v(-1), max_v(-1) {}
};

Node merge(const Node& L, const Node& R) {
    if (L.cnt == 0) return R;
    if (R.cnt == 0) return L;

    Node res;
    res.cnt = L.cnt + R.cnt;
    res.X = (L.X * pow2[R.cnt] + R.X) % MOD;
    res.Y = (L.Y + R.Y * pow2[L.cnt]) % MOD;
    res.ans = (L.ans + R.ans + L.X * R.Y) % MOD;

    res.S2 = (L.S2 + R.S2) % MOD;
    res.S2 = (res.S2 + L.max_v * R.min_v) % MOD;

    res.min_v = L.min_v;
    res.max_v = R.max_v;

    return res;
}

int N, Q;
vector<int> A;
vector<pair<int, int>> queries;
vector<long long> coords;
vector<int> counts; // Leaf counts
vector<Node> tree;
int sz;

void update_leaf(int idx, int val, int count) {
    tree[idx].cnt = count;
    if (count == 0) {
        tree[idx].X = tree[idx].Y = tree[idx].ans = tree[idx].S2 = 0;
        tree[idx].min_v = tree[idx].max_v = -1;
    } else {
        long long V = val % MOD;
        long long term = (pow2[count] - 1 + MOD) % MOD;
        tree[idx].X = (V * term) % MOD;
        tree[idx].Y = (V * term) % MOD;

        if (count > 1) {
            tree[idx].S2 = ((long long)(count - 1) * V % MOD * V) % MOD;
            long long ans_term = (pow2[count] - count - 1 + MOD) % MOD;
            tree[idx].ans = (V * V % MOD * ans_term) % MOD;
        } else {
            tree[idx].S2 = 0;
            tree[idx].ans = 0;
        }
        tree[idx].min_v = V;
        tree[idx].max_v = V;
    }
}

void update(int node, int start, int end, int idx, int val, int delta) {
    if (start == end) {
        counts[start] += delta;
        update_leaf(node, val, counts[start]);
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val, delta);
    else update(2 * node + 1, mid + 1, end, idx, val, delta);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void solve() {
    if (!(cin >> N >> Q)) return;

    A.resize(N);
    coords.clear();
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        coords.push_back(A[i]);
    }

    queries.resize(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        coords.push_back(queries[i].second);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    sz = coords.size();
    counts.assign(sz, 0);
    tree.assign(4 * sz, Node());

    auto get_coord = [&](long long val) {
        return lower_bound(coords.begin(), coords.end(), val) - coords.begin();
    };

    for (int i = 0; i < N; ++i) {
        int idx = get_coord(A[i]);
        update(1, 0, sz - 1, idx, A[i], 1);
    }

    auto print_ans = [&]() {
        long long total = (tree[1].ans + tree[1].S2) % MOD;
        cout << total << "\n";
    };

    print_ans();

    for (int i = 0; i < Q; ++i) {
        int x = queries[i].first - 1; // 0-indexed
        int v = queries[i].second;

        int old_val = A[x];
        int old_idx = get_coord(old_val);
        update(1, 0, sz - 1, old_idx, old_val, -1);

        A[x] = v;
        int new_idx = get_coord(v);
        update(1, 0, sz - 1, new_idx, v, 1);

        print_ans();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

