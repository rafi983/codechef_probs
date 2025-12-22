#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const long long INF = 1e18;

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> B(N);
    for (int i = 0; i < N; ++i) cin >> B[i];

    vector<long long> P(N, -INF);
    vector<long long> PB(N, -INF);

    long long current_pos_sum = 0;
    long long max_elem = -INF;
    bool has_pos = false;

    long long max_b_neg = -INF;
    bool has_pos_b = false;

    for (int i = 0; i < N; ++i) {
        // Update P state
        if (A[i] > 0) {
            current_pos_sum += A[i];
            has_pos = true;
        }
        max_elem = max(max_elem, A[i]);

        if (has_pos) P[i] = current_pos_sum;
        else P[i] = max_elem;

        // Update PB state
        if (B[i]) {
            if (A[i] > 0) has_pos_b = true;
            else max_b_neg = max(max_b_neg, A[i]);
        }

        if (has_pos_b) {
            PB[i] = current_pos_sum;
        } else {
            if (max_b_neg != -INF) {
                PB[i] = current_pos_sum + max_b_neg;
            } else {
                PB[i] = -INF;
            }
        }
    }

    vector<long long> S(N, -INF);
    vector<long long> SB(N, -INF);

    current_pos_sum = 0;
    max_elem = -INF;
    has_pos = false;

    max_b_neg = -INF;
    has_pos_b = false;

    for (int i = N - 1; i >= 0; --i) {
        // Update S state
        if (A[i] > 0) {
            current_pos_sum += A[i];
            has_pos = true;
        }
        max_elem = max(max_elem, A[i]);

        if (has_pos) S[i] = current_pos_sum;
        else S[i] = max_elem;

        // Update SB state
        if (B[i]) {
            if (A[i] > 0) has_pos_b = true;
            else max_b_neg = max(max_b_neg, A[i]);
        }

        if (has_pos_b) {
            SB[i] = current_pos_sum;
        } else {
            if (max_b_neg != -INF) {
                SB[i] = current_pos_sum + max_b_neg;
            } else {
                SB[i] = -INF;
            }
        }
    }

    long long v_all = -INF;
    long long v_mutable = -INF;


    for (int k = 1; k <= N - 2; ++k) {
        long long left_p = P[k-1];
        long long right_s = S[k+1];

        if (left_p != -INF && right_s != -INF) {
            v_all = max(v_all, left_p + right_s);
        }

        long long left_pb = PB[k-1];
        long long right_sb = SB[k+1];

        if (left_pb != -INF && right_s != -INF) {
            v_mutable = max(v_mutable, left_pb + right_s);
        }
        if (left_p != -INF && right_sb != -INF) {
            v_mutable = max(v_mutable, left_p + right_sb);
        }
    }

    if (v_all >= X) {
        cout << 0 << "\n";
    } else {
        if (v_mutable == -INF) {
             // Should not happen given constraints
             cout << 0 << "\n";
        } else {
             long long ans = X - v_mutable;
             if (ans < 0) ans = 0;
             cout << ans << "\n";
        }
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

