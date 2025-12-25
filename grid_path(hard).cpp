#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

int N, Q;
int A[3][MAXN]; // 1-based rows, 1-based cols

struct FenwickTree {
    int size;
    vector<long long> tree;

    void init(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }

    void add(int idx, long long val) {
        for (; idx <= size; idx += idx & -idx)
            tree[idx] += val;
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += tree[idx];
        return sum;
    }

    // Find smallest index p such that query(p) >= k
    int find_kth(int k) {
        int idx = 0;
        long long current_sum = 0;
        // 1 << 18 is 262144, sufficient for N <= 200000
        for (int i = 1 << 18; i > 0; i >>= 1) {
            if (idx + i <= size && current_sum + tree[idx + i] < k) {
                idx += i;
                current_sum += tree[idx];
            }
        }
        return idx + 1;
    }
};

FenwickTree cnt1, sum1;
FenwickTree cnt2, sum2;
int total_cnt1 = 0;
int total_cnt2 = 0;

void update(int r, int c) {
    int val = A[r][c];
    // Flip
    A[r][c] = 1 - val;
    int new_val = A[r][c];

    int delta = (new_val == 1) ? 1 : -1;

    if (r == 1) {
        cnt1.add(c, delta);
        sum1.add(c, delta * c);
        total_cnt1 += delta;
    } else {
        cnt2.add(c, delta);
        sum2.add(c, delta * c);
        total_cnt2 += delta;
    }
}

long long get_p1(int x) {
    // Sum of first x indices in row 1
    if (x == 0) return 0;
    int idx = cnt1.find_kth(x);
    return sum1.query(idx);
}

long long get_p2(int y) {
    // Sum of largest y indices in row 2
    if (y == 0) return 0;
    // Total sum - sum of smallest (total_cnt2 - y)
    long long total = sum2.query(N);
    int rem = total_cnt2 - y;
    if (rem == 0) return total;
    int idx = cnt2.find_kth(rem);
    long long prefix = sum2.query(idx);
    return total - prefix;
}

int get_pos1(int k) {
    return cnt1.find_kth(k);
}

int get_pos2_largest(int k) {
    // k-th largest is (total_cnt2 - k + 1)-th smallest
    return cnt2.find_kth(total_cnt2 - k + 1);
}

void solve_query() {
    int L = max(1, N - total_cnt2 + 1);
    int R = min(N, total_cnt1);

    if (L > R) {
        cout << -1 << "\n";
        return;
    }


    int ans_x = R;
    int low = L, high = R - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int p1 = get_pos1(mid + 1);
        int p2 = get_pos2_largest(N + 1 - mid);
        long long delta = (long long)p1 + p2 - (2LL * mid + 1);

        if (delta >= 0) {
            ans_x = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    long long term1 = get_p1(ans_x);
    long long term2 = get_p2(N + 1 - ans_x);
    long long term3 = (long long)N * (N + 1) / 2 - (long long)ans_x * ans_x;

    cout << (term1 - term2 + term3) << "\n";
}

void solve() {
    if (!(cin >> N >> Q)) return;

    string s1, s2;
    cin >> s1 >> s2;

    // Reset
    cnt1.init(N); sum1.init(N);
    cnt2.init(N); sum2.init(N);
    total_cnt1 = 0;
    total_cnt2 = 0;

    for (int i = 0; i < N; ++i) {
        A[1][i+1] = s1[i] - '0';
        if (A[1][i+1]) {
            cnt1.add(i+1, 1);
            sum1.add(i+1, i+1);
            total_cnt1++;
        }

        A[2][i+1] = s2[i] - '0';
        if (A[2][i+1]) {
            cnt2.add(i+1, 1);
            sum2.add(i+1, i+1);
            total_cnt2++;
        }
    }

    solve_query();

    while (Q--) {
        int r, c;
        cin >> r >> c;
        update(r, c);
        solve_query();
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
