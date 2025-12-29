#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_NODES = 200005 * 32;
struct TrieNode {
    int children[2];
    int count;
} tree[MAX_NODES];
int nodes_cnt = 1;

void init_trie() {
    nodes_cnt = 1;
    tree[0].children[0] = tree[0].children[1] = -1;
    tree[0].count = 0;
}

int new_node() {
    int u = nodes_cnt++;
    tree[u].children[0] = tree[u].children[1] = -1;
    tree[u].count = 0;
    return u;
}

void insert(int val) {
    int u = 0;
    tree[u].count++;
    for (int i = 29; i >= 0; --i) {
        int bit = (val >> i) & 1;
        if (tree[u].children[bit] == -1) {
            tree[u].children[bit] = new_node();
        }
        u = tree[u].children[bit];
        tree[u].count++;
    }
}

void remove(int val) {
    int u = 0;
    tree[u].count--;
    for (int i = 29; i >= 0; --i) {
        int bit = (val >> i) & 1;
        u = tree[u].children[bit];
        tree[u].count--;
    }
}

// Returns min(val ^ x) for x in trie
int query(int val) {
    int u = 0;
    int res = 0;
    for (int i = 29; i >= 0; --i) {
        int bit = (val >> i) & 1;
        if (tree[u].children[bit] != -1 && tree[tree[u].children[bit]].count > 0) {
            u = tree[u].children[bit];
        } else {
            res |= (1 << i);
            u = tree[u].children[1 - bit];
        }
    }
    return res;
}

// Returns the value x in trie that minimizes val ^ x
int query_val(int val) {
    int u = 0;
    int current_val = 0;
    for (int i = 29; i >= 0; --i) {
        int bit = (val >> i) & 1;
        if (tree[u].children[bit] != -1 && tree[tree[u].children[bit]].count > 0) {
            u = tree[u].children[bit];
            if (bit) current_val |= (1 << i);
        } else {
            u = tree[u].children[1 - bit];
            if (1 - bit) current_val |= (1 << i);
        }
    }
    return current_val;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    int S = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        S ^= A[i];
    }

    init_trie();
    for (int x : A) insert(x);

    int max_S_xor_A = -1;
    int second_max_S_xor_A = -1;
    int count_max = 0;

    for (int x : A) {
        int val = S ^ x;
        if (val > max_S_xor_A) {
            second_max_S_xor_A = max_S_xor_A;
            max_S_xor_A = val;
            count_max = 1;
        } else if (val == max_S_xor_A) {
            count_max++;
        } else if (val > second_max_S_xor_A) {
            second_max_S_xor_A = val;
        }
    }

    int ans = -1;

    for (int j = 0; j < N; ++j) {
        int target = S ^ A[j];
        int best_val_in_trie = query_val(target);
        int m1 = target ^ best_val_in_trie;

        remove(best_val_in_trie);

        int m2;
        if (tree[0].count > 0) {
             m2 = query(target);
        } else {
             m2 = 2e9 + 7;
        }

        insert(best_val_in_trie);

        int val_case1 = min(m2, S ^ best_val_in_trie);

        int current_max_S_xor_A;
        int val_k1 = S ^ best_val_in_trie;

        if (val_k1 == max_S_xor_A) {
            if (count_max > 1) {
                current_max_S_xor_A = max_S_xor_A;
            } else {
                current_max_S_xor_A = second_max_S_xor_A;
            }
        } else {
            current_max_S_xor_A = max_S_xor_A;
        }

        int val_case2 = -1;
        if (current_max_S_xor_A != -1) {
            val_case2 = min(m1, current_max_S_xor_A);
        }

        ans = max(ans, max(val_case1, val_case2));
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

