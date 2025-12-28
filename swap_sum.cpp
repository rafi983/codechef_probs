#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int trans[2];
    long long sum[2];
};

int N;
long long K;
vector<long long> A_arr, B_arr;
vector<Node> tree;

void merge(Node& res, const Node& left, const Node& right) {
    res.trans[0] = right.trans[left.trans[0]];
    res.trans[1] = right.trans[left.trans[1]];
    res.sum[0] = left.sum[0] + right.sum[left.trans[0]];
    res.sum[1] = left.sum[1] + right.sum[left.trans[1]];
}

void build(int node, int start, int end) {
    if (start == end) {
        long long v1 = A_arr[start];
        long long v2 = B_arr[start];

        // Case 1: v1 + K < v2 -> SET 1
        if (v1 + K < v2) {
            tree[node].trans[0] = 1; tree[node].sum[0] = v2;
            tree[node].trans[1] = 1; tree[node].sum[1] = v2;
        }
        // Case 2: v2 + K < v1 -> SET 0
        else if (v2 + K < v1) {
            tree[node].trans[0] = 0; tree[node].sum[0] = v1;
            tree[node].trans[1] = 0; tree[node].sum[1] = v1;
        }
        // Case 3: MAINTAIN
        else {
            tree[node].trans[0] = 0; tree[node].sum[0] = v1;
            tree[node].trans[1] = 1; tree[node].sum[1] = v2;
        }
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    merge(tree[node], tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int start, int end, int idx) {
    if (start == end) {
        long long v1 = A_arr[start];
        long long v2 = B_arr[start];

        if (v1 + K < v2) {
            tree[node].trans[0] = 1; tree[node].sum[0] = v2;
            tree[node].trans[1] = 1; tree[node].sum[1] = v2;
        }
        else if (v2 + K < v1) {
            tree[node].trans[0] = 0; tree[node].sum[0] = v1;
            tree[node].trans[1] = 0; tree[node].sum[1] = v1;
        }
        else {
            tree[node].trans[0] = 0; tree[node].sum[0] = v1;
            tree[node].trans[1] = 1; tree[node].sum[1] = v2;
        }
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx);
    else update(2 * node + 1, mid + 1, end, idx);
    merge(tree[node], tree[2 * node], tree[2 * node + 1]);
}

void solve() {
    if (!(cin >> N >> K)) return;

    A_arr.assign(N + 1, 0);
    B_arr.assign(N + 1, 0);
    tree.assign(4 * N + 1, Node());

    for (int i = 1; i <= N; ++i) cin >> A_arr[i];
    for (int i = 1; i <= N; ++i) cin >> B_arr[i];

    build(1, 1, N);

    int Q;
    cin >> Q;
    while (Q--) {
        int t, p;
        long long x;
        cin >> t >> p >> x;
        if (t == 1) A_arr[p] = x;
        else B_arr[p] = x;

        update(1, 1, N, p);
        cout << tree[1].sum[0] << "\n";
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

