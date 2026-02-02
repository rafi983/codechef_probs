#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

const int MOD = 998244353;

void add_val(vector<long long>& diff, int l, int r, long long val) {
    if (l > r) return;
    diff[l] = (diff[l] + val) % MOD;
    if (r + 1 < diff.size()) {
        diff[r + 1] = (diff[r + 1] - val + MOD) % MOD;
    }
}

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Compute L[j]: nearest index k < j such that A[k] <= A[j]
    vector<int> L(N + 1);
    vector<int> st;
    for (int i = 1; i <= N; ++i) {
        while (!st.empty() && A[st.back()] > A[i]) {
            st.pop_back();
        }
        L[i] = st.empty() ? 0 : st.back();
        st.push_back(i);
    }

    // Compute R[j]: nearest index k > j such that A[k] < A[j]
    vector<int> R(N + 1);
    st.clear();
    for (int i = N; i >= 1; --i) {
        while (!st.empty() && A[st.back()] >= A[i]) {
            st.pop_back();
        }
        R[i] = st.empty() ? N + 1 : st.back();
        st.push_back(i);
    }

    vector<long long> diffConst(N + 2, 0);
    vector<long long> diffLinConst(N + 2, 0);
    vector<long long> diffLinCoeff(N + 2, 0);

    for (int j = 1; j <= N; ++j) {
        int start_i = j;
        int end_i = min(R[j] - 1, j + K - 1 - 1); // min(R_j-1, j+K-2)
        int split = L[j] + K - 1;

        if (start_i > end_i) continue;

        // Range 1: [start_i, min(end_i, split)]
        int r1_end = min(end_i, split);
        if (start_i <= r1_end) {
            long long val = (long long)A[j] * (j - L[j]) % MOD;
            add_val(diffConst, start_i, r1_end, val);
        }

        // Range 2: [max(start_i, split + 1), end_i]
        int r2_start = max(start_i, split + 1);
        if (r2_start <= end_i) {
            long long valP = (long long)A[j] * (j + K - 1) % MOD;
            long long valQ = A[j];
            add_val(diffLinConst, r2_start, end_i, valP);
            add_val(diffLinCoeff, r2_start, end_i, valQ);
        }
    }

    // Convert difference arrays to values
    vector<long long> C2(N + 1, 0);
    long long curConst = 0, curLinConst = 0, curLinCoeff = 0;

    for (int i = 1; i <= N; ++i) {
        curConst = (curConst + diffConst[i]) % MOD;
        curLinConst = (curLinConst + diffLinConst[i]) % MOD;
        curLinCoeff = (curLinCoeff + diffLinCoeff[i]) % MOD;

        long long val2 = (curLinConst - (curLinCoeff * i) % MOD + MOD) % MOD;
        C2[i] = (curConst + val2) % MOD;
    }

    // Compute C1
    vector<long long> C1(N + 1, 0);
    deque<int> dq;

    for (int i = 1; i <= N; ++i) {
        while (!dq.empty() && A[dq.back()] >= A[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        if (dq.front() < i - K + 1) {
            dq.pop_front();
        }

        int count = max(0, i - K + 1);
        C1[i] = (long long)count * A[dq.front()] % MOD;
    }

    long long total_ans = 0;
    for (int i = 1; i <= N; ++i) {
        long long term = (C1[i] + C2[i]) % MOD;
        long long mult = (N - i + 1);
        total_ans = (total_ans + term * mult) % MOD;
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
