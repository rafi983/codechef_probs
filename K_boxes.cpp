#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Thief {
    int id;
    int A;
    long long B;
};

bool compareThieves(const Thief& a, const Thief& b) {
    return a.A < b.A;
}

struct Node {
    int cnt;
    long long sum;
};

vector<long long> distinct_B;
vector<Node> tree;
int M; // Size of distinct_B

void update(int node, int start, int end, int idx, long long val) {
    if (start == end) {
        tree[node].cnt++;
        tree[node].sum += val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);

    tree[node].cnt = tree[2 * node].cnt + tree[2 * node + 1].cnt;
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
}

long long query(int node, int start, int end, int k) {
    if (tree[node].cnt <= k) return tree[node].sum;
    if (start == end) {
        // We need k elements from this leaf
        // The value at this leaf is distinct_B[start]
        return (long long)k * distinct_B[start];
    }
    int mid = (start + end) / 2;
    if (tree[2 * node + 1].cnt >= k) {
        return query(2 * node + 1, mid + 1, end, k);
    } else {
        return tree[2 * node + 1].sum + query(2 * node, start, mid, k - tree[2 * node + 1].cnt);
    }
}

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    vector<Thief> thieves(N);
    for (int i = 0; i < N; ++i) {
        thieves[i].id = i;
        cin >> thieves[i].A;
    }
    for (int i = 0; i < N; ++i) {
        cin >> thieves[i].B;
    }

    // Coordinate compression for B
    distinct_B.clear();
    for (int i = 0; i < N; ++i) distinct_B.push_back(thieves[i].B);
    sort(distinct_B.begin(), distinct_B.end());
    distinct_B.erase(unique(distinct_B.begin(), distinct_B.end()), distinct_B.end());
    M = distinct_B.size();


    tree.assign(4 * M, {0, 0});

    // Sort thieves by level A
    sort(thieves.begin(), thieves.end(), compareThieves);

    vector<long long> ans(N);

    for (int i = 0; i < N; ++i) {

        if (i > 0) { // If not the lowest level thief
             ans[thieves[i].id] = query(1, 0, M - 1, K);
        } else {
             ans[thieves[i].id] = 0;
        }

        // Add current thief to the pool
        int b_idx = lower_bound(distinct_B.begin(), distinct_B.end(), thieves[i].B) - distinct_B.begin();
        update(1, 0, M - 1, b_idx, thieves[i].B);
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << (i == N - 1 ? "" : " ");
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

