#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
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

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int C_fixed = 0;
    int T_fixed = 0;
    vector<int> B, C;
    int S_A = 0;
    int base_cost_segments = 0;

    // Count fixed ones and transitions
    for (char c : S) {
        if (c == '1') C_fixed++;
    }

    // Identify segments
    // Since S doesn't start/end with ?, we can just scan
    for (int i = 0; i < N; ) {
        if (S[i] == '?') {
            int j = i;
            while (j < N && S[j] == '?') {
                j++;
            }
            // Segment [i, j-1]
            int len = j - i;
            char left = S[i-1];
            char right = S[j];

            if (left == '0' && right == '0') {
                B.push_back(len);
            } else if (left == '1' && right == '1') {
                C.push_back(len);
            } else {
                S_A += len;
                base_cost_segments++;
            }
            i = j;
        } else {
            if (i + 1 < N && S[i+1] != '?') {
                if (S[i] != S[i+1]) T_fixed++;
            }
            i++;
        }
    }

    long long base_ones = C_fixed;
    for (int len : C) base_ones += len;

    int base_cost = T_fixed + base_cost_segments;

    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    int nB = B.size();
    int nC = C.size();
    vector<long long> SumMaxB(nB + 1, 0);
    vector<long long> SumMaxC(nC + 1, 0);
    for (int i = 0; i < nB; ++i) SumMaxB[i+1] = SumMaxB[i] + B[i];
    for (int i = 0; i < nC; ++i) SumMaxC[i+1] = SumMaxC[i] + C[i];

    vector<int> ans(N + 1, -1);

    // DSU for step=1 case
    DSU dsu_all(N + 2);

    // DSUs for step=2 case
    DSU dsu_even((N / 2) + 2);
    DSU dsu_odd((N / 2) + 2);

    bool special_case = (S_A == 0);
    if (special_case) {
        for (int x : B) if (x > 1) special_case = false;
        for (int x : C) if (x > 1) special_case = false;
    }

    int max_X = nB + nC;
    for (int X = 0; X <= max_X; ++X) {
        int min_i = max(0, X - nC);
        int max_i = min(X, nB);

        if (min_i > max_i) continue;

        long long L_min = min_i - SumMaxC[X - min_i];
        long long R_max = SumMaxB[max_i] - (X - max_i) + S_A;

        long long start_delta = L_min;
        long long end_delta = R_max;

        long long valid_start = max(start_delta, (long long)-base_ones);
        long long valid_end = min(end_delta, (long long)N - base_ones);

        if (valid_start > valid_end) continue;

        int cost = base_cost + 2 * X;
        int blocks = cost + 1;

        long long current = valid_start;

        if (special_case) {
            if ((current - L_min) % 2 != 0) current++;
            if (current > valid_end) continue;

            int k_start = base_ones + current;
            int parity = k_start % 2;
            int idx_start = k_start / 2;

            DSU* curr_dsu = (parity == 0) ? &dsu_even : &dsu_odd;
            int idx = curr_dsu->find(idx_start);

            while (true) {
                int k = idx * 2 + parity;
                long long delta = k - base_ones;

                if (delta > valid_end) break;

                if (ans[k] == -1) ans[k] = blocks;

                curr_dsu->unite(idx, idx + 1);
                idx = curr_dsu->find(idx);
            }
        } else {
            int k_start = base_ones + current;
            int k = dsu_all.find(k_start);

            while (true) {
                long long delta = k - base_ones;
                if (delta > valid_end) break;

                if (ans[k] == -1) ans[k] = blocks;

                dsu_all.unite(k, k + 1);
                k = dsu_all.find(k);
            }
        }
    }

    for (int i = 0; i <= N; ++i) {
        cout << ans[i] << (i == N ? "" : " ");
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
